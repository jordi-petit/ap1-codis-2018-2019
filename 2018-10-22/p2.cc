/* Cerca binària en vector ordenat. */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


double now() {
    return clock() / double(CLOCKS_PER_SEC);
}


// Retorna la posició de x en v si hi és, -1 si no hi és
// Precondicó: v està ordenat creixentment
int cerca_binaria(const vector<int>& v, int x) {
    int n = v.size();
    int e = 0;
    int d = n - 1;
    while (e <= d) {
        int m = (e + d)/2;
        if (v[m] == x) return m;
        if (v[m] < x) e = m + 1;
        else d = m - 1;
    }
    return -1;
}


int main() {
    srand(time(0));
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i <n; ++i) {
        v[i] = 2*i;
    }

    double t1 = now();
    int p = cerca_binaria(v, 1+2*(rand()% n));
    double t2 = now();

    cout << p << ' ' << t2 - t1 << endl;
}
