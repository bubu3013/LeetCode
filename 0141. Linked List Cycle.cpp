/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode * fast = head;
        ListNode * slow = head;
        
        while (fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            
            if (slow == fast)break;
        }
        return (fast->next == NULL || fast->next->next == NULL) ? false : true;
    }
};

// Runtime: 12 ms, faster than 84.85% of C++ online submissions for Linked List Cycle.
// Memory Usage: 8.1 MB, less than 18.13% of C++ online submissions for Linked List Cycle.
