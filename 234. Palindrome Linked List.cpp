/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        stack<int> s;
        ListNode *optr = head;
        while (optr != NULL) {
            s.push(optr->val);
            optr = optr->next;
        }
        while (head != NULL) {
            if (head->val != s.top())
                return false;
            head = head->next;
            s.pop();
        }
        return true;
    }
};
