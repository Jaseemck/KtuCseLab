 39.DICTIONARY
**************************************************************

str=raw_input("Enter the string: ")
d={}
for i in str:
 if i not in d:
  d[i]=1
 else:
  d[i]+=1
print d

"""
OUTPUT
student@student-desktop:~/Desktop$ python dict1.py
Enter the string: tooth
{'h': 1, 't': 2, 'o': 2}
"""
