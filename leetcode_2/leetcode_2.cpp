#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        else if (!l2)  return l1;
        ListNode* result = new ListNode;
        int jinwei = 0;
        if (l1->val + l2->val + jinwei >= 10) {
            result->val = l1->val + l2->val + jinwei - 10;
            jinwei = 1;
        }
        else {
            result->val = l1->val + l2->val + jinwei; jinwei = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
        ListNode* temp = result;
        while (l1 && l2)
        {
            temp->next = new ListNode;
            temp = temp->next;
            if (l1->val + l2->val + jinwei >= 10) {
                temp->val = l1->val + l2->val + jinwei - 10;
                jinwei = 1;
            }
            else {
                temp->val = l1->val + l2->val + jinwei;
                jinwei = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 && !l2)
        {
            temp->next = new ListNode;
            temp = temp->next;
            if (l1->val + jinwei == 10) {
                temp->val = 0;
                jinwei = 1;
            }
            else { temp->val = l1->val + jinwei; jinwei = 0; }
            l1 = l1->next;
        }
        while (!l1 && l2)
        {
            temp->next = new ListNode;
            temp = temp->next;
            if (l2->val + jinwei == 10) {
                temp->val = 0;
                jinwei = 1;
            }
            else { temp->val = l2->val + jinwei; jinwei = 0; }
            l2 = l2->next;
        }
        if (jinwei == 1) { temp->next = new ListNode(1); return result; }
        else return result;
    }
};
int main(){
    
    return 0;
}
