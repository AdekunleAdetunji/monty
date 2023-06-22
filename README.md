# Monty Byte code interpreter

The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

The monty program

	Usage: monty file
		where file is the path to the file containing Monty byte code
	If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
	If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
		where <file> is the name of the file
	If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
		where is the line number where the instruction appears.
		Line numbers always start at 1
	The monty program runs the bytecodes line by line and stop if either:
		it executed properly every line of the file
		it finds an error in the file
		an error occured
	If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
	You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

# Task 0:
Implement the push and pall opcodes.

The push opcode

The opcode push pushes an element to the stack.

	Usage: push <int>
	where <int> is an integer
	if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
	where is the line number in the file
	You won’t have to deal with overflows. Use the atoi function
The pall opcode

The opcode pall prints all the values on the stack, starting from the top of the stack.

	Usage pall
	Format: see example
	If the stack is empty, don’t print anything

# Task 1:
Implement the pint opcode.

The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.

	Usage: pint
	If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

# Task 2:
The pop opcode

The opcode pop removes the top element of the stack.

	Usage: pop
	If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

# Task 3:
Implement the swap opcode.

The swap opcode

The opcode swap swaps the top two elements of the stack.

	Usage: swap
	If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

# Task 4:
Implement the add opcode.

The add opcode

The opcode add adds the top two elements of the stack.

	Usage: add
	If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
	The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		The top element of the stack contains the result
		The stack is one element shorter

# Task 5:
Implement the nop opcode.

The nop opcode

The opcode nop doesn’t do anything.

	Usage: nop

# Task 6:
Implement the sub opcode.

The sub opcode

The opcode sub subtracts the top element of the stack from the second top element of the stack.

	Usage: sub
	If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
	The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		The top element of the stack contains the result
		The stack is one element shorter

# Task 7:
Implement the div opcode.

The div opcode

The opcode div divides the second top element of the stack by the top element of the stack.

	Usage: div
	If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
	The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		The top element of the stack contains the result
		The stack is one element shorter
	If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

# Task 8:
Implement the mul opcode.

The mul opcode

The opcode mul multiplies the second top element of the stack with the top element of the stack.

	Usage: mul
	If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
	The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		The top element of the stack contains the result
		The stack is one element shorter

# Task 9:
Implement the mod opcode.

The mod opcode

The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.

	Usage: mod
	If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
	The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		The top element of the stack contains the result
		The stack is one element shorter
	If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

# Task 10:
Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).

# Task 11:
Implement the pchar opcode.

The pchar opcode

The opcode pchar prints the char at the top of the stack, followed by a new line.

	Usage: pchar
	The integer stored at the top of the stack is treated as the ascii value of the character to be printed
	If the value is not in the ascii table (man ascii) print the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE
	If the stack is empty, print the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

# Task 12:
Implement the pstr opcode.

The pstr opcode

The opcode pstr prints the string starting at the top of the stack, followed by a new line.

	Usage: pstr
	The integer stored in each element of the stack is treated as the ascii value of the character to be printed
	The string stops when either:
		the stack is over
		the value of the element is 0
		the value of the element is not in the ascii table
	If the stack is empty, print only a new line

# Task 13:
Implement the rotl opcode.

The rotl opcode

The opcode rotl rotates the stack to the top.

	Usage: rotl
	The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
	rotl never fails

# Task 14:
Implement the rotr opcode.

The rotr opcode

The opcode rotr rotates the stack to the bottom.

	Usage: rotr
	The last element of the stack becomes the top element of the stack
	rotr never fails

# Task 15:
Implement the stack and queue opcodes.

The stack opcode

The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.

	Usage: stack
The queue opcode

The opcode queue sets the format of the data to a queue (FIFO).

	Usage: queue
When switching mode:

	The top of the stack becomes the front of the queue
	The front of the queue becomes the top of the stack

# Task 16:
Write a Brainf*ck script that prints School, followed by a new line.

	All your Brainf*ck files should be stored inside the bf sub directory
	You can install the bf interpreter to test your code: sudo apt-get install bf
	Read: Brainf*ck

# Task 17:
Add two digits given by the user.

	Read the two digits from stdin, add them, and print the result
	The total of the two digits with be one digit-long (<10)

# Task 18:
Multiply two digits given by the user.

	Read the two digits from stdin, multiply them, and print the result
	The result of the multiplication will be one digit-long (<10)

# Task 19:
Multiply two digits given by the user.

	Read the two digits from stdin, multiply them, and print the result, followed by a new line
