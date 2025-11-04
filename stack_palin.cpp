#include <iostream>
#include <cctype>   // for isalnum and tolower
#include <cstring>  // for strlen
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(char c) {
        if (top < MAX - 1)
            arr[++top] = c;
        else
            cout << "Stack Overflow!\n";
    }

    char pop() {
        if (top >= 0)
            return arr[top--];
        else {
            cout << "Stack Underflow!\n";
            return '\0';
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to clean string: removes spaces/punctuation and converts to lowercase
string cleanString(string str) {
    string cleaned = "";
    for (char c : str) {
        if (isalnum(c))  // keep only letters and digits
            cleaned += tolower(c);
    }
    return cleaned;
}

// Function to reverse string using manual stack
string reverseUsingStack(string str) {
    Stack s;
    for (char c : str)
        s.push(c);

    string rev = "";
    while (!s.isEmpty())
        rev += s.pop();

    return rev;
}

// Function to check palindrome
bool isPalindrome(string str) {
    string cleaned = cleanString(str);
    string reversed = reverseUsingStack(cleaned);
    return cleaned == reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string cleaned = cleanString(input);
    string reversed = reverseUsingStack(cleaned);

    cout << "\nOriginal (cleaned): " << cleaned;
    cout << "\nReversed: " << reversed;

    if (isPalindrome(input))
        cout << "\n\nThe given string IS a palindrome.\n";
    else
        cout << "\n\nThe given string is NOT a palindrome.\n";

    return 0;
}
