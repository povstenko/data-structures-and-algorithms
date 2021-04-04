#include <iostream>
using namespace std;
#define MAX 100

class Stack {
    int top;
 
public:
    int a[MAX];
 
    Stack() {
        top = -1;
    }
    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow";
            return false;
        }
        else {
            a[++top] = x;
            cout << x << " pushed\n";
            return true;
        }
    }
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow";
            return 0;
        }
        else {
            int x = a[top--];
            cout << x << " popped" << endl;
            return x;
        }
    }
    int peek() {
        if (top < 0) {
            cout << "emty stack";
            return 0;
        }
        else {
            int x = a[top];
            return x;
        }
    }
    bool isEmpty() {
        return (top < 0);
    }
    int print() {
        for (int i=0; i<=top; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return 0;
    }
};

int main() {
    class Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    
    s.print();
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    
    s.print();

    return 0;
}