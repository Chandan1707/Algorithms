def merge(arr, lower_bound, mid, upper_bound):
    new_arr = []
    i = lower_bound
    j = mid + 1
    while i <= mid and j <= upper_bound:
        if arr[i] < arr[j]:
            new_arr.append(arr[i])
            i += 1
        else:
            new_arr.append(arr[j])
            j += 1
    while i <= mid:
        new_arr.append(arr[i])
        i += 1
    while j <= upper_bound:
        new_arr.append(arr[j])
        j += 1

    j = 0
    i = lower_bound
    while i <= upper_bound:
        arr[i] = new_arr[j]
        j += 1
        i += 1


def merge_sort(arr, lower_bound, upper_bound):
    if lower_bound < upper_bound:
        mid = (lower_bound + upper_bound) // 2
        merge_sort(arr, lower_bound, mid)
        merge_sort(arr, mid + 1, upper_bound)

        merge(arr, lower_bound, mid, upper_bound)


if __name__ == "__main__":
    n = int(input('\nEnter No of Input :'))
    arr = [int(input('Enter array element :')) for i in range(n)]
    print("\nBefore Sort :", arr)
    merge_sort(arr, 0, n-1)
    print("\nAfter Sort :", arr)
