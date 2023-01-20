#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<char> > v2;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void input(){
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        vector<char> v1(M);
        for (int j = 0; j < M; ++j) {
            cin >> v1[j];
        } // for j
        v2.push_back(v1);
    } // for i
} // input()

void bfs(){
    int ans = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    int y;
    int x;
    while(!q.empty() && v2[N-1][M-1] == '1'){
        int size = q.size();
        for (int h = 0; h < size; ++h) {
            for (int i = 0; i < 4; ++i) {
                y = q.front().first + dir[i][0];
                x = q.front().second + dir[i][1];

                if(0 <= y && y <= N-1 && 0 <= x && x <= M-1 && v2[y][x] == '1'){
                    v2[y][x] = char(v2[q.front().first][q.front().second] + 1);
                    q.push(make_pair(y, x));
                } // if
            } // for i
            q.pop();
        } // for h
        ans++;
    } // while
    cout << ans;
} // bfs()

void solve(){
    input();
    bfs();
} // solve()


int main(){
    solve();
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < M; ++j) {
//            cout << v2[i][j] - '0' << " ";
//        }
//        cout << endl;
//    }
    return 0;
}