/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head->next == NULL){return head;}
    
    bool remove = false;
    struct ListNode * cur = head->next;
//     to find the node right after duplicates
    while (head->val == cur->val)
    {
        cur = cur->next;
        remove = true;
        if (cur == NULL)break;
    }
//     reconnect
    head->next = deleteDuplicates(cur);
    if (remove){
        head = head->next;
    }
    return head;

// Runtime: 7 ms, faster than 73.33% of C online submissions for Remove Duplicates from Sorted List II.
// Memory Usage: 6.5 MB, less than 45.56% of C online submissions for Remove Duplicates from Sorted List II.
