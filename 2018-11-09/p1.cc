/* Fusió de dos vectors ordenats. */

#include <iostream>
#include <vector>
using namespace std;


// Prec: v1 i v2 estan ordenats creixentment
// Post: el resultat és la unió ordenats creixentment dels elemeents a v1 i v2.
vector<double> fusio(const vector<double>& v1, const vector<double>& v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    vector<double> v(n1 + n2);
    int i1 = 0;
    int i2 = 0;
    int k = 0;
    while (i1 < n1 and i2 < n2) {
        if (v1[i1] < v2[i2]) v[k++] = v1[i1++];
        else v[k++] = v2[i2++];
    }
    while (i1 < n1) v[k++] = v1[i1++];
    while (i2 < n2) v[k++] = v2[i2++];
    return v;
}


int main() {
    vector<double> v1 = {3.5, 7.8, 7.8, 9.2, 11.11};
    vector<double> v2 = {1.5, 1.7, 7.8, 55.5};
    vector<double> v = fusio(v1, v2);
    for (double x : v) cout << x << ' ';
    cout << endl;
}
