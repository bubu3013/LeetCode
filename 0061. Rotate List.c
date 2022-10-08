/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// solution 1

struct ListNode* rotateRight(struct ListNode* head, int k){
    
    if (head == NULL || k == 0)return head;
    int i = 0;
    int total = 1;
    struct ListNode * cur = NULL;
    struct ListNode * tail= NULL;
    
    cur = head;
    while (cur ->next != NULL){
        total++;
        cur = cur->next;
    }
    cur->next = head;
    k = k % total;
//     find the tail
    tail = head;
    for (i = 0; i < total - k - 1; i++){tail = tail->next;}
    head = tail->next;
    tail->next = NULL;
    
    return head;
  
//   solution 2 - recursive
  
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
//   basic case
    if (k == 0 || head == NULL)return head;
//   recursive case    
    else
    {
        int total = 1;
        struct ListNode * cur = head;
        while (cur->next != NULL){
            cur = cur->next;
            total++;
        }
        if (k % total == 0)return head; //!!! this line is important
        cur->next = head;
        head = cur;
        
        while (cur->next != head){cur = cur->next;}
        cur->next = NULL;

        return rotateRight(head, k-1);
    }
}
