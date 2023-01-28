#include <iostream>
using namespace std;
#define MAX_NUM 1000


int N;
int arr[MAX_NUM][3];
int dp[MAX_NUM][3];

void input(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
        cin >> arr[i][2];
    } // for i
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
} // input()

void solution(){
    // cout << dp[0][0] << " " << dp[0][1] << " " << dp[0][2] << endl;
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
        //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    } // for i
    cout << min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
} // solution()

void solve(){
    input();
    solution();
}

int main(){
    solve();
}