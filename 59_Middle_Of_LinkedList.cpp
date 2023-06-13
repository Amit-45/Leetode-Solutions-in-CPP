//Middle of linked list by finding length Fraz
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        //Finding the length
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        int half=n/2;
        temp=head;
        //Moving half times 
        while(half--)
        {
            temp=temp->next;
        }
        return temp;
    }
};
