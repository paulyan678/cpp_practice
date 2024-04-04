import random
import sys

def veri_freymat(n):
    while True:
        random_int_1 = random.randint(1, 10)
        random_int_2 = random.randint(1, 10)
        random_int_3 = random.randint(1, 10)
        print(f"try with: {random_int_1}^{n} + {random_int_2}^{n} = {random_int_3}^{n}")
        if (random_int_1**n + random_int_2**n == random_int_3**n):
            print(f"solution found: {random_int_1}^{n} + {random_int_2}^{n} = {random_int_3}^{n}")
            return

veri_freymat(3)