// solution 1: C
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

// solution 2: C++

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1, list2);
    }
private: 
    ListNode * merge(ListNode* list1, ListNode* list2){
        // base case
        if (list1 == NULL && list2 == NULL){
            return NULL;
        }else if (list1 == NULL){
            return list2;
        }else if (list2 == NULL){
            return list1;
        }

        // recursive case
        ListNode *tmp = new ListNode(-105);
        if (list1->val < list2->val){
            tmp->next = list1;
            list1->next = merge(list1->next, list2);
        }else{
            tmp->next = list2;
            list2->next = merge(list1, list2->next);
        }
        return tmp->next;
    }
};

// Runtime 14 ms Beats 55.9% 
// Memory 22.6 MB Beats 8.11%
