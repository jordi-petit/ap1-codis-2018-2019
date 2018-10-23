/* Cerca lineal en un vector. */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


double now() {
    return clock() / double(CLOCKS_PER_SEC);
}


// retorna la posició de x en v si hi és, -1 si no hi és
int cerca(const vector<int>& v, int x) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}


int main() {
    srand(time(0));
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v) {
        x = 2*(rand()%n);
    }

    double t1 = now();
    int p = cerca(v, 1+2*(rand()% n));
    double t2 = now();

    cout << p << ' ' << t2-t1 << endl;
}
