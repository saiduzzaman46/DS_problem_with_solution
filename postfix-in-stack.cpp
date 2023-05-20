#include <iostream>
#define n 100


using namespace std;

class stack
{

private:
    int arr[n];
    int top;

public:
    stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stuck overflow" << endl;
        }
        else
        {
            arr[++top] = x;
        }
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            int x = arr[top--];
            return x;
        }
        return 0;
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
};

int PostfixExpression(string data)
{
    stack valueStack;

    for (char ch : data)
    {
        if (isdigit(ch))
        {
            valueStack.push(ch - '0');
        }
        else
        {
            int a = valueStack.peek();
            valueStack.pop();
            int b = valueStack.peek();
            valueStack.pop();

            int result;

            switch (ch)
            {
            case '+':
                result = b + a;
                break;
            case '-':
                result = b - a;
                break;
            case '*':
                result = b * a;
                break;
            case '/':
                result = b / a;
                break;
            default:
                cout << "Invalid operator" << endl;
                return 0;
            }
            valueStack.push(result);
        }
    }
    return valueStack.peek();
}

int main()
{
    string x;

    cout << "Enter a postfix expression: ";
    cin >> x;

    int result = PostfixExpression(x);

    cout << "Result: " << result << endl;

    return 0;
}
