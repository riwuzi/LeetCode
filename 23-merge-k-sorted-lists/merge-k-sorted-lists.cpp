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

        cout<<"AAA"<<endl;

        for(i=0;i<n;++i)
        {
            ListNode* current = lists[i];
            while (current != nullptr) 
                { 
                    v.push_back(current->val);
                    current = current->next; 
                } 
            
        }

        cout<<"BBB"<<endl;

        stable_sort(v.begin(), v.end());
        int f=v.size();

       // for(i=0;i<f;++i)
       //  cout<<v[i]<<" ";
       // cout<<endl;


        ListNode* head=nullptr;
        ListNode* temp;
        
        cout<<"CCC"<<endl;
        for(i=0;i<f;++i)
          {
            ListNode* A=new ListNode(v[i]);
           

            cout<<"DDD: "<<i<<endl;

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
        while (temp1 != nullptr) 
            { 
                cout<<temp1->val<<" ";
                temp1 = temp1->next; 
            } 
        cout<<"EEE"<<endl;
        return head;
        
    }
};