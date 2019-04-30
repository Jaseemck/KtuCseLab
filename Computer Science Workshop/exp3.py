3. Fibonacci series
t1=0
t2=1
tn=0
dt={1:0,2:1}
l=input("limit:")
#print t1
#print t2
cnt=2
while cnt<l:
 tn=t1+t2
 #print tn
 t1=t2
 t2=tn
 cnt =cnt+1
 dt.setdefault(cnt,tn)
print dt
n=input("enter the nth value u want from fibonacci series ")
print dt[n]

"""
output
limit:7
{1: 0, 2: 1, 3: 1, 4: 2, 5: 3, 6: 5, 7: 8}
enter the nth value u want from fibonacci series 3
1

"""
