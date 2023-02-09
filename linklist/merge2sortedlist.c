/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    struct ListNode *tmp1;
    struct ListNode *tmp2;
    struct ListNode *tail;
    struct ListNode *head;
    struct ListNode *temp;

    tmp1 = list1;
    tmp2 = list2;
    tail = NULL;
    head = NULL;

    while (tmp1 || tmp2) {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!head) {
            head = temp;
            head -> next = NULL;
            tail = temp;
        } else {
            tail -> next = temp;
            tail = temp;
            tail -> next = NULL;
        }

        if (tmp1 && tmp2) {
            if (tmp1 -> val <= tmp2 -> val) {
                temp -> val = tmp1 -> val;
                tmp1 = tmp1 -> next;
            } else {
                temp -> val = tmp2 -> val;
                tmp2 = tmp2 -> next;
            }
        } else if (tmp1) {
            temp -> val = tmp1 -> val;
            tmp1 = tmp1 -> next;
        } else {
            temp -> val = tmp2 -> val;
            tmp2 = tmp2 -> next;
        }

    }


    return head;
}
