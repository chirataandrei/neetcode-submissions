/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *curr = slow;
        ListNode *prev = nullptr;
        while (slow != nullptr) {
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        int max_ts = -1;
        slow = head;
        while (prev != nullptr) {
            max_ts = max(max_ts, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }

        return max_ts;
    }
};