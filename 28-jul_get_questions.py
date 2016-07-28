#!/usr/bin/python3
plik = open("./python_excercises_utf8.txt", "r")
latch = False

increment = 1
for line in plik:
    line = line.rstrip()

    if line == "Question:":
        latch = True
        print()
        line = plik.readline()
        print("Question " + str(increment))
    elif line == "Hints:" or line == "Hint:":
        latch = False
        increment += 1

    if latch == True :
        print(line)
    else:
        print("+", end='')


