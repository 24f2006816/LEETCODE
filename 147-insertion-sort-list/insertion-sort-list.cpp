/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode dummy(0);

        ListNode* curr = head;

        while (curr != NULL) {

            // next node save kar lo
            ListNode* next = curr->next;

            // sorted list ke beginning se search
            ListNode* prev = &dummy;

            // correct position find karo
            while (prev->next != NULL &&
                   prev->next->val <= curr->val) {

                prev = prev->next;
            }

            // curr ko beech mein insert karo
            curr->next = prev->next;
            prev->next = curr;

            // next unsorted node
            curr = next;
        }

        return dummy.next;
    }
};