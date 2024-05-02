import sys

def matrixChainOrder(arr, i, j):
    _min = sys.maxsize
    temp = 0
    for k in range(i, j):
        temp = matrixChainOrder(arr, i, k) + matrixChainOrder(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]
        
    return min(_min, temp)

arr = [1, 2, 3, 4]
n = len(arr)
print(matrixChainOrder(arr, 1, n-1))