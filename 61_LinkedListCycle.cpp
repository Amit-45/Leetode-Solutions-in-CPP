class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode *p,*q;
         p=q=head;
         if(head==NULL||head->next==NULL) return false;
         while(p!=NULL)
         {
             p=p->next;
             if(p!=NULL)p=p->next;
             if(p==q) return true;
             q=q->next;
         }   
         return false;
         }
};
