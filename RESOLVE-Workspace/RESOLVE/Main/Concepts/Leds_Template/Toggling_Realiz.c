#include "Toggling_Realiz.h"
#include "naive_malloc.h"

static void Toggle(r_type_ptr L, r_type_ptr I, Toggling_Capability_for_Leds_Template* this) {
		r_type_ptr Content = Std_Boolean_Fac_Var.core->Boolean->create(Std_Boolean_Fac_Var.core->Boolean);
		r_type_ptr Index = Std_Integer_Fac_Var.core->Integer->create(Std_Integer_Fac_Var.core->Integer);

		r_type_ptr tmp_exp_1;
		r_type_ptr tmp_exp_2;
		r_type_ptr tmp_exp_3;

		tmp_exp_1 = Std_Integer_Fac_Var.core->Replica(I, Std_Integer_Fac_Var.core);
		Std_Integer_Fac_Var.core->assign(Index, tmp_exp_1, Std_Integer_Fac_Var.core);

		tmp_exp_2 = this->core->Status(L, Index, this->core);
		Std_Boolean_Fac_Var.core->assign(Content, tmp_exp_2, Std_Boolean_Fac_Var.core);

		tmp_exp_3 = Std_Boolean_Fac_Var.core->Not(Content, Std_Boolean_Fac_Var.core);
		this->core->Set(L, tmp_exp_3, I, this->core);

		Std_Integer_Fac_Var.core->Integer->destroy(Index, Std_Integer_Fac_Var.core->Integer);
		Std_Boolean_Fac_Var.core->Boolean->destroy(Content, Std_Boolean_Fac_Var.core->Boolean);
		Std_Integer_Fac_Var.core->Integer->destroy(tmp_exp_1, Std_Integer_Fac_Var.core->Integer);
		Std_Integer_Fac_Var.core->Integer->destroy(tmp_exp_2, Std_Integer_Fac_Var.core->Integer);
		Std_Boolean_Fac_Var.core->Boolean->destroy(tmp_exp_3, Std_Boolean_Fac_Var.core->Boolean);
}

extern Toggling_Capability_for_Leds_Template* new_Toggling_Realiz_for_Toggling_Capability_of_Leds_Template(Leds_Template* core) {
    Toggling_Capability_for_Leds_Template* this = scalloc(1, sizeof(Toggling_Capability_for_Leds_Template));
    this->Toggle = Toggle;
    this->core = core;

    return this;
}
