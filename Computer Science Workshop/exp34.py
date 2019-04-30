 34.ROOTS OF QUADRACTIC EQUATION          *      
************************************************** 


a=input("Enter the coefficient of x^2: ")
b=input("Enter the coefficient of x: ")
c=input("Enter the constant: ")
d=((b*b-4*a*c)**1/2)
if (d==0):
 x1=(-b+d)/2*a
 x2=(-b-d)/2*a
 print"Equation has equal roots",x1,x2
elif (d>0):
 x1=(-b+d)/(2*a)
 x2=(-b-d)/(2*a)
 print"Equation has two unequal roots",x1,x2
else:
 print"Equation has no real roots"



"""
OUTPUT
student@student-OptiPlex-3020:~/Desktop$ python eqn.py
Enter the coefficient of x^2: 10
Enter the coefficient of x: 10
Enter the constant: 5
Equation has no real roots

student@student-OptiPlex-3020:~/Desktop$ python eqn.py
Enter the coefficient of x^2: 1
Enter the coefficient of x: 4
Enter the constant: 4
Equation has equal roots -2 -2

"""
