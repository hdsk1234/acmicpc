#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_NUM 60


int n; // SCV 개수
int arr[3]; // SCV 체력
int visited[MAX_NUM + 1][MAX_NUM + 1][MAX_NUM + 1]; // 방문체크

void debug(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                cout << visited[i][j][k] << " ";
            }
            cout << "   ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void sort_two(int& a, int& b){
    if(a < 0) a = 0;
    if(b < 0) b = 0;

    if(a < b){
        int t = a;
        a = b;
        b = t;
    }
} // sort_two()

void sort_three(int& a, int& b, int& c){
    if(a < 0) a = 0;
    if(b < 0) b = 0;
    if(c < 0) c = 0;

    int arr[3] = {a, b, c};
    sort(arr, arr+ 3);

    a = arr[0];
    b = arr[1];
    c = arr[2];
} // sort_three()


void input(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    } // for i
} // input()


void bfs1(){ // SCV 1개인 경우
    cout << (arr[0] - 1) / 9 + 1; // 1-9면 1번, 10-18이면 2번 ...
    return;
} // bfs1()


void bfs2(){ // SCV 2개인 경우
    queue<pair<int, int> > q;
    q.push(make_pair(arr[0], arr[1]));
    int ans = 1;

    while(1){
        int a, b;

        int size = q.size();
        for (int i = 0; i < size; i++) // 2개의 SCV에 9, 3만큼 체력을 깎는 경우의 수는 2!(=2)가지 이다. 모든 경우의 수를 다 따져본다. 2가지인 경우는 방문체크가 필요없다. (사실 하면 더 좋다. 근데 귀찮음.)
        {
            a = q.front().first - 9;
            b = q.front().second - 3;
            sort_two(a, b);
            if(a <= 0 && b <= 0){ // 모두 0보다 작거나 같다면 정답 출력
                cout << ans;
                return;
            } else{ // 양수가 하나라도 있다면 큐에 저장
                q.push(make_pair(a, b));
            }


            a = q.front().first - 3;
            b = q.front().second - 9;
            sort_two(a, b);
            if(a <= 0 && b <= 0){ // 모두 0보다 작거나 같다면 정답 출력
                cout << ans;
                return;
            } else{  // 양수가 하나라도 있다면 큐에 저장
                q.push(make_pair(a, b));
            }

            q.pop();
        } // for i

        ans++;
    } // while
} // bfs2()


void bfs3(){ // SCV 3개인 경우
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(arr[0], make_pair(arr[1], arr[2])));
    int ans = 1;

    while(1){
        int a, b, c;

        int size = q.size();
        for (int i = 0; i < size; i++) // 3개의 SCV에 9, 3, 1만큼 체력을 깎는 경우의 수는 3!(=6)가지 이다. 모든 경우의 수를 다 따져본다.
        {
            a = q.front().first - 9;
            b = q.front().second.first - 3;
            c = q.front().second.second - 1;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){ // 모두 0보다 작거나 같다면 정답 출력
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){ // 양수가 하나라도 있고 방문하지 않은 쌍이라면 큐에 저장
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                //cout << a << " " << b << " " << c << endl;
            }

        

            a = q.front().first - 9;
            b = q.front().second.first - 1;
            c = q.front().second.second - 3;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){ // 모두 0보다 작거나 같다면 정답 출력
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){ // 양수가 하나라도 있고 방문하지 않은 쌍이라면 큐에 저장
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                //cout << a << " " << b << " " << c << endl;
            }


            a = q.front().first - 3;
            b = q.front().second.first - 9;
            c = q.front().second.second - 1;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){ // 모두 0보다 작거나 같다면 정답 출력
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){ // 양수가 하나라도 있고 방문하지 않은 쌍이라면 큐에 저장
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                //cout << a << " " << b << " " << c << endl;
            }


            a = q.front().first - 3;
            b = q.front().second.first - 1;
            c = q.front().second.second - 9;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){ // 모두 0보다 작거나 같다면 정답 출력
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){ // 양수가 하나라도 있고 방문하지 않은 쌍이라면 큐에 저장
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                //cout << a << " " << b << " " << c << endl;
            }


            a = q.front().first - 1;
            b = q.front().second.first - 9;
            c = q.front().second.second - 3;
            sort_three(a, b, c); 
            if(a <= 0 && b <= 0 && c <= 0){ // 모두 0보다 작거나 같다면 정답 출력
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){ // 양수가 하나라도 있고 방문하지 않은 쌍이라면 큐에 저장
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                //cout << a << " " << b << " " << c << endl;
            }


            a = q.front().first - 1;
            b = q.front().second.first - 3;
            c = q.front().second.second - 9;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){ // 모두 0보다 작거나 같다면 정답 출력
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){ // 양수가 하나라도 있고 방문하지 않은 쌍이라면 큐에 저장
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                // cout << a << " " << b << " " << c << endl;
            }


            q.pop();
        } // for i
        ans++;
    } // while
} // bfs3()


void solve(){
    input(); // 입력

    if(n == 1){ // SCV 1개인 경우
        bfs1();
    }
    if(n == 2){ // SCV 2개인 경우
        bfs2();
    }
    if(n == 3){ // SCV 3개인 경우
        bfs3();
    }

} // solve()

int main(){    
    solve();
    return 0;
}

// 시간복잡도: O((3!)^n) = O(6^n)
/*
    어려웠던 점: 방문 체크를 3차원 배열로 한다는 생각이 생소했다.
    함수를 나눠서 푸니까 어려운 문제가 훨씬 쉬워진다. 함수가 왜 필요한지 절실하게 느끼게 되었다.
*/