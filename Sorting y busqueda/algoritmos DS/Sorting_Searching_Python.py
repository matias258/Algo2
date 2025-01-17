import numpy as np
import pandas as pd
import seaborn as sns
import seaborn.objects as so
import matplotlib.pyplot as plt

## Aux
def swap (a, b):
    aux = a
    a = b
    b = aux



## Bubble sort
def BubbleSort(A):
    size = len(A)
    print(size)
    for i in range(0, size - 1):
        for j in range(i+1, size):
            if A[i] > A[j]:
                aux = A[i]
                A[i] = A[j]
                A[j] = aux
    return A  

ejemplo = [4, 2, 2, 8, 3, 3, 1]

print(BubbleSort(ejemplo))

