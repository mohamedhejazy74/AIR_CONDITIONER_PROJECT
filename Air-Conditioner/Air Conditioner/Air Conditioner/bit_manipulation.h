/*
 * bit_manipulation.h
 *
 * Created: 4/21/2023 5:48:26 PM
 *  Author:  ARAFA ARAFA
 *	EMAIL : arafa.arafa.prog@gmail.com
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#ifndef BIT_MASK
#define BIT_MASK        0x01
#endif

#ifndef CLEAR_BIT
#define CLEAR_BIT(REG, BIT_POSN)            (REG &= (~(BIT_MASK << BIT_POSN)))  /*clear a specific bit in reg*/
#endif

#ifndef SET_BIT
#define SET_BIT(REG, BIT_POSN)              (REG |= (BIT_MASK << BIT_POSN))     /*set a specific bit in reg*/
#endif


#define TOGGLE_BIT(REG, BIT_POSN)           (REG ^= (BIT_MASK << BIT_POSN))     /*toggle specific bit in reg*/
#define READ_BIT(REG, BIT_POSN)             (((REG >> BIT_POSN) & BIT_MASK))    /*read a specific bit in reg*/
#define SET_LOW_NIBBLE_BITS(REG, DATA)      (REG = ((REG&0xF0)|(DATA&0x0F)))
#define SET_HIGH_NIBBLE_BITS(REG, DATA)     (REG = ((REG&0x0F)|(DATA&0xF0)))


#endif /* BIT_MANIPULATION_H_ */