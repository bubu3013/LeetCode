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

//solution 1 - find the middle one
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode * cur = head;
//         count the number of nodes
        while(cur){
            cur = cur->next;
            n++;
        }
        n = n/2;
        
        cur = head;
        while (n--){
            cur = cur->next;
        }
        return cur;
    }
};

// Runtime: 3 ms, faster than 61.93% of C++ online submissions for Middle of the Linked List.
// Memory Usage: 7.2 MB, less than 21.61% of C++ online submissions for Middle of the Linked List.

// solution 2 - fast and slow - two pointers

// slow & fast
// (1) "1" -> 2 -> 3 -> 4 -> 5 &  "1" -> 2 -> 3 -> 4 -> 5
// (2) 1 -> "2" -> 3 -> 4 -> 5 &  1 -> 2 -> "3" -> 4 -> 5
// (3) 1 -> 2 -> "3" -> 4 -> 5 &  1 -> 2 -> 3 -> 4 -> "5"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        
        while (slow && fast){ //while(fast && fast->next) is better
            if (fast->next == NULL)break;
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
// Memory Usage: 7.2 MB, less than 21.61% of C++ online submissions for Middle of the Linked List.

// solution 3 - avoid of using fast->next->next

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        return helper(head);
    }
private:
    ListNode* helper(ListNode* head) {
        if (head == NULL)return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && slow){ 
            fast = fast->next;
            if (fast){
                fast = fast->next; // the fast pointer moves forward twice everytime
            }else{
                break;
            }
            slow = slow->next; // the slow pointer moves forward once everytime
        }
        return slow;
    }
};

// Runtime 0 ms Beats 100% 
// Memory 7 MB Beats 95.47%
