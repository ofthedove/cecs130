//Name:Conversion table
//Author: John Stromberg
//date: 9-5-2013
//section:130-02
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
float inputamount , result ;
printf("please enter currency amount between .01 and 999  ");
scanf("%f", &inputamount);
printf("find the currency you entered in the top row and then match it to the currency\n you desire on the right\n");
printf("           USD     GBP     AUD         JPY       CAD        EUR                    ");
printf("USD   %.2f     %.2f    %.2f      %.2f    %.2f     %.2f\n", inputamount, inputamount*1.5593, inputamount*.9133, inputamount*.01, inputamount*.9519, inputamount*1.312 ) ;
printf("   GBP   %.2f    %.2f    %.2f     %.2f     %.2f     %.2f\n", inputamount*0.6415, inputamount, inputamount*0.5855, inputamount*0.0064 , inputamount*0.6108, inputamount*0.8416 ) ;
printf("   AUD   %.2f    %.2f    %.2f     %.2f     %.2f     %.2f\n", inputamount*1.0963, inputamount*1.7084 , inputamount, inputamount*0.0109, inputamount*1.0437, inputamount*1.4379 ) ;
printf("   JPY   %.2f  %.2f  %.2f   %.2f   %.2f   %.2f\n", inputamount*100.1400, inputamount*156.0220, inputamount*91.3230, inputamount*1, inputamount*95.3040, inputamount*131.3300 ) ;
printf("   CAD   %.2f    %.2f    %.2f     %.2f     %.2f     %.2f\n", inputamount*1.0505, inputamount*1.6372, inputamount*0.9583, inputamount*0.0105, inputamount, inputamount*1.3777 ) ;
printf("   EUR   %.2f    %.2f    %.2f     %.2f     %.2f     %.2f\n", inputamount*.7623, inputamount*1.1884, inputamount*0.6956, inputamount*.0076, inputamount*0.7258, inputamount ) ;
//enter the amount of any currency in the box and then it will show a grid. the top is the input currency and the right is the outpu currency
//conversion rates taken from the bloomberg exchange table as of 9-5-13.
}
