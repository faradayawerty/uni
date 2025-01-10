
from random import random

def C(n, k):
    if k == 0:
        return 1;
    return n/k * C(n - 1, k - 1);

def main():
    print("Задание 1")
    N = 0;
    for i in range(1000):
        num = int(random() * 90 + 10)
        if num//10 != num%10:
            N += 1
    print(N / 1000)
    print(1 - 9 / 90)
    
    print("Задание 2")
    print(1 - 1/(2 ** 3))
    
    print("Задание 3")
    print(1 / (6 ** 7))
    
    print("Задание 4")
    print(1 / C(30, 3))
    
    print("Задание 5")
    print(C(10, 2) / C(25, 10))
    
    print("Задание 6")
    
    
    print("Задание 7")
    print("Задание 8")
    print("Задание 9")
    print("Задание 10")

main()