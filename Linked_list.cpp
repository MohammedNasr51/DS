#include <iostream>
#include <string>
#include <cassert>
using namespace std;
class linkedlist
{
    struct node
    {
        int item;
        node *next;
    };
    node *head, *tail;  //pointer to first node and one to the last
    int length;  //to count nodes

public:
    linkedlist()
    {
        head = tail = NULL;
        length = 0;
    }
    bool isembty()
    {
        return length == 0;
    }
    void insertatfirst(int item)  //inserting items at the first position in the list
    {
        node *newnode = new node;
        newnode->item = item;
        if (length == 0)
        {
            head = tail = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        length++;
    }
    void insertatlast(int item)   //inserting items at the lasst position in the list
    {
        node *newnode = new node;
        newnode->item = item;
        if (length == 0)
        {
            head = tail = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = NULL;
            tail->next = newnode;
            tail = newnode;
        }
        length++;
    }
    void insertatposition(int pos, int item)  //inserting items at any position in the list
    {
        if (pos < 0 || pos > length)
        {
            cout << "out of range..!\n";
        }
        else if (pos == 0)
        {
            insertatfirst(item);
        }
        else if (pos == length)
        {
            insertatlast(item);
        }
        else
        {
            node *cur = head;
            node *newnode = new node;
            newnode->item = item;
            for (int i = 1; i < pos; i++)
            {
                cur = cur->next;
            }
            newnode->next = cur->next;
            cur->next = newnode;
            length++;
        }
    }
    void print()  //print list items
    {
        if (isembty())
        {
            cout << "list is empty...!\n";
        }
        else
        {
            node *cur = head;
            while (cur != NULL)
            {
                cout << cur->item << " ";
                cur = cur->next;
            }
        }
    }
    void deleteatposition(int pos)  //deleting items at any position in the list
    {
        node *cur, *prv;
        if (pos < 0 || pos > length)
        {
            cout << "out of range..!\n";
        }
        else if (pos == 0)
        {
            cur = head;
            head = cur->next;
            delete cur;
            length = length - 1;
            if (length == 0)
                tail = NULL;
        }
        else if (pos == length)
        {
            cur = head->next;
            prv = head;
            while (cur != tail)
            {
                prv = cur;
                cur = cur->next;
            }
            tail = prv;
            prv->next = NULL;
            delete cur;
            length = length - 1;
            if (length == 0)
                tail = NULL;
        }
        else
        {
            cur = head->next;
            prv = head;
            for (int i = 1; i < pos; i++)
            {
                prv = cur;
                cur = cur->next;
            }
            prv->next = cur->next;
            delete cur;
            length = length - 1;
            if (length == 0)
                tail = NULL;
        }
    }
};
int main()
{
    linkedlist l1;
    l1.insertatfirst(1);
    l1.insertatlast(2);
    l1.insertatlast(3);
    l1.insertatposition(1, 11);
    l1.insertatposition(0, 100);
    l1.insertatposition(3, 300);
    l1.deleteatposition(0);
    l1.deleteatposition(4);
    l1.deleteatposition(2);
    l1.print();
}
