2. Program to implement a dictionary

letters=input("Enter a string: ")
print letters
dt={}.fromkeys(letters,0)
for ch in letters:
 if ch in dt:
  dt[ch]=dt[ch]+1
print dt

"""
output
Enter a string: "apple"
apple
{'a': 1, 'p': 2, 'e': 1, 'l': 1}
"""
