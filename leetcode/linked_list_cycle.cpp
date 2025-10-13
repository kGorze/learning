#include <vector>
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


bool hasCycle(ListNode *head) {
        //aim for the O(n) time and O(1) space
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
}

int main(){
    std::vector<int> nums = {3,2,0,-4};
    int pos = 0;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for(int i = 1; i < nums.size(); i++){
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    current->next = head->next;
    std::cout << hasCycle(head) << std::endl;
    return 0;
}
