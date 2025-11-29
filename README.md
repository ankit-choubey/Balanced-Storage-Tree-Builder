Balanced Storage Tree Builder 🌳
===============================

A Geometric Visualization Engine comparing Search Efficiency in Balanced vs. Unbalanced Trees.

🚀 Overview
-----------

Balanced Storage Tree Builder is a high-performance educational tool designed to demonstrate the critical impact of data structure selection on search algorithms. In standard databases, inserting sorted data into a Binary Search Tree (BST) degrades performance to linear time \(O(N)\). This project implements a dual-engine system that simultaneously builds an unbalanced BST and a self-balancing AVL Tree, visualizing the structural differences in real-time without external graphics libraries.

- Course: CSE 204: Design and Analysis of Algorithms  
- Institution: SRM University–AP  

⚡ Key Features
--------------

- Unified Architecture: Built on a single Node structure and a global visualization engine to reduce code redundancy by 30%.  
- Zero-Dependency Visualization: Uses a custom In-Order Traversal algorithm to render accurate 2D geometric trees in the console using pure C++.  
- Real-Time Performance Lab: A built-in search engine that tracks and compares "Wasted Steps" between \(O(N)\) and \(O(\log N)\) logic.  
- Geometric Accuracy: Visualizes the "Ladder" (BST) vs. "Pyramid" (AVL) structures to prove why height correlates with speed.  

🛠️ Tech Stack
--------------

- Core Logic: C++ (Standard 11/17)  
- Memory Management: Manual Heap Allocation (`new`/`delete`)  
- Interface: Command Line Interface (CLI)  
- Dependencies: None (Standard `<iostream>`, `stdlib>` only)  

⚙️ How It Works
----------------

1. Input Parsing: Accepts a sequence of N integers.  
2. Dual Construction:  
   - BST Engine: Uses iterative insertion (allows skewing).  
   - AVL Engine: Uses recursive insertion with Backtracking and Rotations (LL, RR, LR, RL) to maintain balance.  
3. Visualization: Maps nodes to a virtual grid using their sorted index to determine horizontal spacing.  
4. Benchmarking: Runs a search loop to count comparisons for any target value.  

📦 Installation & Usage
-----------------------

### Prerequisites

- A C++ Compiler (GCC/G++ recommended)

### Steps

#### Clone the Repository

```bash
git clone https://github.com/CodeHashiraX/Balanced-Storage-Tree-Builder.git
cd Balanced-Storage-Tree-Builder
```

#### Compile the Code

```bash
g++ main.cpp -o tree_builder
```

#### Run the Engine

- Windows:

  ```bash
  tree_builder.exe
  ```

- Mac/Linux:

  ```bash
  ./tree_builder
  ```

📊 Sample Output
----------------

Input: `1 2 3 4 5 6` (Sorted Data)

BST Visualization (The "Ladder"):

```text
Level 0: 1
Level 1:       2
Level 2:             3
Level 3:                   4
...
```

AVL Visualization (The "Pyramid"):

```text
Level 0:             4
Level 1:       2           5
Level 2:    1     3           6
```

Performance Result:

```text
Search Value (-1 to exit): 4
Status: FOUND
BST Comparisons: 4
AVL Comparisons: 1
>> AVL was faster by 3 ops.
```

👥 The Team (SRM University AP)
-------------------------------

Project submitted for the partial fulfilment of the requirements for CSE 204.

| Name                         | Role                    | ID            |
|------------------------------|-------------------------|---------------|
| Ankit Choubey               | Logic Developer         | AP24110010595 |
| Danaboyina Abhiram          | Research & Documentation| AP24110010593 |
| Kilani Jyothirmayi Hanisha  | Testing & Validation    | AP24110010594 |
| Kotha Bhaskara Balaji       | Algorithm Analysis      | AP24110010598 |
| Vaibhav Hindurao Dabade     | Report Designing        | AP24110010602 |

📜 License
----------

This project is licensed under the [MIT License](https://www.google.com/search?q=LICENSE).
