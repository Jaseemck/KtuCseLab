 10. Factorial using recursion

def refact(x):
 if x==1:
  return 1
 else:
  return(x*refact(x-1))
num=input("no:")
if num>=1:
 print 'factorial is',refact(num
