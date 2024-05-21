#include <iostream>
using namespace std;


//Custom data type
struct node 
{
    int data;
    node * next;
    node(int X,node * Y)
    {
        data = X;
        next = Y;
    }
    node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
class linkedList
{
    public:
        node * head = nullptr;
        
        // insert at the end of the linked list
        node * insert(int data)
        {

            if(head == nullptr)
            {
                head = new node(data);
            }else{
                node * temp = head;
                while(temp->next != nullptr)
                {
                    temp = temp->next;
                } 
                temp->next = new node(data);
            }
            return head;
        }

        // print data of list
        void printList()
        {   
            node * current = head;
            while(current != nullptr)
                {
                    cout<<current->data<<" -> ";
                    current = current->next;
                }
                cout<<"null"<<endl;
        }

        //search element in in the list or not
        bool searchNode(int data)
        {   
            bool flag = false;
            node * current = head;
            while(current != nullptr)
                {
                    if(current->data == data) 
                        { 
                            flag = true;
                            break;
                        }
                    current = current->next;
                }  
                return flag;
        }

        // calculate length of a Linked List
        int lengthOfList()
        {
            int len = 0;
            node * current = head;
            while(current != nullptr)
                {
                    len++;
                    current = current->next;
                }
                return len;
        }
        
        //delete first node from the Linked list
        node * deleteFirstNode()
        {   
            if(head == nullptr) return head;
            node * temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        //delete Last node from the Linked list
        node * deleteLastNode()
        {
            if(head == nullptr) return head;
            node * current = head;
            node *  temp = current;
            while(current->next !=nullptr)
            {   
                temp = current;
                current = current->next;
            }
            if(head == current) // if linked list have only one element
            {
                head = nullptr;
            }else
                temp->next = nullptr;
            delete current;
            return head;
        }
        //delete kth Node from linked list
        node * deleteKthNode(int k)
        {
            if(head == nullptr)
                return head;
            
            if(k==1)
            {
                head = deleteFirstNode();
            }else{
                node *pre = head; 
                node * temp = head->next;
                int count = 1;

                while(temp!=nullptr)
                {
                    count++;
                    if(count==k)
                    {
                        pre->next = pre->next->next;
                        delete temp;
                        break;
                    }
                    pre = temp;
                    temp = temp->next;
                }
            }
            return head;
        }

        node * insertBegin(int el)
        {
            node * temp = new node(el,head);
            head = temp;
            return head;
        }

        node * insertKthPosition(int k,int el)
        {
            if(k == 1)
            {
                head = insertBegin(el);
            }else{
                int count = 1;
                node * temp = head;
                while(temp != nullptr)
                {
                    if(count == k-1)
                    {
                        node *curr = new node(el,temp->next);
                        temp->next = curr;
                        break;
                    }
                    count++;
                    temp = temp->next;
                }
            }
                return head;
        }
};


int main() 
{
    linkedList obj = linkedList();
    obj.insert(4);
    obj.insert(9);
    obj.insert(6);
    obj.insert(10);
    obj.insert(7);
    obj.printList();
    obj.deleteKthNode(5);
    obj.printList();
    obj.insertBegin(5);
    obj.printList();
    obj.insertKthPosition(5,12);
    obj.printList();
    /*
    if(obj.searchNode(11))
    {
        cout<<"Found"<<endl;
    }else
    {
        cout<<"not found"<<endl;
    }
    cout<<obj.lengthOfList()<<endl;

    obj.deleteFirstNode();
    obj.printList();
    obj.deleteLastNode();
    obj.printList();
    obj.deleteLastNode();
    obj.deleteLastNode();
    obj.deleteLastNode();
    obj.printList();
    cout<<obj.lengthOfList()<<endl;
    */
    return 0;
}
