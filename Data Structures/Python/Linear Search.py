def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

arr_linear_search = [10, 20, 30, 40, 50]
result_linear_search = linear_search(arr_linear_search, 30)
print(result_linear_search)
