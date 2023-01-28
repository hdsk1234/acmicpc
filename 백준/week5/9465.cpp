#include <iostream>
using namespace std;
#define MAX_NUM 100000

int n;
int score[2][MAX_NUM];
int dp[2][MAX_NUM];


void input(){
    cin >> n;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> score[i][j];
        } // for j
    } // for i
} // input()


void solution(){
    dp[0][0] = score[0][0];
    dp[1][0] = score[1][0];
    //cout << dp[0][0] << " " << dp[1][0] << endl;
    

    dp[0][1] = dp[1][0] + score[0][1];
    dp[1][1] = dp[0][0] + score[1][1];
    //cout << dp[0][1] << " " << dp[1][1] << endl;

    for (int i = 2; i < n; i++)
    {
        dp[0][i] = score[0][i] + max(max(dp[0][i-2], dp[1][i-2]), dp[1][i-1]);
        dp[1][i] = score[1][i] + max(max(dp[0][i-2], dp[1][i-2]), dp[0][i-1]);
        //cout << dp[0][i] << " " << dp[1][i] << endl;
    } // for i
    cout << max(dp[0][n-1], dp[1][n-1]) << endl;
} // solution()

void solve(){
    int test;
    cin >> test;
    
    for (int i = 0; i < test; i++)
    {
        input();
        solution();
    }
    
} // solve()


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}