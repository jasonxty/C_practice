/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode * current;
    struct ListNode * prev;

    if (!head || !head->next) {
        return head;
    }

    current = head->next;
    prev = head;

    while(current) {
        if (prev->val == current ->val) {
            prev->next = current->next;    
        } else {
            prev = current;
        }
        
        current = current->next;
    }

    return head;
}
