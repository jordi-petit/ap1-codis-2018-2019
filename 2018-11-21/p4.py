# exponenciació ràpida

import jutge
import time

# retorna a^b, amb a nombre i b natural
def eleva(a, b):
    if b == 0:
        return 1
    x = eleva(a, b // 2)
    if b % 2 == 0:
        return x * x
    return x * x * a


def main():
    a, b = jutge.read(int, int)

    t1 = time.time()
    r = eleva(a, b)
    t2 = time.time()
    print(t2 - t1)
    # print(r)

main()
