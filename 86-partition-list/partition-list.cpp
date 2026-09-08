class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);

        ListNode* small = smallDummy;
        ListNode* large = largeDummy;

        ListNode* curr = head;

        while (curr != NULL) {

            if (curr->val < x) {
                small->next = curr;
                small = small->next;
            }
            else {
                large->next = curr;
                large = large->next;
            }

            curr = curr->next;
        }

        // Important: large list ka end NULL karo
        large->next = NULL;

        // Small list ke end ko large list se connect karo
        small->next = largeDummy->next;

        return smallDummy->next;
    }
};