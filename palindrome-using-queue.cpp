#include <iostream>
#define n 100
using namespace std;
class queue
{
private:
    int arr[n];
    int front;
    int rear;
public:
    queue()
    {
        front = rear = -1;
    }
    bool isFull()
    {
        return rear == n - 1;
    }
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }
    void enqueue(char x)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }
    char dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
           return front++;
        }
    }
    char peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};
bool isPalindrome(string str)
    {
        queue charQueue;

        for(char data:str){
            charQueue.enqueue(data);
        }
        string reverseStr;
        while (!charQueue.isEmpty())
        {
            reverseStr=charQueue.peek()+reverseStr;
            charQueue.dequeue();
        }
        return str==reverseStr;
    }
int main(){
    string str;
    cout<<"Enter a string : ";
    cin>>str;
    if (isPalindrome(str)) {
         cout << "The string is a palindrome." <<  endl;
    } else {
         cout << "The string is not a palindrome." <<  endl;
    }
    return 0;
}
