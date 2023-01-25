#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_NUM 60


int n;
int arr[3];
int visited[MAX_NUM + 1][MAX_NUM + 1][MAX_NUM + 1];

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


void bfs1(){
    cout << (arr[0] - 1) / 9 + 1;
    return;
} // bfs1()


void bfs2(){
    queue<pair<int, int> > q;
    q.push(make_pair(arr[0], arr[1]));
    int ans = 1;

    while(1){
        int a, b;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            a = q.front().first - 9;
            b = q.front().second - 3;
            sort_two(a, b);
            if(a <= 0 && b <= 0){
                cout << ans;
                return;
            } else{
                q.push(make_pair(a, b));
            }


            a = q.front().first - 3;
            b = q.front().second - 9;
            sort_two(a, b);
            if(a <= 0 && b <= 0){
                cout << ans;
                return;
            } else{
                q.push(make_pair(a, b));
            }

            q.pop();
        } // for i

        ans++;
    } // while
} // bfs2()


void bfs3(){
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(arr[0], make_pair(arr[1], arr[2])));
    int ans = 1;

    while(1){
        int a, b, c;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            a = q.front().first - 9;
            b = q.front().second.first - 3;
            c = q.front().second.second - 1;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                //cout << a << " " << b << " " << c << endl;
            }

        

            a = q.front().first - 9;
            b = q.front().second.first - 1;
            c = q.front().second.second - 3;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                //cout << a << " " << b << " " << c << endl;
            }


            a = q.front().first - 3;
            b = q.front().second.first - 9;
            c = q.front().second.second - 1;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                //cout << a << " " << b << " " << c << endl;
            }


            a = q.front().first - 3;
            b = q.front().second.first - 1;
            c = q.front().second.second - 9;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                //cout << a << " " << b << " " << c << endl;
            }


            a = q.front().first - 1;
            b = q.front().second.first - 9;
            c = q.front().second.second - 3;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){
                q.push(make_pair(a, make_pair(b, c)));
                visited[a][b][c] = 1;
                //cout << a << " " << b << " " << c << endl;
            }


            a = q.front().first - 1;
            b = q.front().second.first - 3;
            c = q.front().second.second - 9;
            sort_three(a, b, c);
            if(a <= 0 && b <= 0 && c <= 0){
                cout << ans;
                return;
            } else if(visited[a][b][c] == 0){
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
    input();

    if(n == 1){
        bfs1();
    }
    if(n == 2){
        bfs2();
    }
    if(n == 3){
        bfs3();
    }

} // solve()

int main(){    
    solve();
    return 0;
}