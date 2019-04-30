19.Armstrong Number or not

n=input('Enter the number')
s=0
m=n
while(m>0):
 r=m%10
 s=s+(r**3)
 m=m/10
if(s==n):
 print 'Armstrong number'
else:
 print 'Not Armstrong number'
'''OUTPUT
Enter the number 153
Armstrong number
'''
