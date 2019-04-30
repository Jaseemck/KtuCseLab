 42.FIBONACCI SEQUENCE USING RECURSION
////////////////////////////////////////////////////////////////////////'''

n=int(input("ENTER NUMBER OF TERMS\n"))
seq=""
def fib(n):
 if n==1:
  return 0
 elif n==2:
  return 1
 elif n>2:
  return fib(n-1)+fib(n-2)
if n<=0:
 print "INVALID"
else:
  i=1 
 while i<=n: 
  seq=seq+" "+str(fib(i))+", "
  i=i+1
print seq

'''/                          OUTPUT
//////////////////////////////////////////////////////////////////////////

ENTER NUMBER OF TERMS
13
 0,  1,  1,  2,  3,  5,  8,  13,  21,  34,  55,  89,  144, 

ENTER NUMBER OF TERMS
-3
INVALID
