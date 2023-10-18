// The stack sizes in memory is typically between 1MB to 8MB.

// Thus, if we create a 10^6 size array of type double, it would occupy 8,000,000 bytes, i.e 8MB of space.
// So allocating this huge size array in our program may result in stack overflow error.

// Here is a table summarizing the practical limits on the maximum size of an array in Linux,
// for both 32-bit and 64-bit systems:

// Data type	         Scope	      32-bit system	    64-bit system
// -------------------------------------------------------------------
// int, double, char  	 Global	      10^6	            10^7
// bool	                 Global	      10^6	            10^8
// int, double, char  	 Function	  10^6	            10^6
// bool	                 Function	  10^6	            10^7

// It is important to note that these are just practical limits. In some cases, it may be
// possible to create larger arrays, but this may require special techniques or privileges.


// Thus, it is not possible to find primes if the range is large, i.e >=10^6.

// Thus, we have to apply a different approach.





