/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
//     declare
    int i = 0;
    int total = 0;
    struct ListNode * cur = NULL;
    struct ListNode * prev= NULL;
    struct ListNode * following = NULL;
    
    cur = head;
    while (cur != NULL){
        ++total;
        cur=cur->next; //!!
    }
    if (total == 1){return NULL;}
    else if (total == 2 && n == 1)
    {
        head->next = NULL;
    }
    else if (total == n) //!!
    {
        head = head->next;   
    }
    else{ // n > 3
         total = total - n;
//     to find the prev one
        cur = head;
        for (int i = 0; i < total -1; i++){cur=cur->next;}
        prev = cur;
//     to find the following one
        following = cur->next->next;
// connect prev to following
        prev->next = following;
    }
    return head;
}
