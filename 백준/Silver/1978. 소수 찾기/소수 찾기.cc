#include <stdio.h>

int main(void){
	
	int N, i, temp;
	int prime = 0;
	scanf("%d", &N);
	int num[N];
	
	
	for(i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}	
	
	for(i = 0; i < N; i++){
		temp = 2;
		while(temp < num[i]){
			if(num[i] % temp == 0){
				num[i] = 1;
				break;
			}
			temp++;
		}
		if(num[i] != 1){
				prime++;
			}
	}
	
	printf("%d", prime);
	
	return 0;
}