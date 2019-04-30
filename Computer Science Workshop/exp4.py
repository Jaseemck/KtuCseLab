4. Vowels in a String

letters="aeiou"
str=input("Enter a string:")
dt={}.fromkeys(letters,0)
for ch in str:
 if ch in dt:
  dt[ch]=dt[ch]+1
print dt

"""
output
Enter a string:"apple"
{'a': 1, 'i': 0, 'e': 1, 'u': 0, 'o': 0}
"""

