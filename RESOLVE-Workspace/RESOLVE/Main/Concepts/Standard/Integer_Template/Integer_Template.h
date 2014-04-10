/*
 * Generated by the RESOLVE to C translator. This file
 * should not be modified.
 */
#ifndef __INTEGER_TEMPLATE_H
#define __INTEGER_TEMPLATE_H

#include "../../../../RESOLVE.h"
#include "../../../../Main/Facilities/Standard/Std_Boolean_Fac.h"

typedef struct Integer_Template Integer_Template;
struct Integer_Template {

    void* Realization_Specific;
    type_info* Integer;
    r_type_ptr (*Is_Zero) (r_type_ptr, Integer_Template*);
    r_type_ptr (*Is_Not_Zero) (r_type_ptr, Integer_Template*);
    void (*Increment) (r_type_ptr, Integer_Template*);
    void (*Decrement) (r_type_ptr, Integer_Template*);
    r_type_ptr (*Less_Or_Equal) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Less) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Greater) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Greater_Or_Equal) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Sum) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Negate) (r_type_ptr, Integer_Template*);
    r_type_ptr (*Difference) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Product) (r_type_ptr, r_type_ptr, Integer_Template*);
/*    r_type_ptr (*Power) (r_type_ptr, r_type_ptr, Integer_Template*);
    void (*Divide) (r_type_ptr, r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Mod) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Rem) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Quotient) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Div) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Are_Equal) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Are_Not_Equal) (r_type_ptr, r_type_ptr, Integer_Template*);
    r_type_ptr (*Replica) (r_type_ptr, Integer_Template*);*/

    void (*Read) (r_type_ptr, Integer_Template*);
    void (*Write) (r_type_ptr, Integer_Template*);
    void (*Write_Line) (r_type_ptr, Integer_Template*);
    r_type_ptr (*Max_Int) (Integer_Template*);
    r_type_ptr (*Min_Int) (Integer_Template*);
    void (*Clear) (r_type_ptr, Integer_Template*);
    r_type_ptr (*createFromInteger) (int, type_info*);

};
#endif