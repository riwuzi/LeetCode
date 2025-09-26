class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int N=points.size();
        if(N==1)
         return 1;
        
        if(N==2)
         return 2;
        
       
        double inf = INFINITY; // C言語
      
        int i,j;
        int num=0;

       
        
        for(i=0;i<N-1;++i)
    {
         map<double,int>  slope_P;
        // int F=0;
    
        for(j=i+1;j<N;++j)
         {
            double slope;
            if(points[i][0]==points[j][0])
               //slope=1.0*(points[i][0]-points[j][0]);
               slope=inf;
            else if(points[i][1]==points[j][1])
             slope=0.0;
            else
               { slope=(1.0*(points[i][1]-points[j][1]))/(1.0*(points[i][0]-points[j][0]));//cout<<slope<<endl;
               }


           // ++F;
          //  cout<<"find the "<<F<<" times"<<endl;
          //  cout<<"confirm the slope_P"<<endl;
          //  for(auto& key_value: slope_P)
          //   {
          //      double a=key_value.first;
           //     int b = key_value.second;
               // cout<<a<<" "<<b<<endl;
                
         

            std::map<double,int>::iterator x;
            x = slope_P.find(slope);
            if (x != slope_P.end()) {
                //
                //check if the value is on
                //++slope_P[slope];
                ++x->second;
              //  cout<<"++"<<endl;
               // cout<<"add a point"<<" the i is "<<i<<" the j is"<<j<<endl;

            } else {
                //add new slope
                slope_P.insert(pair<double, int>(slope, 1));
              //  cout<<"insert"<<endl;

               // cout<<"add a new slope"<<" the i is "<<i<<" the j is"<<j<<endl;
            }
        
         }



         
         for(auto& key_value: slope_P) {
                double k=key_value.first;
                int len = key_value.second+1;
                num=max(num,len);
               // cout<<"key is: "<<k<<endl;
              //  cout<<"value is: "<<key_value.second<<endl;
               // cout<<"len is: "<<len<<endl;
                //if(num==8)
                // cout<<"the slope is: "<<k<<endl;
         }

    }



        return num;
    }
    
};