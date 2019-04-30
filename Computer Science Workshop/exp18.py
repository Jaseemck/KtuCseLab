18.Check whether String is palindrome or not

word=input("Enter the string : ")#string should enter in "" or ''
i=0
p=1
j=len(word)-1
while i<j:
 if word[i]!=word[j]:
  p=0
 i=i+1
 j=j-1
if p==1:
 print "palindrome"
if p==0:
 print "not palindrome" 

