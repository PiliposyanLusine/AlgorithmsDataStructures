#include <iostream>

enum class Color 
{
    RED, 
    BLACK 
};

template <typename T>
class Node 
{
    public:
        T data;
        Node<T>* parent;
        Node<T>* left;
        Node<T>* right;
        Color color;

        Node(const T& val) : data(val), parent(nullptr), left(nullptr), right(nullptr), color(Color::RED) {}
};

template <typename T>
class RBTree 
{
    private:
        Node<T>* root;
        void leftRotate(Node<T>* x) 
        {
            Node<T>* y = x->right;
            x->right = y->left;
            if (y->left)
            {
                y->left->parent = x;
            }
            y->parent = x->parent;
            if (!x->parent)
            {
                root = y;
            }
            else if (x == x->parent->left)
            {
                x->parent->left = y;
            }
            else
            {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }

        void rightRotate(Node<T>* y) 
        {
            Node<T>* x = y->left;
            y->left = x->right;
            if (x->right)
            {
                x->right->parent = y;
            }
            x->parent = y->parent;
            if (!y->parent)
            {
                root = x;
            }
            else if (y == y->parent->left)
            {
                y->parent->left = x;
            }
            else
            {
                y->parent->right = x;
            }
            x->right = y;
            y->parent = x;
        }

        void insertFixup(Node<T>* z) 
        {
            while (z && z != root && z->parent->color == Color::RED) 
            {
                if (z->parent == z->parent->parent->left) 
                {
                    Node<T>* y = z->parent->parent->right;
                    if (y && y->color == Color::RED) 
                    {
                        z->parent->color = Color::BLACK;
                        y->color = Color::BLACK;
                        z->parent->parent->color = Color::RED;
                        z = z->parent->parent;
                    } 
                    else 
                    {
                        if (z == z->parent->right) 
                        {
                            z = z->parent;
                            leftRotate(z);
                        }
                        z->parent->color = Color::BLACK;
                        z->parent->parent->color = Color::RED;
                        rightRotate(z->parent->parent);
                    }
                } 
                else 
                {
                    Node<T>* y = z->parent->parent->left;
                    if (y && y->color == Color::RED) 
                    {
                        z->parent->color = Color::BLACK;
                        y->color = Color::BLACK;
                        z->parent->parent->color = Color::RED;
                        z = z->parent->parent;
                    } 
                    else 
                    {
                        if (z == z->parent->left) 
                        {
                            z = z->parent;
                            rightRotate(z);
                        }
                        z->parent->color = Color::BLACK;
                        z->parent->parent->color = Color::RED;
                        leftRotate(z->parent->parent);
                    }
                }
            }
            root->color = Color::BLACK;
        }

    public:
        RBTree() : root(nullptr) {}
        void insert(const T& data) 
        {
            Node<T>* z = new Node<T>(data);
            Node<T>* y = nullptr;
            Node<T>* x = root;
            while (x) 
            {
                y = x;
                if (z->data < x->data)
                {
                    x = x->left;
                }
                else
                {
                    x = x->right;
                }
            }

            z->parent = y;
            if (!y)
            {
                root = z;
            }
            else if (z->data < y->data)
            {
                y->left = z;
            }
            else
            {
                y->right = z;
            }
            insertFixup(z);
        }


        void inOrderPrint(Node<T>* node) 
        {
            if (node == nullptr) 
            {
                return;
            }
            inOrderPrint(node->left);
            std::cout << node->data << " ";
            inOrderPrint(node->right);
        }

        void print() 
        {
            inOrderPrint(root);
            std::cout << std::endl;
        }
};

    int main() 
    {
        RBTree<int> rbtree;
        rbtree.insert(10);
        rbtree.insert(5);
        rbtree.insert(15);
        rbtree.insert(3);
        rbtree.insert(7);
        rbtree.insert(12);
        rbtree.print();
        return 0;
    }
