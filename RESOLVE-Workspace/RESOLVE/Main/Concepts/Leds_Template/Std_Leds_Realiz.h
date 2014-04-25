#ifndef __STD_LEDS_REALIZ_H
#define __STD_LEDS_REALIZ_H

#include "../../../RESOLVE.h"
#include "../../../Main/Concepts/Leds_Template/Leds_Template.h"
#include "../../../Main/Facilities/Standard/Std_Boolean_Fac.h"
#include "../../../Main/Facilities/Standard/Std_Integer_Fac.h"

extern Leds_Template* new_Std_Leds_Realiz_for_Leds_Template(r_type_ptr Strip_Length);
extern void free_Std_Leds_Realiz_for_Leds_Template(Leds_Template* toFree);

#endif