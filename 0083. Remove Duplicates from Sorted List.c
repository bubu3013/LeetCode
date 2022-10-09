struct ListNode* deleteDuplicates(struct ListNode* head){
//     basic 
    if (head == NULL || head->next == NULL)return head;
//     recursive
    struct ListNode * cur = head;
//     to find the ""last duplicates""
    while (cur->val == cur->next->val)
    {
        cur = cur->next;
//     the special case if the duplicates is the last one
        if (cur->next == NULL)break;
    }
//     reconnect to the next node, and re-do the same procedure
    head->next = deleteDuplicates(cur->next);
    return head;
}

// Runtime: 8 ms, faster than 70.14% of C online submissions for Remove Duplicates from Sorted List.
// Memory Usage: 6.3 MB, less than 99.56% of C online submissions for Remove Duplicates from Sorted List.


struct ListNode* deleteDuplicates(struct ListNode* head){
//     basic 
    if (head == NULL || head->next == NULL)return head;
//     recursive
    struct ListNode * cur = head->next;
//     to find the node ""right after"" duplicates
    while (head->val == cur->val)
    {
        cur = cur->next;
        if (cur == NULL)break;
    }
//     reconnect to the next node, and re-do the same procedure
    head->next = deleteDuplicates(cur);
    return head;
}
// Runtime: 4 ms, faster than 90.00% of C online submissions for Remove Duplicates from Sorted List II.
// Memory Usage: 6.3 MB, less than 93.70% of C online submissions for Remove Duplicates from Sorted List II.
