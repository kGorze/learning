#include <iostream>


struct ListNode {

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
//should aim for the O(n) time and O(1) space
ListNode* slow = head;
ListNode* fast = head;
for(int i = 0; i < n; i++) fast = fast->next;
if(fast == nullptr) return head->next;
while(fast->next != nullptr){
    slow = slow->next;
    fast = fast->next;
}
slow->next = slow->next->next;
return head;
}

int main(){
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2;
    ListNode* result = removeNthFromEnd(head, n);
    while(result != nullptr){
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}