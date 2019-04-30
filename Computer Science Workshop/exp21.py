21.Perfect Square or not

num=input("enter the number")
i=1
while i<=num/2:
 s=i**2
 if s==num:
  print "perfect square"
  break
 i+=1
else:
 print "not a perfect square"

"""
OUTPUT
student@student-desktop:~/Desktop$ python perfect.py
enter the number 16
perfect square
"""
