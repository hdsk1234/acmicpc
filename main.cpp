#include<stdio.h>

int main(){
    int num, sum = 0, min = -1;
    scanf("%d", &num);

    for(int i = 0; i <= num; i += 3){
        if((num - i) % 5 == 0){
            sum = i/3 + (num - i)/5;
            if(min < 0 || min > sum){
                min = sum;
            }
        }
    } // for i

    printf("%d", min);
    return 0;
}