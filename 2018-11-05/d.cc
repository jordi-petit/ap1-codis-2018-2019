#include <iostream>
using namespace std;


bool es_primer(int n) {
    if (n <= 1) return false;
    for (int d = 2; d*d <= n; ++d) {
        if (n%d == 0) return false;
    }
    return true;
}


int concatena(int a, int b) {
    int q = 0;
    int c = 0;
    while (b > 0) {
        c = 10*c + b%10;
        b /= 10;
        ++q;
    }

    for (int i = 0; i < q; ++i) {
        a = 10*a + c%10;
        c /= 10;
    }
    return a;
}


int main() {
    bool trobat = false;
    int a, b;
    cin >> a;
    while (not trobat and cin >> b) {
        if (not es_primer(concatena(a, b))) trobat = true;
        else a = b;
    }
    if (trobat) cout << a << b << endl;
    else cout << "no" << endl;
}
