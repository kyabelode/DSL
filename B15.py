def insertionsort(arr):
    n = len(arr)
    if n <= 1:
        return
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def shellsort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

arr = []

while True:
    print("\nMain Menu")
    print("1. Enter the percentage of students")
    print("2. Sort using Insertion Sort")
    print("3. Sort using Shell Sort")
    print("4. Display top five scores")
    print("5. Exit")
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        n = int(input("Enter the number of students: "))
        arr = []
        for i in range(n):
            percentage = float(input(f"Enter percentage for student {i + 1}: "))
            arr.append(percentage)
        print("\nPercentages entered successfully.")
        
    elif choice == 2:
        if arr:
            insertionsort(arr)
            print("\nArray after Insertion Sort:")
            for i in range(len(arr)):
                print(arr[i], end=" ")
            print()
        else:
            print("\nPlease enter the percentages first.")
            
    elif choice == 3:
        if arr:
            shellsort(arr)
            print("\nArray after Shell Sort:")
            for i in range(len(arr)):
                print(arr[i], end=" ")
            print()
        else:
            print("\nPlease enter the percentages first.")
            
    elif choice == 4:
        if arr:
            print("\nThe top five scores are:")
            for i in range(len(arr)-1, len(arr)-6, -1):
                print(arr[i], end=" ")
            print()
        else:
            print("\nPlease enter the percentages first.")
            
    elif choice == 5:
        break
    else:
        print("Oops! Incorrect choice.")
