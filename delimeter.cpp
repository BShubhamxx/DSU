#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Stack {
    char stk[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { 
        return top == -1; 
    }
    bool isFull() { 
        return top == MAX - 1; 
    }

    void push(char ch) {
        if (!isFull())
            stk[++top] = ch;
        else
            cout << "Stack Full!\n";
    }

    char pop() {
        if (!isEmpty())
            return stk[top--];
        else
            return '\0';
    }
};

class Expression {
    string exp;

public:
    void read() {
        cout << "\nEnter an expression: ";
        getline(cin, exp);
    }

    void display() {
        cout << "\nExpression: " << exp << endl;
    }

    void checkWellFormed() {
        Stack s;
        bool valid = true;

        for (char ch : exp) {
            if (ch == '(' || ch == '{' || ch == '[')
                s.push(ch);
            else if (ch == ')' || ch == '}' || ch == ']') {
                char top = s.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    valid = false;
                    break;
                }
            }
        }

        if (!s.isEmpty())
            valid = false;

        cout << (valid ? "\nExpression is Well Formed!\n" : "\nInvalid Expression!\n");
    }
};

int main() {
    Expression e;
    int choice;

    do {
        cout << "\n--- Expression Parsing ---";
        cout << "\n1. Read Expression";
        cout << "\n2. Display Expression";
        cout << "\n3. Check Expression";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // clear buffer

        switch (choice) {
            case 1: e.read(); break;
            case 2: e.display(); break;
            case 3: e.checkWellFormed(); break;
            case 4: cout << "\nExiting..."; break;
            default: cout << "\nInvalid Choice!"; break;
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Stack {
    char stk[MAX];
    int top;

public:
    Stack(){ 
        top = -1; 
    }

    bool isEmpty(){ 
        return top == -1; 
    }
    void push(char ch){
        stk[++top] = ch; 
    }
    char pop(){ 
        return isEmpty() ? '\0' : stk[top--]; 
    }

    void evaluate(){
        string exp;
        Stack s;
        bool valid = true;

        cout << "Enter a mathematical expression: ";
        getline(cin, exp);

    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                valid = false;
                break;
            }
        }
    }
    if (!s.isEmpty()) valid = false;
    cout << (valid ? "\nExpression is Well Formed!\n"
                   : "\nExpression is NOT Well Formed!\n");
    }
};

int main() {
    Stack s1;
    s1.evaluate();
    return 0;
}

