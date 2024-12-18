def Indexoffirstapp(s, substring):
    words = s.split(' ')
    for i, word in enumerate(words):
        if word == substring:
            return i
    return -1

def OccurenceofeachWord(s):
    word_count = {}
    words = s.split(' ')
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    return word_count
def  WordWithLongestLength(s):
    word = s.split(' ')
    res =""
    for i in word:
        if len(i)>len(res):
            res = i
    return res 

s = input("Enter the string:\n")

while True:
    print("\nMain Menu")
    print("a) Display word with the longest length")
    print("b) Display index of first appearance of the substring")
    print("c) Count the occurrences of each word in the string")
    print("d) Exit")
    choice = input("Enter your choice (a/b/c/d): ").strip().lower()

    if choice == 'a':
        longest_word = WordWithLongestLength(s)
        print(f"The word with the longest length is: '{longest_word}'")
    elif choice == 'b':
        substring = input("Enter the substring to find: ")
        index = Indexoffirstapp(s, substring)
        if index != -1:
            print(f"The substring '{substring}' appears first at word index {index}.")
        else:
            print(f"The substring '{substring}' is not found in the string.")
    elif choice == 'c':
        word_count = OccurenceofeachWord(s)
        print("Occurrences of each word:")
        for word, count in word_count.items():
            print(f"'{word}': {count}")
    elif choice == 'd':
        print("Exiting program. Goodbye!")
        break
    else:
        print("Oops! Incorrect choice. Please try again.")