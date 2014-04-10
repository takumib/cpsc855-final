#include "Boolean_Template.h"

static int ValueOf(r_type_ptr r) {
    return **(int**)r;
}

static r_type_ptr createFromBoolean(int I, type_info* ti) {
	int *space = calloc(1, sizeof(int));
	*space = I;
	int** ret = malloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr createBoolean(type_info* ti) {
    int* t = calloc(1, sizeof(int));
    *t = 0;
    int** ret = malloc(sizeof(int*));
    *ret = t;
    return (r_type_ptr)ret;
}

static void destroyBoolean (r_type_ptr r, type_info* ti) {
    free(*r);
    free(r);
}

static type_info* newBoolean() {
    type_info* pc = calloc(1, sizeof(type_info));
    pc->create = createBoolean;
    pc->destroy = destroyBoolean;
    return pc;
}

static r_type_ptr True(Boolean_Template* this) {
	int *space = calloc(1, sizeof(int));
	*space = 1;
	int** ret = malloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr False(Boolean_Template* this) {
	int *space = calloc(1, sizeof(int));
	*space = 0;
	int** ret = malloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr And(r_type_ptr b1, r_type_ptr b2, Boolean_Template* this) {
	int *space = calloc(1, sizeof(int));
	*space = ((**(int**)b1 == 1) && (**(int**)b2 == 1));

	int** ret = malloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Or(r_type_ptr b1, r_type_ptr b2, Boolean_Template* this) {
	int *space = calloc(1, sizeof(int));
	*space = ((**(int**)b1 == 1) || (**(int**)b2 == 1));

	int** ret = malloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Not(r_type_ptr b1, Boolean_Template* this) {
	int *space = calloc(1, sizeof(int));
	*space = !(**(int**)b1);

	int** ret = malloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Are_Equal(r_type_ptr b1, r_type_ptr b2, Boolean_Template* this) {
	int *space = calloc(1, sizeof(int));
	*space = (**(int**)b1 == **(int**)b2);

	int** ret = malloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Are_Not_Equal(r_type_ptr b1, r_type_ptr b2, Boolean_Template* this) {
	int *space = calloc(1, sizeof(int));
	*space = (**(int**)b1 != **(int**)b2);

	int** ret = malloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static r_type_ptr Replica(r_type_ptr I, Boolean_Template* this) {
	int *space = calloc(1, sizeof(int));
	*space = ValueOf(I);
	int** ret = malloc(sizeof(int*));
	*ret = space;
	return (r_type_ptr)ret;
}

static void Read(r_type_ptr b1, Boolean_Template* this) {
	scanf("%d", *(int**)b1);
}

static void Write(r_type_ptr b1, Boolean_Template* this) {
	printf("%d", **(int**)b1);
}

static void Write_Line(r_type_ptr b1, Boolean_Template* this) {
	printf("%d\n", **(int**)b1);
}

extern Boolean_Template* new_Std_Boolean_Realiz_for_Boolean_Template() {
    Boolean_Template* I = malloc(sizeof(Boolean_Template));
    I -> True = True;
    I -> False = False;
    I -> And = And;
    I -> Or = Or;
    I -> Not = Not;
    I -> Are_Equal = Are_Equal;
    I -> Are_Not_Equal = Are_Not_Equal;
    I -> Replica = Replica;
    I -> Read = Read;
    I -> Write = Write;
    I -> Write_Line = Write_Line;
    I -> createFromBoolean = createFromBoolean;
    I -> Boolean = newBoolean();
    I -> Boolean -> PointerToFacility = I;
    return I;
}

extern void free_Std_Boolean_Realiz_for_Boolean_Template(Boolean_Template* toFree) {
    free(toFree->Boolean);
    free(toFree);
}