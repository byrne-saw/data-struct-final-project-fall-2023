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
        } else if (statValue < current->data.statValue) {
            current = current->left; // Go left if statValue is smaller
        } else {
            current = current->right; // Go right otherwise
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