#!/usr/bin/env python3
import glob
import os

# for file in glob.glob("loop.*.out.orig"):
#     print(file)

for i in range(1, 11):
    file = 'loop.'+str(i)+'.out'
    os.system('cp '+file+' '+file+'.orig')
