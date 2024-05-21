#include <iostream>
using namespace std;

struct node 
{
    int data;
    node * next;
    node * prev;

    node(int X,node * Y,node * Z)
    {
        data = X;
        next = Y;
        prev = Z;
    }
    node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class circularLinkedList
{
    private:
    node * Head = nullptr;
    node * Tail = nullptr;

    bool InsertIfEmptyList(int data)
    {
        if(Head == nullptr && Tail == nullptr)
        {
            Head = new node(data);
            Tail = Head;
            Head->prev = Tail;
            Tail->next = Head;  
            return true;
        }
        return false;
    }

    public:
    void InsertAtBegin(int data)
    {
        if(InsertIfEmptyList(data))
            return;

        node * temp ;
        temp = new node(data);
        temp->next = Head;
        Head->prev = temp;
        Head = temp;
        Head->prev = Tail;
        Tail->next = Head;
    }
    void InsertAtMiddle(int data,int index)
    {   
        if(Head == nullptr || index == 0)
        {
            InsertAtBegin(data);
            return;
        }

        node * curr = Head->next; 
        int count = 1;
        while(curr != Head)
        {
            
            if(count  == index)
            {
                node * temp = new node(data);
                node * prev = curr->prev;

                temp->next = curr;
                temp->prev = prev;
                curr->prev = temp;
                prev->next = temp;
                
                return ;
            }
            count++;
            curr = curr->next; 
        }   
        cout<<count<<endl;
        
    }
    void InsertAtEnd(int data)
    {
        if(InsertIfEmptyList(data))
            return;

        node * temp ;
        temp = new node(data);
        temp->prev = Tail;
        Tail->next = temp;
        Tail = temp;
        Head->prev = Tail;
        Tail->next = Head;

    }
    void display()
    {
        node * curr = Head;
        if(curr == nullptr){
            cout<<"Nothing in the List"<<endl;
            return;
        }
        if(curr->next == nullptr)
        {
            cout<<curr->data<<" "<<endl;
            return;
        }
        cout<<curr->data<<" ";
        curr = curr->next;
        while(curr!= Head)
        {
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }


};
int main()
{
    circularLinkedList obj;
    obj.display();
    obj.InsertAtBegin(6);
    obj.display();
    obj.InsertAtBegin(9);
    obj.InsertAtBegin(7);
    obj.display();
    obj.InsertAtEnd(12);
    obj.display();
    obj.InsertAtMiddle(34,4);
    obj.display();
    return 0;
}