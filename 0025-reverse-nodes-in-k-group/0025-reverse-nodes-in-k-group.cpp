class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;

        // Check if k nodes exist
        for(int i = 0; i < k; i++) {
            if(temp == NULL)
                return head;

            temp = temp->next;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        int cnt = 0;

        while(curr != NULL && cnt < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};