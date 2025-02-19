class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        

        int len=nums.size();
        if(len==1)
            return 1;
        std::vector<int> larger(len+20, 0);      //  要素数10、全ての要素の値5 

        int max_count=-1000000000;

        for(int i=len-1;i>=0;--i)
            {
                int flag=0;
                int max_large=-100000000;
                for(int j=i+1;j<len;++j)
                {
                    
                    
                    if(nums[j]<=nums[i])
                        continue;
                    else
                    {
                        if(larger[j]>max_large)
                        {
                            flag=1;
                            max_large=larger[j];
                        }
                        else
                            continue;
                    }
                    
                }
                if(flag)
                    larger[i]+=(max_large+1);
                
            }
        
        int max = *std::max_element(larger.begin(), larger.end());
        return (max+1);
        
    }
};