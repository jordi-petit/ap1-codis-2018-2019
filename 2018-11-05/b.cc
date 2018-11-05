#include <iostream>
using namespace std;


// Escriu el caracter c n vegades.
void escriu(char c, int n) {
    for (int i = 0; i < n; ++i) cout << c;
}


int main() {
    int t = 0;
    int n = 0;
    bool error = false;
    int x, y;
    while (not error and cin >> x >> y) {
        t += x;
        n += y;
        if (t < 0 or n < 0) {
            cout << "ERROR" << endl;
            error = true;
        }
        else {
            escriu('X', t);
            escriu('.', n);
            cout << endl;
        }
    }
}
