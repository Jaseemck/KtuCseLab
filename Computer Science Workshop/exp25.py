 25. Delete Duplicate numbers in a list


l1=input("Enter the list")
l2=[]
for i in l1:
 if i not in l2:
  l2.append(i)
print l2


"""
OUTPUT
student@student-desktop:~/Desktop$ python duplicate.py
Enter the list[1,2,3,4,5,7,3,8,2,9,1,6,8] 
[1, 2, 3, 4, 5, 7, 8, 9, 6]
"""
