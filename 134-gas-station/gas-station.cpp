class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i;
        int n=gas.size();

        vector<int> v(n+10);
        for(i=0;i<n;++i)
         v[i]=gas[i]-cost[i];

         int total=0;
         int start=0;
         int sum=0;

        for(i=0;i<n;++i)
         {
            total+=v[i];
            sum+=v[i];
            if(total<0)
             {
               start=i+1;
               total=0;
             }
         }
         
         if(sum<0)
          return -1;
         else
          return start;
        
        
    }
};