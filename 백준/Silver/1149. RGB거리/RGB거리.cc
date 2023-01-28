#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int> > dp;
    vector<int> t(3);
    cin >> t[0];
    cin >> t[1];
    cin >> t[2];
    dp.push_back(t);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> t[j];
            dp[i-1][(j+1)%3] > dp[i-1][(j+2)%3] ? t[j] += dp[i-1][(j+2)%3] : t[j] += dp[i-1][(j+1)%3];
        }
        dp.push_back(t);
    }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }


    cout << *min_element(dp[n-1].begin(), dp[n-1].end());


    return 0;
}