class Solution {
public:
    int numSquares(int n) {

        if(n==1)
            return 1;
        if(n==2)
         return 2;
        if(n==3)
            return 3;
        if(n==4)
            return 1;
        if(n==5)
            return 2;
        if(n==6)
            return 3; 
        std::vector<int> v(10005,-1);
        v[0]=0;
        v[1]=1;  
        v[2]=2;   
        v[3]=3;   
        v[4]=1;   
        v[5]=2;    
        v[6]=3;

        for(int i=1;i*i<=n;++i)
            v[i*i]=1;

        for(int i=7;i<=n;++i)
        { 
            if(v[i]!=-1)//have not been decided
                continue;
            else
            {
                int count=5000000;
                for(int j=1;j<=i/2;++j)
                    {   
                        
                        
                            
                        int current_num = v[j]+v[i-j];
                        if(current_num<count)
                            count = current_num; 
                            
                    
                    }
            
                v[i]=count;
            }
        }
        
        
        return v[n];
        
    }
};