
#!/usr/bin/python
import random

file = open('complejidadN2.txt', 'w+')

for x in xrange(0, 100, 1):
		file.write(str(x*x) + ' ' +'\n')
file.close()
