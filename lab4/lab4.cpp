#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList {
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T val)
            : data(val)
            , next(nullptr)
            , prev(nullptr)
        {
        }
    };
    Node *head, *tail;
    Node* findVal(T n) // returns node of the given number
    {
        Node* node = head;
        while (node != nullptr) {
            if (node->data == n)
                return node;

            node = node->next;
        }
        cerr << "No such element in the list \n";
        return nullptr;
    }

    void display(ostream& out = cout) const
    {
        Node* node = head;
        while (node != nullptr) {
            out << node->data << " ";
            node = node->next;
        }
    }

public:
    DoublyLinkedList()
        : head(nullptr)
        , tail(nullptr)
    {
    }

    ~DoublyLinkedList()
    {
        Node* tmp = nullptr;
        while (head) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        head = nullptr;
    }

    DoublyLinkedList(const DoublyLinkedList<T>& dll) = delete;
    DoublyLinkedList& operator=(DoublyLinkedList const&) = delete;

    void insertFront(T val)
    {
        Node* node = new Node(val);
        Node* tmp = head;
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head = node;
            node->next->prev = node;
        }
    }

    void insertBack(T val)
    {
        Node* node = new Node(val);
        if (tail->next == nullptr) {
            tail->next = node;
            tail = node;
        }
    }

    void deleteVal(T val)
    {
        Node* find = findVal(val);
        Node* tmp = head;

        if (tmp == find) {
            head = tmp->next;
        }
        else {
            while (find != nullptr) {
                if (tmp->next == find) {
                    tmp->next = find->next;
                    find->next->prev = tmp;
                    delete find;
                    return;
                }
                tmp = tmp->next;
            }
        }
    }
    void clean()
    {
        head = nullptr;
        tail = nullptr;
    }
    int count()
    {
        int n = 0;
        for (Node *e = this->head; e != nullptr; e = e->next, n++)
            ;
        return n;
    }

    template <class U>
    friend ostream& operator<<(ostream& os, const DoublyLinkedList<U>& dll)
    {
        dll.display(os);
        return os;
    }
};

int main()
{
    DoublyLinkedList<int> l1;
    l1.insertFront(3);
    l1.insertBack(5);
    l1.insertBack(12);
    l1.insertFront(6);
    l1.insertBack(88);
    cout << l1 << "\n";
    l1.deleteVal(11);
    cout << l1 << "\n";
    l1.clean();
    cout << l1 << "\n";
    cout << l1.count() << "\n";
    l1.insertFront(13);
    l1.insertBack(4);
    l1.insertBack(7);
    cout << l1 << "\n";
    cout << l1.count() << "\n";
    return 0;
}