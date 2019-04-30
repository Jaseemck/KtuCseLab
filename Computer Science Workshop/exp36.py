 36.*        CHECK WHETHER LEAP YEAR OR NOT          *
**************************************************


y=input("Enter the the year: ")
if (y%4==0):
 if (y%100==0):
  if(y%400==0):
   print "Leap year"
  else:
   print "Not a leap year"
 else:
  print "Leap Year"
else:
 print"Not a leap year"


"""
Output
student@student-desktop:~/Desktop$ python leap.py
Enter the the year: 1900
Not a leap year
"""

