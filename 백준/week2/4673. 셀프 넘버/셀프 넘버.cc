#include <stdio.h>

 

int main() {

    int temp, a[10000], i, j;

    
    for(i = 1; i <= 10000; i++){
        a[i] = i;
    }
	
        for(j = 1; j <= 10000; j++){

            int temp1, temp2, temp3, temp4, temp5;

            temp = j;

            while(temp <= 10000){
            	
                temp1 = temp % 10;
                temp2 = (temp % 100 - temp % 10) / 10;
                temp3 = (temp % 1000 - temp % 100) / 100;
                temp4 = (temp % 10000 - temp % 1000) / 1000;
                temp5 = (temp % 100000 - temp % 10000) / 10000;

                temp = temp + temp1 + temp2 + temp3 + temp4 + temp5;

				if(temp < 10000){
				    a[temp] = 0;	
				}
            } // while
        } // for j



    for(i = 0; i < 10000; i++){

        if(a[i] != 0){

            printf("%d\n", a[i]);

        }

    }

    

    return 0;

}