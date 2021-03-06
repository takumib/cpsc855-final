/*
 * Generated by the RESOLVE to C translator. This file
 * should not be modified.
 */
#include "Leds_Test.h"
void Leds_Test_create() {
	Std_Boolean_Fac_create();
	Std_Integer_Fac_create();
 	Std_Clock_Fac_create();
 	r_type_ptr __arg_0 = Std_Integer_Fac_Var.core->createFromInteger(4,Std_Integer_Fac_Var.core->Integer);
	Led_Facility_Var.core = new_Std_Leds_Realiz_for_Leds_Template(__arg_0);
	Led_Facility_Var.Toggling_Capability = new_Toggling_Realiz_for_Toggling_Capability_of_Leds_Template(
											Led_Facility_Var.core);
	Std_Integer_Fac_Var.core->Integer->destroy(__arg_0, Std_Integer_Fac_Var.core->Integer);
}

void Leds_Test_destroy() {
    free_Std_Leds_Realiz_for_Leds_Template(Led_Facility_Var.core);
    Std_Boolean_Fac_destroy();
    Std_Integer_Fac_destroy();
}

void Main() {
	r_type_ptr this = Led_Facility_Var.core->Led->create(Led_Facility_Var.core->Led);
	r_type_ptr b = Std_Boolean_Fac_Var.core->createFromBoolean(1, Std_Boolean_Fac_Var.core->Boolean);
	r_type_ptr i = Std_Integer_Fac_Var.core->createFromInteger(0, Std_Integer_Fac_Var.core->Integer);
	r_type_ptr i2 = Std_Integer_Fac_Var.core->createFromInteger(1, Std_Integer_Fac_Var.core->Integer);
	r_type_ptr i3 = Std_Integer_Fac_Var.core->createFromInteger(2, Std_Integer_Fac_Var.core->Integer);
	
	while(**(int**)b) {
		Led_Facility_Var.Toggling_Capability->Toggle(this, i, Led_Facility_Var.Toggling_Capability);
		Std_Clock_Fac_Var.core->Wait_500_Milli_Seconds(Std_Clock_Fac_Var.core);
		Led_Facility_Var.Toggling_Capability->Toggle(this, i2, Led_Facility_Var.Toggling_Capability);
		Std_Clock_Fac_Var.core->Wait_500_Milli_Seconds(Std_Clock_Fac_Var.core);
		Led_Facility_Var.Toggling_Capability->Toggle(this, i3, Led_Facility_Var.Toggling_Capability);
		Std_Clock_Fac_Var.core->Wait_500_Milli_Seconds(Std_Clock_Fac_Var.core);
	}
	
	Std_Integer_Fac_Var.core->Integer->destroy(i, Std_Integer_Fac_Var.core->Integer);
	Std_Integer_Fac_Var.core->Integer->destroy(i2, Std_Integer_Fac_Var.core->Integer);
	Std_Integer_Fac_Var.core->Integer->destroy(i3, Std_Integer_Fac_Var.core->Integer);
	Std_Boolean_Fac_Var.core->Boolean->destroy(b, Std_Boolean_Fac_Var.core->Boolean);
	Led_Facility_Var.core->Led->destroy(this, Led_Facility_Var.core->Led);
}

int main() {
    Leds_Test_create();
    Main();
    Leds_Test_destroy();
    return 0;
}
