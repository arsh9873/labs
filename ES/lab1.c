/*program to blink an LED. */
#include <p89v51rd2.h>
void delay(unsigned int dela)
{
	unsigned int i,j;
	for(i=0;i<=1000;i++)
		for(j=0;j<=dela;j++);
}

void main(void)
{
	while(1){
		RxD = 0;
		delay(20);
		RxD = 1;
		delay(20);
	}
}