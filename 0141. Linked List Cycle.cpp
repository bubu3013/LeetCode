// solution 1: C++

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

// solution 2: C++
// avoid "fast->next->next"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        return helper(head);
    }
private:
    bool helper(ListNode *head){
        bool ans = false;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && slow != NULL){
            // fast moves forward for two steps
            fast = fast->next;
            if (fast == NULL || fast->next == NULL){
                ans = false;
                break;
            }else{
                fast = fast->next;
            }
            // slow moves forward for one step
            slow = slow->next;
            // to determine if it exists a cycle
            if (fast != NULL && slow != NULL && fast == slow ){
                ans = true;
                break;
            }
        }
        return ans;
    }
};
