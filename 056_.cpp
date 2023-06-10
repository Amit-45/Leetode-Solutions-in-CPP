class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;     // Pointer to track the current node
        ListNode* second = head;    // Pointer to track the (n+1)-th node from the beginning

        // Move the second pointer to the n-th node from the beginning
        for (int i = 1; i <= n; i++) {
            if (second == nullptr)
                return head;        // If n is greater than the length of the list, no removal is needed
            second = second->next;
        }

        // Handle the case where the first node is to be removed
        if (second == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Move both pointers until the second pointer reaches the end of the list
        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        ListNode* temp = first->next;
        first->next = temp->next;
        delete temp;

        return head;
    }
};

