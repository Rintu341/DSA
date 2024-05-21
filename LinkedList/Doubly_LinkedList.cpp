#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node * next;
    Node * prev;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
    Node(int data ,Node * next,Node * prev )
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node * Tail = nullptr;
Node * head = nullptr;

// insertion of Node in Doubly Linked List
void insertAtTail(int data)
{   
    Node * temp = new Node(data);
    if(head == nullptr)
    {
        head = temp;
        Tail = head;
        return;
    }
    Tail->next = temp;
    temp->prev = Tail;
    Tail = temp;
    
}

void insertAtHead(int data)
{
    Node * temp = new Node(data);
    if(head == nullptr)
    {
        head = temp;
        Tail = head;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtKthElement(int k,int data)
{
    if((head == nullptr && k == 1) || k==1)
    {
        insertAtHead(data);
        return;
    }

    int count = 1;
    Node * temp = head->next;
    while(temp != nullptr)
    {
        count++;
        if(count == k)
        {
            Node * preNode = temp->prev;
            Node * newNode = new Node(data,temp,preNode);
            preNode->next = newNode;
            temp->prev= newNode;
            return;
        }
        temp = temp->next;
    }
}

// Deletion of Node in Doubly Linked list 

void deleteHead()
{   
    if(head == nullptr)
        return;
    Node * temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}
void deleteKthElement(int k)
{   
    if(head == nullptr)
        return;

    if(k == 1)
    {
        deleteHead();
        return;
    }

    int count = 1;
    Node * temp = head->next;
    while(temp != nullptr)
    {
        count++;
        if(count == k)
        {
            Node * preNode = temp->prev;
            Node * nextNode = temp->next;
            preNode->next = nextNode;
            nextNode->prev = preNode;
            delete temp;
            return;
        }
        temp = temp->next;
    }
}
void deleteTail()
{   
    if(Tail == nullptr)
        return;
    Node * temp = Tail;
    Tail = Tail->prev;
    Tail->next = nullptr;
    delete temp;
}

// Display Node in Doubly Linked List

void displayNodeValues()
{
    Node * curr = head;

    if(head == nullptr)
        return;

    while(curr != nullptr)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
void displayNodeValuesBackWard()
{
    Node * curr = Tail;
    if( Tail == nullptr)
        return;

    while(curr != nullptr)
    {
        cout<<curr->data<<" ";
        curr = curr->prev;
    }
    cout<<endl;
}
int main() 
{
    insertAtTail(17);
    insertAtTail(12);
    insertAtTail(11);
    insertAtTail(34);
    insertAtTail(45);
    displayNodeValues();
    deleteKthElement(2);
    displayNodeValues();
    insertAtKthElement(4,8);
    displayNodeValues();
    deleteHead();
    displayNodeValues();
    deleteTail();
    displayNodeValues();
    return 0;
}