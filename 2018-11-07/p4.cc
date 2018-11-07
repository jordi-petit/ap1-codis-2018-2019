/* Ordenació per inserció 2 */

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


// ordenació per inserció
void ordena(vector<double>& v) {
    int n = v.size();
    // invariant: el subvector v[0..i[ està ordenat
    for (int i = 1; i < n; ++i) {
        double x = v[i];
        int j = i - 1;
        while (j >= 0 and v[j] > x) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = x;
    }
}


int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    for (double& x : v) {
        x = rand() / double(RAND_MAX);
    }
    double t1 = now();
    ordena(v);
    double t2 = now();
    cout << t2 - t1 << endl;
    assert(ordenat(v));
}
