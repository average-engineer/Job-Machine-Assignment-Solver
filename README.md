# Job-Machine-Assignment-Solver

A). Introduction:
1). Aim: The Aim of the project is to reduce the machining lead time for various operations and to make an optimized plan for allocation of different operations on different machines.
2). Objective: Allocations of various operations to different machines on the shop floor has to be done according to an optimised plan. This optimised plan has to make the operation allocations in such a way that the aggregate machining time of all those operations is as less as possible. 
B). Engineering background and problem: 
Currently the allotment of different jobs/operations to different machines is done on the basis of experience; the shop floor supervisor allots the machines based on his rough knowledge on how much time a machine takes to finish a job, which he has gained from his experience of using that machine and operating the shop floor.
This process is not fool proof and not the most optimized as it makes a lot of assumptions, does not take each and every factor into consideration and has no definite plan for reference. As a result of this process leads to a lot of delay in the manufacturing process. If the shop floor has a definite plan which it can follow and in doing that, it is decreasing its overall manufacturing lead time, it can function more efficiently as a whole and thus increase siemens’ standards.
C). Methodology:
For making the optimised plan, the RESOURCE LOCATION METHOD is used. A survey of all the machines on the shop floor was conducted with regard to the kind of processes which can be carried out on the machines and the machining time the machine takes for each different process. After all the data was collected and organised, a sample set of 5 machines and 5 operations was taken. An optimised plan will be created for this sample set only for this project in order to check the viability of the method being followed. If we are able to minimise the aggregate machining time of the 5 operations on the 5 machines, we can expand this method to the entire shop floor. 
Since this project is being done in the context of just 5 machines and 5 operations, it must be noted that in the case of the whole shop floor, applying this method manually may not be feasible. Thus, we need to build a solver tool which will require a set of input data and will automatically generate an optimised plan for the input data.
In-order to develop this solver, a program needs to be coded in a suitable programming language. 
For this project, C is used in order to program the solver.
RESOURCE ALLOCATTION METHOD:
This method helps in allocating a number of resources to an equal number of agents in such a way that that a particular parameter (cost, distance, time etc.) is minimised. 
In this a NxN matrix is formed for where the jobs are represented along the columns and the rows are represented along the rows. 
 
	
Here Cij represents the time taken for completing operation/job j on machine I in hours.
There are a couple of assumptions in this method:
•	The number of jobs= number of machines. If there are more machines, we might introduce dummy jobs and if there are a smaller number of machines, we might introduce dummy machines.
•	Each job is assigned to one and only one machine. And each machine does one and one job only from that sample set.
The Hungarian algorithm is used to find out the optimised matrix for any sample set.
Example:

8	6	5	7	5
6	5	3	4	3
7	8	4	6	4
6	7	5	6	5



Step 1: From each entry of a row, we subtract the minimum value in that row and get the following reduced matrix.
3	1	0	2
3	2	0	1
3	4	0	2
1	2	0	1
1	1	0	1



Step 2: From each entry of a column, we subtract the minimum value in that column and get the following reduced matrix:
2	0	0	1
2	1	0	0
2	3	0	1
0	1	0	0
	
Step 3: Now we test whether an assignment can be made as follows. If such an assignment is possible, it is the optimal assignment.
a)	Examine the first row. If there is only one zero, highlight it and cancel out/ cross out all the other zeros in the column passing through the highlighted zero. Examine all the other rows in a similar way and if a row has more than one zero, do nothing to that row and move on to the next row. Step 3 (a) gives us the following matrix:
2	0	0
1
2	1	0
0
2	3	0	1
0	1	0
0

b)	Now repeat the above step for columns (don’t consider assigned or crossed elements)
2	0	0
1
2	1	0
0
2	3	0	1
0	1	0
0


c)	If there is a highlighted zero in each row, the solution is optimised. 
In this case the optimised case is:
Job 2 assigned to machine 1
Job 4 assigned to machine 2
Job 3 assigned to machine 3
Job 1 assigned to machine 4
Optimal aggregate machining time= 6+4+4+6= 20 hours.






For the project, the following sample set (from the shop floor) was taken:
Machines
VTL 1.6
VTL 2.0
VTL 4.0
BORING
MILLING

Operations
SHROUDING
FINAL FINISHING
ROUGH FINISHING
LABYRINTH
PARTING PLANE






The input matrix is given by:
	Shrouding	Final Finishing	Rough Finishing	Labyrinth	Parting Plane
Boring	8.25	12	11.5	12.5	10.31
Milling	8.857	13	12	13	11.68
VTL 1.6M	8.5	12.5	12	8.45	12
VTL 2M	10	11.684	8.83	12	13
VTL 4M	14	10.845	11.11	11.5	14


The solver was coded in C where by entering the time taken to complete different operations on different machines we are able to find the optimized solution to it. A matrix till 100*100 can be solved by using the program. (i.e. a maximum of 100 machines and 100 operations can be optimized by this code).

D). Results:
 The resultant matrix, when done manually, should come out as:
	Shrouding	Final Finishing	Rough Finishing	Labyrinth	Parting Plane
Boring	0
3.75	3.25	4.25	0
Milling	0	4.143	3.143	4.143	0.763
VTL 1.6M	0.05	4.05	3.55	0	1.49
VTL 2M	1.17	2.854	0	3.17	2.11
VTL 4M	3.155	0	0.265	0.655	1.095

Parting plane machining: Boring Machine
Shrouding: Milling machine
Labyrinth Machining: VTL 1.6M
Rough Finishing: VTL 2M
Final Finishing: VTL 4M
Minimum aggregate machining time= 10.31+8.857+8.45+8.83+10.845= 47.292 hours.
Before this optimized plan, operations were allotted to machines randomly by the shop floor manager based on his experience. A sample allotment by the manager was noted and was as follows for the same machines and processes:
Parting Plane: Milling Machine (machining time= 11.68 hrs)
Final Finishing: VTL 2M (machining time= 11.684 hrs)
Rough Finishing: VTL 4M (machining time= 11.11 hrs)
Labyrinth Machining: VTL 1.6M (machining time= 8.45 hrs)
Shrouding: Boring Machine (machining time= 8.25 hrs)
According to the above allocation, the aggregate machining time comes out to be= 11.68+11.684+11.11+8.45+8.25 = 51.174 hrs.
Thus, we can clearly see that on the basis of random allocation, the aggregate machining time comes out to be higher.
NOTE: The above allocation is random and subject to change. In any case the aggregate machining time cannot be lesser than the optimized machining time.


Below are the result snippets after successful code compilation:
Job 0: Shrouding
Job 1: Final Finishing
Job 2: Rough Finishing
Job 3: Labyrinth Machining
Job 4: Parting Plane Machining
Machine 0: Boring Machine
Machine 1: Milling Machine
Machine 2: VTL 1.6M
Machine 3: VTL 2M
Machine 4: VTL 4M

Shop Floor Application –
The shop floor allotment is done on the basis of past experience of the manager. This tool will help him make an optimized allotment. He needs to input the data in the solver to find the allotment plan. Now the allotment can be done on the basis of that plan and meanwhile the next plan is prepared so that no time is wasted in scheduling. 
Planning systematically in this way will help in dealing with the data which will clearly state the time at which the machine will complete its job. Now in case of a rework (which is there most of the time) the shop floor manager can check the data and allot the rework to the machines accordingly.
Rework jobs does tend to disturb the plan and will lead to delays but that delay is there in any case. Suppose the optimized plan is not followed then also the amount of delays due to critical reworks will be the same because the number of such reworks is independent of which plan the shop floor follows. Apart from the rework delay we are left with the machining lead time which is much smaller when the optimized plan is followed.
 
For Example-
Two consecutive plans are prepared to be implemented on the shop floor. Machine (a) takes 15hrs to complete both the tasks whereas machine (b) takes11hrs to complete its job. Now the person can allot the rework job on machine (b) so that machine (b) is not idle while machine (a) is doing its work.    



Limitations –
•	Siemens is a project specific plant i.e. the requirements for each project is usually different this means that the amount of assembly rework which needs to be done on each component varies for each project. This creates uncertainty in the frequency of assembly rework and the time of its requirement which makes the optimized plan susceptible to disruption due to unpredictable needs for rework.
•	For an effective optimized plan the number of jobs should be equal to the number of machines or dummy set needs to be considered i.e. the plan works to its full extend only if all the jobs in the set can be carried out on all the machines of the set.
•	Each job is assigned to one and only one machine and each machine does one and only one job from a sample set considered. 


E). Conclusions:
The method of employee allocation can thus be implemented if we want to minimize the aggregate machining time on the shop floor. The viability of the method is checked by using a sample set of 5 machines and 5 operations and there are 2 types of tools available in order to implement this method: Microsoft excel sheets (using excel solver) and C program (with a code compiler). The availability of the solver in either of the platforms provides the benefit of an automated generated optimization plan where the shop floor manager has to just input the machining time data of different processes on different machines.
