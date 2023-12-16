#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>
#include <functional>
#include <memory>
#include <iostream>

using namespace std;

// PlayerStats structure definition
struct PlayerStats {
    string name;
    string team;
    string position;
    float statValue;

    // Constructor declaration
    PlayerStats(const string& playerName, const string& playerTeam, 
                const string& playerPosition, float value);
    PlayerStats();
};

// Node structure for AVL Tree
struct AVLNode {
    PlayerStats data;
    shared_ptr<AVLNode> left;
    shared_ptr<AVLNode> right;
    int height;

    // Constructor for AVLNode
    AVLNode(const PlayerStats& playerData);
};

// AVLTree class definition
class AVLTree {
public:
    AVLTree(bool highToLow);
    AVLTree();
    ~AVLTree() = default;

    void insert(const PlayerStats& player);
    void remove(float statValue);
    PlayerStats* find(float statValue) const;
    void displayStats() const;
    void displayTree() const;
    void exportToDot(const string& filename) const;
    

private:
    shared_ptr<AVLNode> root;
    bool isHighToLow; // True for high-to-low sorting of statValue, false for low-to-high
    
    // Helper functions for AVL operations
    int getHeight(shared_ptr<AVLNode> node) const;
    int getBalanceFactor(shared_ptr<AVLNode> node) const;
    shared_ptr<AVLNode> minValueNode(shared_ptr<AVLNode> node);
    shared_ptr<AVLNode> rightRotate(shared_ptr<AVLNode> y);
    shared_ptr<AVLNode> leftRotate(shared_ptr<AVLNode> x);
    shared_ptr<AVLNode> insertNode(shared_ptr<AVLNode> node, const PlayerStats& player);
    shared_ptr<AVLNode> removeNode(shared_ptr<AVLNode> node, float statValue);
    shared_ptr<AVLNode> rebalanceTree(shared_ptr<AVLNode> node);
    void inOrderTraversal(shared_ptr<AVLNode> node, function<void(const PlayerStats&)> func) const;
    
    void displayTreeHelper(shared_ptr<AVLNode> node, int space) const;
    void generateDotRepresentation(shared_ptr<AVLNode> node, ostream& file) const;
};

#endif // AVL_TREE_H