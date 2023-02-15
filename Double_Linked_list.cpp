#include <iostream>
#include <string>
using namespace std;
class DoulyLinkedList
{
    struct node
    {
        int item;
        node *next, *prev;
    };
    node *head, *tail;
    int length;

public:
    DoulyLinkedList()
    {
        head = tail = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return (length == 0);
    }
    void insertatfirst(int item) // inserting data at first
    {
        node *newnode = new node;
        newnode->item = item;
        if (isEmpty())
        {
            head = tail = newnode;
            newnode->next = newnode->prev = NULL;
        }
        else
        {
            head->prev = newnode;
            newnode->prev = NULL;
            newnode->next = head;
            head = newnode;
        }
        length++;
    }
    void insertatend(int item) // inserting data at end
    {
        node *newnode = new node;
        newnode->item = item;
        if (isEmpty())
        {
            head = tail = newnode;
            newnode->next = newnode->prev = NULL;
        }
        else
        {
            tail->next = newnode;
            newnode->next = NULL;
            newnode->prev = tail;
            tail = newnode;
        }
        length++;
    }
    void isertatpos(int pos, int item) // inserting data at sertain positin
    {
        if (pos < 0 || pos > length)
        {
            cout << "out of rang\n";
        }
        else if (pos == 0)
        {
            insertatfirst(item);
        }
        else if (pos == length)
        {
            insertatend(item);
        }
        else
        {
            node *newnode = new node;
            node *cur = head;
            for (size_t i = 1; i < pos; i++)
            {
                cur = cur->next;
            }
            newnode->prev = cur;
            newnode->next = cur->next;
            cur->next->prev = newnode;
            cur->next = newnode;
        }
        length++;
    }
    void removeatfirst() // removing data from firts
    {
        if (isEmpty())
        {
            cout << "Nothing to remove...!\n";
        }
        else if (length == 0)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node *cur = head;
            head = head->next;
            head->prev = NULL;
            delete cur;
        }
        length--;
    }
    void removeatend() // removing data from end
    {
        if (isEmpty())
        {
            cout << "Nothing to remove...!\n";
        }
        else if (length == 1)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node *cur = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete cur;
        }
        length--;
    }
    void removeatpos(int pos) // removing data of sertain positin
    {
        if (pos < 0 || pos > length)
        {
            cout << "out of rang\n";
        }
        else if (pos == 0)
        {
            removeatfirst();
        }
        else if (pos == length - 1)
        {
            removeatend();
        }
        else
        {
            node *cur;
            if (pos <= (length / 2))
            {
                cur = head->next;
                for (size_t i = 1; i < pos; i++)
                {
                    cur = cur->next;
                }
                cur->next->prev = cur->prev;
                cur->prev->next = cur->next;
                delete cur;
            }
            else
            {
                cur = tail->prev;
                for (size_t i = 1; i < length - pos - 1; i++)
                {
                    cur = cur->prev;
                }
                cur->next->prev = cur->prev;
                cur->prev->next = cur->next;
                delete cur;
            }
        }
        length--;
    }
    void printforward() // printing data forward
    {
        if (isEmpty())
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
            cout << endl;
        }
    }
    void printreverse() // printing data reverse
    {
        if (isEmpty())
        {
            cout << "list is empty...!\n";
        }
        else
        {
            node *cur = tail;
            while (cur != NULL)
            {
                cout << cur->item << " ";
                cur = cur->prev;
            }
            cout << endl;
        }
      }
    ~DoulyLinkedList()
    {
        node*cur;
        while(head!=NULL)
        {
            cur=head;
            head=head->next;
            delete cur;
        }
        last=NULL;
        length=0;
    }
    
};
int main()
{
    DoulyLinkedList d1;
    d1.insertatfirst(4); // 4 
    d1.insertatfirst(3); // 3 4 
    d1.insertatfirst(2); // 2 3 4 
    d1.insertatfirst(1); // 1 2 3 4 
    d1.insertatend(6);   // 1 2 3 4 6
    d1.insertatend(7);   // 1 2 3 4 6 7
    d1.insertatpos(4,5); // 1 2 3 4 5 6 7
    d1.printforward();   // 1 2 3 4 5 6 7
    d1.printreverse();   // 7 6 5 4 3 2 1
    d1.removeatfirst();  // removing 1
    d1.printforward();   // 2 3 4 5 6 7
    d1.printreverse();   // 7 6 5 4 3 2
    d1.removeatend();    // removing 7
    d1.printforward();   // 2 3 4 5 6
    d1.printreverse();   // 6 5 4 3 2
    d1.removeatpos(2);   // removing 4 at pos 2
    d1.printforward();   // 2 3 5 6
    d1.printreverse();   // 6 5 3 2
}
