#include "Std_Clock_Fac.h"

int Std_Clock_Fac_INSTANCE = 0;

//If our facility has already been created, we don't want a new copy.
void Std_Clock_Fac_create() {
	if (Std_Clock_Fac_INSTANCE == 0) {
		Std_Clock_Fac_Var.core = new_Std_Clock_Realiz_for_Clock_Template();
		Std_Clock_Fac_INSTANCE = 1;
	}
}

void Std_Clock_Fac_destroy() {
	if (Std_Clock_Fac_INSTANCE == 1) {
		free_Std_Clock_Realiz_for_Clock_Template(Std_Clock_Fac_Var.core);
		Std_Clock_Fac_INSTANCE = 0;
	}
}


