/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
//     initialize
    int digit = 0;
    int l1_val = 0;
    int l2_val = 0;
    bool is_carry = false; 
    
    struct ListNode * cur = NULL;    
    struct ListNode * head = (struct ListNode *)malloc(sizeof(struct ListNode));
    
    digit = l1->val + l2->val;
    is_carry = digit / 10;
    
    head->val = digit % 10;
    head->next= NULL;
    
    l1 = l1->next;
    l2 = l2->next;
    
    cur = head;
    
    while (l1 != NULL || l2 != NULL){
        
        if (l1 == NULL){l1_val = 0;}
        else {//l1 != NULL
            l1_val = l1->val;
            l1 = l1->next;
        }
        if (l2 == NULL){l2_val = 0;}
        else {//l2 != NULL
            l2_val = l2->val;
            l2 = l2->next;
        }
//         calculate
        digit = l1_val + l2_val + is_carry;
        is_carry = digit / 10;
//         linked list
        struct ListNode * new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = digit % 10;
        new->next= NULL;
        
        cur->next = new;
        cur = cur->next;
    }
    
    if (is_carry)
    {
        struct ListNode * new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = is_carry;
        new->next= NULL;
        
        cur->next = new;
        cur = cur->next;
    }
    return head;
}

