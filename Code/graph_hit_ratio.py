import matplotlib.pyplot as plt
import math 
from matplotlib.animation import FuncAnimation
figure, axis = plt.subplots(3,4)
plt.suptitle("PageHit Ratio Vs Frames")
xaxianfu=[]
yaxisnfu=[]
with open("nfuoutput.txt",'r') as fpnfu:
	read1=fpnfu.readlines()
	for i in read1:
		i=i.split();
		print(i)
		xaxianfu.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxisnfu.append(p)
print(xaxianfu)
print(yaxisnfu)
axis[0, 0].plot(xaxianfu, yaxisnfu)
axis[0, 0].set_title("NFU")
xaxiaagging=[]
yaxisagging=[]
with open("agingoutput.txt",'r') as fpagging:
	read2=fpagging.readlines()
	for i in read2:
		i=i.split();
		print(i)
		xaxiaagging.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxisagging.append(p)
print(xaxiaagging)
print(yaxisagging)
axis[0, 1].plot(xaxiaagging, yaxisagging)
axis[0, 1].set_title("Aging")
xaxiafifo=[]
yaxisfifo=[]
with open("fifo_output.txt",'r') as fpfifo:
	read3=fpfifo.readlines()
	for i in read3:
		i=i.split();
		print(i)
		xaxiafifo.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxisfifo.append(p)
print(xaxiafifo)
print(yaxisfifo)
axis[0, 2].plot(xaxiafifo, yaxisfifo)
axis[0, 2].set_title("FIFO")
xaxiafifosc=[]
yaxisfifosc=[]
with open("fifo_sc_output.txt",'r') as fpfifosc:
	read4=fpfifosc.readlines()
	for i in read4:
		i=i.split();
		print(i)
		xaxiafifosc.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxisfifosc.append(p)
print(xaxiafifosc)
print(yaxisfifosc)
axis[0, 3].plot(xaxiafifosc, yaxisfifosc)
axis[0, 3].set_title("FIFO-SECOND CHANCE")
xaxiaopt=[]
yaxisopt=[]
with open("optimaloutput.txt",'r') as fpopt:
	read5=fpopt.readlines()
	for i in read5:
		i=i.split();
		print(i)
		xaxiaopt.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxisopt.append(p)
print(xaxiaopt)
print(yaxisopt)
axis[1, 0].plot(xaxiaopt, yaxisopt)
axis[1, 0].set_title("OPTIMAL")
xaxiaran=[]
yaxisran=[]
with open("randomoutput.txt",'r') as fpran:
	read6=fpran.readlines()
	for i in read6:
		i=i.split();
		print(i)
		xaxiaran.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxisran.append(p)
print(xaxiaran)
print(yaxisran)
axis[1, 1].plot(xaxiaran, yaxisran)
axis[1, 1].set_title("RANDOM")
xaxialfu=[]
yaxislfu=[]
with open("lruoutput.txt",'r') as fplfu:
	read7=fplfu.readlines()
	for i in read7:
		i=i.split();
		print(i)
		xaxialfu.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxislfu.append(p)
print(xaxialfu)
print(yaxislfu)
axis[1, 2].plot(xaxialfu, yaxislfu)
axis[1, 2].set_title("LFU")
xaxiawor=[]
yaxiswor=[]
with open("WorkingSetoutput.txt",'r') as fpwor:
	read8=fpwor.readlines()
	for i in read8:
		i=i.split();
		print(i)
		xaxiawor.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxiswor.append(p)
print(xaxiawor)
print(yaxiswor)
axis[1, 3].plot(xaxiawor, yaxiswor)
axis[1, 3].set_title("WORKING-SET")
xaxianru=[]
yaxisnru=[]
with open("nruoutput.txt",'r') as fpnru:
	read9=fpnru.readlines()
	for i in read9:
		i=i.split();
		print(i)
		xaxianru.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxisnru.append(p)
print(xaxianru)
print(yaxisnru)
axis[2, 0].plot(xaxianru, yaxisnru)
axis[2, 0].set_title("NRU")
xaxiaclock=[]
yaxisclock=[]
with open("clockoutput.txt",'r') as fpclock:
	read10=fpclock.readlines()
	for i in read10:
		i=i.split();
		print(i)
		xaxiaclock.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxisclock.append(p)
print(xaxiaclock)
print(yaxisclock)
axis[2, 1].plot(xaxiaclock, yaxisclock)
axis[2, 1].set_title("CLOCK")
xaxiawsclock=[]
yaxiswsclock=[]
with open("wsclockoutput.txt",'r') as fpwsclock:
	read11=fpwsclock.readlines()
	for i in read11:
		i=i.split();
		print(i)
		xaxiawsclock.append(i[0])
		p=round(float(i[2])/float(i[3]),3)
		yaxiswsclock.append(p)
print(xaxiawsclock)
print(yaxiswsclock)
axis[2, 2].plot(xaxiawsclock, yaxiswsclock)
axis[2, 2].set_title("WS CLOCK")
figure.tight_layout()

figure.delaxes(axis[2,3])
plt.show()
