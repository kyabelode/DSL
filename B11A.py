def linearsearch(arr, target):
    n = len(arr)
    for i in range(0, n):
        if target == arr[i]:
            return i
    return -1

def sentinalsearch(arr, target):
    n = len(arr)
    arr[n-1] = target
    i = 0
    while arr[i] != target:
        i = i + 1
    arr[n-1] = target  
    if i < n-1 or arr[n-1] == target:
        return i
    return -1

arr = []
while True:
    print("\n1. Enter elements")
    print("2. Linear Search")
    print("3. Sentinel Search")
    print("4. Exit")
    choice = int(input("Choose an option: "))

    if choice == 1:
        arr = list(map(int, input("Enter elements separated by space: ").split()))
    elif choice == 2:
        target = int(input("Enter element to search using Linear Search: "))
        index = linearsearch(arr, target)
        if index != -1:
            print(f"Element {target} found at index {index}.")
        else:
            print(f"Element {target} not found.")
    elif choice == 3:
        target = int(input("Enter element to search using Sentinel Search: "))
        index = sentinalsearch(arr, target)
        if index != -1:
            print(f"Element {target} found at index {index}.")
        else:
            print(f"Element {target} not found.")
    elif choice == 4:
        break
    else:
        print("Invalid option. Try again.")
