/* Ordenació per fusió */

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


// prec: v[e..m] i v[m+1..d] estan ordenats creixentment i e ≤ m < d.
// post: v[e..d] està ordenat creixentment
void merge (vector<double>& v, int e, int m, int d) {
    vector<double> r(d - e + 1);
    int i = e;
    int j = m + 1;
    int k = 0;
    while (i <= m and j <= d) {
        if (v[i] < v[j]) r[k++] = v[i++];
        else r[k++] = v[j++];
    }
    while (i <= m) r[k++] = v[i++];
    while (j <= d) r[k++] = v[j++];
    for (k = 0; k < d - e + 1; ++k) v[k+e] = r[k];
}


// ordena creixentment v[e..d]
void mergesort (vector<double>& v, int e, int d) {
    if (d > e) {
        int m = (e + d)/2;
        mergesort(v, e, m);
        mergesort(v, m + 1, d);
        merge(v, e, m, d);
    }
}


// ordenació per fusió
void mergesort (vector<double>& v) {
    mergesort(v, 0, v.size() - 1);
}



int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    for (double& x : v) {
        x = rand() / double(RAND_MAX);
    }
    double t1 = now();
    mergesort(v);
    double t2 = now();
    cout << t2 - t1 << endl;
    assert(ordenat(v));
}
