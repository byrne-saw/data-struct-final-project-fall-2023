#include "../code/AVLTree.h"

int main() {
    /*
    Points Per Game (PPG)

        This section demonstrates:
            - Creating an AVLTree instance to track a high to low sorted stat
            - Inserting 25 nodes into the AVLTree in random order
                - Displaying an error message if a duplicate node is inserted
            - Using the Find Function to find a node by statValue
                - demonstrating both a found node and a not found node
            - Creating a visual GraphViz representation of the AVLTree with all nodes added
            - Listing the stats in order with all nodes added
            - Removing a node from the AVLTree by statValue
            - Creating a visual GraphViz representation of the AVLTree after a node has been removed
            - Listing the stats in order after a node has been removed
    */

    cout << "Begin begin Points Per Game (PPG) demo" << endl << endl;
    

    // Create an AVLTree instance to track PPG
    cout << "Creating an AVLTree instance to track PPG" << endl << "..." << endl;
    AVLTree PPG;
    cout << "AVLTree PPG instance created" << endl;
    cout << "------------------------------------" << endl;

    // Insert 25 PlayerStats into the PPG
    cout << "Inserting 25 PlayerStats into the PPG" << endl << "..." << endl;

    PPG.insert(PlayerStats("Robert Brown", "Galactic Gladiators", "Center", 25.42f));
    PPG.insert(PlayerStats("Richard Jones", "Quantum Quakers", "Shooting Guard", 25.31f));
    PPG.insert(PlayerStats("James Williams", "Neptune Ninjas", "Point Guard", 32.42f));
    PPG.insert(PlayerStats("Michael Williams", "Mars Mavericks", "Point Guard", 38.65f));
    PPG.insert(PlayerStats("Richard Davis", "Saturn Spartans", "Shooting Guard", 35.9f));
    PPG.insert(PlayerStats("John Johnson", "Galactic Gladiators", "Point Guard", 35.03f));
    PPG.insert(PlayerStats("John Moore", "Neptune Ninjas", "Center", 33.91f));
    PPG.insert(PlayerStats("Thomas Smith", "Pluto Pirates", "Power Forward", 39.75f));
    PPG.insert(PlayerStats("William Davis", "Venus Vikings", "Point Guard", 38.83f));
    PPG.insert(PlayerStats("Thomas Moore", "Mars Mavericks", "Point Guard", 26.63f));
    PPG.insert(PlayerStats("Michael Jones", "Mars Mavericks", "Shooting Guard", 28.9f));
    PPG.insert(PlayerStats("Thomas Williams", "Venus Vikings", "Power Forward", 39.5f));
    PPG.insert(PlayerStats("Joseph Moore", "Neptune Ninjas", "Point Guard", 29.1f));
    PPG.insert(PlayerStats("Michael Davis", "Jupiter Giants", "Power Forward", 28.09f));
    PPG.insert(PlayerStats("William Smith", "Earth Enforcers", "Small Forward", 33.39f));
    PPG.insert(PlayerStats("Thomas Wilson", "Venus Vikings", "Small Forward", 27.01f));
    PPG.insert(PlayerStats("James Davis", "Galactic Gladiators", "Point Guard", 31.77f));
    PPG.insert(PlayerStats("Joseph Davis", "Pluto Pirates", "Power Forward", 28.98f));
    PPG.insert(PlayerStats("David Brown", "Neptune Ninjas", "Power Forward", 31.78f));
    PPG.insert(PlayerStats("Charles Miller", "Jupiter Giants", "Power Forward", 36.79f));
    PPG.insert(PlayerStats("John Wilson", "Galactic Gladiators", "Point Guard", 35.72f));
    PPG.insert(PlayerStats("John Miller", "Earth Enforcers", "Shooting Guard", 36.01f));
    PPG.insert(PlayerStats("Thomas Johnson", "Jupiter Giants", "Small Forward", 31.5f));
    PPG.insert(PlayerStats("Robert Moore", "Mercury Monarchs", "Center", 37.9f));
    PPG.insert(PlayerStats("James Smith", "Venus Vikings", "Small Forward", 27.85f));
    
    cout << "25 PlayerStats inserted into the PPG" << endl;
    cout << "------------------------------------" << endl;

    // Attempt to insert a duplicate 
    cout << "Attempting to insert a duplicate PlayerStats into the PPG" << endl << "..." << endl;

    PPG.insert(PlayerStats("James Smith", "Venus Vikings", "Small Forward", 27.85f));

    cout << endl << "Duplicate PlayerStats not inserted into the PPG" << endl;
    cout << "------------------------------------" << endl;

    // Create a visual representation of the AVLTree
    cout << "Creating a visual representation of the AVLTree" << endl << "..." << endl;
    PPG.exportToDot("../app_demo/ppg/ppg_01__25_inserts.dot");

    cout << "../app_demo/ppg/ppg_01__25_inserts.dot and ppg_01__25_inserts.png created" << endl;
    cout << "------------------------------------" << endl;

    // Using the Find Function to find a node by statValue
    cout << "Using the Find Function to find a node by statValue of 35.72f" << endl << "..." << endl;

    float searchStatValue = 35.72f;
    PlayerStats* foundPlayer = PPG.find(searchStatValue);
    if (foundPlayer != nullptr) {
        cout << "Found player with statValue " << searchStatValue << ": " << foundPlayer->name << endl;
    } else {
        cout << "No player found with statValue " << searchStatValue << endl;
    }

    cout << "------------------------------------" << endl;

    cout << "Using the Find Function to find a node by statValue of 35.72f" << endl << "..." << endl;

    searchStatValue = 35.72f;
    if (foundPlayer != nullptr) {
        cout << "Found player with statValue " << searchStatValue << ": " << foundPlayer->name << endl;
    } else {
        cout << "No player found with statValue " << searchStatValue << endl;
    }

    cout << "------------------------------------" << endl;

    











   /* 
   Turnovers Per Game (TOPG)

        This section demonstrates:
            - Creating an AVLTree instance to track a low to high sorted stat
            - Inserting nodes into the AVLTree in random order
            - After every insertion a visual GraphViz representation of the AVLTree is created
            
   */ 

  /*
  Very large AVL Tree

        This section demonstrates:
            - Mocking up the creation of a very large AVLTree
            - Creating a visual GraphViz representation of the AVLTree periodically to demonstrate
                the adherence to the AVLTree invariants 
            - These trees are randomly created every time the program is run, GraphViz files
                are created with timestamps appended by a _int to prevent overwriting
  */
    return 0;
}


