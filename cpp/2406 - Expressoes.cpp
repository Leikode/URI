#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> pilha;
    string a;
    int n;
    bool ok = true;

    cin >> n;

    for (int j = 0; j < n; j++) {
        cin >> a;

        ok = true;
        pilha = stack<char>();

        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] == '(' || a[i] == '[' || a[i] == '{') {
                pilha.push(a[i]);
            } else {
                if (!pilha.empty()) {
                    if ((a[i] == ')' && pilha.top() == '(') || (a[i] == ']' && pilha.top() == '[') || (a[i] == '}' && pilha.top() == '{')) {
                        pilha.pop();
                    } else {
                        ok = false;
                        break;
                    }
                } else {
                    ok = false;
                    break;
                }
            }
        }

        if (ok && pilha.empty()) {
            cout << 'S' << endl;
        } else {
            cout << 'N' << endl;
        }
    }
}