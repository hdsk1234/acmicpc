#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NUM 1000


int N;
int arr[MAX_NUM];
int dp[MAX_NUM];

void input(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    } // for i
} // input()


void solution(){
    for (int i = 0; i < N; i++)
    {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && dp[j] + arr[i] > dp[i]){
                dp[i] = dp[j] + arr[i];
            }
        } // for j
        //cout << dp[i] << " ";
    } // for i
    cout << *max_element(dp, dp + N);
} // solution()


void solve(){
    input();
    solution();
} // solve()

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}