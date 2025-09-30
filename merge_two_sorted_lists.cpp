#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
 //O(n+m), O(1)
 ListNode* dummy = new ListNode();
 ListNode* tail = dummy;
 while(list1 != nullptr && list2 != nullptr){
    if(list1->val <= list2->val){
        tail->next = list1;
        list1 = list1->next;
    }else{
        tail->next = list2;
        list2 = list2->next;
    }
    tail = tail->next;
 }
 tail->next = (list1 ? list1 : list2);
 ListNode* head = dummy->next;
 delete dummy;
 return head;
}

int main(){
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* result = mergeTwoLists(list1, list2);
    while(result != nullptr){
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}