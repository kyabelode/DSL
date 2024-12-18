def Indexoffirstapp(s, string):
    words = s.split(' ')
    for i, word in enumerate(words):
        if word == string:
            return i
    return -1

def OccurenceofeachCharachter(s):
    char_count = {}
    for char in s:
        if char in char_count:
            char_count[char] += 1
        else:
            char_count[char] = 1
    return char_count

def Copythestring(s):
    res = s[:5]  
    return res

s = input("Enter the string:\n")
while True:
    print("\nMain Menu")
    print("1. Index of first appearance of the given string")
    print("2. Occurrence of each character in the string")
    print("3. Copy the string")
    print("4. Exit")
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        substring = input("Enter the substring to find: ")
        k = Indexoffirstapp(s, substring)
        if k != -1:
            print(f"The substring '{substring}' appears first at index {k}.")
        else:
            print(f"The substring '{substring}' is not found in the string.")
    elif choice == 2:
        char_count = OccurenceofeachCharachter(s)
        print("Character occurrences:")
        for char, count in char_count.items():
            print(f"'{char}': {count}", end=" ")
        print()
    elif choice == 3:
        k = Copythestring(s)
        print(f"The first 5 characters of the string are: '{k}'")
    elif choice == 4:
        print("Exiting program. Goodbye!")
        break
    else:
        print("Oops! Incorrect choice.")
