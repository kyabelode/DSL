def binarysearch(arr, low, high, target):
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            return mid
        elif target > arr[mid]:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def fibonaccisearch(arr, target):
    n = len(arr)
    start = -1
    f0 = 0
    f1 = 1
    f2 = 1
    while f2 < n:
        f0 = f1
        f1 = f2
        f2 = f1 + f0
    while f2 > 1:
        index = min(start + f0, n-1)
        if arr[index] < target:
            f2 = f1
            f1 = f0
            f0 = f2 - f1
            start = index
        elif arr[index] > target:
            f2 = f0
            f1 = f2
            f0 = f2 - f1
        else:
            return index
    if f1 and arr[n-1]:
        return n-1
    return None

arr = []
while True:
    print("\n1. Enter elements")
    print("2. Binary Search")
    print("3. Fibonacci Search")
    print("4. Exit")
    choice = int(input("Choose option: "))

    if choice == 1:
        arr = list(map(int, input("Enter elements: ").split()))
    elif choice == 2:
        target = int(input("Enter element to search using Binary Search: "))
        index = binarysearch(arr, 0, len(arr)-1, target)
        print(f"Element found at index {index}" if index != -1 else "Element not found.")
    elif choice == 3:
        target = int(input("Enter element to search using Fibonacci Search: "))
        index = fibonaccisearch(arr, target)
        print(f"Element found at index {index}" if index is not None else "Element not found.")
    elif choice == 4:
        break
    else:
        print("Invalid option.")
