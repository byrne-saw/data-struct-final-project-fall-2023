#include "AVLTree.h"

// PlayerStats constructor definition
PlayerStats::PlayerStats(const string& playerName, const string& playerTeam, 
                         const string& playerPosition, float value) {
    name = playerName;
    team = playerTeam;
    position = playerPosition;
    statValue = value;
}

PlayerStats::PlayerStats() {
    name = "";
    team = "";
    position = "";
    statValue = 0.0f;
}

// AVLNode constructor
AVLNode::AVLNode(const PlayerStats& playerData) {
    data = playerData;
    left = nullptr;
    right = nullptr;
    height = 1;
}

// AVLTree constructor
AVLTree::AVLTree(bool highToLow) {
    root = nullptr;
    isHighToLow = highToLow;
}
AVLTree::AVLTree() {
    root = nullptr;
    isHighToLow = true;
}


// Insert function
void AVLTree::insert(const PlayerStats& player) {
    root = insertNode(root, player);
}

// Remove function
void AVLTree::remove(float statValue) {
    root = removeNode(root, statValue);
}

// Find function
PlayerStats* AVLTree::find(float statValue) const {
    // Start searching from the root
    shared_ptr<AVLNode> current = root;
    while (current != nullptr) {
        // Check if current node's data matches the statValue
        if (current->data.statValue == statValue) {
            return &(current->data);
        } else {
            // Decide the direction of traversal based on isHighToLow flag
            if ((isHighToLow && statValue > current->data.statValue) || 
                (!isHighToLow && statValue < current->data.statValue)) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }
    return nullptr; // Return nullptr if a player with the given statValue is not found
}

// Display function
void AVLTree::displayStats() const {
    inOrderTraversal(root, [](const PlayerStats& player) {
        cout << player.name << " - " << player.statValue << endl;
    });
}

// Helper functions implementation

int AVLTree::getHeight(shared_ptr<AVLNode> node) const {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVLTree::getBalanceFactor(shared_ptr<AVLNode> node) const {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

shared_ptr<AVLNode> AVLTree::rightRotate(shared_ptr<AVLNode> y) {
    // Get the left child of y
    shared_ptr<AVLNode> x = y->left;
    shared_ptr<AVLNode> T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

shared_ptr<AVLNode> AVLTree::leftRotate(shared_ptr<AVLNode> x) {
    // Get the right child of x
    shared_ptr<AVLNode> y = x->right;
    shared_ptr<AVLNode> T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

shared_ptr<AVLNode> AVLTree::minValueNode(shared_ptr<AVLNode> node) {
    shared_ptr<AVLNode> current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

shared_ptr<AVLNode> AVLTree::insertNode(shared_ptr<AVLNode> node, const PlayerStats& player) {
    if (node == nullptr) {
        return make_shared<AVLNode>(player);
    }

    if ((isHighToLow && player.statValue > node->data.statValue) ||
        (!isHighToLow && player.statValue < node->data.statValue)) {
        node->left = insertNode(node->left, player);
    } else if ((isHighToLow && player.statValue < node->data.statValue) ||
               (!isHighToLow && player.statValue > node->data.statValue)) {
        node->right = insertNode(node->right, player);
    } else {
        cout << "Error: A player with statValue " << player.statValue << " already exists." << endl;
        return node;
    }

    // Update the height of the node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Use rebalanceTree to balance the AVL tree
    return rebalanceTree(node);
}

shared_ptr<AVLNode> AVLTree::removeNode(shared_ptr<AVLNode> node, float statValue) {
    if (node == nullptr) {
        return node;
    }

    // Navigate to the node to be removed based on statValue
    if ((isHighToLow && statValue > node->data.statValue) ||
        (!isHighToLow && statValue < node->data.statValue)) {
        node->left = removeNode(node->left, statValue);
    } else if ((isHighToLow && statValue < node->data.statValue) ||
               (!isHighToLow && statValue > node->data.statValue)) {
        node->right = removeNode(node->right, statValue);
    } else {
        // Node with only one child or no child
        if (node->left == nullptr || node->right == nullptr) {
            shared_ptr<AVLNode> temp = node->left ? node->left : node->right;

            // No child case
            if (temp == nullptr) {
                return nullptr;
            } else { // One child case
                return temp; // Return the non-empty child
            }
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            shared_ptr<AVLNode> temp = minValueNode(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = removeNode(node->right, temp->data.statValue);
        }
    }

    // Update the height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Rebalance the tree
    return rebalanceTree(node);
}

shared_ptr<AVLNode> AVLTree::rebalanceTree(shared_ptr<AVLNode> node) {
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && getBalanceFactor(node->left) >= 0) {
        return rightRotate(node);
    }

    // Left Right Case
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(node->right) <= 0) {
        return leftRotate(node);
    }

    // Right Left Case
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::inOrderTraversal(shared_ptr<AVLNode> node, function<void(const PlayerStats&)> func) const {
    if (node != nullptr) {
        inOrderTraversal(node->left, func);
        func(node->data);
        inOrderTraversal(node->right, func);
    }
}

void AVLTree::displayTree() const {
    displayTreeHelper(root, 0);
}

void AVLTree::displayTreeHelper(shared_ptr<AVLNode> node, int depth) const {
    if (node == nullptr) {
        return;
    }

    // Increase depth for sub-levels
    int newDepth = depth + 4;

    // Process right child first (tree will be displayed with root on left)
    displayTreeHelper(node->right, newDepth);

    // Print current node
    if (depth > 0) {
        std::cout << std::setw(depth) << ' ';
    }
    std::cout << node->data.statValue << std::endl;

    // Process left child
    displayTreeHelper(node->left, newDepth);
}

void AVLTree::generateDotRepresentation(shared_ptr<AVLNode> node, ostream& out) const {
    static int nodeId = 0;
    int balanceFactor = getBalanceFactor(node);

    if (!node) return;

    // Define the current node
    int currentNodeId = nodeId++;
    out << "    node" << currentNodeId << " [label=\"" 
        << node->data.statValue << "\\n" 
        << "(" + to_string(balanceFactor) + ")" << "\\n"
        << node->data.name
        << "\\n" << node->data.team << "\\n" << node->data.position << "\"];\n";

    if (node->left) {
        // Define the left child and the edge to it
        int leftChildId = nodeId;
        generateDotRepresentation(node->left, out);
        out << "    node" << currentNodeId << " -> node" << leftChildId << ";\n";
    }

    if (node->right) {
        // Define the right child and the edge to it
        int rightChildId = nodeId;
        generateDotRepresentation(node->right, out);
        out << "    node" << currentNodeId << " -> node" << rightChildId << ";\n";
    }
}

void AVLTree::exportToDot(const string& filename) const {
    std::ofstream out(filename);
    out << "digraph AVLTree {\n";
    generateDotRepresentation(root, out);
    out << "}\n";
    out.close();
    // need to install Graphviz to use this
    // sudo apt-get install graphviz
    // Construct the Graphviz command
    string outfile = filename.substr(0, filename.find_last_of(".")) + ".png";
    string command = "dot -Tpng " + filename + " -o " + outfile;
    
    // Execute the command
    system(command.c_str());

}
