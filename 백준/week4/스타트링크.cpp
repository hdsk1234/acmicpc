#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
#define MAX_NUM 1000000

/*
 * 아이디어: 다 따져본다. 위치에서 올라가거나 내려갈 수 있는 위치를 전부 큐에 저장해서 목적지에 도달할 때까지
 *
 * 어려웠던 점: use the stairs 를 출력할 조건이 헷갈렸다.(다변수 일차함수?)
 */

int f, s, g, u, d;
vector<int> v(MAX_NUM + 1);

void input(){
    cin >> f >> s >> g >> u >> d;
    for (int i = 0; i <= MAX_NUM; ++i) {
        v[i] = i;
    }
} // input

void bfs(int _s){
    if(g == s) {
        cout << 0;
        return;
    }
    int ans = 0;
    queue<int> q;
    q.push(_s);
    while(!q.empty()){
        ans++;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            if(q.front() + u <= f && v[q.front() + u]){
                if(q.front() + u == g){
                    cout << ans;
                    return;
                }
                q.push(q.front() + u);
                v[q.front() + u] = 0;
            }

            if(1 <= q.front() - d && v[q.front() - d]){
                if(q.front() - d == g){
                    cout << ans;
                    return;
                }
                q.push(q.front() - d);
                v[q.front() - d] = 0;
            }
            q.pop();
        } // for i
    } // while
    cout << "use the stairs";
}

void solve(){
    input();
    bfs(s);
}
int main(){
    solve();
    return 0;
}

