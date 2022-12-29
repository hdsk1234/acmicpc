#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> stack;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string t;
        getline(cin, t);

        if(t == "pop"){
            if(stack.size() == 0) cout << -1 << '\n';
            else{
                cout << stack.top() << '\n';
                stack.pop();
            }
        } else if(t == "size"){
            cout << stack.size() << '\n';
        } else if(t == "empty"){
            cout << stack.empty() << '\n';
        } else if(t == "top"){
            if(stack.size() == 0) cout << -1 << '\n';
            else cout << stack.top() << '\n';
        } else{
            t = t.substr(5, t.size()-1);
            int temp = 0;
            int digit = pow(10, t.size()-1);
            for(int j = 0; j < t.size(); j++){
                temp += int(t[j] - 48) * digit;
                digit /= 10;
            }
            stack.push(temp);
        }
    } // for i
    return 0;
}