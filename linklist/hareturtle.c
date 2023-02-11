/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
   
    //hare
    struct ListNode *current1;
    //turtle
    struct ListNode *current2;
    
    current1 = head;
    current2 = head;

    while(current1 && current1->next) {
        current1 = current1->next->next;
        current2 = current2->next;

        if (current1 == current2)
            return true;
    }

    return false;
}
