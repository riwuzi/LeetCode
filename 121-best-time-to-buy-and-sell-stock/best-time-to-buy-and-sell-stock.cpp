class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==1)
            return 0;

        int max_profit=-100000;
        
        std::vector<int> min_price(100005);
        min_price[0]=prices[0]; 

        for(int i=1;i<len;++i)
            {
                min_price[i]=min(min_price[i-1],prices[i-1]);
                int curren=prices[i]-min_price[i];
                if(max_profit<curren)
                    max_profit=curren;
            }
        
        if(max_profit<0)
            return 0;
        else
            return max_profit;
        
    }
};