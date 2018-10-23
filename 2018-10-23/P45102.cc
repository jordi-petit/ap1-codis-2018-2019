#include <iostream>
#include <cassert>
using namespace std;

// llegeix la següent expressió i en retorna
// la seva avaluació
int expressio() {
    char c;
    cin >> c;
    if (c >= '0' and c <= '9') {
        return c - '0';
    } else {
        assert(c == '(');
        int r1 = expressio();
        char op;
        cin >> op;
        int r2 = expressio();
        char tanca;
        cin >> tanca;
        assert(tanca == ')');
        if (op == '+') return r1 + r2;
        if (op == '-') return r1 - r2;
        if (op == '*') return r1 * r2;
        assert(false);
        return 0;
    }
}

int main() {
    cout << expressio() << endl;
}
