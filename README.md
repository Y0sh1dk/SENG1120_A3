# SENG1120 - A3

## Task:
You are required to create a binary search tree and a hash table data structures to store strings that will function with the supplied TreeHashTableDemo.cpp and makefile. Both structures should have functions to add and remove elements, plus two overloaded operators: += and <<.

The classes MUST be implemented as class templates. As per the supplied makefile, the binary search tree
class must be called BSTree and will use as nodes instances of BTNode. The hash table class must be named HTable.
You will be provided with TreeHashTableDemo.cpp and makefile, and your classes need to interface with it.

The binary search tree contents must be printed using an inorder traversal.
The hash table class must store the numbers in an array of size 150, and the contents can be printed
from position 0 to n-1, but only for those positions that contain a valid entry.
The hash function used must sum up the ASCII values of each character in the string and
return the result of that sum mod (%) 150

Compile:
    
    make clean && make
    
Execute:

    ./a3.exe