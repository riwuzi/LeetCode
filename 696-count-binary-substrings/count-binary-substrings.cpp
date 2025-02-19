class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int len=s.size();
        if(len==1)
            return 0;

        int count=0;
        for(int i=0;i<len-1;++i)
            if(s[i]!=s[i+1])
                { 
                    ++count;
                    for(int j=1;;++j)
                        if(i-j>=0&&i+1+j<len&&s[i-j]==s[i]&&s[i+1+j]==s[i+1])
                            ++count;
                        else 
                            break;
                }
            

        return count;
        
    }
};