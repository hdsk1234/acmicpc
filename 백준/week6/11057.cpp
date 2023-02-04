#include <iostream>
using namespace std;
#define MAX_NUM 1000

/*
    시간복잡도: O(N)
    삼중 반복문인데 O(N^3)이 아닌게 신기하군

    아이디어: 0뒤엔 0만, 1뒤엔 0과 1, 2뒤엔 0과 1과 2 .... 
    이렇게 n 뒤에는 n보다 작거나 같은 수만 올 수 있다는 점을 이용해서 이차원 배열로 dp하면 easy함.

    어려웠던 점: 삼중반복문을 쓰고 싶지 않아서 이차원 배열 두 개 만들면서 객기 부렸는데 쓰니까 쉬웠다.
    마지막에 dp[i][0]부터 dp[i][9]까지 더해서 ans를 구할 때도 10007로 나눠야 하는 거 잊지말자.
*/
 
int N;
int dp[MAX_NUM + 1][10];

void input(){
    cin >> N;
} // input()

void solution(){
    for (int i = 0; i <= 9; i++)
    {
        dp[1][i] = 1;
    } // for i

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for(int h = 0; h <= j; h++){
                dp[i][j] += dp[i-1][h]; // i자리수 중 맨 뒷자리수가 j인 수 저장하기: i-1자리수 중 맨 뒷자리수가 j보다 작거나 같은 수들의 개수를 더한다.
                dp[i][j] %= 10007;
            } // for h
            // cout << dp[i][j] << " ";
        } // for j
        // cout << endl;
    } // for i
    
    int ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += dp[N][i];
        ans %= 10007;
    } // for i
    cout << ans;
    
} // solution()


void solve(){
    input();
    solution();
} // solve()

int main(){
    solve();
    return 0;
} // main()