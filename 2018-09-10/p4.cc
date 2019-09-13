/* Programa que calcula potències. */

#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;      // suposem x ≥ 0

    int p = 1;
    int i = 1;
    while (i <= y) {
        p = p * x;
        i = i + 1;
    }

    cout << p << endl;
}
