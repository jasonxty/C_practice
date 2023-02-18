/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode * current;
    struct ListNode * prev;
    struct ListNode * next;

    prev = head;
    if (head) {
        current = head->next;
        head->next = NULL;
    } else {
        return head;
    }

    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;

}
