
#!/usr/bin/python
import random
import math

file = open('complejidadNlogN.txt', 'w+')

for x in xrange(1, 100, 1):
		file.write(str(x*math.log(x)) + ' ' +'\n')

file.close()
