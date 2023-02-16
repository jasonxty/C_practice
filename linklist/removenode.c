/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *current;
    struct ListNode *prev;

    current = head;

    while(current) {
        if (current->val == val) {
            if (current == head) {
                head = head->next;
            } else {
                prev->next = current->next;
            }
        } else {
            prev = current;
        }
        current = current->next;
    }

    return head;
}
