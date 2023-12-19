# AVL Tree for NBA Player Statistics Management System
## CSPB 2270 – Data Structures - Term Project
Author: Andrew Byrnes  
CU ID: anby7602  
GitHub Username: byrne-saw  

## README

### AVL Tree Explanation 

The __AVL Tree__, implemented in this project, is an advanced form of a binary search tree (BST). Named after its inventors Adelson-Velsky and Landis, the AVL Tree is renowned for its self-balancing capability, ensuring that the tree remains optimally balanced during insertions and deletions. This self-balancing characteristic maintains the tree's height to a logarithmic scale relative to the number of nodes, thereby guaranteeing O(log n) complexity for key operations like insertion, deletion, and lookup.  

#### Node Structure ####
Each node in the AVL Tree encapsulates a PlayerStats object. This object holds essential player data, such as name, team, position, and a primary statistic that the tree organizes. Additionally, each node maintains its height information, crucial for the balancing operations of the tree.

#### Balancing Mechanism ####
The hallmark of the AVL Tree is its ability to maintain a balanced state. After standard BST operations (insertion or deletion), the tree might become unbalanced. An AVL Tree tackles this by assessing the balance factor of each node, defined as the height difference between its left and right subtrees. For efficient operation, this balance factor is kept between -1, 0, and 1.

#### Rotations for Balancing ####
When the balance factor of a node deviates from this range, the tree undergoes specific rotations to restore balance:  
1. __Right Rotation:__ Applied in a 'Left-Left' case, where a node has become unbalanced due to an insertion in the left subtree of its left child. This rotation involves pivoting the node downwards to its right, making its left child the new root of the sub-tree.
2. __Left Rotation:__ Used in a 'Right-Right' case, where an imbalance occurs due to an insertion in the right subtree of a node’s right child. The node is pivoted downwards to its left, with the right child ascending as the new root of the sub-tree.
3. __Left-Right Rotation:__ This is a two-step process addressing the 'Left-Right' imbalance. First, a left rotation on the left child of the node is performed, followed by a right rotation on the node itself. This scenario arises when the left child of a node is right-heavy.
4. __Right-Left Rotation:__ Analogous to the Left-Right rotation, this two-step process corrects a 'Right-Left' imbalance. It starts with a right rotation on the right child of the unbalanced node, followed by a left rotation on the node. This situation occurs when the right child of a node is left-heavy. 


### Important Files
My Project has following folder tree, noteable files __bolded__ below.

```
.  
├── CMakeLists.txt  
├── CMakeLists.txt.in  
├── project_proposal.md 
├── README.md  

├── app_1  
│   ├── main_1.cpp
│   ├── avlTree*
│   └── avlTreeLH*
├── app_demo 
│   ├── main_demo.cpp
│   ├── ppg
│   │   ├── ppg_01*
│   │   └── ppg_02*
│   ├── topg
│   │   └── topg_01*
├── build  
├── code  
│   ├── AVLTree.cpp  
│   └── AVLTree.h  
└── tests  
    └── test.cpp  
```

| File | Descrition |
|---|---|
| CMakeLists.txt      | Ignore this file - rules to build the Makefile for this project (used by cmake)|
| CMakeLists.txt.in   | Ignore this file - more rules to build the Makefile for this project (used by cmake)|
| __project_proposal.md__ | __Orginal Project Proposal submission, includes problem statements and additional context for AVL Tree selection__ |
| __README.md__           | __Readme file you are viewing here__ |
| app_1\                 | Testing application folder 
| ├── main_1.cpp            | Exploratory "main" file used for validation while developing. For purposes of final grading can be ignored. Preserved to provide additional insight to my process.   | 
| ├── avlTree*            | a set of .dot and .png files used to create a GraphViz representation of the AVL Tree sorted default, high -> low  | 
| └── avlTreeLH*           | a set of .dot and .png files used to create a GraphViz representation of the AVL Tree sorted default, low -> high   | 
| __app_demo\\__                 | __Demo application folder__ 
| __├── main_demo.cpp__            | __Main app that creates multiple AVL Trees and demonstrates all of the primary I've created. This app can be run locally as part of grading.__    | 
| __├── ppg\\__            | __Folder containing .dot and .png files representing the AVL Trees created in the Points Per Game Demo section of code__    | 
| __├── topg\\__            | __Folder containing .dot and .png files representing the AVL Trees created in the Turnovers Per Game Demo section of code__    | 
| __└── very_large_avl_tree\\__            | __Folder containing .dot and .png files representing the AVL Trees created in the Very large AVL Tree Demo section of code__    | 
| __build\\__              | __Build folder to build the project. Will need to use CMake here__ |
| __code\\__               | __CPP and Header Files.__   
| __├── AVLTree.cpp__      | __AVLTree class source file__  |
| __└── AVLTree.h__        | __AVLTree class heather file__ |
| tests\              | Tests folder - did not get a chance to implement  |
| test_.cpp | Place holder for future iteration   |


### Project Features Overview ###
* Advanced Data Structure Implementation
  * Implementation of an AVL Tree, a self-balancing binary search tree, ensuring optimal balance and efficiency in operations.
  * Customizable sorting order (high-to-low or low-to-high) for organizing player statistics, demonstrating versatility in data handling.
* PlayerStats Integration
  * Incorporation of a PlayerStats class within each AVL Tree node, containing player-specific information like name, team, position, and a key statistical value.
  * Flexible data model design, allowing for easy adaptation and extension to different types of player statistics.
* Core AVL Tree Operations
  * Efficient insertion algorithm that maintains the tree's balance after each addition, ensuring logarithmic operation time.
  * Removal function capable of handling various scenarios including leaf nodes, nodes with one child, and nodes with two children, while maintaining tree balance.
  * Find function to search for nodes based on statistical value, showcasing the tree's quick lookup capabilities.
* Self-Balancing Mechanism
  * Implementation of AVL rotations (Right, Left, Right-Left, Left-Right) to ensure the tree remains balanced after insertions and deletions.
  * Balancing logic that dynamically adjusts the tree structure, maintaining its invariants and optimizing search paths.
* Utility and Visualization Functions
  * In-order traversal function for displaying player statistics in sorted order, useful for verifying the tree's structure and balance.
  * Tree visualization support through GraphViz integration, enabling graphical representation of the tree's structure and balance factors.
  * Export function to generate .dot files for visualizing the AVL Tree, providing a clear and immediate representation of its current state.
* Demonstration and Testing
  * Practical demonstration of AVL Tree functionalities in different scenarios, including handling of large datasets and real-time updates.
  * Error handling for duplicate node insertions, enhancing the robustness of the data structure.
  * Comprehensive test cases in the main demonstration file (__main_demo.cpp__), covering a range of functionalities such as insertion, removal, searching, and visualization.



### Local Execution Guide for main_demo.cpp ###
In case you encounter any difficulties in running the program locally, all the generated files are included for your reference. The only aspect missing would be the live terminal output.

A feature of this project is its ability to generate .png images to visually represent the AVL Trees. This functionality leverages a widely-used package called GraphViz, which can be found at [Graphviz's official website](https://graphviz.org/).

#### Installing GraphViz on Unix Systems: ####
To install GraphViz on a Unix system, use the following commands:
```
sudo apt-get update
sudo dnf install graphviz
```
#### Building the Application: ####
1. First, navigate to the build directory and run cmake. This step generates the necessary makefiles:
```
cd [path to cloned location]/term-project-byrne-saw/build
cmake .
```
2. Following this, compile the application using make to build the executable from the source code:
```
make
```
#### Running the Application: ####

Once the build process is complete, you will find a local executable named __run_app_demo__. Running this file will execute the code from main_demo.cpp, allowing you to observe the AVL Tree operations in action.