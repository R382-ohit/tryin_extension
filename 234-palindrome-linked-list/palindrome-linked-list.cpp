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
    ListNode* reverseLL(ListNode* curr) {

        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* p2 = reverseLL(slow);
        ListNode* p1 = head;
        while (p1 != NULL && p2 != NULL) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};