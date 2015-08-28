#!/usr/bin/python
file = open('complejidadLinealbis.in', 'w+')

for x in xrange(1,10000, 1):
	file.write(str(x * 0.006659993)+ '\n')
	
file.close()
