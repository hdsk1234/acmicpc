#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 100000


int N, K;
int W[MAX_NUM + 1];
int V[MAX_NUM + 1];
int ans[100 + 1][100000 + 1];
    
// 어려웠던 점: 거의 처음으로 벽을 느끼고 답을 보고 푼 문제인 것 같다....


void input(){
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i];
        cin >> V[i];
        // cout << "W[i]:" << W[i] << "V[i]:" << V[i] << endl;
    }
    
} // input()

void solution(){
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if(j < W[i]){
                ans[i][j] = ans[i-1][j];
            } else{
                ans[i][j] = max(ans[i-1][j], ans[i-1][j - W[i]] + V[i]);
                //cout << "W[i]: " << W[i] << " ";
            }
            //cout << ans[i][j] << " ";
        } // for j
        //cout << endl;
    } // for i
    cout << ans[N][K];
} // solution()

void solve(){
    input();
    solution();
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}