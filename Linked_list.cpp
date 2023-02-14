#include <iostream>
#include <string>
using namespace std;
class linkedlist
{
    struct node
    {
        int item;
        node *next;
    };
    node *head, *tail;
    int length;

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
    void insertatfirst(int item)
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
    void insertatlast(int item)
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
    void insertatposition(int pos, int item)
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
    void print()
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
    void deleteatposition(int pos)
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
    void reverse()
    {
        node *prv, *cur, *next;
        prv = NULL;
        cur = head;
        next = cur->next;
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prv;
            prv = cur;
            cur = next;
        }
        head = prv;
    }
    int search(int item)
    {
        node *cur = head;
        int pos = 0;
        while (cur != NULL)
        {
            if (cur->item == item)
            {
                return pos;
            }
            cur = cur->next;
            pos = pos + 1;
        }
        return -1;
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
    l1.reverse();
    cout << l1.search(300) << endl;
    l1.print();
}
