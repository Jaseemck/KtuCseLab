 43.                     ARMSTRONG NUMBER WITH FUNCTIONS
////////////////////////////////////////////////////////////////////////

def getcube(n):
 sum=0 
 while n>0:
  sum=sum+((n%10)**3)
  n=n/10
 else:
  return sum
n=100
while n<=999:
 if n==getcube(n):
  print n
  n=n+1
 else:
  n=n+1

'''/                            OUTPUT
//////////////////////////////////////////////////////////////////////////

153
370
371
407

'''
