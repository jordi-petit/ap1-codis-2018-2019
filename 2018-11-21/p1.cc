/* Cercar els primers nombres primers amb algorisme elemental. */

#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;


// retorna el nombre de segons actuals des d'algun moment
double now() {
    return clock() / double(CLOCKS_PER_SEC);
}


// indica si x és o no primer
// prec: x≥2
bool primer(int x) {
    for (int c = 2 ; c*c <= x; ++c) {
        if (x % c == 0) {
            return false;
        }
    }
    return true;
}

// retorna tots els primers fins a n, en ordre creixent
vector<int> primers(int n) {
    vector<int> ps;
    for (int x = 2; x <= n; ++x) {
        if (primer(x)) {
            ps.push_back(x);
        }
    }
    return ps;
}


// trobar els n primers nombres primers i dir quants n'hi ha,
// tot comptant el temps.
int main() {
    int n;
    cin >> n;
    double t1 = now();
    vector<int> ps = primers(n);
    double t2 = now();
    cout << t2 - t1 << " " << ps.size() << endl;
    // for (int x : ps) cout << x << " "; cout << endl;
}
