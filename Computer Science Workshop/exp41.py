 41. PICKLE AND UNPICKLE
**************************************************************

import pickle
f=open("file.txt","w")
l=[1,2,3,4]
pickle.dump(l,f)
l[3]=5
f.close()

import pickle
f=open("file.txt","r")
unpick=pickle.load(f)
for i in unpick:
 print "i is",i
print"l is",l


"""
OUTPUT
student@student-desktop:~/Desktop$ python pic.py
i is 1
i is 2
i is 3
i is 4
l is [1, 2, 3, 5]
"""
