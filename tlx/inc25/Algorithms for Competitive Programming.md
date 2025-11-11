# Algorithms for Competitive Programming

## Algebra

- Fundamentals

  - Binary Exponentiation
  - Euclidean algorithm for computing the greatest common divisor
  - Extended Euclidean Algorithm
  - Linear Diophantine Equations
  - Fibonacci Numbers

- Prime numbers

  - Sieve of Eratosthenes
  - Linear Sieve
  - Primality tests
  - Integer factorization

- Number-theoretic functions

  - Euler's totient function
  - Number of divisors / sum of divisors

- Modular arithmetic

  - Modular Inverse
  - Linear Congruence Equation
  - Chinese Remainder Theorem
  - Garner's Algorithm
  - Factorial modulo p
  - Discrete Log
  - Primitive Root
  - Discrete Root
  - Montgomery Multiplication

- Number systems

  - Balanced Ternary
  - Gray code

- Miscellaneous
  - Bit manipulation
  - Enumerating submasks of a bitmask
  - Arbitrary-Precision Arithmetic
  - Fast Fourier transform
  - Operations on polynomials and series
  - Continued fractions
  - Factoring Exponentiation

## Data Structures

- Fundamentals

  - Minimum Stack / Minimum Queue
  - Sparse Table

- Trees

  - Disjoint Set Union
  - Fenwick Tree
  - Sqrt Decomposition
  - Segment Tree
  - Treap
  - Sqrt Tree
  - Randomized Heap

- Advanced
  - Deleting from a data structure in O(T(n) log n)

## Dynamic Programming

- Introduction to Dynamic Programming
- Knapsack Problem
- Longest increasing subsequence
- DP optimizations
  - Divide and Conquer DP
  - Knuth's Optimization
- Tasks
  - Dynamic Programming on Broken Profile. Problem "Parquet"
  - Finding the largest zero submatrix
  - String Processing

## String Processing

- Fundamentals
  - String Hashing
  - Rabin-Karp for String Matching
  - Prefix function - Knuth-Morris-Pratt
  - Z-function
  - Suffix Array
  - Aho-Corasick algorithm
- Advanced
  - Suffix Tree
  - Suffix Automaton
  - Lyndon factorization
- Tasks
  - Expression parsing
  - Manacher's Algorithm - Finding all sub-palindromes in O(N)
  - Finding repetitions

## Linear Algebra

- Matrices
  - Gauss & System of Linear Equations
    - Gauss
    - Overview
    - Search for the pivoting element
    - Degenerate cases
    - Implementation
    - Complexity
    - Acceleration of the algorithm
    - Solving modular SLAE
    - A little note about different heuristics of choosing pivoting row
    - Improve the solution
    - Practice Problems
  - Gauss & Determinant
  - Kraut & Determinant
  - Rank of a matrix

## Combinatorics

- Fundamentals
  - Finding Power of Factorial Divisor
  - Binomial Coefficients
  - Catalan Numbers
- Techniques
  - The Inclusion-Exclusion Principle
  - Burnside's lemma / Pólya enumeration theorem
  - Stars and bars
  - Generating all K-combinations
- Tasks
  - Placing Bishops on a Chessboard
  - Balanced bracket sequences
  - Counting labeled graphs

## Numerical Methods

- Search
  - Binary Search
  - Ternary Search
  - Newton's method for finding roots
  - Simulated Annealing
- Integration
  - Integration by Simpson's formula

## Geometry

- Elementary operations
  - Basic Geometry
  - Finding the equation of a line for a segment
  - Intersection Point of Lines
  - Check if two segments intersect
  - Intersection of Segments
  - Circle-Line Intersection
  - Circle-Circle Intersection
  - Common tangents to two circles
  - Length of the union of segments
- Polygons
  - Oriented area of a triangle
  - Area of simple polygon
  - Check if points belong to the convex polygon in O(log N)
  - Minkowski sum of convex polygons
  - Pick's Theorem - area of lattice polygons
  - Lattice points of non-lattice polygon
- Convex hull
  - Convex hull construction
  - Convex hull trick and Li Chao tree
- Sweep-line
- Search for a pair of intersecting segments
- Planar graphs
  - Finding faces of a planar graph
  - Point location in O(log N)
- Miscellaneous
  - Finding the nearest pair of points
  - Delaunay triangulation and Voronoi diagram
  - Vertical decomposition
  - Half-plane intersection - S&I Algorithm in O(N log N)
  - Manhattan Distance
  - Minimum Enclosing Circle

## Graphs

- Graphs
  - Graph traversal
  - Breadth First Search
  - Depth First Search
- Connected components, bridges, articulations points - Finding Connected Components - Finding Bridges in O(N+M) - Finding Bridges Online - Finding Articulation Points in O(N+M)
  - Strongly Connected Components and Condensation Graph
  - Strong Orientation
- Single-source shortest paths
  - Dijkstra - finding shortest paths from given vertex
  - Dijkstra on sparse graphs
  - Bellman-Ford - finding shortest paths with negative weights
  - 0-1 BFS
  - D´Esopo-Pape algorithm
- All-pairs shortest paths
  - Floyd-Warshall - finding all shortest paths
  - Number of paths of fixed length / Shortest paths of fixed length
- Spanning trees
  - Minimum Spanning Tree - Prim's Algorithm
  - Minimum Spanning Tree - Kruskal
  - Minimum Spanning Tree - Kruskal with Disjoint Set Union
  - Second best Minimum Spanning Tree - Using Kruskal and Lowest Common Ancestor
  - Kirchhoff Theorem
  - Prüfer code
- Cycles
  - Checking a graph for acyclicity and finding a cycle in O(M)
  - Finding a Negative Cycle in the Graph
  - Eulerian Path
- Lowest common ancestor - Lowest Common Ancestor - Lowest Common Ancestor - Binary Lifting - Lowest Common Ancestor - Farach-Colton and Bender algorithm - Solve RMQ by finding LCA
  - Lowest Common Ancestor - Tarjan's off-line algorithm
  - Flows and related problems
  - Maximum flow - Ford-Fulkerson and Edmonds-Karp
  - Maximum flow - Push-relabel algorithm
  - Maximum flow - Push-relabel algorithm improved
  - Maximum flow - Dinic's algorithm
  - Maximum flow - MPM algorithm
  - Flows with demands
  - Minimum-cost flow
  - Assignment problem
- Matchings and related problems
  - Bipartite Graph Check
  - Kuhn's Algorithm - Maximum Bipartite Matching
  - Hungarian Algorithm
- Miscellaneous
  - Topological Sorting
  - Edge connectivity / Vertex connectivity
  - Tree painting
  - 2-SAT
  - Heavy-light decomposition

## - Miscellaneous

- Sequences
  - RMQ task (Range Minimum Query - the smallest element in an interval)
  - Search the subsegment with the maximum/minimum sum
  - K-th order statistic in O(N)
  - MEX task (Minimal Excluded element in an array)
- Game Theory
  - Games on arbitrary graphs
  - Sprague-Grundy theorem. Nim
- Schedules
  - Scheduling jobs on one machine
  - Scheduling jobs on two machines
  - Optimal schedule of jobs given their deadlines and durations
- Miscellaneous
  - Tortoise and Hare Algorithm (Linked List cycle detection)
  - Josephus problem
  - 15 Puzzle Game: Existence Of The Solution
  - The Stern-Brocot Tree and Farey Sequences

 "_id"
    
  
  "plot": "Three men hammer on an anvil and pass a bottle of beer around.",
  "genres": [
    "Short"
  ],
  "runtime": 1,
  "cast": [
    "Charles Kayser",
    "John Ott"
  ],
  "num_mflix_comments": 1,
  "title": "Blacksmith Scene",
  "fullplot": "A stationary camera looks at a large anvil with a blacksmith behind it and one on either side. The smith in the middle draws a heated metal rod from the fire, places it on the anvil, and all three begin a rhythmic hammering. After several blows, the metal goes back in the fire. One smith pulls out a bottle of beer, and they each take a swig. Then, out comes the glowing metal and the hammering resumes.",
  "countries": [
    "USA"
  ],
  "released"
    
      
    
  
  "directors": [
    "William K.L. Dickson"
  ],
  "rated": "UNRATED",
  "awards"
    "wins": 1,
    "nominations": 0,
    "text": "1 win."
  
  "lastupdated": "2015-08-26 00:03:50.133000000",
  "year": 1893,
  "imdb"
    "rating": 6.2,
    "votes": 1189,
    "id": 5
  
  "type": "movie",
  "tomatoes"