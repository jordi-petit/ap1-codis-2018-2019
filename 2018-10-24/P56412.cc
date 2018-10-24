
bool es_xupiguai(int n, int b) {
    return n == 0 or (n%b >= b/2 and (n/b)%b < b/2 and es_xupiguai(n/b/b, b));
}
