#include<stdio.h>
#include<conio.h>
#include<math.h>

int copyarray[]={0};

int convertintoDecimal(int hex){
	int dec=0,r,count=0;
	if(hex>9){
	while(hex>0){
		r = hex%10;
		dec += r*pow(16,count);
		hex /= 10;
		count++;
	}
	    return dec-6;
    }
    else
        return hex;
}

int* descend(int *array,int n){	
	int x,i,j,temp;
	for(x=0;x<n;x++){
		copyarray[x]=convertintoDecimal(array[x]);
	}	
	printf("Before Sorting: %d %d %d %d %d %d ",copyarray[0],copyarray[1],copyarray[2],copyarray[3],copyarray[4],copyarray[5]);
	for (i = 0; i < n; ++i){
         for (j = i + 1; j < n; ++j){
                if (copyarray[i] < copyarray[j]) {
                    temp =  copyarray[i];
                    copyarray[i] = copyarray[j];
                    copyarray[j] = temp;
                }
           }
       }
	return copyarray;  	
}

int main()
{
	  int inputarray[] = {0xf,0xe,0xd,0xf,0x6,0xa};
	  int length = sizeof(inputarray) / sizeof(inputarray[0]);
	  //printf("\n Input Array Dec Val: %d %d ",inputarray[0],inputarray[1]);
    int *array = descend(inputarray,length);
    printf("\nArray Sorted in Descending Order: %d %d %d %d %d %d ",array[0],array[1],array[2],array[3],array[4],array[5]);
	return 0;
}
