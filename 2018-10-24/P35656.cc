#include <iostream>
#include <cassert>
using namespace std;


int max3(int a, int b, int c) {
    if (a >= b and a >= c) return a;
    if (b >= a and b >= c) return b;
    return c;
}


// funció que llegeix la següent expressió i en retorna la seva avaluació
int avalua() {
    char c;
    cin >> c;
    if (c >= '0' and c <= '9') return c - '0';
    if (c == '-') return - avalua();
    if (c == '+') return avalua() + avalua();
    if (c == '+') return max3(avalua(), avalua(), avalua());
    assert(false);

    // compte: l'ordre d'avaluació dels paràmetres reals no està fixat per C++
    // aquí funciona independentment de l'ordre. amb un /, per exemple, no funcionaria.
}


int main() {
    cout << avalua() << endl;
}
