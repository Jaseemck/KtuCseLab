 16.Reverse a number

n=input("num:")
rev=0
#steps in loop let dem do
while(n!=0):
 rem=n%10
 rev=rev*10+rem
 n=n/10
print rev

