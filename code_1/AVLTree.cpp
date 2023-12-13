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
    // Perform standard BST insertion based on statValue
    if (node == nullptr) {
        return make_shared<AVLNode>(player);
    }

    if (player.statValue < node->data.statValue) {
        node->left = insertNode(node->left, player);
    } else if (player.statValue > node->data.statValue) {
        node->right = insertNode(node->right, player);
    } else {
        // Duplicate statValue found, output an error
        cout << "Error: A player with statValue " << player.statValue << " already exists." << endl;
        return node; // Return the current node without inserting a new one
    }

    // Update the height of the node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Calculate the balance factor
    int balance = getBalanceFactor(node);

    // Balance the tree based on the balance factor and statValue
    // Left Left Case
    if (balance > 1 && player.statValue < node->left->data.statValue) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && player.statValue > node->right->data.statValue) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && player.statValue > node->left->data.statValue) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && player.statValue < node->right->data.statValue) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (potentially changed) node pointer
    return node;
}

shared_ptr<AVLNode> AVLTree::removeNode(shared_ptr<AVLNode> node, float statValue) {
    // Step 1: Perform standard BST delete
    if (node == nullptr) {
        return node;
    }

    // If the statValue to be deleted is smaller than the node's statValue, then it lies in the left subtree
    if (statValue < node->data.statValue) {
        node->left = removeNode(node->left, statValue);
    }
    // If the statValue to be deleted is greater than the node's statValue, then it lies in the right subtree
    else if (statValue > node->data.statValue) {
        node->right = removeNode(node->right, statValue);
    }
    // If statValue is the same as node's statValue, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if ((node->left == nullptr) || (node->right == nullptr)) {
            shared_ptr<AVLNode> temp = node->left ? node->left : node->right;

            // No child case
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else { // One child case
                *node = *temp; // Copy the contents of the non-empty child
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

    // If the tree had only one node then return
    if (node == nullptr) {
        return node;
    }

    // Step 2: Update the height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Step 3: Get the balance factor of this node to check whether this node became unbalanced
    int balance = getBalanceFactor(node);

    // Step 4: If the node becomes unbalanced, then balance the tree
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


