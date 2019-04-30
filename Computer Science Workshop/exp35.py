 35. GRADE OF A STUDENT                *      
************************************************** 
M1=input("Enter the mark OF M1: ")
M2=input("Enter the mark of M2: ")
M3=input("Enter the mark of M3: ")
T=300.00
D=M1+M2+M3
g=(D/T)*100.00
if (g>=90):
 print "A grade"
elif (90<g>=80):
 print "B grade"
elif (80<g>=70):
 print "C grade"
elif (70<g>=60):
 print "D grade"
else: 
 print "fail"




"""
Output
student@student-desktop:~/Desktop$ python grade.py
Enter the mark OF M1: 95.00
Enter the mark of M2: 85.00
Enter the mark of M3: 90.00
A grade
"""
