 
#A1[A] 	In second year computer engineering class, group A student’s play cricket, group B students play badminton and 
#group C students play football. 
#Write a Python program using functions to compute following:  
#a)	List of students who play both cricket and badminton 
#b)	Number of students who play cricket and football but not badminton. 

def intersection(l1, l2):
    res = []
    for student in l1:
        if student in l2:
            res.append(student)
    return res


def union(l1, l2):
    res = l2.copy()
    for student in l1:
        if student not in l2:
            res.append(student)
    return res


def diff(l1, l2):
    res = []
    for student in l1:
        if student not in l2:
            res.append(student)
    return res


# Input for students who play cricket only
list1 = []
a = int(input("Enter the number of students who play cricket only: "))
for i in range(a):
    name = input(f"Enter the student name {i+1}: ")
    list1.append(name)

# Input for students who play badminton only
list2 = []
b = int(input("Enter the number of students who play badminton only: "))
for i in range(b):
    name = input(f"Enter the student name {i+1}: ")
    list2.append(name)

# Input for students who play football only
list3 = []
c = int(input("Enter the number of students who play football only: "))
for i in range(c):
    name = input(f"Enter the student name {i+1}: ")
    list3.append(name)

# Display the lists
print("The students who play cricket:", list1)
print("The students who play badminton:", list2)
print("The students who play football:", list3)

# Students who play both cricket and badminton
print("Students who play both cricket and badminton:", intersection(list1, list2))

u = union(list1, list3)
print("Students who play cricket and football but not badminton:", diff(u, list2))
