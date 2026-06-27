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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (left && right){
            if (left->val <= right->val){
                tail->next = left;
                left = left->next;
            }
            else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if (left)
            tail->next = left;
        if (right)
            tail->next = right;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;

        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};