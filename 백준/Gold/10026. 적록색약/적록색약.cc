#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<char> >picture2;
vector<vector<char> >picture3;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우

void input(){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        vector<char> picture1(N);
        for (int j = 0; j < N; ++j) {
            cin >> picture1[j];
        } // for j
        picture2.push_back(picture1);
        picture3.push_back(picture1);
    } // for i
} // input()


void bfs_normal(char start_color, int start_y, int start_x){
    queue<pair<int, int> > q;
    q.push(make_pair(start_y, start_x));
    picture2[q.front().first][q.front().second] = 0;

    while(!q.empty()){
        int y, x;
        for (int i = 0; i < 4; ++i) {
            y = q.front().first + dir[i][0];
            x = q.front().second + dir[i][1];
            if(0 <= x && x <= N-1 && 0 <= y && y <= N-1 && picture2[y][x] == start_color){
                q.push(make_pair(y, x));
                picture2[y][x] = 0;
                //cout << y << " " << x << endl;
            } // if
        } // for i
        q.pop();
    } // while
} // bfs_normal()


void bfs_abnormal(char start_color, int start_y, int start_x){
    queue<pair<int, int> > q;
    q.push(make_pair(start_y, start_x));
    picture3[q.front().first][q.front().second] = 0;

    while(!q.empty()){
        int y, x;
        for (int i = 0; i < 4; ++i) {
            y = q.front().first + dir[i][0];
            x = q.front().second + dir[i][1];
            if(0 <= x && x <= N-1 && 0 <= y && y <= N-1 && picture3[y][x] == start_color){
                q.push(make_pair(y, x));
                picture3[y][x] = 0;
                //cout << y << " " << x << endl;
            } // if
        } // for i
        q.pop();
    } // while
} // bfs_abnormal()


void normal_solve(){
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(picture2[i][j] != 0){
                bfs_normal(picture2[i][j], i, j);
                ans++;
            } // if
        } // for j
    } // for i
    cout << ans << " ";
} // normal_solve()

void abnormal_solve(){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(picture3[i][j] == 'G'){
                picture3[i][j] = 'R';
            } // if
        } // for j
    } // for i

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(picture3[i][j]){
                bfs_abnormal(picture3[i][j], i, j);
                ans++;
            } // if
        } // for j
    } // for i
    cout << ans;
} // abnormal_solve()


void solve(){
    input();
    normal_solve();
    abnormal_solve();
}


int main(){
    solve();
    return 0;
}
