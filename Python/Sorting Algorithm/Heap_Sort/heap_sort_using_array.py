

def heapify(arr, index, n):
    i = 2 * index + 1
    flag = True
    while i <= n-1 and flag:
        if i < n - 1 and arr[i] < arr[i + 1]:
            i += 1
        if arr[i] > arr[index]:
            arr[index], arr[i] = arr[i], arr[index]
        else:
            flag = False
        index = i
        i = 2 * index + 1


def max_heap(arr, n):
    i = n // 2 - 1
    while i >= 0:
        heapify(arr, i, n)
        i -= 1


def heap_sort(arr):
    n = len(arr)
    i = n // 2 - 1
    while i >= 0:
        heapify(arr, i, n)
        i -= 1

    while n > 1:
        arr[0], arr[n - 1] = arr[n - 1], arr[0]
        n -= 1
        heapify(arr, 0, n)


if __name__ == '__main__':
    a = [12, 43, 57, 98, 34, 46, 76, 45]
    print(a)
    heap_sort(a)
    print(a)
