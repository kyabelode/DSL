def Longestword(s):
    word = s.split()
    res =""
    for i in word:
        if len(i)>len(res):
            res = i
    return res 

def OccurenceofCharachter(s,target):
    n = len(s)
    count = 0
    for i in range (0,n):
        if s[i] == target:
            count+=1
    return count      
   
def ispalindrome(s):
    n = len(s)
    j = " "
    k = " "
    for i in range(0,n):
        j+=s[i]
    for i in range(n-1,-1,-1):
        k+=s[i]
    if j == k:
        return True
    else :
        return False


s = str(input("Enter the string\n"))
while True:
    print("Main Menu")
    print("1.The length of the Longest Word")
    print("2.Occurence of the word ")
    print("3.ispalindrome")
    print("4.exit")
    choice = int(input("Enter your choice:"))
    
    if choice == 1:
        k = Longestword(s)
        print(k)
    elif choice ==2:
        char = input("Enter the charchter: ")
        count = OccurenceofCharachter(s,char)
        print(f"The character '{char}' occurred {count} times.")
    elif choice == 3:
      if(ispalindrome(s)):
          print("Yes")
      else:
          print("No")
    elif choice == 4:
        break
    else:
        print("Oops! Incorrect Choice.")  