#include <stdio.h>

int main(void){
	
	int N, i, temp;
	int prime = 0;
	scanf("%d", &N); //숫자 개수
	int num[N];
	
	
	//숫자 입력
	for(i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}	
	
	//그냥 무식하게
	//나누어떨어질 때까지 2로 나눈다
	//안 나눠떨어지면 3으로 반복
	//4로반복
	//5로반복
	//....
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
