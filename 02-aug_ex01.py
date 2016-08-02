#!/usr/bin/python3
# Question 1
# Write a program which will find all such numbers which are divisible by 7 but are not a multiple of 5, between 2000 and 3200 (both included).
# The numbers obtained should be printed in a comma-separated sequence on a single line.

# [x] between 2000 and 3200 (both included)
# [x] divisible by 7
# [x] not a multiple of 5
# [x] print on single line (comma separated)
myVars = list(range(2000,3201))
result = list(filter(lambda x: x % 5 > 0, myVars ))
result = list(filter(lambda x: x % 7 == 0, result ))
for i in result:
    if i == max(result) :
        print(i, sep='',end='')
    else:
        print(i, sep='',end=',')

# Hints:
# Consider use range(#begin, #end) method
#
# Solution:
# l=[]
# for i in range(2000, 3201):
#     if (i%7==0) and (i%5!=0):
#         l.append(str(i))
#
# print ','.join(l)
