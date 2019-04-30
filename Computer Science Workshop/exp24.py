 24. Delete all vowels in a string


stri=raw_input("Enter the string : ")
v1="aeiou"
v2="AEIOU"
str2=""
str3=""
for i in range(len(stri)):
 if stri[i] not in v1:
  str2+=stri[i]
for k in range(len(str2)):
 if str2[k] not in v2:
  str3+=str2[k]
print str3


"""
OUTPUT
student@student-desktop:~/Desktop$ python delvow.py
Enter the string : ElEpHanT
lpHnT

"""

