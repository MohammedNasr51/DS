#include <iostream>
#include <string>
using namespace std;
template <class t>
class stack
{
    struct node
    {
        t item;
        node *next;
    };
    node *top, *cur;

public:
    stack()
    {
        top = NULL;
    }; // initialization of top in the costructor
    void push(t newItem)
    {
        node *newItemptr = new node;
        if (newItemptr == NULL)
        { // when pushing we first check if the stack is full
            cout << "stack push can't allocate the memory\n";
        }
        else
        { // if it isn't full we make top increases and put the value in item [top]
            newItemptr->item = newItem;
            newItemptr->next = top;
            top = newItemptr;
        }
    }
    bool isEmpty()
    { // check if the stack is empty before pop
        return top == NULL;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty\n";
        }
        else
        {
            node *temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }
    void pop(t &element)
    {
        if (isEmpty())
        {
            cout << "stack is empty\n";
        }
        else
        {
            element = top->item;
            node *temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }
    void getTop(t &element)
    {
        if (isEmpty())
        {
            cout << "stack is empty\n";
        }
        else
        {
            element = top->item;
        }
    }
    void print()
    { // to print all the values of stack
        cur = top;
        cout << "[ ";
        while (cur != NULL)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << " ]\n";
    }
};
int main()
{
    stack<int> s; // putting the type is integer
    s.print();    // show that stack is empty
    s.push(1);    // pushing elements to the stack
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print(); // 5 4 3 2 1
    int x = 0;
    s.getTop(x);       // get the top value 5 so x will equal 5
    cout << x << endl; // 5
    s.pop(x);          // 5 will be deleated but its value will be saved in x
    s.print();         // 4 3 2 1
    cout << x << endl; // 5
    s.pop();           // 4 will be deleated only   3 2 1
    s.print();
}
