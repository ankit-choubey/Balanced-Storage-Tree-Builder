#include <iostream>
#include <cstdlib>
using namespace std;

// --- 1. UNIFIED NODE ---
struct Node {
    int key, h; 
    Node *left, *right;
    Node(int k) { key = k; h = 1; left = right = NULL; }
};

// --- 2. GLOBAL HELPERS (Simple If-Else) ---

// Helper to get height safely
int getHeight(Node* n) { 
    if (n == NULL) {
        return 0;
    } else {
        return n->h;
    }
}

// Helper to find maximum of two numbers
int maxVal(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Calculate height recursively (For Visualization)
int calcHeight(Node* n) { 
    if (n == NULL) return 0;
    int l = calcHeight(n->left);
    int r = calcHeight(n->right);
    
    // Ternary removed, using maxVal logic directly
    if (l > r) {
        return l + 1;
    } else {
        return r + 1;
    }
}

// --- 3. VISUALIZATION LOGIC ---
void printLevel(Node* n, int targetLevel, int curLevel, int &x, int &lastX) {
    if (n == NULL) return;
    
    printLevel(n->left, targetLevel, curLevel + 1, x, lastX);
    
    if (curLevel == targetLevel) {
        int spaces = (x - lastX) * 4;
        for (int i = 0; i < spaces; i++) cout << " ";
        cout << n->key;
        lastX = x + 1;
    }
    x++;
    
    printLevel(n->right, targetLevel, curLevel + 1, x, lastX);
}

void visualize(Node* root, string name) {
    cout << "\n--- Visualizing " << name << " ---\n";
    int h = calcHeight(root); 
    for (int i = 1; i <= h; i++) {
        cout << "Level " << i-1 << ": ";
        int x = 0, lastX = 0;
        printLevel(root, i, 1, x, lastX);
        cout << endl;
    }
}

// --- 4. BST CLASS ---
class BST {
public:
    Node* root;
    BST() { root = NULL; }

    void insert(int key) {
        if (root == NULL) { 
            root = new Node(key); 
            return; 
        }
        Node* cur = root; 
        Node* parent = NULL;
        while (cur != NULL) {
            parent = cur;
            if (key < cur->key) {
                cur = cur->left;
            } else if (key > cur->key) {
                cur = cur->right;
            } else {
                return; // Duplicate
            }
        }
        if (key < parent->key) {
            parent->left = new Node(key);
        } else {
            parent->right = new Node(key);
        }
    }

    int search(int key, bool &found) {
        Node* cur = root;
        int count = 0;
        found = false;
        while (cur != NULL) {
            count++;
            if (cur->key == key) { 
                found = true; 
                return count; 
            }
            
            // Simple If-Else for movement
            if (key < cur->key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return count;
    }
};

// --- 5. AVL CLASS ---
class AVL {
public:
    Node* root;
    AVL() { root = NULL; }

    int bf(Node* n) { 
        return getHeight(n->left) - getHeight(n->right); 
    }

    // Function to handle rotations
    Node* rotate(Node* y, string type) {
        Node* x = NULL;
        
        // Removed Ternary Operator
        if (type == "right") {
            x = y->left;
        } else {
            x = y->right;
        }
        
        if (type == "right") { 
            // Right Rotate Logic
            y->left = x->right; 
            x->right = y;
        } else { 
            // Left Rotate Logic
            y->right = x->left; 
            x->left = y;
        }
        
        // Update Heights using simple maxVal
        y->h = 1 + maxVal(getHeight(y->left), getHeight(y->right));
        x->h = 1 + maxVal(getHeight(x->left), getHeight(x->right));
        return x;
    }

    Node* insertNode(Node* n, int key) {
        if (n == NULL) return new Node(key);
        
        if (key < n->key) {
            n->left = insertNode(n->left, key);
        } else if (key > n->key) {
            n->right = insertNode(n->right, key);
        } else {
            return n;
        }

        n->h = 1 + maxVal(getHeight(n->left), getHeight(n->right));
        int b = bf(n);

        // Standard If logic for balancing
        if (b > 1 && key < n->left->key) {
            return rotate(n, "right");
        }
        if (b < -1 && key > n->right->key) {
            return rotate(n, "left");
        }
        if (b > 1 && key > n->left->key) { 
            n->left = rotate(n->left, "left"); 
            return rotate(n, "right"); 
        }
        if (b < -1 && key < n->right->key) { 
            n->right = rotate(n->right, "right"); 
            return rotate(n, "left"); 
        }
        return n;
    }

    void insert(int key) { root = insertNode(root, key); }

    int search(int key, bool &found) {
        Node* cur = root;
        int count = 0; 
        found = false;
        while (cur != NULL) {
            count++;
            if (cur->key == key) { 
                found = true; 
                return count; 
            }
            
            // Simple If-Else movement
            if (key < cur->key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return count;
    }
};

// --- 6. MAIN ---
int main() {
    int n, searchVal;
    cout << "Enter number of elements: ";
    if (!(cin >> n)) return 0;
    
    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    BST bst; AVL avl;
    for (int i = 0; i < n; ++i) {
        bst.insert(arr[i]);
        avl.insert(arr[i]);
    }

    visualize(bst.root, "BST (Simple Visualization)");
    visualize(avl.root, "AVL (Balanced)");

    cout << "\n[Heights] BST: " << calcHeight(bst.root) << " | AVL: " << calcHeight(avl.root) << endl;

    while (true) {
        cout << "\nSearch Value (-1 to exit): "; 
        cin >> searchVal;
        if (searchVal == -1) break;

        bool bstFound, avlFound;
        int s1 = bst.search(searchVal, bstFound);
        int s2 = avl.search(searchVal, avlFound);

    if (bstFound) {
            cout << "Status: FOUND\n";
            cout << "BST Comparisons: " << s1 << endl;
            cout << "AVL Comparisons: " << s2 << endl;
            
            if (s1 > s2) 
                cout << ">> AVL was faster by " << s1-s2 << " ops.\n";
            else 
                cout << ">> Performance equal.\n";
        } else {
            cout << "Status: NOT FOUND\n";
            cout << "BST wasted " << s1 << " ops.\n";
            cout << "AVL wasted " << s2 << " ops.\n";
        }
    }
    
    delete[] arr;
    return 0;
}