#!/usr/bin/python
import random

#file = open('1erEjemploConNumerosRandom.in', 'w+')
#file2 = open('ejemploTamCiudades.txt', 'w+')

#for x in xrange(1,10000, 100):
##i = 0
##ciudad = 0
##file.write(str(random.randrange(x)) + '\n')
##file2.write(str(x) + '\n')

##while i < x:
###ciudad = ciudad + (random.randrange(i+1)+1)
###file.write(str(ciudad) + ' ')
###i = i + 1
##
##file.write('\n')

#file2.close()

#file = open('2doEjemploCableCorto.in', 'w+')
#file2 = open('ejemploTamCiudades.txt', 'w+')

#for x in xrange(1,10000, 100):
#	i = 0
#	ciudad = 0
#	file.write('1' + '\n')
#	file2.write(str(x) + '\n')

#	while i < x:
#		ciudad = ciudad + (random.randrange(i+1)+1)
#		file.write(str(ciudad) + ' ')
#		i = i + 1
	
#	file.write('\n')

#file2.close()


file = open('3erEjemploCableLargo.in', 'w+')
file2 = open('ejemploTamCiudades.txt', 'w+')

for x in xrange(1,10000, 100):
	i = 0
	ciudad = 0
	file.write('100000000' + '\n')
	file2.write(str(x) + '\n')

	while i < x:
		ciudad = ciudad + (random.randrange(i+1)+1)
		file.write(str(ciudad) + ' ')
		i = i + 1
	
	file.write('\n')

file2.close()