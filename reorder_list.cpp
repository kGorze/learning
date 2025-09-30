#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void reorderList(ListNode* head) {
//should aim for the O(n) time and O(1) space solution
//find the middle part of the list
    if (!head) return;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* middle = nullptr;
    while (fast->next && fast->next->next) {
        slow = slow->next;           
        fast = fast->next->next;    
    }
    middle = slow; 

    //reverse the second part of the list
    ListNode* l1 = head;
    ListNode* l2 = middle->next;
    ListNode* prev = nullptr;
    while(l2 != nullptr){
        ListNode* next = l2->next;
        l2->next = prev;
        prev = l2;
        l2 = next;
    }
    l2 = prev;
    //merge the two parts of the list
    while(l1 != nullptr && l2 != nullptr){
        ListNode* next1 = l1->next;
        ListNode* next2 = l2->next;
        l1->next = l2;
        l2->next = next1;
        l1 = next1;
        l2 = next2;
    }
    l1->next = nullptr;
}

int main(){
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* result = reorderList(head);
    while(result != nullptr){
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}