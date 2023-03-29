import random

list_l = [i for i in range(1, 100001)]
random.shuffle(list_l)

for i in list_l:
    print(i, end=", ")
