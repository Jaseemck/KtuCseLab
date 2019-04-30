 30.SWAP TWO NUMBERS USING FUNCTION
**************************************************************

def swap(a,b):
 c=a
 a=b
 b=c
 print "After swaping","a=",a,"b=",b
a=input("Enter the value for a: ")
b=input("Enter the value for b: ")
swap(a,b)


"""
OUTPUT
student@student-desktop:~/Desktop$ python swapfunct.py
Enter the value for a: 1
Enter the value for b: 2
After swaping a= 2 b= 1
"""
