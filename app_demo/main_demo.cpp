#include "../code/AVLTree.h"
#include <random>
#include <chrono>
#include <ctime>

// function to generate random float between min and max
float getRandomFloat(float min, float max) {
    // Use random_device to seed the random number generator
    random_device rd;
    // Mersenne Twister: Good quality random number generator
    mt19937 rng(rd());
    // Uniform distribution in range [min, max]
    uniform_real_distribution<float> uni(min, max);
    return uni(rng);
}

// getting current epoch time as a string for use in GraphViz file names
string getCurrentEpochTimeAsString() {
    // Get the current time as a time_point
    auto now = chrono::system_clock::now();
    // Convert to a duration since the epoch
    auto epoch = now.time_since_epoch();
    // Narrow the duration to seconds
    auto value = std::chrono::duration_cast<std::chrono::seconds>(epoch);
    // Convert to string
    return to_string(value.count());
}

int main() {
    cout << endl << "##################################################################"  << endl;
    cout << "                  Begin Points Per Game (PPG) demo" << endl;
    cout << "##################################################################"  << endl << endl;
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

    // List the stats in order
    cout << "Listing the stats in order" << endl << "..." << endl;

    PPG.displayStats();

    cout << "------------------------------------" << endl;

    // Remove the first node, the last node, and a middle node by statValue
    cout << "Removing the first node from PPG by statValue of 39.75f" << endl << "..." << endl;

    PPG.remove(39.75f);
    cout << "Removing the last node from PPG by statValue of 25.31f" << endl << "..." << endl;
    PPG.remove(25.31f);
    cout << "Removing a middle node from PPG by statValue of 32.42f" << endl << "..." << endl;
    PPG.remove(32.42f);

    cout << "------------------------------------" << endl;
    cout << "Displaying the stats in order after removals" << endl;
    cout << "and creating a visual representation of the AVL tree" << "..." << endl;

    PPG.displayStats();

    cout << endl;
    PPG.exportToDot("../app_demo/ppg/ppg_02__3_removals.dot");

    cout << "../app_demo/ppg/ppg_02__3_removals.dot and ppg_02__3_removals.png created" << endl;
    cout << "------------------------------------" << endl;





    cout << endl << "##################################################################"  << endl;
    cout << "                  Begin Turnovers Per Game (TOPG) Demo" << endl;
    cout << "##################################################################"  << endl << endl;
    /* 
    Turnovers Per Game (TOPG)

        This section demonstrates:
            - Creating an AVLTree instance to track a low to high sorted stat
            - Inserting nodes into the AVLTree in random order
            - After every insertion a visual GraphViz representation of the AVLTree is created
            
    */ 

    // Create an AVLTree instance to track TOPG
    cout << "Creating an AVLTree instance to track TOPG" << endl << "..." << endl;
    
    AVLTree TOPG(false);
    
    cout << "AVLTree TOPG instance created" << endl;
    cout << "------------------------------------" << endl;   

    // Insert 25 PlayerStats into the TOPG and create a visual representation of TOPG after each insertion
    cout << "Inserting 25 PlayerStats into the TOPG and creating 25 visualizations" << endl << "..." << endl;

    TOPG.insert(PlayerStats("Richard Jones", "Earth Enforcers", "Power Forward", 0.15f));
    TOPG.exportToDot("../app_demo/topg/topg_01__1_insert.dot");
    TOPG.insert(PlayerStats("John Smith", "Earth Enforcers", "Power Forward", 1.95f));
    TOPG.exportToDot("../app_demo/topg/topg_01__2_inserts.dot");
    TOPG.insert(PlayerStats("William Davis", "Pluto Pirates", "Center", 0.24f));
    TOPG.exportToDot("../app_demo/topg/topg_01__3_inserts.dot");
    TOPG.insert(PlayerStats("Robert Williams", "Neptune Ninjas", "Center", 2.42f));
    TOPG.exportToDot("../app_demo/topg/topg_01__4_inserts.dot");
    TOPG.insert(PlayerStats("Robert Miller", "Earth Enforcers", "Center", 0.87f));
    TOPG.exportToDot("../app_demo/topg/topg_01__5_inserts.dot");
    TOPG.insert(PlayerStats("James Moore", "Mercury Monarchs", "Small Forward", 2.07f));
    TOPG.exportToDot("../app_demo/topg/topg_01__6_inserts.dot");
    TOPG.insert(PlayerStats("Charles Taylor", "Earth Enforcers", "Shooting Guard", 1.0f));
    TOPG.exportToDot("../app_demo/topg/topg_01__7_inserts.dot");
    TOPG.insert(PlayerStats("Robert Wilson", "Earth Enforcers", "Center", 1.18f));
    TOPG.exportToDot("../app_demo/topg/topg_01__8_inserts.dot");
    TOPG.insert(PlayerStats("William Smith", "Jupiter Giants", "Power Forward", 2.05f));
    TOPG.exportToDot("../app_demo/topg/topg_01__9_inserts.dot");
    TOPG.insert(PlayerStats("Robert Davis", "Earth Enforcers", "Small Forward", 0.56f));
    TOPG.exportToDot("../app_demo/topg/topg_01__10_inserts.dot");
    TOPG.insert(PlayerStats("David Smith", "Earth Enforcers", "Center", 0.22f));
    TOPG.exportToDot("../app_demo/topg/topg_01__11_inserts.dot");
    TOPG.insert(PlayerStats("Thomas Johnson", "Quantum Quakers", "Shooting Guard", 2.5f));
    TOPG.exportToDot("../app_demo/topg/topg_01__12_inserts.dot");
    TOPG.insert(PlayerStats("Charles Miller", "Mars Mavericks", "Small Forward", 2.28f));
    TOPG.exportToDot("../app_demo/topg/topg_01__13_inserts.dot");
    TOPG.insert(PlayerStats("Joseph Taylor", "Quantum Quakers", "Shooting Guard", 2.18f));
    TOPG.exportToDot("../app_demo/topg/topg_01__14_inserts.dot");
    TOPG.insert(PlayerStats("Charles Williams", "Pluto Pirates", "Power Forward", 0.02f));
    TOPG.exportToDot("../app_demo/topg/topg_01__15_inserts.dot");
    TOPG.insert(PlayerStats("Charles Brown", "Earth Enforcers", "Shooting Guard", 1.7f));
    TOPG.exportToDot("../app_demo/topg/topg_01__16_inserts.dot");
    TOPG.insert(PlayerStats("Charles Davis", "Venus Vikings", "Point Guard", 0.96f));
    TOPG.exportToDot("../app_demo/topg/topg_01__17_inserts.dot");
    TOPG.insert(PlayerStats("James Davis", "Neptune Ninjas", "Point Guard", 0.25f));
    TOPG.exportToDot("../app_demo/topg/topg_01__18_inserts.dot");
    TOPG.insert(PlayerStats("James Taylor", "Quantum Quakers", "Point Guard", 0.62f));
    TOPG.exportToDot("../app_demo/topg/topg_01__19_inserts.dot");
    TOPG.insert(PlayerStats("David Johnson", "Mars Mavericks", "Shooting Guard", 1.06f));
    TOPG.exportToDot("../app_demo/topg/topg_01__20_inserts.dot");
    TOPG.insert(PlayerStats("David Moore", "Jupiter Giants", "Power Forward", 0.32f));
    TOPG.exportToDot("../app_demo/topg/topg_01__21_inserts.dot");
    TOPG.insert(PlayerStats("John Wilson", "Galactic Gladiators", "Point Guard", 2.26f));
    TOPG.exportToDot("../app_demo/topg/topg_01__22_inserts.dot");
    TOPG.insert(PlayerStats("Thomas Jones", "Galactic Gladiators", "Shooting Guard", 2.45f));
    TOPG.exportToDot("../app_demo/topg/topg_01__23_inserts.dot");
    TOPG.insert(PlayerStats("John Taylor", "Neptune Ninjas", "Shooting Guard", 1.49f));
    TOPG.exportToDot("../app_demo/topg/topg_01__24_inserts.dot");
    TOPG.insert(PlayerStats("Charles Moore", "Saturn Spartans", "Point Guard", 2.19f));
    TOPG.exportToDot("../app_demo/topg/topg_01__25_inserts.dot");
    
    cout << "25 PlayerStats inserted into the TOPG and 25 visualizations created " << endl;
    cout << "------------------------------------" << endl;






    cout << endl << "##################################################################"  << endl;
    cout << "                  Begin Very large AVL Tree Demo" << endl;
    cout << "##################################################################"  << endl << endl;
    /*
    Very large AVL Tree

        This section demonstrates:
            - Mocking up the creation of a very large AVLTree
            - Creating a visual GraphViz representation of the AVLTree periodically to demonstrate
                the adherence to the AVLTree invariants 
            - These trees are randomly created every time the program is run, GraphViz files
                are created with timestamps appended by a _int to prevent overwriting
    */
    // Set variables used for random value generation and a time indicator for the GraphViz files
    float min = 0.0f;
    float max = 1000.0f;
    string now = getCurrentEpochTimeAsString();
    // Create an AVLTree instance
    cout << "Creating an AVLTree instance to track a very large AVLTree" << endl << "..." << endl;

    AVLTree veryLargeAVLTree;

    cout << "AVLTree veryLargeAVLTree instance created" << endl;
    cout << "------------------------------------" << endl;

    // insert 25 nodes with random statValues into veryLargeAVLTree
    // for this demonstration we won't populate name, team, or position
    // it's possible (but unlikely) that a duplicate node will be inserted, in which case
    // an error message will be written to the terminal and the node will not be inserted
    cout << "Inserting 25 random PlayerStats into the veryLargeAVLTree" << endl << "..." << endl;

    for (int i = 0; i < 25; i++) {
        veryLargeAVLTree.insert(PlayerStats("", "", "", getRandomFloat(min, max)));
    }

    cout << "25 random PlayerStats inserted into the veryLargeAVLTree" << endl;
    cout << "------------------------------------" << endl;

    // Create a visual representation of the AVLTree
    cout << "Creating a visual representation of the veryLargeAVLTree after 25 insertions" << endl << "..." << endl;

    veryLargeAVLTree.exportToDot("../app_demo/very_large_avl_tree/very_large_avl_tree_01__25_inserts_" + now + ".dot");

    cout << "../app_demo/very_large_avl_tree/very_large_avl_tree_01__25_inserts_" + now + ".dot and very_large_avl_tree_01__25_inserts_" + now + ".png created" << endl;
    cout << "------------------------------------" << endl;

    // insert 55 more nodes with random statValues into veryLargeAVLTree
    cout << "Inserting 55 random PlayerStats into the veryLargeAVLTree" << endl << "..." << endl;

    for (int i = 0; i < 55; i++) {
        veryLargeAVLTree.insert(PlayerStats("", "", "", getRandomFloat(min, max)));
    }

    cout << "55 random PlayerStats inserted into the veryLargeAVLTree" << endl;
    cout << "------------------------------------" << endl;

    // Create a visual representation of the AVLTree
    cout << "Creating a visual representation of the veryLargeAVLTree after 80 insertions" << endl << "..." << endl;

    veryLargeAVLTree.exportToDot("../app_demo/very_large_avl_tree/very_large_avl_tree_02__80_inserts_" + now + ".dot");

    cout << "../app_demo/very_large_avl_tree/very_large_avl_tree_02__80_inserts_" + now + ".dot and very_large_avl_tree_02__80_inserts_" + now + ".png created" << endl;
    cout << "------------------------------------" << endl;

    // insert 1000 more nodes with random statValues into veryLargeAVLTree
    cout << "Inserting 1000 random PlayerStats into the veryLargeAVLTree" << endl << "..." << endl;

    for (int i = 0; i < 1000; i++) {
        veryLargeAVLTree.insert(PlayerStats("", "", "", getRandomFloat(min, max)));
    }

    cout << "1000 random PlayerStats inserted into the veryLargeAVLTree" << endl;
    cout << "------------------------------------" << endl;

    // Create a visual representation of the AVLTree
    cout << "Creating a visual representation of the veryLargeAVLTree after 1080 insertions" << endl << "..." << endl;

    veryLargeAVLTree.exportToDot("../app_demo/very_large_avl_tree/very_large_avl_tree_03__1080_inserts_" + now + ".dot");

    cout << "../app_demo/very_large_avl_tree/very_large_avl_tree_03__1080_inserts_" + now + ".dot and very_large_avl_tree_03__1080_inserts_" + now + ".png created" << endl;
    cout << "------------------------------------" << endl;


    return 0;
}


