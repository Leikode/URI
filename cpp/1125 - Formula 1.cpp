#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Piloto {
    int id;
    vector<int> posicoes;
    int pontos;
};

bool ordenarPorId(Piloto a, Piloto b) {
    return a.id < b.id;
}

void resetarPiloto(Piloto pilotos [ ], int p) {
    sort(pilotos, pilotos + p, ordenarPorId);
    for (int i = 0; i < p; i++) {
        pilotos[i].pontos = 0;
    }
}

void imprimirVencedor(Piloto pilotos [ ], int p) {
    int max = 0;

    for (int i = 0; i < p; i++) {
        if (pilotos[i].pontos >= max) {
            if (i != 0) cout << " ";
            cout << pilotos[i].id;
            max = pilotos[i].pontos;
        } else {
            break;
        }
    }

    cout << endl;

    resetarPiloto(pilotos, p);
}

bool ordenarPorPontos(Piloto a, Piloto b) {
    if (a.pontos != b.pontos) return a.pontos > b.pontos;
    return a.id < b.id;
}

void calcularPontos(int premios [ ], Piloto pilotos [ ], int p) {
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < pilotos[i].posicoes.size(); j++) {
            pilotos[i].pontos += premios[pilotos[i].posicoes[j] - 1];
        }
    }
    sort(pilotos, pilotos + p, ordenarPorPontos);
}

int main() {
    int g, p, v, s, k;  // g - numero de corridas; p - n de pilotos; s - n de regras; k - n de premiações 
    Piloto pilotos[105];

    while (cin >> g >> p && (g != 0 && p != 0)) {

        for (int i = 0; i < p; i++) {
            pilotos[i].id = i + 1;
            pilotos[i].posicoes.clear();
            pilotos[i].pontos = 0;
        }

        for (int i = 0; i < g; i++) {
            for (int j = 0; j < p; j++) {
                cin >> v; // lê a posição dos pilotos na corrida
                pilotos[j].posicoes.push_back(v);
            }
        }

        cin >> s; // lê o número de regras

        for (int i = 0; i < s; i++) {
            cin >> k; // Lê o número de prêmios
            int premios[105] = { 0 };
            for (int j = 0; j < k; j++) {
                cin >> premios[j]; // prêmios 
            }

            calcularPontos(premios, pilotos, p);
            imprimirVencedor(pilotos, p);
        }
    }
}