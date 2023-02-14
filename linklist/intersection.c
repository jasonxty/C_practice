/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tmpA = headA;
    struct ListNode *tmpB = headB;

    while(tmpA) {
       while(tmpB) {
           if (tmpA == tmpB) {
               return tmpA;
           }
           tmpB = tmpB->next;
       }
       tmpA = tmpA->next;
       tmpB = headB;
    }

    return NULL;
}
