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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode(0);
        ListNode *pos = ans;

        int addOne = 0;
        while (l1 != NULL && l2 != NULL) {
            int res = l1->val + l2->val + addOne;
            pos->next = new ListNode(res % 10);;
            pos = pos->next;
            addOne = res / 10;

            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *tail = l1;
        if (tail == NULL)
            tail = l2;

        while (tail != NULL) {
            int res = tail->val + addOne;
            pos->next = new ListNode(res % 10);
            pos = pos->next;
            
            addOne = res / 10;
            tail = tail->next;
        }
        if (addOne == 1) 
            pos->next = new ListNode(1);
        
        return ans->next;
    }
};