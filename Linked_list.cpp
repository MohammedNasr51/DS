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
    void insertatfirst(int item)//iserting data at the first position in the list
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
    void insertatlast(int item)//iserting data at the last position in the list
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
    void insertatposition(int pos, int item)//iserting data at any position in the list
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
    void print()//printing data
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
            cout<<endl;
        }
    }
    void deleteatposition(int pos)//deleting data from any position in the list
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
    void reverse()//reversing list data
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
    int search(int item)//finding position of an item
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
    l1.insertatfirst(1);//insert 1 at pos 0
    l1.insertatlast(2);//insert 2 at last pos
    l1.insertatlast(3);//3 becomes last element
    l1.insertatposition(1, 11);//inserting 11 at pos 1
    l1.insertatposition(0, 100);//inserting 100 at pos 0
    l1.insertatposition(3, 300);//inserting 300 at pos 3
    l1.print();// 100 1 11 300 2 3
    cout << l1.search(300) << endl;//the pos of 300 is 3
    l1.deleteatposition(0);//deleting pos 0 is 100
    l1.deleteatposition(4);//deleting pos 4 is 3
    l1.deleteatposition(2);//deleting pos 2 is 300
    l1.print();// 1 11 2
    l1.reverse();//reversing data
    l1.print();// 2 11 1
}
