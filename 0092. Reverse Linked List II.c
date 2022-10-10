/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if (head->next == NULL || left == right)return head;
    struct ListNode * prev  = NULL;
    struct ListNode * forw  = NULL; //forward
    struct ListNode * left_ = NULL;
    struct ListNode * right_= NULL;
    
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next= head;

//     original order:
//     prev/dummy -> left_/right_/head -> forw
    prev = dummy;         \
    left_= right_ = head; 
    forw = head->next;    
    
    int diff = right - left;
    
//     move to the left position
    while (--left){
        prev   = prev->next;
        left_  = left_->next;
        right_ = right_->next;
        forw   = forw->next;
    }
//     start to reverse
    while (diff--){
//      1. forward points to right (reverse point)
//      2. iterate right_, forward
//      (1)
//      prev    left_      forw     temp   
//      1   ->  2     "<-" 3    ->  4    ->  5
//              right_
//      (2)
//      prev    left_      right_     fowr     temp
//      1   ->  2     "<-" 3     "<-" 4    ->  5         
        struct ListNode * temp = forw->next;
        forw->next = right_;
        right_ = forw;
        forw = temp;
    }
//      reconnect 
    prev->next = right_;
    left_->next= forw;
    return dummy->next;
}

// Runtime: 0 ms, faster than 100.00% of C online submissions for Reverse Linked List II.
// Memory Usage: 5.9 MB, less than 56.49% of C online submissions for Reverse Linked List II.
