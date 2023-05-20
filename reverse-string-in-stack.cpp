#include <iostream>
#define n 100

using namespace std;
class Stack {
private:
    
    char data[n];
    int top;

public:
    Stack() {
        top = -1;
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == n - 1);
    }
    void push(char x) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
            return;
        }
        data[++top] = x;
    }
    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        return data[top--];
    }
};
string reverseString(string str) {
    Stack charStack;

    for (char ch : str) {
        charStack.push(ch);
    }
    string reversedStr;

    while (!charStack.isEmpty()) {
        reversedStr += charStack.pop();
    }
    return reversedStr;
}
int main() {
    string str;
    cout << "Enter a string: ";
    cin>>str;
    string reversedStr = reverseString(str);
    cout << "Reversed string: " << reversedStr << endl;
    return 0;
}
