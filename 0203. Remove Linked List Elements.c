/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// solution 1 -> O(n^2)
// two pointer: cur + temp/cur->next
struct ListNode* removeElements(struct ListNode* head, int val){
    if (head == NULL)return head;
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next= head;
    
    struct ListNode * cur = dummy;    
    while (cur != NULL){
        struct ListNode * tmp = cur->next;
        while (tmp != NULL && tmp->val == val){
            tmp = tmp->next;
        }
        cur->next = tmp;
        cur = cur->next;
    }
    return dummy->next;
}

// Runtime: 17 ms, faster than 74.77% of C online submissions for Remove Linked List Elements.
// Memory Usage: 8.1 MB, less than 52.28% of C online submissions for Remove Linked List Elements.

// solution 2 -> O(n)
// two pointer: prev + cur
struct ListNode* removeElements(struct ListNode* head, int val){
    if (head == NULL)return head;
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next= head;
    
    struct ListNode * prev = dummy;
    
    while (head){
        if (head->val == val){
            prev->next = head->next;
        }
        else{
            prev = head;
        }
        head = head->next;
    }
    return dummy->next;
}
// Runtime: 21 ms, faster than 55.93% of C online submissions for Remove Linked List Elements.
// Memory Usage: 8.1 MB, less than 52.28% of C online submissions for Remove Linked List Elements.
