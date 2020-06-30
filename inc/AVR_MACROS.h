/*
*  File:          AVR_MACROS.h
*  Description:   AVR Librariy includes & Bit Manipulation Macros Definition
*/

#ifndef AVR_MACROS_H_
#define AVR_MACROS_H_

#include <stdint.h>

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>





/* SET BIT IN REGISTER */
#define SET_BIT(REG,BIT)   (REG |= 1 << BIT)

/* CLEAR BIT IN REGISTER */
#define CLR_BIT(REG,BIT)   (REG &= ~(1 << BIT))

/* TOGGLE BIT IN REGISTER */
#define TOG_BIT(REG,BIT)   (REG ^= 1 << BIT)

/* READ BIT FROM REGISTER */
#define READ_BIT(REG,BIT)  ((REG >> BIT) & 1)




#endif /* AVR_MACROS_H_ */