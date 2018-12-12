
#include <iostream>
#include <vector>
#include <cassert>


using namespace std;


// A Set is a subset of [0..8] implemented with 9 booleans
using Set = vector<bool>;

// A Sudoku is a 9x9 matrix of Sets
using Sudoku = vector<vector<Set>>;


// returns the sudoku read from cin
Sudoku read() {
    Sudoku s(9, vector<Set>(9, Set(9, true)));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c;
            cin >> c;
            if (c != '.') {
                s[i][j] = Set(9, false);
                s[i][j][c - '1'] = true;
            }
        }
    }
    return s;
}


// returns the cardinality of c
int cardinality(const Set& c) {
    int cnt = 0;
    for (int k = 0; k < 9; ++k) {
        if (c[k]) ++cnt;
    }
    return cnt;
}


// retorns the unique element in the set c
// Prec: |c| = 1
int unique(const Set& c) {
    for (int i = 0; i < 9; ++i) {
        if (c[i]) return i;
    }
    assert(0);
}


// propagates the restrictions from a given unique cell in the sudoku
// Prec: |s[i][j]| = 1
void propagate(Sudoku& s, int i, int j) {
    int p = unique(s[i][j]);
    // propagate row
    for (int k = 0; k < 9; ++k) if (k != j) {
        s[i][k][p] = false;
    }
    // propagate column
    for (int k = 0; k < 9; ++k) if (k != i) {
        s[k][j][p] = false;
    }
    // propagate box
    int ci = (i/3)*3;
    int cj = (j/3)*3;
    for (int ii = ci; ii < ci+3; ++ii) {
        for (int jj = cj; jj < cj+3; ++jj) {
            if (ii != i or jj != j) {
                s[ii][jj][p] = false;
            }
        }
    }
}


// propagates the restrictions from all unique cells in the sudoku
void propagate_from_all(Sudoku& s) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (cardinality(s[i][j]) == 1) {
                propagate(s, i, j);
            }
        }
    }
}


// tells if s is solved (because each cell has just 1 candidate)
bool solved(const Sudoku& s) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (cardinality(s[i][j]) != 1) {
                return false;
            }
        }
    }
    return true;
}


// tells if s does not have any solution (because some cell has 0 candiates)
bool failed(const Sudoku& s) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (cardinality(s[i][j]) == 0) {
                return true;
            }
        }
    }
    return false;
}


// does propagation as much as possible
void propagate_as_much_as_possible(Sudoku& s) {
    Sudoku s2;
    do {
        s2 = s;
        propagate_from_all(s);
    } while (s != s2);
}


// returns in i,j a cell that has at least two elements
// (in fact, a cell with that minimum number of elements)
// prec: not solved() and not failed()
void get_cell(const Sudoku& s, int& i, int& j) {
    int m = 10;
    for (int ii = 0; ii < 9; ++ii) {
        for (int jj = 0; jj < 9; ++jj) {
            int c = cardinality(s[ii][jj]);
            if (c > 1 and c < m) {
                m = c;
                i = ii;
                j = jj;
            }
        }
    }
}


// solves a sudoku using propagation and back-tracking
// input: a sudoku s
// output: s is solved or s is failed
void solve(Sudoku& s) {
    propagate_as_much_as_possible(s);
    if (not solved(s) and not failed(s)) {
        int i, j;
        get_cell(s, i, j);
        for (int k = 0; k < 9; ++k) if (s[i][j][k]) {
            Sudoku s2 = s;
            s[i][j] = Set(9, false);
            s[i][j][k] = true;
            solve(s);
            if (solved(s)) return;
            s = s2;
        }
    }
}


// prints the current state of a sudoku to help debugging
void debug(const Sudoku& s) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9; ++k) {
                if (s[i][j][k]) cout << k+1;
                else cout << '.';
            }
            cout << ' ';
        }
        cout << endl;
    }
}


// prints the solution of a sudoku
// prec: s is solved
void print(const Sudoku& s) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << unique(s[i][j]) + 1 << ' ';
        }
        cout << endl;
    }
}


int main() {
    Sudoku s = read();
    solve(s);
    if (solved(s)) print(s);
    else cout << "no solution" << endl;
}
