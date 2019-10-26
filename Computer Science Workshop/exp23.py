23.Calculator

def add(x,y):
 print "Sum of two numbers is ",(x+y)
def sub(x,y):
 print"Difference of two numbers is ",(x-y)
def multi(x,y):
 print"Product of two number is ",(x*y)
def div(x,y):
 print"Quotient is",(x/y)
x=input("Enter the value for x : ")
y=input("Enter the value for y : ")
z=raw_input("Enter your choice +,-,*,/ : ")
if z=='addition':
 add(x,y)
elif z=='subtraction':
 sub(x,y)
elif z=='multiplication':
 multi(x,y)
else:
 div(x,y)


"""
OUTPUT
student@student-OptiPlex-3020:~/Desktop$ python calculator.py
Enter the value for x4
Enter the value for y5
Enter your choice +,-,*,/: +
Sum of two numbers is 9
"""
