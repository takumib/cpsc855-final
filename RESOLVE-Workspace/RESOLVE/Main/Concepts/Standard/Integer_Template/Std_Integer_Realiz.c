#include <limits.h>
#include "Integer_Template.h"

static int ValueOf(r_type_ptr r) {
    return **(int**)r;
}

static void assign(r_type_ptr r, r_type_ptr i, IntegerTemplate* this) {
	**(int**)r = **(int**)i;	
}

static r_type_ptr createFromInteger(int I, type_info* ti) {
	int *space = scalloc(1, sizeof(int));
	*space = I;
	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr createInteger(type_info* ti) {
    int* t = scalloc(1, sizeof(int));
    *t = 0;
    int** ret = salloc(sizeof(int*));
    *ret = t;
    return (r_type_ptr)ret;
}

static void destroyInteger (r_type_ptr r, type_info* ti) {
    sfree(*r);
    sfree(r);
}

static type_info* newInteger() {
    type_info* pc = scalloc(1, sizeof(type_info));
    pc->create = createInteger;
    pc->destroy = destroyInteger;
    return pc;
}

static r_type_ptr Is_Zero(r_type_ptr i, Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = (**(int**)i == 0);

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Is_Not_Zero(r_type_ptr i, Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = (**(int**)i != 0);

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static void Increment(r_type_ptr i, Integer_Template* this) {
	**(int**)i = **(int**)i + 1;
}

static void Decrement(r_type_ptr i, Integer_Template* this) {
	**(int**)i = **(int**)i - 1;
}

static r_type_ptr Less_Or_Equal(r_type_ptr i1, r_type_ptr i2, Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = ((**(int**)i1 <= (**(int**)i2)));

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Less(r_type_ptr i1, r_type_ptr i2, Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = ((**(int**)i1 < (**(int**)i2)));

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Greater(r_type_ptr i1, r_type_ptr i2, Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = ((**(int**)i1 > (**(int**)i2)));

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Greater_Or_Equal(r_type_ptr i1, r_type_ptr i2, Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = ((**(int**)i1 >= (**(int**)i2)));

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Sum(r_type_ptr i1, r_type_ptr i2, Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = **(int**)i1 + **(int**)i2;

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Negate(r_type_ptr i, Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = -(**(int**)i);

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Difference(r_type_ptr i1, r_type_ptr i2, Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = (**(int**)i1) - (**(int**)i2);

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Product(r_type_ptr i1, r_type_ptr i2, Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = (**(int**)i1) * (**(int**)i2);

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Max_Int(Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = **(int**)INT_MAX;

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Min_Int(Integer_Template* this) {
	int *space = scalloc(1, sizeof(int));
	*space = **(int**)INT_MIN;

	int** ret = salloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static void Clear(r_type_ptr i, Integer_Template* this) {
	**(int**)i = 0;	//Is this what we are looking for?
}

static void Read(r_type_ptr i, Integer_Template* this) {
	scanf("%d", *(int**)i);
}

static void Write(r_type_ptr i, Integer_Template* this) {
	printf("%d", **(int**)i);
}

static void Write_Line(r_type_ptr i, Integer_Template* this) {
	printf("%d\n", **(int**)i);
}

extern Integer_Template* new_Std_Integer_Realiz_for_Integer_Template() {
    Integer_Template* I = salloc(sizeof(Integer_Template));
    I -> Is_Zero = Is_Zero;
    I -> Is_Not_Zero = Is_Not_Zero;
    I -> Increment = Increment;
    I -> Decrement = Decrement;
    I -> Less_Or_Equal = Less_Or_Equal;
    I -> Less = Less;
    I -> Greater = Greater;
    I -> Greater_Or_Equal = Greater_Or_Equal;
    I -> Sum = Sum;
    I -> Negate = Negate;
    I -> Difference = Difference;
    I -> Product = Product;
    I -> Max_Int = Max_Int;
    I -> Min_Int = Min_Int;

    // Fill in the rest of these...

	I -> Clear = Clear;
    I -> Read = Read;
    I -> Write = Write;
    I -> Write_Line = Write_Line;
    I -> createFromInteger = createFromInteger;
    I -> Integer = newInteger();
    I -> Integer -> PointerToFacility = I;
    return I;
}

extern void free_Std_Integer_Realiz_for_Integer_Template(Integer_Template* tofree) {
    sfree(tofree->Integer);
    sfree(tofree);
}