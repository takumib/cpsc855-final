#ifdef TELOS
#include <msp430.h>
#include <legacymsp430.h>
#endif
#include "Std_Leds_Realiz.h"
#include "naive_malloc.h"

#define LED0 (0x0010)
#define LED1 (0x0020)
#define LED2 (0x0040)

#ifdef TELOS
#define LED_DIR P5DIR
#define LED_OUT P5OUT
#else
int LED_OUT = 0;
#endif

static r_type_ptr createLed(type_info* LedType) {
	Leds_Template* this = salloc(sizeof(Leds_Template));
	return (r_type_ptr)this;
}

static void destroyLed(r_type_ptr r, type_info* LedType) {
	sfree(*r);
	sfree(r);
}

static void Set(r_type_ptr r, r_type_ptr b, r_type_ptr i, Leds_Template* this) {
	int hex = 0x00;
	int out = **(int**)i;
	int led0, led1, led2;
	if(**(int**)b == 0) {
		hex = LED0 << out;
	}

	if(out == 0) {
		led1 = LED_OUT & LED1;
		led2 = LED_OUT & LED2;
		LED_OUT = (hex & LED0) + led1 + led2;
	}	
	else if(out == 1) {
		led0 = LED_OUT & LED0;
		led2 = LED_OUT & LED2;
		LED_OUT = (hex & LED1) + led0 + led2;
	}
	else {
		led0 = LED_OUT & LED0;
		led1 = LED_OUT & LED1;
		LED_OUT = (hex & LED2) + led0 + led1;
	}
}

static r_type_ptr Status(r_type_ptr r, r_type_ptr i, Leds_Template* this) {
	int *mask = scalloc(1, sizeof(int));

	if(**(int**)i == 0) {
		*mask = LED_OUT & LED0;
		*mask = *mask ^ LED0;
		*mask = *mask >> 3;
	}
	else if(**(int**)i == 1) {
		*mask = LED_OUT & LED1;
		*mask = *mask ^ LED1;
	}
	else {
		*mask = LED_OUT & LED2;
		*mask = *mask ^ LED2;
	}

	int **ret = salloc(sizeof(int*));
	*ret = mask;
	return (r_type_ptr)(ret);
}

extern Leds_Template* new_Std_Leds_Realiz_for_Leds_Template(r_type_ptr Strip_Length) {

    Leds_Template* this = scalloc(1, sizeof(Leds_Template));
	this->Set = Set;
	this->Status = Status;
	this->Strip_Length = Std_Integer_Fac_Var.core->Replica(Strip_Length, Std_Integer_Fac_Var.core);
	type_info* Led_i = scalloc(1, sizeof(type_info));
	Led_i->create = createLed;
	Led_i->destroy = destroyLed;
	this->Led = Led_i;
	this->Led->PointerToFacility = this;

#ifdef TELOS
	WDTCTL = WDTPW + WDTHOLD;
    
    _BIS_SR(OSCOFF);
    BCSCTL2 |= DIVM1;

    DCOCTL = DCO2 | DCO0 | MOD4 | MOD2;
    BCSCTL1 = XT2OFF | RSEL2 | RSEL1 | RSEL0;
    BCSCTL2 = DIVS1;

	LED_DIR |= LED0;
	LED_DIR |= LED1;
	LED_DIR |= LED2;
	
	eint();
#endif

	LED_OUT = LED0 + LED1 + LED2;

	return this;
}

extern void free_Std_Leds_Realiz_for_Leds_Template(Leds_Template* toFree) {
	Std_Integer_Fac_Var.core->Integer->destroy(toFree->Strip_Length, Std_Integer_Fac_Var.core->Integer);
    sfree(toFree);
}
