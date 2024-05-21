#include <iostream>
#include <limits.h> // for INT_MIN and INT_MAX
#define MAX 100
using namespace std;


class Stack
{
    private:
        int arr[MAX];
        int top ;
        int size;

    public:
        
        Stack()
        {
            top = -1;
            size = MAX;
        }
        void push(int value)
        {
            if(top < size - 1)
            {
                arr[++top] = value;
            }else
            {
                cout<<"stack OverFlow"<<endl;
            }
        }

        int pop()
        {
            if(top == -1)
            {
                cout<<"stack is UnderFlow"<<endl;
                return -1;
            }else{
                int temp = arr[top];

                arr[top--] = INT_MIN;
                return temp;
            }   
        }

        void DisplayElement()
        {
            if(top == -1)
            {
                cout<<"stack is empty"<<endl;
            }else
            {
                for(int i = 0; i <= top; i++ )
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }

        bool isFull()
        {
            if(top == size - 1)
                return true;
            else
                return false;
        }
        bool isEmpty()
        {
            if(top == -1)
                return true;
            else
                return false;
        }
        int Size()
        {
            return top + 1;
        }
};
int main() 
{
    

    Stack s;
    s.DisplayElement();
    s.pop();
    s.push(2);
    s.push(5);
    s.DisplayElement();
    s.pop();
    s.DisplayElement();
    cout<<s.Size()<<endl;
    return 0;
}