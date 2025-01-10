
from itertools import permutations

def fact(n):
    if(n*n == n):
        return n;
    return n * fact(n - 1)

def C(n, k):
    if k == 0:
        return 1;
    return n/k * C(n - 1, k - 1);

def A(n, k):
    if k == 0:
        return 1;
    return n * A(n - 1, k - 1);

def main():

    print("Задание 1")
    AC = 3
    CB = 5
    print(AC * CB)
    
    print("Задание 4")
    n = 15
    k = 10
    print(C(15, 10))
    
    print("Задание 9")
    print(A(7, 3))
    
    print("Задание 12")
    print(C(25, 7) * C(25 - 7, 7))
    
    print("Задание 17")
    perms = [''.join(p) for p in permutations('приоритет')]
    print(len(set(perms)))
    
    print("Задание 20")
    print(2 ** 5)
    
    print("Задание 25")
    print(C(5, 3))
    
    print("Задание 28")
    print(3 * C(20 - 3, 4))
    
    print("Задание 33")
    print(C(8, 3) - 6 * fact(3))
    
    print("Задание 36")
    print(C(8, 3) / 2)

main()