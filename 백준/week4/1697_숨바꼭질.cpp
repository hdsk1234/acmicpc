#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_NUM 100000

int N, K;
vector<int> v(MAX_NUM + 1);

void input(){
    cin >> N >> K;
    for (int i = 0; i <= MAX_NUM; ++i) {
        v[i] = i;
    } // for i
}

void bfs(){
    int ans = 1;
    queue<int> q;
    q.push(N);

    while(1){
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            if(q.front() + 1 <= MAX_NUM && v[q.front() + 1]) {
                if(q.front() + 1 == K){
                    cout << ans;
                    return;
                }
                q.push(q.front() + 1);
                v[q.front() + 1] = 0;
            } // for i

            if(0 <= q.front() - 1 && v[q.front() - 1]) {
                if(q.front() - 1 == K){
                    cout << ans;
                    return;
                }
                q.push(q.front() - 1);
                v[q.front() - 1] = 0;
            } // for i

            if(q.front() * 2 <= MAX_NUM && v[q.front() * 2]) {
                if(q.front() * 2 == K){
                    cout << ans;
                    return;
                }
                q.push(q.front() * 2);
                v[q.front() * 2] = 0;
            } // for i

            q.pop();
        } // for i
        ans++;
    } // while

} // bfs

void solve(){
    input();
    if(N >= K){
        cout << N - K;
        return;
    }
    bfs();
}


int main(){
    solve();
    return 0;
}

// 시간복잡도: O(N)
// 어려웠던 점: N >= K 인 경우 예외 처리, 큐 메모리 초과 방지를 위한 벡터 선언