# Create a double linked list for the elements of the stack
# 1 Create a new data type, a struct that holds the following info: (done)
	i. head node of stack (front of queue)
	ii. Last node of stack (back of queue)
	iii. Line number of the file being read
	iv. Mode of program, stack or queue
	v. present instruction vector being run
	vi. lineptr
having these in a single struct which will be the global variable, will make it easy to:
	access information in any source file, 
	free vectors, line pointers, stack or queue before exiting incase of errors
	set the program mode, and also behaviour of pop if in stack or queue mode

# Write the opcode selector function by creating an array of instructions data type
function created, array to be updated as instructions are created

# Start writing the instructions
# We need to free in the instruction functions