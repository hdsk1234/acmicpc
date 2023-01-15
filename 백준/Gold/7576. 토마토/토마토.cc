#include <iostream>
#include <queue>
using namespace std;
#define MAX_NUM 1000

int tomato[MAX_NUM+1][MAX_NUM+1]; // 전부 0으로 초기화
int one_num = 0;
int minus_num = 0;

int bfs(queue<pair<int, int> >&_queue, int _m, int _n){
    int size;
    int ans = -1;
    while(!_queue.empty()){
        size = _queue.size();
        for (int i = 0; i < size; ++i) {
            int x = _queue.front().first;
            int y = _queue.front().second;
            if(y-1 >= 1 && tomato[x][y-1] == 0){ // 상
                tomato[x][y-1] = 1;
                _queue.push(make_pair(x, y-1));
                one_num++;
            }
            if(y+1 <= _m && tomato[x][y+1] == 0){ // 하
                tomato[x][y+1] = 1;
                _queue.push(make_pair(x, y+1));
                one_num++;
            }
            if(x-1 >= 1 && tomato[x-1][y] == 0){ // 좌
                tomato[x-1][y] = 1;
                _queue.push(make_pair(x-1, y));
                one_num++;
            }
            if(x+1 <= _n && tomato[x+1][y] == 0){ // 우
                tomato[x+1][y] = 1;
                _queue.push(make_pair(x+1, y));
                one_num++;
            }
            _queue.pop();
        } // for i

        ans++;
    } // while

    if(one_num + minus_num == _m*_n){ // tomato에 1과 -1밖에 안 남아있다면 == 안 익은 토마토가 없다면
        return ans;
    }else{
        return -1;
    }


} // bfs

int main(){
    queue<pair<int, int> > queue; // 1인 인덱스 저장할 map
    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> tomato[i][j];

            if(tomato[i][j] == 1){
                queue.push(make_pair(i, j));
                one_num++;
            } else if(tomato[i][j] == -1){
                minus_num++;
            }
        } // for j
    } // for i
    // 여기까지는 입력

    cout << bfs(queue, m, n);
    return 0;
}


// 시간복잡도:
