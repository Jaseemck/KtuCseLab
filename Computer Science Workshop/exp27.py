
27.  SEARCH THE ELEMENT IN A LIST

L=input("Enter the list: ")
num=input("Enter the element: ")
for i in range(len(L)):
 if (L[i]==num):
  print "Element is found"
  break
else:
 print "Element is not found"


"""
OUTPUT
student@student-OptiPlex-3020:~/Desktop$ python search.py
Enter the list: ['a','b',1,2,3,'c']
Enter the element: 'b'
Element is found
"""
