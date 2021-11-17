#include <iostream>
#include <algorithm>
using namespace std;

int tamanho(char n [ ]) {
    int i;
    for (i = 0; i < 10; i++) {
        if (n[i] == '\0') { break; }
    }
    return i;
}

void resposta(char a [ ], char b [ ], int tam1, int tam2) {
    int prox = 0, res = 0;

    tam1--;

    for (int i = tam2 - 1; i >= 0; i--) {
        int soma = (a[tam1] - '0') + (b[i] - '0') + prox;
        if (soma > 9) {
            res++;
            prox = 1;
        } else {
            prox = 0;
        }
        tam1--;
    }

    if (tam1 >= 0 && prox == 1) {
        for (int i = tam1; i >= 0; i--) {
            int soma = (a[i] - '0') + prox;

            if (soma > 9) {
                res++;
                prox = 1;
            } else {
                break;
            }
        }
    }
    if (res == 0) {
        cout << "No carry operation." << endl;
    } else if (res > 1) {
        cout << res << " carry operations." << endl;
    } else {
        cout << res << " carry operation." << endl;
    }
}

int main() {
    char a[10], b[10];
    int soma, res;

    while (true) {
        cin >> a >> b;
        if (a[0] == '0' && b[0] == '0') {
            break;
        }

        res = 0;

        int tamA, tamB;

        tamA = tamanho(a);
        tamB = tamanho(b);

        if (tamA >= tamB) {
            resposta(a, b, tamA, tamB);
        } else {
            resposta(b, a, tamB, tamA);
        }

    }
}