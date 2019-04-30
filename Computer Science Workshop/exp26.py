 26. Largest amont 3 tuples

t1=input("Enter the 1st tuple: ")
t2=input("Enter the 2nd tuple: ")
t3=input("Enter the 3rd tuple: ")
if (cmp(t1,t2)==1):
 if(cmp(t1,t3)==1):
  print "t1 is the largest"
 else:
  print"t3 is the largest"
else:
 if(cmp(t2,t3)==1):
  print"t2 is the largest"
 else:
  print"t3 is the largest"


"""
OUTPUT
student@student-desktop:~/Desktop$ python largest.py
Enter the 1st tuple: (5,6,7)
Enter the 2nd tuple: (1,2,3)
Enter the 3rd tuple: (8,4,'ab')      
t3 is the largest
"""

