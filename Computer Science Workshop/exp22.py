22.Sum of digits of a number

num=input("enter the number")
s=0
while(num>0):
 r=num%10
 s=s+r
 num=num/10
print "sum of numbers",s




"""
OUTPUT
student@student-desktop:~/Desktop$ python squares.py
enter the number 14
sum of numbers 5

"""
