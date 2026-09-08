class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length and tail
        int n = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            n++;
        }

        // k can be greater than n
        k = k % n;

        if (k == 0)
            return head;

        // Make circular
        tail->next = head;

        // Find new tail
        int steps = n - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break circular link
        newTail->next = NULL;

        return newHead;
    }
};