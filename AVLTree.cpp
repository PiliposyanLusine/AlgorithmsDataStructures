#include <iostream>


struct Node
{
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    return node->height;
}

void updateHeight(Node* node)
{
    node->height = 1 + std::max(height(node->left), height(node->right));
}

Node* rotateRight(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* rotateLeft(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* balance(Node* node)
{
    int balanceFactor = height(node->left) - height(node->right);
    if (balanceFactor > 1)
    {
        if(height(node->left->left) >= height(node->left->right))
        {
            return rotateRight(node);
        }
        else
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    if(balanceFactor < -1)
    {
        if(height(node->right->right) >= height(node->right->left))
        {
            return rotateLeft(node);
        }
        else
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }
}

void inOrder(Node* node)
{
    if(node == nullptr)
    {
        return;
    }
    inOrder(node->left);
    std::cout << node->key << std::endl;
    inOrder(node->right);
}
Node* insert(Node* node, int key) 
{
    if (node == nullptr) 
    {
        return new Node{key, nullptr, nullptr, 1};
    }

    if (key < node->key) 
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) 
    {
        node->right = insert(node->right, key);
    }
    else 
    {
        return node; 
    }

    updateHeight(node);
    return balance(node);
}
int main()
{
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, )
    cout << "In-order traversal of AVL tree: ";
    inOrder(root);
}