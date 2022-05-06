#include "sinus.h"
#include <math.h>



unsigned int sinn[STEP];
unsigned int sinn_120[STEP];
unsigned int sinn_240[STEP];
unsigned int sin_ar[STEP];
unsigned int sin_ar_120[STEP];
unsigned int sin_ar_240[STEP];
unsigned char counter=1; 
unsigned char amplitud=1; 
unsigned int freg_signal=MOD_Freq;
unsigned int steps=STEP;
unsigned char flag_counter=0; 
unsigned char flag_freq=0;

void sinus_init(void)
{
  if(counter<amplitud)
     flag_counter=PLUS;
  else if(counter>amplitud)
     flag_counter=MINUS;
  sinus_calculation();
  sinus_array();
  
}

void sinus_calculation(void)
{
  freq_signal_calculation();
  for(int i = 0; i<steps; i++)
  {
    sinn[i] = (unsigned int)(fabs(sin(2* i * pi / steps)+1)*100 );
    sinn_120[i] = (unsigned int)(fabs(sin(2* i * pi / steps+2*pi/3)+1)*100 );
    sinn_240[i] = (unsigned int)(fabs(sin(2* i * pi / steps+4*pi/3)+1)*100 );
  }
}


void sinus_array(void)
{
   for(int i = 0; i<steps; i++)
   {
     sin_ar[i] = (unsigned int)(sinn[i]*precision*counter/(200*100));
     sin_ar_120[i] = (unsigned int)(sinn_120[i]*precision*counter/(200*100));
     sin_ar_240[i] = (unsigned int)(sinn_240[i]*precision*counter/(200*100));
   }
}

void sinus_recalculation_minus_array(void)
{
  if(counter>amplitud)
  {
    counter--;
    sinus_array();
  }
}

void sinus_recalculation_plus_array(void)
{
  if(counter<amplitud)
  {
    counter++;
    sinus_array();
  }
}


void freq_signal_calculation(void)
{
    steps=PWM_Freq/freg_signal;
}
