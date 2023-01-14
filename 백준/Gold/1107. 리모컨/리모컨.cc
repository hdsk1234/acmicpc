/*
 * 첫번째 난관: 이걸 어케함 => 브루트포스로 해결 (진짜 다 해보기;;)
 * 두번째 난관: 시간 초과 => 무한 루프 도는 거였음. 조건 추가로 해결
 * 세번째 난관: 5퍼에서 자꾸 틀림 => num2가 음수가 돼도 num1을 찾는 조건 추가로 해결.
 * 네번째 난관: 그래도 5퍼에서 틀림 => length 변수를 잘못 설정함. 코딩하다가 다음 날 다시하면 이게 문제다. 변수가 기억이 안 나.
 * 네번째 난관: 29퍼에서 자꾸 틀림 => 뭔데 ㅅㅂ 이제 ㅁ로라 => 커지는 것부터 검사하니까 만약 위로 갔을 때랑 아래로 갔을 때랑 답이 동시에 나오면 오류 발생..!! 반례: 1555, 3, 0 1 9
 *
 * */

// 시간복잡도: O(n)
// 공간복잡도: O(1)
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> num(10);
    int t;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        num[t] = 1;
    }

    int num1 = n;
    int num2 = n;

    int i, j;

    // 답이 될 수 있는 경우의 수는 세 가지이다.

    // 1번경우 바로 채널 눌러서 가기
    // 2번경우 +-만 눌러서 가기
    // 3번경우 적당한 채널로 간 뒤 +- 눌러서 가기

    // 다음은 이 세 가지 중 가장 적합한 것을 고르는 과정이다.

    while(num2 >= -500000){ // 점점 작아지는 수가 0보다도 작아지면 더 따질 필요 없이 +- 만 사용해서 채널까지 가야한다... 라고 생각했는데 아니다. num2를 0까지만 따져본다는 건 num1을 n*2 까지만 따져보겠다는 것과 같다. 이렇게 하면 3번 경우인데도 while문을 빠져 나가는 경우가 발생한다.
        // 위와 같은 방식으로 1씩 작아진다.
        for (j = 0; j < to_string(num2).length(); ++j) {
            if(num[to_string(num2)[j] - '0']) break;
        } // for j
        if(j == to_string(num2).length() && num2 >= 0){ // while 문은 num2가 음수여도 돌지만 이 if문은 num2가 음수일 때 돌면 안 된다.
            int ans = min(abs(n - 100), int(to_string(num2).length() + abs(n - num2)));
            int k2;
            for (k2 = 0; k2 < to_string(n).length(); ++k2) {
                if(num[to_string(n)[k2] - '0']) break;
            }
            if(k2 == to_string(n).length()){
                ans = min(int(to_string(n).length()), ans);
            }
            cout << ans;
            return 0;
        }
        num2--;

        for (i = 0; i < to_string(num1).length(); ++i) {
            if(num[to_string(num1)[i] - '0']) break;
        } // for i
        if(i == to_string(num1).length()){ // == break 안 걸렸다면 == 리모컨에서 누를 수 있는 숫자라면
            int ans = min(abs(n - 100), int(to_string(num1).length() + abs(n - num1))); // 2와 3중 최솟값이 정답일 가능성이 있다.
            int k1;
            for (k1 = 0; k1 < to_string(n).length(); ++k1) { // 1이 가능하다면 => 1과 (2와 3중 최솟값) 중 최솟값이 정답이다.
                if(num[to_string(n)[k1] - '0']) break;
            }
            if(k1 == to_string(n).length()){
                ans = min(int(to_string(n).length()), ans);
            }
            cout << ans;
            return 0;
        }
        num1++;


    } // while

    // while문을 빠져나왔으면 3번 경우가 불가능하다는 뜻이다. 따라서 1,2번 경우만 따진다.

    int ans = abs(n - 100);
    int k3;
    for (k3 = 0; k3 < to_string(n).length(); ++k3) {
        if(num[to_string(n)[k3] - '0']) break;
    }
    if(k3 == to_string(n).length()){
        ans = min(int(to_string(n).length()), ans);
    }
    cout << ans;
    return 0;
}

