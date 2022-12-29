/*
시간복잡도: O(n)
공간복잡도: O(1)

어려웠던 점: dp는 그냥 생소해서 어려웠다
*/

#include<stdio.h>

int main(){
	int num, sum = 0, min = -1;
	scanf("%d", &num);
	
	// 3의 개수가 늘어나면서 되는 5의 개수를 각각 세서 최솟값 구한다. 근데 이게 dp냐..?
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
