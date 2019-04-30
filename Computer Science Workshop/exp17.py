 17. Sort a string in alphabetical order

word=input("Enter the string : ")
l=len(word)-1
for i in range(0,l):
 for j in range(0,l):
  if (word[i]>word[j]):
   temp=word[i]
   word[i]=word[j]
   word[j]=temp

print word
