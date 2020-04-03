You have been hired by the National council for Traffic Management to computerize traffic control at a 3-way intersection (pictured below).

The M.G street street is one-way as pointed by the directional arrow. The B.S street is two-way. The rules for this intersection are:
 

1.	Each car (process) arriving at the intersection will call a procedure Enter(inDir, outDir), where inDir and outDir are parameters whose value is one of the defined constants: NORTH, SOUTH, EAST, or WEST. The parameter inDir is the direction that you enter the intersection, and outDir is the direction that you will leave the intersection. This procedure returns only when it is safe to proceed through the intersection.

2.	After  leaving  the  intersection,  the  car

(process) must call procedure Leave(outDir), where outDir is defined the same as above.

3.	Cars can proceed straight or make legal turns. U turns are illegal.

4.	If cars are waiting from both the north and east directions, they should proceed at the same time if they can safely do so.

5.	If cars are waiting from both the north and east directions, and they cannot both safely proceed at the same time, they must alternate (this prevents starvation).

6.	The east-west street has a single lane. The

north-south street has two lanes - one in either direction.

You are to write the code for the Enter() and Leave() methods. You can assume that you are supplied with

(already written) a procedure called DriveThroughTheIntersection(). You have no idea how long this procedure takes to execute. The first program will be written using semaphores as the synchronization mechanism. Assume that car each is a process. You are to define the global variables (including semaphores) that are to be used, and how they are initialized. You are to then write the code that the cars will use.
