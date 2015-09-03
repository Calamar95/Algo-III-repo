
#!/usr/bin/python
import random
from math import log

file = open('complejidadN2.txt', 'w+')

for x in xrange(1, 101, 1):
		file.write(str(x*log(x)/40) + ' ' +'\n')
file.close()
