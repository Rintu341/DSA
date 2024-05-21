#include <iostream>
#include <vector>
using namespace std;


class DynamicStack
{
    private:
        vector<int> arr;
        vector<int> minStack;
        int top ;
    public:
        DynamicStack()
        {
            top = -1;
        }    

        void push(int value)
        {      
            if(top == -1)
            {
                minStack.push_back(value);
            }else{
                if(value < minStack[top])
                {
                    minStack.push_back(value);
                }else{
                    int temp = minStack[top];
                    minStack.push_back(temp);
                }
            }
            arr.push_back(value);
            top++;
        }

        int pop()
        {
            if(top == -1)
            {
                cout<<"Stack UnderFlow"<<endl;
                return -1;
            }else{
                int temp = arr[top];
                arr.pop_back();
                top--;
                return temp;
            }
        }

        void display()
        {
            if(top == -1)
            {
                cout<<"Stack is empty"<<endl;
            }else
            {
                for(int i = 0 ; i <= top; i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }

        int topElement()
        {
            return arr[top];
        }

        bool isEmpty()
        {
            if(top == -1)
            {
                return true;
            }else{
                return false;
            }
        }

        bool isFull()
        {
            if(top < arr.size()-1)
            {
                return false;
            }else
            {
                return true;
            }
        }
        int currentMin()
        {
            return minStack[top];
        }
    
};
int main() 
{
    DynamicStack st;
        st.display();
        st.push(3);
        cout<<st.currentMin()<<endl;
        st.push(9);
        cout<<st.currentMin()<<endl;
        st.push(6);
        cout<<st.currentMin()<<endl;
        st.push(1);
        cout<<st.currentMin()<<endl;
        st.push(8);
        cout<<st.currentMin()<<endl;
        st.pop();
        st.display();
    return 0;
}