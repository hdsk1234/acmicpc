#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<char> v(m); // int로 받으면 한자리 숫자로 받지 않고 한 줄을 하나의 숫자로 받아서 char로 받았음. 아스키코드가 들어가겠지만 문제풀이에 지장 없으므로 무시.
    vector<vector<char> > v2; // 2차원 벡터

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[j];
        }
        v2.push_back(v);
    }

    // 여기까지는 그냥 입력

    int max = n > m ? n : m; // n, m 중 큰 거
    int min = n > m ? m : n; // n, m 중 작은 거

    int t = min - 1; // (정사각형 길이) - 1 후보, 1씩 작아질 거임

    while(t + 1 > 1){ // 정사각형 길이가 1보다 클 때만 조사.
        for (int i = 0; i + t < n; ++i) { // i+t의 범위는 n 미만이다.
            for (int j = 0; j + t < m; ++j) {// j+t의 범위는 m 미만이다.
                if(v2[i][j] == v2[i][j+t] && v2[i][j] == v2[i+t][j] && v2[i][j] == v2[i+t][j+t]){
                    cout << (t+1) * (t+1); // t == (정사각형 길이) - 1이다. 왜냐하면 왼쪽 위 꼭짓점에서 t만큼 인덱스를 키우면 나머지 꼭짓점이라는 뜻이니까.
                    return 0;
                }
            }
        }
        t--; // 변의 길이가 t인 정사각형이 존재하지 않으므로 t보다 1 작은 수에 대하여 같은 로직을 반복한다.
    }

    cout << 1*1; // while문을 전부 돌았다면 답은 1이다 .
    return 0;
}