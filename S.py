from math import ceil, log
import sys
x = 0
for i in sys.stdin:
    i = int(i)
    x += 1
    print('Case ' + str(x) + ': ' + str(ceil(log(3*(3/2)**(i))/log(10))))
