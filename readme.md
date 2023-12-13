# AVL Tree for NBA Player Statistics Management System
## CSPB 2270 – Data Structures - Term Project
Author: Andrew Byrnes  
CU ID: anby7602  
GitHub Username: byrne-saw  


## Project Proposal  

### Summary  
The objective of this project is to design and implement a C++ data management system that employs at least one AVL Tree for the efficient storage and retrieval of NBA player statistics. The system will prioritize swift operations such as the addition, deletion, and updating of player statistics, along with the prompt retrieval of player rankings based on specified criteria.

The Minimum Viable Product (MVP) for this endeavor entails the development of an AVL Tree data structure, accompanied by a main.cpp file to demonstrate functionality. The MVP will also incorporate a suite of unit tests designed to verify the accurate performance of all functions.

Should time allow, the project's scope will be broadened to include the ability to serialize the AVL Tree into a CSV file and deserialize it back to reconstruct or "load" the AVL Tree, thereby ensuring persistence of data across sessions.

The ambitious stretch goal includes the creation of a user-friendly command-line interface (CLI) that would allow a user to interact with and modify various statistics, ensuring the data's persistence between sessions.

### Problem Statement
From the perspective of live sports broadcasting, there is a critical need for generating and updating player statistics instantaneously. The system must be capable of rapid data manipulation to reflect real-time performance metrics presented during broadcasts accurately. This project proposes the development of a system that could meet these requirements by utilizing an AVL Tree for efficient statistic management, ensuring that viewers receive accurate and current performance data without perceptible delay.

### Proposed Data Structure

The **AVL Tree** is the chosen data structure for this project. It is a self-balancing binary search tree that maintains its balance with a complexity of O(log n) for insertion, deletion, and lookup operations, making it ideal for our needs. Each node in the AVL Tree will contain a PlayerStats object, which includes the player's name, team, position, and the primary statistic the tree tracks.

### Alternative Data Structures Considered:

**Hash Tables**: While quick with an average time complexity of O(1) for search, insert, and delete, they do not maintain order, making it difficult to retrieve sorted data.

**Red-Black Trees**: Similar to AVL trees in terms of balance and order, but AVL trees have stricter balancing, making them faster for lookup-intensive applications, which is essential for our project.

### Implementation Plan

The implementation will be divided into the following components:

* AVL Tree Construction: Nodes will be defined to hold player statistics, with functions for insertion, deletion, and rebalancing.

* Serialization/Deserialization: Implement functionality to serialize the AVL tree into a CSV format and deserialize the CSV back into an AVL tree, maintaining the correct structure and balance of the tree.

* Command-Line Interface: Develop a CLI that will allow users to perform operations such as adding a new stat, adding/removing/updating players, and saving/loading the tree state to and from a CSV file.

### Member Functions and API

The following member functions will be implemented:

* **insert(PlayerStats)**: Insert a new player or update stats if the player exists.  
* **remove(std::string playerName)**: Remove a player from the tree.  
* **find(std::string playerName)**: Retrieve player stats.  
* **serialize(std::ofstream&)**: Save the current state of the AVL tree to a CSV file.  
* **deserialize(std::ifstream&)**: Load the AVL tree state from a CSV file.  
* **displayStats()**: Display player stats in a sorted manner based on the selected statistic.  

### Testing and Validation

Unit tests will be written to ensure each component functions correctly. These will include tests for:

* Insertion, removal, and retrieval operations.  
* AVL property (balance factor) maintenance.  
* Serialization and deserialization accuracy.  
* CLI operation verifications.  

### Definition of "Done"
MVP:
* The AVL Tree is fully functional with the ability to add, remove, and update player stats, and quickly retrieve rankings.  

If Time allows: 
* The system can save the current state to a CSV file and load from it, preserving the AVL Tree structure and its balance.

Stretch goal:  
* The CLI allows users to perform all intended operations, including creating new stats categories, modifying player information, and managing the persistent storage through save/load operations.

### Conclusion

This project will result in a robust NBA Player Statistics Management System that leverages the AVL Tree data structure for efficient data manipulation and retrieval, coupled with a persistent storage solution and an intuitive command-line interface for ease of use. The system will meet the demands of quick data access and modification, which is essential in a sports statistics context.

## Notes while working on the Project

* I didn't consider duplicate values .... will move forward for now returning an error if a dupe is attempted to be inserted
  * could potentially treat nodes as buckets and use a vector to store multiple player stats
* Initially gave no consideration to different stats making sense in specific directions; Turnovers (low->high), Points (high->low)
  * Implemented an additional member on AVL tree defaulting to true
