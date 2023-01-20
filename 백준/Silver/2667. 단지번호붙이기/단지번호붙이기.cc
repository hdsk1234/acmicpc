#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<char> > v2;
vector<int> Size;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void input(){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        vector<char> v1(N);
        for (int j = 0; j < N; ++j) {
            cin >> v1[j];
        } // for j
        v2.push_back(v1);
    } // for i
} // input()

void bfs(int _y, int _x){
    int _size = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(_y, _x));
    v2[_y][_x] = '0';

    while(!q.empty()){
        for (int i = 0; i < 4; ++i) {
            int y = q.front().first + dir[i][0];
            int x = q.front().second + dir[i][1];

            if(0 <= x && x <= N-1 && 0 <= y && y <= N-1 && v2[y][x] == '1'){
                q.push(make_pair(y, x));
                _size++;
                v2[y][x] = '0';
            } // if
        } // for i
        q.pop();
    } // while
    Size.push_back(_size);
} // bfs()


void solve(){
    input();
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(v2[i][j] == '1'){
                bfs(i, j);
                ans++;
            }
        } // for j
    } // for i
    cout << ans << '\n';
    sort(Size.begin(), Size.end());
    for (int i = 0; i < Size.size(); ++i) {
        cout << Size[i] << '\n';
    }
} // solve()



int main(){
    solve();
    return 0;
}