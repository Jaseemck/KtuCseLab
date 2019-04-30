 28. SUM OF SERIES
**************************************************************


def series(n):
 if n==0:
  return 1
 else:
  return n*series(n-1)
i=input("enter the number")
sum=0
for n in range(1,i+1):
 if n%2==0:
  sum=sum-series(n)
 else:
  sum=sum+series(n)
print sum


"""
OUTPUT
student@student-desktop:~/Desktop$ python series.py
enter the number5
101


