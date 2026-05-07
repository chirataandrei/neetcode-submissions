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

        int num_sums = 0;

        while (fast) {
            slow = slow->next;
            fast = fast->next->next;
            num_sums++;
        }
        
        vector<int> ts(num_sums);
        fast = slow;
        slow = head;
        for (int i = 0; i < num_sums; i++) {
            ts[i] += slow->val;
            ts[num_sums - i - 1] += fast->val;
            
            slow = slow->next;
            fast = fast->next;
        }

        int max_ts = -1;
        for (int i = 0; i < num_sums; i++) {
            max_ts = max(max_ts, ts[i]);
        }

        return max_ts;
    }
};