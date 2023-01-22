#include <iostream>
#include <vector>
using namespace std;
#define MAX_NUM 500

int n;
vector<vector<int> > tri;
int dp[MAX_NUM][MAX_NUM];


void input(){
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> temp[j];
        } // for j
        tri.push_back(temp);
    }  // for i
} // input()

void solve(){
    input();

    dp[0][0] = tri[0][0];

    int ans = dp[0][0];
    
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i-1][0] + tri[i][0];
        if(ans < dp[i][0]) ans = dp[i][0];
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = tri[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            if(ans < dp[i][j]) ans = dp[i][j];
        } // for j
        dp[i][i] = dp[i-1][i-1] + tri[i][i];
        if(ans < dp[i][i]) ans = dp[i][i];
    } // for i
    cout << ans;
} // solve()

int main(){
    solve();
    return 0;
}