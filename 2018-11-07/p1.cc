/* Ordenació per selecció 1 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;


// retorna el nombre de segons actuals des d'algun moment
double now() {
    return clock() / double(CLOCKS_PER_SEC);
}


// indica si un vector està o no ordenat creixentment
bool ordenat(const vector<double>& v) {
    int n = v.size();
    for (int i = 1 ; i < n; ++i) {
        if (v[i - 1] > v[i]) {
            return false;
        }
    }
    return true;
}


// retorna la posició del mínim de v[e..d].
int posicio_del_minim (const vector<double>& d, int e, int d) {
    int p = v[e];
    for (int j = e + 1; j < d; ++j) {
        if (v[j] < v[p]) {
            p = j;
        }
    }
    return p;
}


// ordenació per selecció
void ordena(vector<double>& v) {
    int n = v.size();
    // invariant: el subvector v[0..i[ està correctament ordenat
    for (int i = 0; i < n; ++i) {
        int p = posicio_del_minim(v, i, n - 1);
        swap(v[i], v[p]);
    }
}


int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    for (double& x : v) {
        x = rand() / double(RAND_MAX);  // valor aleatori entre 0 i 1
    }
    double t1 = now();
    ordena(v);
    double t2 = now();
    cout << t2 - t1 << endl;
    assert(ordenat(v));
}
