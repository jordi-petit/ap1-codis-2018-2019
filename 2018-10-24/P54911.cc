#include <iostream>
using namespace std;


// escriu el nombre de parells consecutius d'una seqüència d'enters acabada en -1.
void parells_consecutius() {
    int c = 0;      // comptador de parells consecutius
    int p, s, t;    // primer, segon, tercer
    cin >> p;
    if (p != -1) {
        cin >> s;
        if (s != -1) {
            cin >> t;
            while (t != -1) {
                if (t < p) ++c;
                p = s;
                s = t;
                cin >> t;
    }   }   }
    cout << c << endl;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        parells_consecutius();
    }
}
