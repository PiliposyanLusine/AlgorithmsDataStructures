#include <iostream>

template <typename T>
class Node 
{
    public:
        T data;
        Node* next;
        Node* prev;

        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList 
{
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;

    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

        void push_back(T value) 
        {
            Node<T>* newNode = new Node<T>(value);
            if (tail == nullptr) 
            {
                head = tail = newNode;
            } 
            else 
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        void push_front(T value) 
        {
            Node<T>* newNode = new Node<T>(value);
            if (head == nullptr) 
            {
                head = tail = newNode;
            } 
            else 
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        void pop_back() 
        {
            if (tail == nullptr) 
            {
                return;
            }
            Node<T>* temp = tail;
            tail = tail->prev;
            if (tail == nullptr) 
            {
                head = nullptr;
            } 
            else 
            {
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }

        void pop_front() 
        {
            if (head == nullptr) return;
            Node<T>* temp = head;
            head = head->next;
            if (head == nullptr) 
            {
                tail = nullptr;
            } 
            else 
            {
                head->prev = nullptr;
            }
            delete temp;
            length--;
        }


        void erase(int position) 
        {
            if (position < 0 || position >= length) return;
            if (position == 0) 
            {
                pop_front();
            } 
            else if (position == length - 1) 
            {
                pop_back();
            } 
            else 
            {
                Node<T>* current = head;
                for (int i = 0; i < position; i++) 
                {
                    current = current->next;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                length--;
            }
        }


        void insert(int position, T value) 
        {
            if (position < 0 || position > length) return;
            if (position == 0) 
            {
                push_front(value);
            } 
            else if (position == length) 
            {
                push_back(value);
            } 
            else 
            {
                Node<T>* newNode = new Node<T>(value);
                Node<T>* current = head;
                for (int i = 0; i < position; i++) 
                {
                    current = current->next;
                }
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
                length++;
            }
        }

        void clear() 
        {
            while (!empty()) 
            {
                pop_front();
            }
        }


        bool empty() const 
        {
            return length == 0;
        }


        int size() const 
        {
            return length;
        }




        void reverse() 
        {
            if (length <= 1) return;
            Node<T>* current = head;
            while (current != nullptr) 
            {
                Node<T>* temp = current->next;
                current->next = current->prev;
                current->prev = temp;
                if (temp == nullptr) 
                {
                    tail = head;
                    head = current;
                }
                current = temp;
            }
        }


        void merge(DoublyLinkedList<T>& other) 
        {
            if (other.empty()) return;
            if (empty()) 
            {
                head = other.head;
                tail = other.tail;
                length = other.length;
                other.head = other.tail = nullptr;
                other.length = 0;
                return;
            }

            Node<T>* thisCurrent = head;
            Node<T>* otherCurrent = other.head;
            Node<T>* prev = nullptr;

            while (thisCurrent != nullptr && otherCurrent != nullptr) 
            {
                if (thisCurrent->data <= otherCurrent->data) 
                {
                    prev = thisCurrent;
                    thisCurrent = thisCurrent->next;
                }
                else 
                {
                    Node<T>* temp = otherCurrent->next;
                    otherCurrent->next = thisCurrent;
                    otherCurrent->prev = prev;
                    if (prev != nullptr) 
                    {
                        prev->next = otherCurrent;
                    } 
                    else 
                    {
                        head = otherCurrent;
                    }
                    prev = otherCurrent;
                    otherCurrent = temp;
                    length++;
                }
            }

            if (otherCurrent != nullptr) 
            {
                tail = other.tail;
                length += other.length;
                other.head = other.tail = nullptr;
                other.length = 0;
            }
        }


        
        ~DoublyLinkedList() 
        {
            clear();
        }
};

int main() {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(3);
    list.push_back(2);
    list.push_front(0);

    
    list.reverse();
    std::cout << "Reversed List: ";
}

