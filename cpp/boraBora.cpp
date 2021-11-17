#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Jogador {
    int id;
    int numCartas;
    vector<int> cartas;
};

void comprarCarta(Jogador jogadores [ ], int vez, vector<int> *saque) {
    jogadores[vez].cartas.push_back(saque->front());
    saque->erase(saque->begin());
    jogadores[vez].numCartas++;
    sort(jogadores[vez].cartas.begin(), jogadores[vez].cartas.begin() + jogadores[vez].numCartas, greater<int>());
}

bool descartarCarta(int num, int naipe, Jogador jogadores [ ], int vez, bool *descarteNovo, int *descarte, bool *horario) {
    bool descartado = false;

    for (unsigned int i = 0; i < jogadores[vez].cartas.size(); i++) {
        if ((jogadores[vez].cartas[i] / 10) == num || (jogadores[vez].cartas[i] % 10) == naipe) {
            *descarteNovo = true;
            *descarte = jogadores[vez].cartas[i];
            jogadores[vez].cartas.erase(jogadores[vez].cartas.begin() + i);
            jogadores[vez].numCartas--;

            descartado = true;

            break;
        }
    }

    if ((*descarte / 10) == 12 && *descarteNovo) {
        if (*horario) *horario = false;
        else *horario = true;
    }

    return descartado;
}

int main() {
    int p, m, n, x, vez = 0, descarte;
    bool horario, descarteNovo, passaVez, primeiraVez;
    vector<int> saque;
    char s;

    while (cin >> p >> m >> n) { // p = 2, m = 2, n = 10
        if (p == 0 && m == 0 && n == 0) {
            break;
        }

        Jogador jogadores[11];

        vez = 0; saque.clear(); horario = true; descarteNovo = true; passaVez = false, primeiraVez = true;

        for (int i = 0; i < p; i++) { // limpa os jogadores
            jogadores[i].id = i + 1;
            jogadores[i].numCartas = 0;
            jogadores[i].cartas.clear();
        }

        for (int i = 0; i < n; i++) {
            cin >> x >> s;

            x *= 10;

            switch (s) {
            case 'C':
                x += 1;
                break;
            case 'D':
                x += 2;
                break;
            case 'H':
                x += 3;
                break;
            case 'S':
                x += 4;
                break;
            }

            if (jogadores[vez].numCartas < m) { // montando as mãos
                jogadores[vez].cartas.push_back(x);
                jogadores[vez].numCartas++;

                if (jogadores[vez].numCartas == m) {
                    vez++;
                    vez = vez % p;
                }
            }

            if (i == p * m) {
                descarte = x; // primeira carta da pilha de descarte
            }

            if (i > (p * m)) {
                saque.push_back(x); // montando as cartas de saque
            }
        }

        for (int i = 0; i < p; i++) {
            sort(jogadores[i].cartas.begin(), jogadores[i].cartas.begin() + jogadores[i].numCartas, greater<int>());
        }

        vez = 0;

        while (true) {
            int num, naipe;
            num = descarte / 10;
            naipe = descarte % 10;

            if (descarteNovo) {
                descarteNovo = false;
                switch (num) {
                case 7:
                    passaVez = true;
                    comprarCarta(jogadores, vez, &saque);
                    comprarCarta(jogadores, vez, &saque);
                    break;
                case 1:
                    passaVez = true;
                    comprarCarta(jogadores, vez, &saque);
                    break;
                case 11:
                    passaVez = true;
                    break;
                }
            }

            if (!passaVez) {
                bool descartado;
                descartado = descartarCarta(num, naipe, jogadores, vez, &descarteNovo, &descarte, &horario);

                if (!descartado) {
                    comprarCarta(jogadores, vez, &saque);
                    descartarCarta(num, naipe, jogadores, vez, &descarteNovo, &descarte, &horario);
                }

                if (jogadores[vez].numCartas == 0) {
                    cout << jogadores[vez].id << endl;
                    break;
                }
            }

            if ((num == 12) && primeiraVez) {
                if (horario) horario = false;
                else horario = true;
            }

            if (horario) {
                vez++;
                vez = vez % p;
            } else {
                vez--;
                if (vez == -1) vez = p - 1;
            }
            passaVez = false;
            primeiraVez = false;
        }
    }
}