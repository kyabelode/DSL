""":Write a Python program to store marks scored in subject “Fundamental of Data Structure” 
by N students in the class. Write functions to compute following: 
a)	The average score of class 
b)	Highest score and lowest score of class 
c)	Count of students who were absent for the test 
d)	Display mark with highest frequency"""

# Function to calculate the average score
def calculate_average(marks):
    valid_marks = []
    for mark in marks:
        if mark != -1:  # Exclude absentees (-1)
            valid_marks.append(mark)
    if valid_marks:
        return sum(valid_marks) / len(valid_marks)
    return 0  # If all students are absent, return 0

# Function to find the highest and lowest scores
def find_highest_and_lowest(marks):
    valid_marks = []
    for mark in marks:
        if mark != -1:  # Exclude absentees (-1)
            valid_marks.append(mark)
    if valid_marks:
        return max(valid_marks), min(valid_marks)
    return None, None  # If all students are absent

# Function to count absent students
def count_absent_students(marks):
    return marks.count(-1)  # Count occurrences of -1

# Function to find the mark with the highest frequency
def most_frequent_mark(marks):
    valid_marks = []
    for mark in marks:
        if mark != -1:  # Exclude absentees (-1)
            valid_marks.append(mark)
    if not valid_marks:
        return None, 0  # If no valid marks exist
    freq = {}
    for mark in valid_marks:
        freq[mark] = freq.get(mark, 0) + 1  # Count frequency
    max_mark = max(freq, key=freq.get)  # Find mark with max frequency
    return max_mark, freq[max_mark]

# Main Program
marks = []
n = int(input("Enter the number of students: "))
print("Enter marks for each student (use -1 for absent students):")
for i in range(n):
    mark = int(input(f"Enter marks for student {i + 1}: "))
    marks.append(mark)

while True:
    print("\nMenu:")
    print("1. Average score of the class")
    print("2. Highest and lowest scores")
    print("3. Count of absent students")
    print("4. Mark with the highest frequency")
    print("5. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        avg = calculate_average(marks)
        print(f"Average score: {avg:.2f}")
    elif choice == 2:
        highest, lowest = find_highest_and_lowest(marks)
        print(f"Highest score: {highest}")
        print(f"Lowest score: {lowest}")
    elif choice == 3:
        absent_count = count_absent_students(marks)
        print(f"Number of absent students: {absent_count}")
    elif choice == 4:
        mark, freq = most_frequent_mark(marks)
        print(f"Mark with the highest frequency: {mark} (Frequency: {freq})")
    elif choice == 5:
        print("Exiting the program. Goodbye!")
        break
    else:
        print("Invalid choice. Please try again.")
