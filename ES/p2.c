#include <p89v51rx2.h>
void incr(int arr[]) {
	int i;
	for(i = 0 ; i < 4; i++) {
		if(arr[i] == 0) {
			arr[i] = 1;
			return;
		}
		else {
			arr[i] = 0;
		}
	}
}
 
void delay(unsigned int dela){
	unsigned int i,j;
	for(i=0;i<=1000;i++){
		for(j=0;j<=dela;j++);
	}
}
 
void main() {
		int arr[4] = {0, 0, 0, 0};
		while(1) {
			delay(100);
			RxD = arr[3];
			TxD = arr[2];
			WR = arr[1];
			RD = arr[0];
			incr(arr);
		}
}
 
