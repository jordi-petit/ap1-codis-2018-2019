# Ordenació per fusió en Python


import random
from jutge import read


def fusió(v, e, m, d):
    r = []
    i, j = e, m + 1
    while i <= m and j <= d:
        if v[i] < v[j]:
            r.append(v[i])
            i += 1
        else:
            r.append(v[j])
            j += 1
    while i <= m:
        r.append(v[i])
        i += 1
    while j <= d:
        r.append(v[j])
        j += 1
    for k in range(e, d + 1):
        v[k] = r[k - e]


def ordenació_per_fusió_rec(v, e, d):
    if d > e:
        m = (e + d) // 2
        ordenació_per_fusió_rec(v, e, m)
        ordenació_per_fusió_rec(v, m+1, d)
        fusió(v, e, m, d)


def ordenació_per_fusió(v):
    ordenació_per_fusió_rec(v, 0, len(v) - 1)


def main():
    n = read(int)
    v = [random.random() for i in range(n)]
    ordenació_per_fusió(v)


main()
