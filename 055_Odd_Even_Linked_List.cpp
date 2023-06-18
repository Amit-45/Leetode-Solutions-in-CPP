//OddEvenElements Leetcode -> codebix
//Question is - Bring all even positioned elements to one side and odd positioned to the othe
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;                // Pointer for odd-indexed nodes
        ListNode* even = head->next;         // Pointer for even-indexed nodes
        ListNode* evenHead = even;           // Head of the even-indexed nodes

        while (odd->next != nullptr && even->next != nullptr)
         {
            odd->next = even->next;          // Link the odd node to the next odd-indexed node
            odd = odd->next;                 // Move the odd pointer to the next odd-indexed node
            even->next = odd->next;          // Link the even node to the next even-indexed node
            even = even->next;               // Move the even pointer to the next even-indexed node
        }

        odd->next = evenHead;                 // Link the end of odd-indexed nodes with the start of even-indexed nodes

        return head;                          // Return the head of the rearranged linked list
    }
};
