 40. READ AND WRITE A FILE
**************************************************************

f=open("file.txt","w")
str="hello\nhai"
f.write(str)
f=open("file.txt","r")
str1=f.read()
print str1


"""
OUTPUT
student@student-desktop:~/Desktop$ python file.py
hello
hai
"""
