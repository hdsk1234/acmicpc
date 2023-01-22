#include <iostream>
using namespace std;
#define MAX_NUM 10000

int stairs[MAX_NUM + 1];
int dp[MAX_NUM + 1];
int n;

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stairs[i];
    } // for i
    
} // input()

void cal(){
    int ans = -1;
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = stairs[3] + max(stairs[1], stairs[2]);
    // cout << dp[1] << endl;
    // cout << dp[2] << endl;
    // cout << dp[3] << endl;
    ans = max(max(dp[1], dp[2]), dp[3]);
    for (int i = 4; i <= n; i++)
    {
        dp[i] = stairs[i] + max(dp[i-2], stairs[i-1] + dp[i-3]);
        if(ans < dp[i]) ans = dp[i];
        //cout << dp[i] << endl;
    }
    cout << dp[n];
} // cal()

void solve(){
    input();
    cal();
} // solve()

int main(){
    solve();
    return 0;
}