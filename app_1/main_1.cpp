#include <iostream>
#include <fstream>

#include "../code_1/AVLTree.h"

using namespace std;

int main() {
    // Create an AVLTree instance
    AVLTree avlTree;

    // Insert some PlayerStats into the AVLTree
    avlTree.insert(PlayerStats("Alice", "TeamA", "Forward", 15.5f));
    avlTree.exportToDot("../app_1/avlTree1.dot");
    avlTree.insert(PlayerStats("Bob", "TeamB", "Midfielder", 10.0f));
    avlTree.exportToDot("../app_1/avlTree2.dot");
    avlTree.insert(PlayerStats("Charlie", "TeamC", "Defender", 12.0f));
    avlTree.insert(PlayerStats("David", "TeamD", "Goalkeeper", 8.0f));
    avlTree.insert(PlayerStats("Eve", "TeamE", "Forward", 9.0f));
    avlTree.insert(PlayerStats("Frank", "TeamF", "Midfielder", 7.0f));
    avlTree.insert(PlayerStats("Grace", "TeamG", "Defender", 6.0f));
    avlTree.insert(PlayerStats("Heidi", "TeamH", "Goalkeeper", 5.0f));
    avlTree.insert(PlayerStats("Ivan", "TeamI", "Forward", 4.0f));
    avlTree.insert(PlayerStats("Judy", "TeamJ", "Midfielder", 3.0f));
    avlTree.insert(PlayerStats("Kevin", "TeamK", "Defender", 2.0f));
    avlTree.insert(PlayerStats("Linda", "TeamL", "Goalkeeper", 1.0f));
    avlTree.exportToDot("../app_1/avlTree.dot");


    // Attempt to insert a duplicate (should show an error)
    avlTree.insert(PlayerStats("Duplicate", "TeamD", "Goalkeeper", 10.0f));

    // Display the stats in the AVL Tree
    std::cout << "Displaying Player Stats:" << std::endl;
    avlTree.displayStats();

    // Find a player by statValue
    float searchStatValue = 10.0f;
    PlayerStats* foundPlayer = avlTree.find(searchStatValue);
    if (foundPlayer != nullptr) {
        std::cout << "Found player with statValue " << searchStatValue << ": " << foundPlayer->name << std::endl;
    } else {
        std::cout << "No player found with statValue " << searchStatValue << std::endl;
    }

    // Remove a player by statValue
    float statValueToRemove = 10.0f;
    avlTree.remove(statValueToRemove);
    std::cout << "After removing player with statValue " << statValueToRemove << ":" << std::endl;
    avlTree.displayStats();
    avlTree.displayTree();

    ////////

    // Create an AVLTree instance with low-to-high sorting
    AVLTree avlTreeLH(false);

    // Insert some PlayerStats into the avlTreeLH
    avlTreeLH.insert(PlayerStats("Alice", "TeamA", "Forward", 15.5f));
    avlTreeLH.insert(PlayerStats("Bob", "TeamB", "Midfielder", 10.0f));
    avlTreeLH.insert(PlayerStats("Charlie", "TeamC", "Defender", 12.0f));
    avlTreeLH.insert(PlayerStats("David", "TeamD", "Goalkeeper", 8.0f));
    avlTreeLH.insert(PlayerStats("Eve", "TeamE", "Forward", 9.0f));
    avlTreeLH.insert(PlayerStats("Frank", "TeamF", "Midfielder", 7.0f));
    avlTreeLH.exportToDot("../app_1/avlTreeLH.dot");

    // Attempt to insert a duplicate (should show an error)
    avlTreeLH.insert(PlayerStats("Duplicate", "TeamD", "Goalkeeper", 10.0f));

    // Display the stats in the AVL Tree
    std::cout << "Displaying Player Stats:" << std::endl;
    avlTreeLH.displayStats();

    // Find a player by statValue
    float searchStatValueLH = 10.0f;
    PlayerStats* foundPlayerLH = avlTreeLH.find(searchStatValueLH);
    if (foundPlayerLH != nullptr) {
        std::cout << "Found player with statValue " << searchStatValueLH << ": " << foundPlayerLH->name << std::endl;
    } else {
        std::cout << "No player found with statValue " << searchStatValueLH << std::endl;
    }

    // Remove a player by statValue
    float statValueToRemoveLH = 10.0f;
    avlTreeLH.remove(statValueToRemoveLH);
    std::cout << "After removing player with statValue " << statValueToRemoveLH << ":" << std::endl;
    avlTreeLH.displayStats();
    avlTreeLH.displayTree();

    return 0;
}


