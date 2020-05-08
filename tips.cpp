// a header file that includes every standard library. In programming contests, 
// using this file is a good idea, when you want to reduce the time wasted in 
// doing chores; especially when your rank is time sensitive.
#include <bits/stdc++.h>

// In programming, we cannot have variables, functions, etc with the same name. 
// So to avoid those conflicts we use namespaces. So for one namespace we can 
// have one unique name and that same name can also be used in another namespace.
// “using namespace std” means we use the namespace named std. std is an abbreviation 
// for standard. So that means we use all the things with in std namespace. If we 
// don’t want to use this line of code, we can use the things in this namespace 
// like this. std::cout, std::endl.
using namespace std;

// ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~

// Tips for optimizing:
// - Use C++ instead of Java
// - Use the faster C-style scanf/printf rather than cin/cout.
// - Use the expected cache-friendly quicksort in C++ STL algorithm::sort rather than the cache-friendly heapsort
// - Access a 2D array in a row major fashion (row by row) rather than in a column major fashion
// - Bit manipulation on the built-in integer data types is more efficient than index manipulation in an array of booleans
// - Use lower level data structures/types at all times if you do not need the extra functionality
// - Declare most data structures (especially the bulky ones, e.g. large arrays) once by placing them in global scope
// - Allocate enough memory to deal with the largest input of the problem.
// - Between iterative and recursive, choose iterative.
// - Array access in (nested) loops can be slow. If you have an array A and you frequently access the value of A[i] (without 
//   changing it) in (nested) loops, it may be beneficial to use a local variable temp = A[i] and works with temp instead.
// - In C/C++, appropriate usage of macros or inline functions can reduce runtime.
// - Using C-style character arrays will yield faster execution than when using the C++ STL string.

// ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~
// Linear Data Structures in C++ STL:

// - Static Array: (native support in both C/C++ )
// This is clearly the most commonly used data structure in programming contests.
// Whenever there is a collection of sequential data to be stored and later accessed us-
// ing their indices, the static array is the most natural data structure to use. As the
// maximum input size is usually mentioned in the problem statement, the array size
// can be declared to be the maximum input size, with a small extra buffer (sentinel) for
// safety—to avoid the unnecessary ‘off by one’ RTE. Typically, 1D, 2D, and 3D arrays
// are used in programming contests—problems rarely require arrays of higher dimension.
// Typical array operations include accessing elements by their indices, sorting elements,
// performing a linear scan or a binary search on a sorted array.

// - Dynamically-Resizeable Array: C++ STL vector
// This data structure is similar to the static array, except that it is designed to handle
// runtime resizing natively. It is better to use a vector in place of an array if the size
// of the sequence of elements is unknown at compile-time. Usually, we initialize the size
// (reserve() or resize()) with the estimated size of the collection for better perfor-
// mance. Typical C++ STL vector operations used in competitive programming include
// push back(), at(), the [] operator, assign(), clear(), erase(), and iterators for
// traversing the contents of vectors.

// - Array of Booleans: C++ STL bitset
// If our array needs only to contain Boolean values (1/true and 0/false), we can use
// an alternative data structure other than an array—a C++ STL bitset. The bitset
// supports useful operations like reset(), set(), the [] operator and test().

// - Bitmasks:
// a.k.a. lightweight small sets of Booleans (An integer is stored in 
// a computer’s memory as a sequence/string of bits. Thus, we can use integers to 
// represent a lightweight small set of Boolean values.) All set operations
// then involve only the bitwise manipulation of the corresponding integer, which makes
// it a much more efficient choice when compared with the C++ STL vector<bool>,
// bitset, or set<int> options. Such speed is important in competitive programming.
// Some important operations are shown in section below.

// - Linked List: C++ STL list
// Although this data structure almost always appears in data structure and algorithm
// textbooks, the Linked List is usually avoided in typical (contest) problems. This is due
// to the inefficiency in accessing elements (a linear scan has to be performed from the
// head or the tail of a list) and the usage of pointers makes it prone to runtime errors
// if not implemented properly.

// - Stack: C++ STL stack 
// This data structure is often used as part of algorithms that solve certain problems (e.g.
// bracket matching, Postfix calculator and Infix to Postfix conversion, finding Strongly 
// Connected Components and Graham’s scan). A stack only allows for O(1) insertion (push) 
// and O(1) deletion (pop) from the top. This behavior is usually referred to as Last In 
// First Out (LIFO) and is reminiscent of literal stacks in the real world. Typical C++ STL 
// stack operations include push()/pop() (insert/remove from top of stack), top() (obtain 
// content from the top of stack), and empty().

// - Queue: C++ STL queue
// This data structure is used in algorithms like Breadth First Search (BFS). 
// A queue only allows for O(1) insertion (enqueue) from the back (tail) and O(1)
// deletion (dequeue) from the front (head). This behavior is similarly referred to as
// First In First Out (FIFO), just like actual queues in the real world. Typical C++
// STL queue operations include push()/pop() (insert from back/remove from front of
// queue), front()/back() (obtain content from the front/back of queue), and empty().

// - Double-ended Queue (Deque): C++ STL deque
// This data structure is very similar to the resizeable array (vector) and queue above,
// except that deques support fast O(1) insertions and deletions at both the beginning
// and the end of the deque. This feature is important in certain algorithm, e.g. the
// Sliding Window algorithm. Typical C++ STL deque operations include push back(), pop
// front() (just like the normal queue), push front() and pop back() (specific for deque).


// ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~
// Some useful and fast bitmask operations:

// To multiply/divide an integer by 2, we only need to shift the bits in the integer
// left/right, respectively. This is faster than using the operator "/". Notice that 
// the truncation in the shift right operation automatically rounds the division-by-2 
// down, e.g. 17/2 = 8.
int multiply_by_2_exp(int num, int n) {return num << n;} // This function returns num * 2^n
int divide_by_2_exp(int num, int n) {return num >> n;} // This function returns round_down(num / 2^n)
bool check_bit_on(int num, int j) {return num & (1 << j);} // Check if the j-th bit (0-based indexing) is on
int turn_bit_on(int num, int j) {return num | (1 << j);} // Turn the j-th bit on
int turn_bit_off(int num, int j) {return num & ~(1 << j);} // Turn the j-th bit off
int toggle_bit(int num, int j) {return num ^ (1 << j);} // Flip the status of the j-th bit
bool lsb_value(int num) {return num & (-num);} // Return the value of the least significant bit
int light_n_first_bits(int n) {return (1 << n) -1;} // Turn on the n firsts bits

// ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~
// Non-Linear Data Structures:

// - Balanced Binary Search Tree (BST): C++ STL map/set
// The BST is one way to organize data in a tree structure. In each subtree rooted at x,
// the following BST property holds: Items on the left subtree of x are smaller than x
// and items on the right subtree of x are greater than (or equal to) x.

// - Heap: C++ STL priority_queue
// The heap is another way to organize data in a tree. The (Binary) Heap is also a binary
// tree like the BST, except that it must be a complete 14 tree. Complete binary trees
// can be stored efficiently in a compact 1-indexed array of size n + 1, which is often
// preferred to an explicit tree representation.

// - Hash Table: C++11 STL unordered_map
// ‘Direct Addressing Tables’ (DATs) can be considered to be Hash Tables where the keys
// themselves are the indices, or where the ‘hash function’ is the identity function. For
// example, we may need to assign all possible ASCII characters [0-255] to integer values,
// e.g. ‘a’ → ‘3’, ‘W’ → ‘10’, . . . , ‘I’ → ‘13’.

// ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~
// Data Structures with our own libraries:

// - Graph:
// The graph is a pervasive structure which appears in many Computer Science problems. A
// graph (G = (V, E)) in its basic form is simply a set of vertices (V) and edges (E; storing
// connectivity information between vertices in V).

// - Union-Find Disjoint Sets:
// The Union-Find Disjoint Set (UFDS) is a data structure to model a collection of disjoint sets
// with the ability to efficiently —in ≈ O(1) — determine which set an item belongs to (or to
// test whether two items belong to the same set) and to unite two disjoint sets into one larger
// set. Such data structure can be used to solve the problem of finding connected components
// in an undirected graph (Section 4.2.3). Initialize each vertex to a separate disjoint set, then
// enumerate the graph’s edges and join every two vertices/disjoint sets connected by an edge.

// - Binary Indexed (Fenwick) Tree
// The Fenwick Tree is a useful data structure for implementing dynamic cumulative frequency tables. 
// Given an array of integers A[0 ... N−1]. A Fenwick tree is just an array T[0 ... N−1], where each of its 
// elements is equal to the sum of elements of A in some range [g(i),i]. Where g is some function that 
// satisfies 0 ≤ g(i) ≤ i. 

// ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~
// Problem Solving Paradigms:

// Complete Search:
// The Complete Search technique, also known as brute force or recursive backtracking, is a
// method for solving a problem by traversing the entire (or part of the) search space to obtain
// the required solution. During the search, we are allowed to prune (that is, choose not to
// explore) parts of the search space if we have determined that these parts have no possibility
// of containing the required solution. In programming contests, a contestant should develop a 
// Complete Search solution when there is clearly no other algorithm available.
// Tips: Filtering versus Generating. Programs that examine lots of (if not all) candidate solutions 
// and choose the ones that are correct (or remove the incorrect ones) are called ‘filters’.
// Programs that gradually build the solutions and immediately prune invalid partial solu-
// tions are called ‘generators’. Generally, filters are easier to code but run slower, given that it is 
// usually far more difficult to prune more of the search space iteratively. 
// When generating solutions using recursive backtracking (see the tip no 1 above), we may
// encounter a partial solution that will never lead to a full solution. We can prune the search
// there and explore other parts of the search space. Some problems have symmetries and we should 
// try to exploit symmetries to reduce execution time. Sometimes it is helpful to generate tables or other 
// data structures that accelerate the lookup of a result prior to the execution of the program itself. This 
// is called Pre-Computation, in which one trades memory/space for time. Try Solving the Problem Backwards
// Optimizing Your Source Code by understanding computer hardware and how it is organized, especially the I/O, 
// memory, and cache behavior, can help you design better code. 

// Divide and Conquer:
// Divide and Conquer (abbreviated as D&C) is a problem-solving paradigm in which a problem
// is made simpler by ‘dividing’ it into smaller parts and then conquering each part.
// E.g.'s: Various sorting algorithms (e.g. Quick Sort, Merge Sort, Heap Sort) and Binary Search and
// The way data is organized in Binary Search Tree, Heap, Segment Tree, and Fenwick Tree also
// relies upon the D&C paradigm

// Greedy:
// An algorithm is said to be greedy if it makes the locally optimal choice at each step with the
// hope of eventually reaching the globally optimal solution. A problem must exhibit these two
// properties in order for a greedy algorithm to work: It has optimal sub-structures.
// Optimal solution to the problem contains optimal solutions to the sub-problems; It has the greedy property
// If we make a choice that seems like the best at the moment and proceed to solve the remaining subproblem, we 
// reach the optimal solution. We will never have to reconsider our previous choices.

// Dynamic Programming:
// DP is primarily used to solve optimization problems and counting problems. If you
// encounter a problem that says “minimize this” or “maximize that” or “count the ways to
// do that”, then there is a (high) chance that it is a DP problem. Most DP problems in
// programming contests only ask for the optimal/total value and not the optimal solution
// itself, which often makes the problem easier to solve by removing the need to backtrack and
// produce the solution.

// ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~

// Main for tests:

int main() {

	return 0;
}
