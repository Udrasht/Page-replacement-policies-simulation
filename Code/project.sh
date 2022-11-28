#!/bin/bash

#aging
g++  AOS_Project_Aging.cpp -o aging 
./aging

#optimal
g++  AOS_Project_Optimal.cpp -o optimal 
./optimal
#nfu
g++  AOS_Project_Nfu.cpp -o nfu
./nfu
#random
g++  Aos_project_Random.cpp -o random
./random
#workingset
g++  Aos_project_workingset.cpp -o workingset
./workingset
#LFU
g++  Aos_project_lru.cpp -o lru
./lru
#fifo
g++  Aos_project_fifo.cpp -o fifo
./fifo
#fifosecond chance
g++  Aos_project_fifo_sc.cpp -o fifo_sc
./fifo_sc
#Nfu
g++  Aos_project_Nru.cpp -o nru
./nru
#clock
g++  Aos_Project_clock.cpp -o clock
./clock
#clock
g++  Aos_Project_Ws_clock.cpp -o wsclock
./wsclock

python3 graph_fault_ratio.py

python3 graph_hit_ratio.py
./remo.sh
 


#remove un wanted file
#rm agingoutput.txt
#rm optimaloutput.txt
