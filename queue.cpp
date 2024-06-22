/// Implementation of Queue using Arrays
/* #include <iostream>
using namespace std;

class queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    queue()
    {
        size = 100;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    void enqueue(int data);
    void dequeue();
    bool isEmpty();
    void front();
    void print();
};

void queue::enqueue(int data)
{
    if (rear == size)
    {
        cout << "Queue is full!\n";
        return;
    }
    else
    {
        arr[rear] = data;
        rear = rear + 1;
        cout << data << " enqueued!\n";
    }
}

void queue::dequeue()
{
    if (qfront == rear)
    {
        cout << "Queue is empty\n";
        return;
    }
    else
    {
        int x = arr[qfront];
        cout << "Dequeued element = " << x << endl;
        qfront = qfront + 1;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }
    }
}

void queue::front()
{
    if (qfront == rear)
    {
        cout << "Queue is empty\n";
        return;
    }
    else
    {
        int x = arr[qfront];
        cout << "Front element = " << x << endl;
    }
}

bool queue::isEmpty()
{
    if (qfront == rear)
        return true;
    else
        return false;
}

void queue::print()
{
    if (qfront == rear)
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = qfront; i < rear; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    queue q;
    q.enqueue(15);
    q.enqueue(30);
    q.enqueue(18);
    q.print();
    q.dequeue();
    q.print();
    q.front();
    q.print();
} */

// Implementation of circular queue

#include <iostream>
using namespace std;

class circularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    circularQueue()
    {
        size = 100;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    void enqueue(int data);
    void dequeue();
    void print();
};
void circularQueue::enqueue(int data)
{
    if ((front == 0) &&rear = (size - 1) || (rear == (front - 1) % (size - 1)))
    {
        cout << "The queue is full! \n";
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
    }
}
