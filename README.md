# Data Structure Fundamentals

A small collection of C implementations of data structures you are likely to encounter in a data structures course. I put these together from assignments and in-class exercises in Florida Poly's COP 4415 - Data Structures course in Fall of 2019.

## Topics
The topics covered in this repo (given in order that they were covered in class):

* Prerequisites, including IO, pointers, structs, and dynamic memory allocation in C
* Linked lists
* Stacks and queues
* Sorting algorithms
* Trees
* Heaps
* Dictionaries and hash tables

Tip: Each topic corresponds to a folder.

## Usage
Each .c file can be comiled using `gcc`. No need to worry about Makefiles or linking. For example, if I wanted to try out selection sort, I would do the following:

Make sure you are in the right place. From the root of the repository:

`cd sorting`

Compile:

`gcc selectionSort.c -o selectionSort`

Run:

`./selectionSort`

Output:

```
Starting array: 
[ 1  8  666  43  765  2  47  98 ]
Sorted array: 
[ 1  2  8  43  47  98  666  765 ]
```