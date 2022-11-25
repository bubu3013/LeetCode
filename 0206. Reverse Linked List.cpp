// solution 1: iterative

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)return NULL;
        return reverse(head);
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode(-5005);// create the dummy node
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        while (cur){ // reverse the list
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        head->next = NULL;
        return prev;
    }
};

// Runtime 3 ms Beats 98.83% 
// Memory 8.2 MB Beats 79.9%

// solution 2: recursion

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)return NULL;
        ListNode* dummy = new ListNode(-5005);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        ListNode* new_head = reverse(cur, prev);
        head->next = NULL;
        return new_head;
    }
    ListNode* reverse(ListNode* cur, ListNode* prev) {
        if (cur == NULL){return prev;}
        cout<<cur->val<<endl;
        ListNode* tmp = cur->next;
        cur->next = prev;
        prev = reverse(tmp, cur);
        cur = tmp;
        return prev;
    }
};

// Runtime 16 ms Beats 30.60% 
// Memory 8.3 MB Beats 40.34%
