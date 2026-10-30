#include <iostream>

/*

Arrays are continuos memory buffers allowing O(1) random access via pointer arithmetic.

Fixed-Size Raw Array (static)

	$ int arr[5];
	$ int arr[] = {10, 20, 30, 40, 50};

	$ Allocated directly on the stack
	+ Zero allocation overhead; extremely fast access; automatic cleanup when out of scope.
	- Size must be known at compile-time; cannot resize; prone to stack overflow if too large.

Heap-Allocated Arrays
	
	(C) malloc / free
	$ int *heapArr = (int *)malloc(n * sizeof(int));
	$ if(!heapArr)
		return;
	$ heapArr[0] = 100;
	$ free(heapArr);
	$ heapArr = NULL; 

	$ Allocated on the heap; pointer metadata lives on the stack.
	- Allocates raw/uninitialized bytes
	- does not call object constructors (fine for primitive types like int)
	- manual memory management required

	(C++) new[] / delete[]
	$ int* heapArr = new int[n];
	$ heapArr[0] = 42;
	$ delete[] heapArr;
	$ heapArr = NULL;
	
	+ new[] / delete[] invoke constructors on allocation and destructors on deallocation.
	-- Considered Bad practice --
		- manual memory management required (delete[])
		- It Is Not Exception-Safe
		- there are safer ways to do this in cpp


The Idiomatic C++98 Solution: std::vector

	- The vector metadata (size, capacity, buffer pointer) lives on the stack;
    - the contiguous elements live in heap memory.
	+ Dynamic resizing
	+ RAII-compliant (automatic memory release when out of scope)
		+ No manual cleanup: heap storage is automatically released when 'vec' goes out of scope.
	+ exception-safe
	+ robust API (size(), capacity(), push_back()).

	$ std::vector<int> vec(n);
	$ vec[0] = 10;
	$ vec.push_back(20); // Automatically resizes heap buffer if capacity is exceeded
	$ size_t size = vec.size();
	

	*/


//Testing Understanding of Arrays and Pointers:
int main(){

	{
		int arr[10];
		int *ptr = arr;
		
		printf("%zu\n", sizeof(arr)); // Prints 40 (10 * sizeof(int))
		printf("%zu\n", sizeof(ptr)); // Prints 8  (size of a 64-bit address)

	}

	{
		int a[5], b[5];
		int *p = a;
		p = b;      // Valid: pointer now holds address of b
		p++;        // Valid: advances pointer to next element


		a = b;    // Compile ERROR: cannot assign to array type
		a++;      // Compile ERROR: lvalue required as increment operand

	}

}





// The Great Misconception in C and CPP

/* 

{
	int arr[5];			// arr is of size 20
	
	&arr;				// &arr is of size 8	
	int* ptr = arr; 	// ptr is of size 8	
	
}
	
?? What does ptr hold and what does &arr hold?

	Both ptr and &arr evaluate to the exact same numerical memory address (the location where the array starts), 
	but they have different types and represent different concepts to the compiler.!


	** int arr[5]	is an ARRAY OBJECT of type int[5]
					is exactly of size 20 bytes! No address gets stored!
					arr++; Compile Error: An array is not a modifiable lvalue

					What about (&arr++)?
					- gets parsed as (&(arr++)) by compiler => Tries arr++ (Fail)
					
					What about (&arr)++
					- &arr is a temporary pointer of type int (*)[5]
					- temporary memory address are no lvalues (Fail)

					How to do it then?
					int (*p_arr)[5] = &arr; 	// p_arr is of size (8 bytes)and of type int*()[5] and points to 20 bytes!
					p_arr++;					// VALID: Advances by sizeof(int[5]) (20 bytes) -> points past arr

					How do I only advance one element?
					int *p = arr;		// *p is of size (8 bytes), it is of type int* and points to 4 bytes
					p++; 				// Advances by sizeof(int) (4 bytes) -> points to arr[1]


	** int* p		is a POINTER of type int*
					is of size 8
					p++; advances by sizeof(int)(4 bytes), pointing to arr[1];

*/

// A function parameter "int arr[100]" or "int arr[]"" get rewritten to int *arr by the compiler!
// Arrays cannot be passed by value in C, only by
//		- Workaround: pass a const int* src along with the size and make a local copy with memcpy OR wrap it in a struct to begin with

void process(int arr[100]) {
	printf("%zu\n", sizeof(arr)); // Prints 8, NOT 400!
}

int main(){
	
	int my_data[100];
	process(my_data); // Decays to a pointer (int*) pointing to my_data[0]
	
	{	
		//The expressions arr, &arr[0], and &arr all produce the same numerical address
		//but they have completely different types and pointer arithmetic:

		int arr[5];			// arr is an array object of type int[5] containing 5 contiguous integers (5*4)
		
		int	*p1 = &arr;  	// &arr is of type int (*)[5] // p1 expects a value of type int * (pointer to a single int).

		int	*p1 = arr;     		// p1 point to arr[0]. p1 is of type int*
		int (*p2)[5] = &arr;  	// Points to the ENTIRE array. Type: int(*)[5]
	
	}
}



/*

Why Compilers need the definition of a Template function when compiling a .cpp file.

Normally:
If a definition for a function needed in main.cpp lives in another.cpp file, 
the linker will find the binary code of that definition in the another.o file and match it.

In case of Template:
If the definition of the Template function lives in another.cpp file. No binary code will be
generated for it, because Templates are just blueprints. It is not possible for the compiler to assemble
anything, as Template function could be called for any possible sized type of variabel.
The Compiler will simply skip this part of another.cpp.
Therefore, the Linker wont find the definition of it in any .o file, to match the function call from main.o.
This is why, when main.cpp is getting compiled, we should #include a .hpp or .tpp that serves the definition.
If the Template definition is available at assembly time, the function can be insantiates with concrete types and
will be assembled into the .o file.



the linker will later ma
binary code



*/