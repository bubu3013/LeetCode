/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    if (head == NULL || head->next == NULL)return head;   
//         declare
    struct ListNode * left = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * right = (struct ListNode *)malloc(sizeof(struct ListNode)); 
    struct ListNode * left_tail = left;
    struct ListNode * right_tail = right;
//          initialized
    left->val = 0;
    left->next= NULL;
    right->val = 0;
    right->next= NULL;    
    
    while (head != NULL)
    {
//          initialize new node
        struct ListNode * new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = head->val;
        new->next= NULL;
        if (head->val < x){
            left_tail->next = new;
            left_tail = left_tail->next; 
        }else
            {
            right_tail->next = new;
            right_tail = right_tail->next;
        }
        head = head->next;
    }
    left_tail->next = right->next;
    right_tail->next= NULL;
    
    return left->next;
}

//Runtime: 0 ms, faster than 100.00% of C online submissions for Partition List.
//Memory Usage: 6 MB, less than 53.59% of C online submissions for Partition List.
