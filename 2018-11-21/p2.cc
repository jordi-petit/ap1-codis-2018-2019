/* Cercar els primers nombres primers amb garbell d'Eratòstenes. */

#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;


// retorna el nombre de segons actuals des d'algun moment
double now() {
    return clock() / double(CLOCKS_PER_SEC);
}


// retorna tots els primers fins a n, en ordre creixent
vector<int> primers(int n) {
    // garbell d'Eratòstenes: p[i] dius si i és primer
    vector<bool> p(n+1, true);
    p[0] = p[1] = false;
    for (int i = 2; i*i <= n; ++i) {
        if (p[i]) {
            for (int j = 2*i; j <= n; j += i) {
                p[j] = false;
            }
        }
    }

    // recollir els primers
    vector<int> ps;
    for (int i = 2; i <= n; ++i) {
        if (p[i]) {
            ps.push_back(i);
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
