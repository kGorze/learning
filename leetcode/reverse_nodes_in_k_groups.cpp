#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* getKth(ListNode* current, int k) {
    while (current && k > 0) {
        current = current->next;
        --k;
    }
    return current; 
}


ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode* prev = tail->next;        
    ListNode* curr = head;
    while (prev != tail) {              
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return tail;                       
}


ListNode* reverseKGroup(ListNode* head, int k) {
    if (k <= 1 || !head) return head;
    ListNode* sentinel = new ListNode(0, head); 
    ListNode* groupPrev = sentinel;
    while (true) {
        ListNode* kth = getKth(groupPrev, k);   
        if (!kth) break;                        
        ListNode* groupNext = kth->next;        
        ListNode* first = groupPrev->next;      

        ListNode* newHead = reverse(first, kth);

        groupPrev->next = newHead;             
        groupPrev = first;                      
    }
    ListNode* res = sentinel->next;
    delete sentinel;                             
    return res;
}

int main(){
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 2;
    ListNode* result = reverseKGroup(head, k);
    while(result){
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}