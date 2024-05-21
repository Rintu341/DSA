#include <iostream>
using namespace std;

 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * current = head;
        ListNode * pre = nullptr;
        ListNode * temp;
        while(current != nullptr)
        {
            temp = current->next;
            current->next = pre;
            pre = current;
            current = temp;
        }
        return pre;
    }
    ListNode * reorderList(ListNode* head) {
            if(head->next == NULL || head->next->next == NULL)
                return head;

            ListNode * fast = head;
            ListNode * slow = head;
            ListNode * temp;
            while(fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            temp = slow;
            slow = slow->next;
            temp->next = nullptr;

            ListNode * SecondPre = reverseList(slow);
            ListNode * SecondNext = SecondPre->next;

            ListNode * FirstPre = head;
            ListNode * FirstNext = head->next;

            while( SecondPre != nullptr )
            {
                FirstPre->next = SecondPre;
                SecondPre->next = FirstNext;

                FirstPre = FirstNext;
                FirstNext = FirstNext->next;

                SecondPre = SecondNext;
                if(SecondNext != nullptr)
                {   
                    SecondNext = SecondNext->next;
                }
            }
            
            return head;
            
    }

    void printList(ListNode * node)
    {
        ListNode * temp = node;

        while(temp != nullptr)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};
int main() 
{
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    
    Solution s;
    head = s.reorderList(head);
    s.printList(head);

}