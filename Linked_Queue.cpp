#include <iostream>
#include <string>
#include <cassert>
using namespace std;
template <class t>
class Linked_Queue
{
private:
    struct Node
    {
        t item;
        Node *next;
    };
    Node *frontptr, *rearptr;
    int length;

public:
    Linked_Queue() : frontptr(NULL), rearptr(NULL), length(0) {}//initializing attributes in default constructor
    bool is_empty()
    {
        return length == 0;
    }
    void enqueue(t element)
    {
        Node *newnode = new Node;
        newnode->item = element;
        newnode->next = NULL;
        if (is_empty())
        {
            frontptr = rearptr = newnode;
        }
        else
        {
            rearptr->next = newnode;
            rearptr = newnode;
        }
        length++;
    }
    void dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is Empty...!\n";
        }
        else if (length == 1)
        {
            delete frontptr;
            rearptr = NULL;
            length = 0;
        }
        else
        {
            Node *curr = frontptr;
            frontptr = frontptr->next;
            curr = curr->next = NULL;
            free(curr);
            length--;
        }
    }
    int get_length()
    {
        return length;
    }
    void get_front(t &ele)
    {
        assert(!is_empty());
        ele = frontptr->item;
    }
    void get_rear(t &ele)
    {
        assert(!is_empty());
        ele = rearptr->item;
    }
    void clearqueue()
    {
        Node *curr;
        while (frontptr != NULL)
        {
            curr = frontptr;
            frontptr = frontptr->next;
            delete curr;
        }
        rearptr = NULL;
        length = 0;
    }
    void display()
    {
        Node *curr = frontptr;
        cout << "Queue Items are : [ ";
        while (curr != NULL)
        {
            cout << curr->item << " ";
            curr = curr->next;
        }
        cout << "]\n";
    }
    void search(t element)
    {
        Node *curr = frontptr;
        bool flag = true;
        while (curr != NULL)
        {
            if (curr->item == element)
            {
                cout << element << " is found in queue\n";
                flag = false;
            }
            curr = curr->next;
        }
        if (flag)
        {
            cout << element << " is not found in queue\n";
        }
    }
};
int main()
{
    Linked_Queue<char> q1;
    q1.enqueue('M');
    q1.enqueue('o');
    q1.enqueue('h');
    q1.enqueue('a');
    q1.enqueue('m');
    q1.enqueue('m');
    q1.enqueue('e');
    q1.enqueue('d');
    q1.display();
    char x = ' ';
    q1.get_front(x);
    cout << x << endl;
    q1.get_rear(x);
    cout << x << endl;
    cout << q1.get_length() << endl;
    q1.dequeue();
    q1.display();
    q1.search('s');
    q1.search('d');
    q1.clearqueue();
    q1.display();
}/*
the output-----
-----
Queue Items are : [ M o h a m m e d ]
M
d
8
Queue Items are : [ o h a m m e d ]
s is not found in queue
d is found in queue
Queue Items are : [ ]*/
