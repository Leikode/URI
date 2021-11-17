#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int a, cont = 0;
double xa1, ya1, xb1, yb1, xa2, ya2, xb2, yb2, d, fi, xc, yc, alf, tet, pi, bet;
int main() {
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> xa1 >> ya1;
        cin >> xb1 >> yb1;
        cin >> xa2 >> ya2;
        cin >> xb2 >> yb2;
        d = pow(xb1, 2) + pow(yb1, 2) - pow(xb2, 2) - pow(yb2, 2);
        tet = pow(xa1, 2) + pow(ya1, 2) - pow(xa2, 2) - pow(ya2, 2);
        fi = 2 * (yb1 - yb2);
        alf = 2 * (xa1 - xa2);
        bet = 2 * (ya1 - ya2);
        pi = 2 * (xb1 - xb2);
        yc = ((alf * d) - (tet * pi)) / ((alf * fi) - (bet * pi));
        xc = (tet - (bet * yc)) / alf;
        if (yc == (-0.00) || yc == (+0.00)) { yc = 0.00; }
        if (xc == (-0.00) || xc == (+0.00)) { xc = 0.00; }
        cont++;
        cout << fixed << setprecision(2) << "Caso #" << cont << ": " << xc << " " << yc << endl;
    }
}