// Implementation of Stacks using arrays

/* #include <iostream>
using namespace std;
#define max 100
class Stack
{
    int top;

public:
    int a[max];
    Stack()
    {
        top = -1;
    }
    void push(int x);
    void pop();
    void peek();
    bool isEmpty();
    bool isFull();
    void print();
};
void Stack::push(int x)
{
    if (top == (max - 1))
    {
        cout << "Stack Overflow";
        return;
    }
    else
    {
        top = top + 1;
        a[top] = x;
        cout << x << " pushed in the stack\n";
    }
}

void Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow! ";
        return;
    }
    else
    {
        int x = a[top];
        top = top - 1;
        cout << x << " popped from the stack!\n";
    }
}

void Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack Underflow! ";
        return;
    }
    else
    {
        int x = a[top];
        cout << "Top element =" << x << endl;
    }
}

bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

bool Stack::isFull()
{
    if (top == (max - 1))
        return true;
    else
        return false;
}

void Stack::print()
{
    if (isEmpty())
    {
        cout << "The stack is empty!\n";
        return;
    }
    cout << "Stack elements are: ";
    for (int i = top; i >= 0; i--)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    Stack s;
    s.push(15);
    s.push(30);
    s.push(18);
    s.print();
    s.pop();
    s.print();
    s.peek();
    s.print();
} */

// Implementation of  stacks using Linked Lists
/* #include <iostream>
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

class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    bool isEmpty();
    void push(int data);
    void pop();
    void peek();
    void print();
};

bool Stack::isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}
void Stack::push(int data)
{
    Node *newNode = new Node(data);
    newNode->next = top;
    top = newNode;
    cout << data << " pushed to stack!\n";
}

void Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow!\n";
        return;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        int x = temp->data;
        delete temp;
        cout << x << " popped from the stack!\n";
    }
}

void Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack Underflow!\n";
        return;
    }
    else
    {
        cout << "Top element is " << top->data << endl;
    }
}

void Stack::print()
{
    Node *temp = top;
    cout << "Stack Elements are: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Stack s;
    s.push(15);
    s.push(30);
    s.push(18);
    s.print();
    s.pop();
    s.print();
    s.peek();
    s.print();
} */