def linearsearch(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def binarysearch(arr, low, high, target):
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif target < arr[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return -1

arr = []
while True:
    print("\n1. Enter roll numbers")
    print("2. Search using Linear Search")
    print("3. Search using Binary Search")
    print("4. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        n = int(input("Enter the number of students: "))
        arr = [int(input(f"Enter roll number {i+1}: ")) for i in range(n)]
        arr.sort()
        print("Sorted roll numbers:", arr)
    elif choice == 2:
        target = int(input("Enter roll number to search: "))
        index = linearsearch(arr, target)
        if index != -1:
            print(f"Roll number {target} found at index {index}.")
        else:
            print(f"Roll number {target} not found.")
    elif choice == 3:
        target = int(input("Enter roll number to search: "))
        index = binarysearch(arr, 0, len(arr) - 1, target)
        if index != -1:
            print(f"Roll number {target} found at index {index}.")
        else:
            print(f"Roll number {target} not found.")
    elif choice == 4:
        break
    else:
        print("Invalid choice. Please try again.")
