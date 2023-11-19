#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(reg,bitN)    ((reg) |= (1<<bitN))
#define CLR_BIT(reg,bitN)  ((reg) &= ~(1<<bitN))
#define TOG_BIT(reg,bitN) ((reg) ^= (1<<bitN))
#define GET_BIT(reg,bitN)    (1 & ((reg)>>bitN))


#endif
