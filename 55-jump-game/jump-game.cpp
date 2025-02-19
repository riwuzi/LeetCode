class Solution {
public:
    

    int pass(vector<int>& nums,int start,int end)//BFS
    {
      queue<int> nums_queue;
      vector<int> flag(110000,0);

      int i,j;

      if(start==end)
       return 1;
      else
      {
        nums_queue.push(end);
        flag[end]=1;
        while (!nums_queue.empty()) 
        {
            int k=nums_queue.front();
            if(k==start)
             return 1;
            else
             {
                for(i=0;i<k;++i)
                 if((flag[i]==0)&&((k-i)<=nums[i]))
                 { 
                    nums_queue.push(i);
                    flag[i]=1;

                 }
                   

                nums_queue.pop();
             }
        }

      }
      return 0;

    }

    bool canJump(vector<int>& nums) {
        
        int len=nums.size();//the length of the nums
        int end=len-1;

        
        if(pass(nums,0,end))
         return true;
        else
         return false;
         
    }
};