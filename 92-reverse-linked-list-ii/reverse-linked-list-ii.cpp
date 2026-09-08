class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right)
            return head;

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Find node just before left
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Reverse from left to right
        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; i++) {

            ListNode* temp = curr->next;

            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next;
    }
};