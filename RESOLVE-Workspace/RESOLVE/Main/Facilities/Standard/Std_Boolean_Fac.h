#ifndef __STD_BOOLEAN_FAC_H
#define __STD_BOOLEAN_FAC_H

#include "../../../RESOLVE.h"
#include "../../Concepts/Standard/Boolean_Template/Std_Boolean_Realiz.h"

typedef struct Std_Boolean_Fac Std_Boolean_Fac;
struct Std_Boolean_Fac {
	Boolean_Template* core;
};
Std_Boolean_Fac Std_Boolean_Fac_Var;

void Std_Boolean_Fac_create();
void Std_Boolean_Fac_destroy();

#endif