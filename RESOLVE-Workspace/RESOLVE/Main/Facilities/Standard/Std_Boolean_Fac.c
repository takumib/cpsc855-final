#include "Std_Boolean_Fac.h"

int Std_Boolean_Fac_INSTANCE = 0;

//If our facility has already been created, we don't want a new copy.
void Std_Boolean_Fac_create() {
	if (Std_Boolean_Fac_INSTANCE == 0) {
		Std_Boolean_Fac_Var.core = new_Std_Boolean_Realiz_for_Boolean_Template();
		Std_Boolean_Fac_INSTANCE = 1;
	}
}

void Std_Boolean_Fac_destroy() {
	if (Std_Boolean_Fac_INSTANCE == 1) {
		free_Std_Boolean_Realiz_for_Boolean_Template(Std_Boolean_Fac_Var.core);
		Std_Boolean_Fac_INSTANCE = 0;
	}
}