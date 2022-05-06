#ifndef __SINUS_H
#define __SINUS_H

#define CPU_Freq 168000000 
#define PWM_Freq 20000    
#define MOD_Freq 50       
#define MINUS 1    
#define PLUS 2  
#define precision (CPU_Freq/PWM_Freq/8)
#define STEP (PWM_Freq/MOD_Freq)
#define pi  3.1415926535

void sinus_init(void);
void sinus_calculation(void);
void sinus_array(void);
void sinus_recalculation_minus_array(void);
void sinus_recalculation_plus_array(void);
void freq_signal_calculation(void);
#endif /* SINUS */