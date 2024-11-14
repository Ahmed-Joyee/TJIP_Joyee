//TC:O(n)
//MC: O(1)

class Solution {
public:
    int pairSum(ListNode* head) {
        if(!head) return 0;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        int maxsum = 0;
        ListNode* first = head;
        ListNode* second = prev;
        while(second) {
            maxsum = max(maxsum, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxsum;
    }
};
