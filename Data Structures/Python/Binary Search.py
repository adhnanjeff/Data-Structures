def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1

arr_binary_search = [10, 20, 30, 40, 50]
result_binary_search = binary_search(arr_binary_search, 30)
print(result_binary_search)
