#include <iostream>


struct ListNode {

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  //aim for the O(m+n) time and O(1) space
  int carry = 0;
  ListNode dummy(0);
  ListNode* tail = &dummy;

  while(l1 || l2 || carry){
    int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
    carry = sum / 10;
    int digit = sum % 10;
    tail->next = new ListNode(digit);
    tail = tail->next;
    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
  }
return dummy.next;
}

int main(){
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result = addTwoNumbers(l1, l2);
    while(result != nullptr){
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}