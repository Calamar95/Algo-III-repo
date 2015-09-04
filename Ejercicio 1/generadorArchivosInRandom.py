#!/usr/bin/python
import random
import sys

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


#file = open('3erEjemploCableLargo.in', 'w+')
#file2 = open('ejemploTamCiudades.txt', 'w+')

#for x in xrange(1,10000, 100):
#	i = 0
#	ciudad = 0
#	file.write('100000000' + '\n')
#	file2.write(str(x) + '\n')

#	while i < x:
#		ciudad = ciudad + (random.randrange(i+1)+1)
#		file.write(str(ciudad) + ' ')
#		i = i + 1
	
#	file.write('\n')

#file2.close()

#file = open('4toEjemploPrimerasCiudades.in', 'w+')

#for x in xrange(1,10000, 100):
#	i = 0
#	ciudad = 0
#	long_cable = random.randrange(x)
#	file.write(str(long_cable) + '\n')

#	while i < x:
#		if long_cable > 0:
#			proxima_ciudad = random.randrange(i+1)+1 
#			ciudad = ciudad + proxima_ciudad
#			long_cable = long_cable - proxima_ciudad
#			file.write(str(ciudad) + ' ')
#		else:
#			ciudad = 100000
#			file.write(str(ciudad) + ' ')
#		i = i + 1
#	file.write('\n')

#file.close()

#file = open('5toEjemploUltimasCiudades.in', 'w+')

#for x in xrange(1,10000, 100):
#	i = 0
#	ciudad = 0
#	long_cable = random.randrange(x)
#	file.write(str(long_cable) + '\n')
#	ciudades = []

#	while i < x:	
#		if long_cable > 0:
#			proxima_ciudad = random.randrange(i+1)+1
#			if long_cable - proxima_ciudad > 0:
#				ciudad = ciudad + proxima_ciudad
#				long_cable = long_cable - proxima_ciudad
#				ciudades.append(ciudad)
#			else:
#				long_cable = 0
#		else:
#			ciudad = sys.maxint
#			ciudades.insert(0, ciudad)
#		i = i + 1

#	for ciudad in ciudades:
#		file.write(str(ciudad) + ' ')
#	file.write('\n')

#file.close()


