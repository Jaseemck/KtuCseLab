 12. Check number is palindrome or not

n=input("num:")
w=n
rev=0
#steps in loop let dem do
while(n!=0):
 rem=n%10
 rev=rev*10+rem
 n=n/10
print rev
if rev ==w:
 print "paliandrome"
else:
 print "not palindrome"

