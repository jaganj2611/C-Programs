#include <stdio.h>

int power(int a, int b) {
    if(b==0)
    return 1;
	
    return(a*power(a,b-1));
}

int LCM(int a,int b) {
    static int temp = 1;
    if(temp%a == 0 && temp%b == 0){
    	return temp;
	}
	else{
		temp++;
		LCM(a,b);
		return temp;
	}
}

typedef int (*fun)(int, int);                 
fun function[2] = {&power,&LCM};      
                                            
int main() {
    int a,b;
    a = function[0](5,4);
    printf("Power:%d",a);
    b = function[1](6,9);
    printf("\nLCM: %d",b);
    return 0;
}
