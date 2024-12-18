def selectionsort(arr):
    n = len(arr)
    for i in range(n-1):
        min_idx = i
        for j in range(i+1, n):
            if arr[min_idx] > arr[j]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def bubblesort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-1):
            if arr[i] < arr[j]:
                arr[i], arr[j] = arr[j], arr[i]

arr = []

while True:
    print("\nMain Menu")
    print("1. Enter the percentage of students")
    print("2. Sort using Selection Sort")
    print("3. Sort using Bubble Sort")
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
            selectionsort(arr)
            print("\nArray after Selection Sort:")
            for i in range(len(arr)):
                print(arr[i], end=" ")
            print()
        else:
            print("\nPlease enter the percentages first.")
            
    elif choice == 3:
        if arr:
            bubblesort(arr)
            print("\nArray after Bubble Sort:")
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
