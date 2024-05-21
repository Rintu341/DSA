#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *List1 = l1,*List2 = l2,*temp3,*temp;
        temp3 = new ListNode();
        temp = temp3;
        int sum=0,carry=0;
        while(1){
            if(List1==NULL||List2 == NULL)
                break;
            else{
                sum = List1->val + List2 ->val;
                if(sum>=10){
                    
                }
            }
        }
        return temp;
    }
 }; 
int main(){
    
    return 0;
}