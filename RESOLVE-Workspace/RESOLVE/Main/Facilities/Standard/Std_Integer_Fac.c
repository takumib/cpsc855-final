#include "Std_Integer_Fac.h"

int Std_Integer_Fac_INSTANCE = 0;

//If our facility has already been created, we don't want a new copy.
void Std_Integer_Fac_create() {
	if (Std_Integer_Fac_INSTANCE == 0) {
		Std_Integer_Fac_Var.core = new_Std_Integer_Realiz_for_Integer_Template();
		Std_Integer_Fac_INSTANCE = 1;
	}
}

void Std_Integer_Fac_destroy() {
	if (Std_Integer_Fac_INSTANCE == 1) {
		free_Std_Integer_Realiz_for_Integer_Template(Std_Integer_Fac_Var.core);
		Std_Integer_Fac_INSTANCE = 0;
	}
}
