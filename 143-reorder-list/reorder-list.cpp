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
    ListNode* left;
    bool reorder(ListNode* right){
        if (right == nullptr) return true;
        if(!reorder(right->next)){
            return false;
        }
        if (left == right || left->next == right){
            right->next = nullptr;
            return false;
        }
        ListNode* nextLeft = left->next;
        left->next = right;
        right->next = nextLeft;
        left = nextLeft;
        return true;
    }
    void reorderList(ListNode* head) {
        left = head;
        reorder(head);
    }
};