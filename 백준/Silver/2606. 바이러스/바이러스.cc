#include <iostream>
#include <queue>
using namespace std;
#define MAX_NUM 100

int arr[MAX_NUM + 1][MAX_NUM + 1];
int visited[MAX_NUM + 1];

int bfs(int _comp_num){
    int ans = 0;
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int size = q.size();
        for (int h = 0; h < size; ++h) {
            for (int i = 1; i <= _comp_num; ++i) {
                if(!visited[i] && arr[q.front()][i]){
                    q.push(i);
                    visited[i] = 1;
                    ans++;
                }
            } // for i
            q.pop();
        } // for h
    } // while

    return ans;
}


int main(){
    int comp_num;
    cin >> comp_num;
    int pair;
    cin >> pair;


    int a, b;
    for (int i = 0; i < pair; ++i) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    cout << bfs(comp_num);
    return 0;
}