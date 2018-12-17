/* Esquelet d'un problema del final passat */


struct Rectangle {
    int w, h;
};


int area(const Rectangle& a) {
    return a.w * a.h;
}

int perimetre(const Rectangle& a) {
    return 2 * (a.w + a.h);
}


bool compara(const Rectangle& a, const Rectangle& b) {
    int area_a = area(a);
    int area_b = area(b);
    if (area_a != area_b) return area_a < area_b;

    int perimetre_a = perimetre(a);
    int perimetre_b = perimetre(b);
    if (perimetre_a != perimetre_b) return perimetre_a > perimetre_b;

    return a.w < b.w;
}


int main() {
    vector<Rectangle> rectangles;
    int w, h;
    while (cin >> w >> h) {
        rectangles.push_back({w, h});
    }
    sort(rectangles.begin(), rectangles.end(), compara);
}


