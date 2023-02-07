#include <iostream>
#include <string>
#include <cassert>
using namespace std;
template <class t>
class arrayQueue
{
    int front;
    int rear;
    int count;
    t *arr;
    int Maxsize;

public:
    arrayQueue(int size)
    {
        if (size <= 0)
            Maxsize = 100;
        else
            Maxsize = size;
        arr = new t[Maxsize];
        front = 0;
        rear = Maxsize - 1;
        count = 0;
    }
    int isEmpty()
    {
        return count == 0;
    }
    int isFull()
    {
        return count == Maxsize;
    }
    void enQueue(t Element)
    {
        if (!isFull())
        {
            rear = (rear + 1) % Maxsize;
            arr[rear] = Element;
            count++;
        }
        else
        {
            cout << "Queue is Full can't Enqueue...!\n";
        }
    }
    void Dequeue()
    {
        if (!isEmpty())
        {
            front = (front + 1) % Maxsize;
            --count;
        }
        else
        {
            cout << "Queue is Empty can't Dequeue...!\n";
        }
    }
    t getfront()
    {
        assert(!isEmpty());
        {
            return arr[front];
        };
    }
    t getrear()
    {
        assert(!isEmpty());
        {
            return arr[rear];
        };
    }
    void print()
    {
        if (!isEmpty())
        {
            for (size_t i = front; i != rear; i = (i + 1) % Maxsize)
            {
                cout << arr[i] << " ";
            }
            cout << arr[rear] << " ";
        }
        else
        {
            cout << "Queue is Empty Nothing to print....!\n";
        }
    }
    int QueueSearch(t Element)
    {
        int pos = -1;
        if (!isEmpty())
        {
            for (size_t i = front; i != rear; i = (i + 1) % Maxsize)
            {
                if (arr[i] == Element)
                    pos = i;
            }
            if (arr[rear] == Element)
                pos = rear;
        }
        else
        {
            cout << "Queue is Empty Nothing to print....!\n";
        }
        return pos;
    }
};
int main()
{
    arrayQueue<string> q1(200);
    q1.enQueue("ahmed1");
    q1.enQueue("ahmed2");
    q1.enQueue("ahmed3");
    q1.enQueue("ahmed4");
    q1.enQueue("ahmed5");
    q1.Dequeue();
    q1.enQueue("ahmed6");
    q1.print();
    cout << q1.QueueSearch("ahmed4") << endl;
    return 0;
}
