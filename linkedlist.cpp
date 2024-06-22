/* // Basic node implementation using class and constructor
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Creating new node using constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int main()
{
    Node *node1 = new Node(15);
    cout << node1->data << endl
         << node1->next;
} */

/* // Inserting at head, tail, specified positions
#include <iostream>
using namespace std;
class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // Checking first element
        if (this->next != NULL)
        {
            delete this;
            this->next = NULL;
        }
        cout << "Memory is free for node with data : " << value << endl;
    }
};
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node *&tail, Node *&head, int p, int d)
{
    if (p == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < p - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
    }
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}
void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}
void deleteNode(int p, Node *head)
{
    if (p == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < p)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(30);
    Node *head = node1;
    Node *tail = node1;
    printLL(head);
    insertAtHead(head, 15);
    printLL(head);
    insertAtTail(tail, 18);
    printLL(head);
    insertAtPosition(tail, head, 2, 23);
    printLL(head);
    deleteNode(2,head);
    printLL(head);
} */

/* // Doubly Linked List
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data) 
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data: " << value << endl;
    }
};
void printDLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    cout << "Length of DLL = " << len << endl;
}

void insertAtHead(Node *&tail, Node *&head, int d)
{
    if (head == NULL) // incase of empty list
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{
    if (head == NULL) // incase of empty list
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&tail, Node *&head, int p, int d)
{
    if (p == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < p - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int p, Node *&head)
{
    if (p == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting middle/last node
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < p)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    printDLL(head);
    insertAtHead(tail, head, 11);
    printDLL(head);
    insertAtHead(tail, head, 13);
    printDLL(head);
    insertAtHead(tail, head, 8);
    printDLL(head);
    insertAtTail(tail, head, 25);
    printDLL(head);
    insertAtPosition(tail, head, 2, 100);
    printDLL(head);
    insertAtPosition(tail, head, 1, 101);
    printDLL(head);
    insertAtPosition(tail, head, 7, 102);
    printDLL(head);
    deleteNode(1, head);
    printDLL(head);
    deleteNode(6, head);
    printDLL(head);
}
 */
/*
// Circular Linked List
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data: " << value << endl;
    }
};

void printCL(Node *tail)
{
    Node *temp = tail;
    //  cout<<tail->data<<" ";
    // while(tail->next!=temp)
    // {
    //     cout<<tail->data<<" ";
    //     tail=tail->next;
    // }
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL) // when list is empty
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else // non-empty list
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(Node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "LIst is empty, please check again!" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr == prev)
        {
            tail = NULL;
        }
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    printCL(tail);
    insertNode(tail, 3, 5);
    printCL(tail);
    insertNode(tail, 5, 7);
    printCL(tail);
    insertNode(tail, 5, 6);
    printCL(tail);
    deleteNode(tail, 6);
    printCL(tail);
} */

// Reverse a link list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

/* void reverse_recursion(Node *head, Node *curr, Node *prev)
{
    Node *curr = head;
    Node *prev = NULL;
    reverse_recursion(head, curr, prev)
    { 
        if (head == NULL)
        {
            return head;
        }
    }
} */

Node *reverseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (curr != NULL)
    {
        forward = curr->next; // So that we don't loose track of remaining list
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
int main()
{
    Node *node1 = new Node(30);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 20);
    insertAtTail(tail, 10);
    insertAtTail(tail, 5);
    printLL(head);
    head = reverseLinkedList(head);
    printLL(head);
}