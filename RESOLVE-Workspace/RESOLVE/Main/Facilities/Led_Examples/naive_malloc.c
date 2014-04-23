#ifdef DEBUG
#include <stdio.h>
#endif

#include "naive_malloc.h"

#define MAX_MEM 4096
#define align4(x) (((((x)-1)>>2)<<2)+4)

static void *stack[MAX_MEM];
static void *base = NULL;
static void *cur_brk = (void*)&stack[0];

typedef struct block_t *block;

struct block_t
{
	size_t size;
	block next;
	block prev;
	int free;
	int pad;
	void *ptr;
	char data[1];
};


#define BLOCK_SIZE (sizeof(struct block_t)-sizeof(char*))

block get_block(void *p);
int valid_addr(void *p);
block fusion(block b);

void split_block(block b, size_t size) 
{
	block new_block;
	new_block = (void*)b->data + size;
	new_block->size = b->size - size - BLOCK_SIZE;
	new_block->free = 1;
	b->size = size;
	b->next = new_block;	
	new_block->next = b->next;
	new_block->prev = b;
	new_block->ptr = new_block->data;
}

block find_block(block *last, size_t size) 
{
	block b = base;
	while(b && !(b->free && b->size >= (size))) {
		*last = b;
		b = b->next;
	}

	return b;
}

void *stack_sbrk(int n)
{
	cur_brk += n;
	if(cur_brk > (void*)&stack[MAX_MEM-1]) {
		return (void*)-1;
	}
	return (void*)(cur_brk);		
}

void stack_brk(void *ptr)
{
	cur_brk = ptr;
}

block extend_stack(block last, size_t size)
{
	block b;
	b = stack_sbrk(0);
	if(stack_sbrk(BLOCK_SIZE + size) == (void*)-1) {
		return NULL;
	}
	b->size = size;
	b->next = NULL;
	b->ptr = b->data;
	if(last) {
		last->next = b;
		b->prev = last;
	}
	b->free = 0;
	return b;
}

void *scalloc(int n, size_t size) {
	size_t *new;
	size_t s4, i;
	new = salloc(n * size);
	if(new) {
		s4 = align4(n * size) << 2;
		for(i = 0; i < s4; i++) {
			new[i] = 0;
		}
	}
	return (void*)new;
}
void examine_blocks() {
	block b = base;
	size_t free = 0;
	size_t used = 0;
	size_t total = 0;
	while(b) {
		if(b->free == 0) {	
			used += b->size + sizeof(struct block_t);
		} else {
			free += b->size + sizeof(struct block_t);
		}
		b = b->next;
	}	
	total = free + used;
//#ifdef DEBUG
	//printf("Memory Usage: \n");
	//printf("Used Blocks: %lu\n", used);
	//printf("Free Blocks: %lu\n", free);
	//printf("Total usage: %lu\n", total);
//#endif
}

void *salloc(size_t size)
{
	block b, last;
	size_t s;
	s = align4(size);

	if(base) {
		last = base;
		b = find_block(&last, s);
		if(b) {
			if((b->size - s) >= (BLOCK_SIZE))
				split_block(b, s);
			b->free = 0;
		} else {
			b = extend_stack(last, s);
			if(!b)
				return NULL;
		}
	}
	else {
#ifdef DEBUG
			//printf("Creating initial pointer\n");
			//printf("Printing stack address 0: %p\n", &stack[0]);
#endif
		b = extend_stack(NULL, s);
		if(!b)
			return NULL;
		base = b;
	}

	//printf("Start of block %p\n", b);
	//printf("Size of data %d\n", b->size);
	//printf("Sizeof block %d\n", sizeof(struct block_t));
	//examine_blocks();
	return b->data;
}

block get_block(void *p)
{
	char *tmp;
	tmp = p;
	p = tmp -= BLOCK_SIZE;
#ifdef DEBUG
	//printf("Returning get block address %p\n", p);
#endif
	return p;
}

int valid_addr(void *p)
{
	if(base) {
		if(p > base && p < stack_sbrk(0)) {
			return (p == (get_block(p))->ptr);
		}
	}
	return 0;
}

block fusion(block b)
{
	if(b->next && b->next->free) {
#ifdef DEBUG
		//printf("Fusing blocks\n");
#endif
		b->size += BLOCK_SIZE + b->next->size;
		b->next = b->next->next;
		if(b->next) {
			b->next->prev = b;
		}
	}
	return b;
}

void sfree(void *p)
{
	block b;
	if(valid_addr(p)) {
#ifdef DEBUG
		//printf("Found valid address\n");
#endif
		b = get_block(p);
		b->free = 1;
		if(b->prev && b->prev->free)
			b = fusion(b->prev);
		if(b->next)
			fusion(b);
	    else {
			if(b->prev) {
				b->prev->next = NULL;
			} else {
				base = NULL;
			}
			stack_brk(b);
		}
	}

}
