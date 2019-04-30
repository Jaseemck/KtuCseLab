 15.Diplay a pyramid

#a=10
for i in range(1,11):
 for j in range(11,-i):
  print " ",
 for j in range(1,i):
  print "*",
 for i in range(i,0,-1):
  print "&",
  """for s in range(a,1,-1):
   print " ",
  print "*", 
  print "\n"
  a=a-1"""
 print "\n"

