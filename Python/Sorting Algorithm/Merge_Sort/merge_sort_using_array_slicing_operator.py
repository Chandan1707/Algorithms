def merge(left_arr, right_arr):
    n1 = len(left_arr)
    n2 = len(right_arr)
    new_arr = []
    i = j = 0
    while i < n1 and j < n2:
        if left_arr[i] < right_arr[j]:
            new_arr.append(left_arr[i])
            i += 1
        else:
            new_arr.append(right_arr[j])
            j += 1
    while i < n1:
        new_arr.append(left_arr[i])
        i += 1
    while j < n2:
        new_arr.append(right_arr[j])
        j += 1
    return new_arr


def merge_sort(arr):
    n = len(arr)
    if n > 1:
        mid = n // 2
        left = merge_sort(arr[:mid])
        right = merge_sort(arr[mid:])

        return merge(left, right)
    return arr


def verify(arr):
    n = len(arr)
    i = 0
    result = True
    while i < n - 1:
        if arr[i] > arr[i+1]:
            result = False
        i += 1

    return result


if __name__ == "__main__":
    n = int(input('\nEnter No of Input :'))
    arr = [int(input('Enter array element :')) for i in range(n)]
    print("\nBefore Sort :", arr)
    arr = merge_sort(arr)
    print("\nAfter Sort :", arr)
    print('\n Verify Sort :', verify(arr))
