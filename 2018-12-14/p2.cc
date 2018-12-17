/* Generar totes les combinacions d'n bits amb u uns. */

#include <iostream>
#include <vector>
using namespace std;


void escriure(const vector<int>& v) {
    for (int x : v) cout << x;
    cout << endl;
}


// Genera totes les combinacions de n bits
// en v, havent fixat les primeres i posicions de v
// tot sabent que ja s'han col·locat u uns.
void genera(vector<int>& v, int i, int n, int uns, int u) {
    if (i == n) {
        escriure(v);
    } else {
        if (i - uns < n - u) {  // si encara hi caven més zeros
            v[i] = 0;
            genera(v, i + 1, n, uns, u);
        }
        if (uns < u) {          // si encara hi caben més uns
            v[i] = 1;
            genera(v, i + 1, n, uns + 1, u);
        }
    }
}


int main() {
    int n, u;
    cin >> n >> u;
    vector<int> v(n);
    genera(v, 0, n, 0, u);
}
