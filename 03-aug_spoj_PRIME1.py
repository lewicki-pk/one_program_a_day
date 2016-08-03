#!/usr/bin/python3
# WIP
# PRIME1 - Prime Generator
# #number-theory
# 
# Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate
# all prime numbers between two given numbers!
# Input
# 
# The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are
# two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.
# Output
# 
# For every test case print all prime numbers p such that m <= p <= n, one number per line,
# test cases separated by an empty line.
# Example
# 
# Input:
# 2
# 1 10
# 3 5
# 
# Output:
# 2
# 3
# 5
# 7
# 
# 3
# 5
# 
# Warning: large Input/Output data, be careful with certain languages
# (though most should be OK if the algorithm is well designed)
iterations = int(input("How many iterations? "))
l = list()
for i in range(1, iterations + 1):
    l.insert(len(l), input("give 2 values:").split(sep=" "))

print(l)
for each in l:
    a = int(each[0])
    b = int(each[1]) + 1

    primes = list(range(a, b))

    for i in range(a + 1, b - 1):
        primes = list(filter(lambda x: (x % i != 0) if x != i else True, primes))

    for y in primes:
        print(y)
    

