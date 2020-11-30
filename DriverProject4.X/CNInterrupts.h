
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

   

#ifdef	__cplusplus
}
#endif /* __cplusplus */




#endif	/* XC_HEADER_TEMPLATE_H */

void Debounce_check(void);

void __attribute__((interrupt, no_auto_psv))_CNInterrupt(void);

extern unsigned int CN30flag;
extern unsigned int CN0flag;
extern unsigned int CN1flag;