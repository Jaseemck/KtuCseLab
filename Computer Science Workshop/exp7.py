 7.File Operations

f=open("tst.txt",'r+')
#print (f.read())

f1=open("dest.txt",'a+')
for ln in f:
      #print(ln)      
     f1.write(ln)
f1.close()#other wise dont print to keyboard
f1=open("dest.txt",'r+')
print (f1.read())
