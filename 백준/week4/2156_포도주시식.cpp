#include <iostream>
using namespace std;
#define MAX_NUM 10000

int n;
int wine[MAX_NUM + 1];
int dp[MAX_NUM + 1];


void input(){
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> wine[i];
    } // for i
    
} // input()

void solve(){
    int ans = -1;

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    dp[3] = wine[3] + max(wine[1], wine[2]);

    if(wine[3] == 0){
        dp[3] = dp[2];
    }
    if(dp[2] > dp[3]){
        dp[3] = dp[2];
    }

    // cout << dp[1] << endl;
    // cout << dp[2] << endl;
    // cout << dp[3] << endl;

    for (int i = 1; i <= 3; i++)
    {
        if(dp[i] > ans) ans = dp[i];
    }
    
    for (int i = 4; i <= n; i++)
    {
        dp[i] = wine[i] + max(wine[i - 1] + dp[i - 3], dp[i - 2]);
        dp[i] = max(dp[i], dp[i-1]);
        if(wine[i] == 0){
            dp[i] = dp[i-1];
        }
        if(dp[i] > ans) ans = dp[i];
       //cout << dp[i] << endl;
    } // for i
    cout << ans;
} // solve()


int main(){
    input();
    solve();
    return 0;
}