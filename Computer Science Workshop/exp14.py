 14..Display prime numbers  between two limits

lw = input("lw:")
up=input("up:")

for num in range(lw,up+1):
 if num>1:
  flag=0
  for i in range(2,num):
   if (num%i)==0:
    flag=1
  if flag==0:
   print num

