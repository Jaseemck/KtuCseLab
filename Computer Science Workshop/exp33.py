 33.TO COUNT THE NUMBER OF VOWELS
**************************************************************


str=raw_input("Enter the string : ")
v1="aeiou"
v2="AEIOU"
for i in range(len(v1)):
 count=0
 for j in range(len(str)):
  if str[j]==v1[i]:
   count+=1
 print v1[i]," count is : ",count



"""
OUTPUT
student@student-desktop:~/Desktop$ python vowel.py
Enter the string : fruit
a  count is :  0
e  count is :  0
i  count is :  1
o  count is :  0
u  count is :  1
"""
