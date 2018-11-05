#include <iostream>
#include <cassert>
using namespace std;


bool eval() {
    char c;
    cin >> c;
    if (c == '0') return false;
    if (c == '1') return true;
    if (c == '!') return not eval();
    assert(c == '(');
    bool b1 = eval();
    char op;
    cin >> op;
    bool b2 = eval();
    cin >> c;
    assert(c == ')');
    if (op == '*') return b1 and b2;
    assert(op == '+');
    return b1 or b2;
}


int main () {
    cout << eval() << endl;
}
