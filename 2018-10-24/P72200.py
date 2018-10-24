from jutge import read


def escriu_quadrat(n):
    for i in range(n - 1, -1, -1):
        for j in range(n - 1, -1, -1):
            print(min(i, j) % 10, end='')
        print()


def main():
    n, primer = read(int), True
    while n is not None:
        if not primer:
            print()
        escriu_quadrat(n)
        n, primer = read(int), False


main()
