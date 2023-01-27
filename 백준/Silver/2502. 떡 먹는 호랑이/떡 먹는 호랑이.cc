#include <iostream>
using namespace std;
#define MAX_NUM 30

int D, K;
int dp[MAX_NUM + 1][2];

void input(){
    cin >> D >> K;
}

void solve(){
    input();
    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[2][0] = 0;
    dp[2][1] = 1;
    for (int i = 3; i <= D; ++i) {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    } // for i


    int index1 = 1;
    int index2 = 1;
    while(1){
        index2 = 1;
        while((dp[D][0] * index1) + (dp[D][1] * index2) <= K){
            if(K == (dp[D][0] * index1) + (dp[D][1] * index2)){
                cout << index1 << endl << index2;
                return;
           } // if
            index2++;
        } // while
        index1++;
    } // while
} // solve()

int main(){
    solve();
    return 0;
}