/*
 * Generated by the RESOLVE to C translator. This file
 * should not be modified.
 */
#ifndef __ALT_REV_STACK_H
#define __ALT_REV_STACK_H

#include "../../../RESOLVE.h"
#include "../../../Main/Facilities/Standard/Std_Boolean_Fac.h"
#include "../../../Main/Facilities/Standard/Std_Integer_Fac.h"

typedef struct Stack_Fac Stack_Fac;
struct Stack_Fac {
    Stack_Template* core;
    Reading_Capability_for_Stack_Template* Reading_Capability;
    Writing_Capability_for_Stack_Template* Writing_Capability;
};
Stack_Fac __Stack_Fac_Var;
void Alt_Rev_Stack_create();
void Alt_Rev_Stack_destroy();

#endif