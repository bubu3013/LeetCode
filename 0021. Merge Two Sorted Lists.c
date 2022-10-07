/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
// by l1 to choose the smaller candidates
    struct ListNode * cur = NULL;
    struct ListNode * cur_1 = list1;
    struct ListNode * cur_2 = list2;
    
    if (list1 == NULL)return list2;
    else if (list2 == NULL)return list1;
    
    struct ListNode * head = (struct ListNode *)malloc(sizeof(struct ListNode)); //!!
    
    if (cur_1->val < cur_2->val){
        head->val = cur_1->val;
        cur_1 = cur_1->next;
    }else
    {
        head->val = cur_2->val;
        cur_2 = cur_2->next;
    }
    head->next = NULL;
    
    cur = head;
    while (cur_1 != NULL || cur_2 != NULL){
        struct ListNode * new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->next = NULL;
//         assign value
        if (cur_1 == NULL)
        {
            new->val = cur_2->val;
            cur_2 = cur_2-> next;
        }else if (cur_2 == NULL || cur_1->val < cur_2->val)
        {
            new->val = cur_1->val;
            cur_1 = cur_1->next;
        }else if (cur_1->val < cur_2->val)
        {
            new->val = cur_1->val;
            cur_1 = cur_1->next; 
        }else {
            new->val = cur_2->val;
            cur_2 = cur_2-> next;
        }
        cur->next = new;
        cur = cur->next;
    }
    return head;
}
