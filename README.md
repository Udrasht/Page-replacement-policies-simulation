## "PAGE REPLACEMENT POLICIES SIMULATION"
### Requirements:
- C++ for compiling and running various page replacement algorithm
- Python3 for graph
- Matplotlib library for graph
- Install c++
- Bash shell to run project.sh script
```sh
		$ sudo apt install g++
```
- Install python
```sh
		$ sudo apt install python3
```
- Install Matplotlib
```sh
		$ python -m pip install -U matplotlib
```
### Input Format
Each test case will be in three line
First line contain number of frame
Second line contain request page number stream.All the page number are space seperated
Third line contain dirty Page Information
	
		Eample Testcase 1 :
		2
		7 0 1 2 0 3 0 4 2 3 0 3 2
		0 0 0 0 1 0 0 1 0 0 0 0 0

		Eample Testcase 2 :
		3
		7 0 1 2 0 3 0 4 2 3 0 3 2
		0 0 0 0 1 0 0 1 0 0 0 0 0

		Eample Testcase 3 :
		4
		7 0 1 2 0 3 0 4 2 3 0 3 2
		0 0 0 0 1 0 0 1 0 0 0 0 0

		Eample Testcase 4 :
		5
		7 0 1 2 0 3 0 4 2 3 0 3 2
		0 0 0 0 1 0 0 1 0 0 0 0 0

###### NOTE: Input is given with input.txt file


### How To Run
- open terminal and execute project.sh file
- command
```sh
		./project.sh
```
- With the help of project.sh all the page replacement c++ file run and produce output in txt files which is use in python as input to draw graph between pagefault ratio and frame number
###### NOTE: All the temporary files will created during the execution and delete after the execution.

### Output
- You see below result for individual page replacement algorithm.
- For Example:

			Number of frame in MM: 2
			Number of pages: 13
			Number of page hit: 2
			Number of page fault: 11
			Page hit ratio : 0.153846
			Page miss ratio: 0.846154

- Graph1 show individual page replacement algorithm between page fault ratio(y-axis) and number of frames(x-axis).
- Graph2 show individual page replacement algorithm between page hit ratio(y-axis) and number of frames(x-axis).

## Team Name : Aos_project_1234
## Team Members :
- Dishant Sharma (2022202019) 
- Udrasht Pal (2022201020) 
- Jugnu Gill (2022201011)  
- Vikram Raj Bakshi (2022201044)
