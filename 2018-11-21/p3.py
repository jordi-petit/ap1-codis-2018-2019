# exponenciació tradicional

import jutge
import time

# retorna a^b, amb a nombre i b natural
def eleva(a, b):
    r = 1
    for i in range(b):
        r *= a
    return r


def main():
    a, b = jutge.read(int, int)

    t1 = time.time()
    r = eleva(a, b)
    t2 = time.time()
    print(t2 - t1)
    # print(r)

main()
