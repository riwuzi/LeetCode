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
 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;

        int n=lists.size();

        if(n==0)
         return NULL;

        if((n==1)&&(lists[0]==nullptr))
         return nullptr;

        int i,j;

        
        for(i=0;i<n;++i)
        {
            ListNode* current = lists[i];
            while (current != nullptr) 
                { 
                    v.push_back(current->val);
                    current = current->next; 
                } 
            
        }


        stable_sort(v.begin(), v.end());
        int f=v.size();

       
        ListNode* head=nullptr;
        ListNode* temp;
        
        
        for(i=0;i<f;++i)
          {
            ListNode* A=new ListNode(v[i]);
           
            if(head==nullptr)
             {
                temp=A;
                head=temp;
             }

            else
                temp->next=A;

            temp=A;

          }

        ListNode* temp1=head;
        
        return head;
        
    }
};