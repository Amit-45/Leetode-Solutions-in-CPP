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
        ListNode* dummy = new ListNode(10000); // Create a dummy node to serve as the head of the sorted list
        
        while (head) {
            ListNode* next = head->next; // Save the next node in the original list
            ListNode* temp = dummy; // Initialize a pointer to traverse the sorted list
            
            while (temp->next && temp->next->val < head->val) {
                temp = temp->next; // Move to the next node in the sorted list
            }
            
            head->next = temp->next; // Insert the current node after temp
            temp->next = head;
            
            head = next; // Move to the next node in the original list
        }
        
        return dummy->next; // Return the sorted list (excluding the dummy node)
    }
};
