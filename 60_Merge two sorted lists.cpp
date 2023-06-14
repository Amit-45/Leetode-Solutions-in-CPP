// Assuming ListNode class is properly defined

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // base case
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        // Dummy node
        ListNode *ans = new ListNode(-1);
        ListNode *tail = ans;

        // till both the l1 and l2 become empty
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1; // tail ke next me l1 attach karo
                tail = l1;       // tail ko aage badhao
                l1 = l1->next;   // l1 ko bhi aage badhao
            }
            else
            {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }

        if (l1 == NULL)
        { // agar l1 khatam ho gya
            tail->next = l2;
        }
        if (l2 == NULL)
        { // agar l2 khatam ho gya
            tail->next = l1;
        }

        return ans->next;
    }
}; // Don't forget the semicolon at the end of the class definition
