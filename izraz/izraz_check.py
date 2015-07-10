import sys

def goodLine (original, modified):
    if len(original) != len(modified): return 0
    cnt = 0
    for i in range(len(original)):
        if original[i] == modified[i]: continue
        if modified[i] != '+' and modified[i] != '-': return 0
        else: cnt += 1
    return cnt == 1

inp = open(sys.argv[1], 'r')
off = open(sys.argv[2], 'r')
out = open(sys.argv[3], 'r')
line = inp.read()

offLines = off.readlines()
cmpLines = out.readlines();

offVal = eval(offLines[0])

if goodLine(line, cmpLines[0]) == False:
    print 'Izraz nije validan.'
    sys.exit()

if int(eval(cmpLines[0])) != int(cmpLines[1]): 
    print 'Izraz nije dobro izracunat.'
    sys.exit()

if int(eval(cmpLines[0])) != int(offLines[1]):
    print 'Izraz nije maksimalan.'
    sys.exit()

print 'Tocno rjesenje!'
