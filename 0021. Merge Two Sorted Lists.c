struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * head = NULL;
    
//     if any of lists is empty, than return the other list
    if (l1 == NULL)return l2;
    else if (l2 == NULL)return l1;
//     choose the smaller one as the next one
    else if (l1->val < l2->val){
        head = l1;
        head->next = mergeTwoLists(l1->next, l2);
    }
    else if (l1->val >= l2->val){
        head = l2;
        head->next = mergeTwoLists(l1, l2->next);
    }
// you have to what you return in basic case
    return head;
}
