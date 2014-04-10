#ifndef __STD_INTEGER_FAC_H
#define __STD_INTEGER_FAC_H

#include "../../../RESOLVE.h"
#include "../../Concepts/Standard/Integer_Template/Std_Integer_Realiz.h"

typedef struct Std_Integer_Fac Std_Integer_Fac;
struct Std_Integer_Fac {
	Integer_Template* core;
};
Std_Integer_Fac Std_Integer_Fac_Var;

void Std_Integer_Fac_create();
void Std_Integer_Fac_destroy();

#endif