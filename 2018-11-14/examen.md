
# Problema P87198: Octàgons facilets

## Possible solució

```python
def escriu_octògon(n):
    # part superior
    for i in range(n):
        print((n - i - 1) * ' ', end='')
        print((n + 2 * i) * 'X')
    # part del mig
    for i in range(n - 2):
        print((3 * n - 2) * 'X')
    # part inferior
    for i in range(n - 1, -1, -1):
        print((n - i - 1) * ' ', end='')
        print((n + 2 * i) * 'X')
    print()

def main():
    n = read(int)
    while n is not None:
        escriu_octògon(n)
        n = read(int)

main()
```

## Errors freqüents

- Solucions massa llargues i complicades.

- `main()`:
    - No llegir una seqüència d'enters sinó un sol enter.
    - Ficar part del codi per pintar un octògon al `main` enlloc
      de fer-ho dins d'una acció.
    - Complicar-se la vida per separar els octògons amb línies
      en blanc quan l'enunciat deia de posar-les sempre
      (és a dir, no llegir bé l'enunciat).

- Utilitzar bucles `while`s on clarament un bucle `for in range()`
  seria molt millor.

- No utilitzar la possibilitat de multiplicar un caràcter per un enter
  per repetir-lo.

- No controlar bé els `print()` amb `sep`, `end` o fer
  `print('')` enlloc de `print()`.

- Posar parèntesis sobrers al voltant de les condicions de `if`s i `while`s.

- Usar tabuladors.



# Problema P37257: Funció per a tres dígits iguals consecutius

## Possible solució

```c++
// diu si els tres darrers digits de n en base b són tots iguals
bool tres_digits_finals_iguals(int n, int b) {
    int primer = n % b;
    int segon = (n/b) % b;
    int tercer = (n/b/b) % b;
    return primer == segon and segon == tercer;
}

// diu si n té tres digits en base b seguits tots iguals
bool tres_digits_seguits_iguals(int n, int b) {
    return n > 0 and (tres_digits_finals_iguals(n, b) or tres_digits_seguits_iguals(n/b, b));
}
```

## Errors freqüents

- No fer una solució recursiva (és a dir, no llegir bé l'enunciat).

- No fer que cada branca acabi amb un `return` (és a dir, no compilar
  amb `g++ -Wall -std=c++11 -O2`, que ho hauria avisat).

- No controlar bé el cas base.

- Complicar la llegibilitat no introduint variables pel primer, segon i tercer
  dígit.

- Cridar recursivament però no fer res amb el resultat obtingut.

- Intentar convertir l'enter a un altres enter que, escrit en base 10 i interpretat
  en base `b`, bla bla bla. Quantes vegades hem dit que això no va enlloc?

- Utilitzar un `while` que, com que a dins retorna, hauria de ser un `if`.

- No indentar, no indentar consistenment, o indentar malament.

- Excés de comentaris.


# Problema P39308: Divisors en ordre

## Possible solució (iterativa)
```c++
int main() {
    int n;
    while (cin >> n){
        cout << "divisors de " << n << ":";

        int d; // Variable que recorre els possibles divisors de n
        // Recorrem els divisors petits
        for (d = 1; d*d <= n; ++d) {
            if (n%d == 0) cout << " " << d;
        }

        // I ara els divisors grans
        --d;
        while (d > 0) {
            if (n%d == 0 and n/d != d) cout << " " << n/d;
            --d;
        }
        cout << endl;
    }
}
```

## Possible solució (recursiva)
```c++
// Escriu els divisors de n que van entre d i n/d (inclosos)
void divisors(int n, int d) {
    if (d*d <= n) {
        bool esDivisor = n%d == 0;
        if (esDivisor) cout << " " << d;
        divisors(n, d + 1); // divisors entre d+1 i n/(d+1)
        if (esDivisor and d*d != n) cout << " " << n/d;
    }
}

int main(){
    int n;
    while (cin >> n){
        cout << "divisors de " << n << ":";
        divisors(n, 1);
        cout << endl;
    }
}
```

## Errors freqüents
- Mala indentació del codi
- Dissenyar funcions auxiliars sense especificar-les o posant especificacions incompletes (per exemple, no explicant el significat dels paràmetres).
- No escriure els divisors en order ascendent.
- Repetir un divisor quan el nombre és un quadrat perfecte.
- Dissenyar una funció auxiliar mirant si el nombre és primer (no cal).
- Codi ineficient pel fet de recórrer tots els divisors des d'1 fins n sense tenir en compte que només cal explorar fins l'arrel quadrada.

# Problema P68777: Patró recursiu

## Possible solució
```c++
// Escriu el patro recursiu segons l'enunciat del problema
void patroRecursiu(char c) {
    cout << c;
    for (int i = 0; i < int(c - 'a'); ++i) {
        patroRecursiu(c - 1);
        cout << c;
    }
}

int main() {
    char a;
    cin >> a;
    patroRecursiu(a);
    cout << endl;
}
```

## Errors freqüents i possibles millores

- No combinar la recursivitat amb la iteració per generar el patró que demanava l'enunciat.
- Utilitzar un `while` dins del `main()` No és un error, però no calia.
- Entre el cas bàsic i el cas recursiu, sovint es pot reaprofitar una part comuna: `if (c == 'a') cout << c; else cout << c ...`
- No calia tractar el cas bàsic amb un `if` (veure la solució proposada).

