#include<iostream>
#include<string>
using namespace std;
const int Max = 100; //size of stack array
template <class t>
class stack {
    int top;
    t item[Max];
public:
    stack() :top(-1) {};//initialization of top in the costructor
    void push(t element) {
        if (top >= Max - 1) { //when pushing we first check if the stack is full
            cout << "stack is full\n";
        }
        else {         //if it isn't full we make top increases and put the value in item [top]  
            top++;
            item[top] = element;
        }
    }
    bool isEmpty() {//check if the stack is empty before pop
        return top <0;
    }
    void pop() {
        if (isEmpty()) {
            cout << "stack is empty\n";
        }
        else {//we decrease the value of top to pop
            top--;
        }
    }
    void pop(t&element) {//we decrease the value of top to pop but save the value in a vareable
        if (isEmpty()) {
            cout << "stack is empty\n";
        }
        else {
            element = item[top];
            top--;
        }
    }
    t getTop(t& value) { //to get the value of the last element
        value = item[top];
        return value;
    }
    void print() { //to print all the values of stack
        if (isEmpty()) {
            cout << "stack is empty\n";
        }
        else {
            for (int i = top; i >= 0; i--)
            {
                cout << "| " << item[i] << " |\n";
            }
            cout << "|___|\n";
        }
    }
};
int main()
{
    stack<int>s;   //putting the type is integer
    s.print();     //show that stack is empty
    s.push(1);     //pushing elements to the stack
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();      // 5 4 3 2 1
    int x = 0;      
    s.getTop(x);    // get the top value 5 so x will equal 5
    cout << x << endl;// 5
    s.pop(x);       // 5 will be deleated but its value will be saved in x
    s.print();      // 4 3 2 1
    cout << x << endl;// 5
    s.pop();        // 4 will be deleated only   3 2 1
    s.print();
}
