 29.   SORT THE LIST
**************************************************************

a=input('Enter the list :')
for i in range (len(a)):
 for j in range (i+1,len(a)):
  if a[i]>a[j]:
   t=a[i]
   a[i]=a[j]
   a[j]=t
else:
 print a

'''
OUTPUT
Enter the list :[2,1,5,3,6,9]
[1, 2, 3, 5, 6, 9]
'''
