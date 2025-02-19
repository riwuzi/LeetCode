class Solution {
public:
    string frequencySort(string s) {

        typedef std::pair<int, char> pair;
        std::vector<pair> pair_vec;
        std::string s1;

        int len=s.size();
        //for(int i=0;i<len;++i)
        for (int i=0;i<26;++i)
            {pair_vec.push_back({ 0,'a'+i });}
        for (int i=26;i<52;++i)
            {pair_vec.push_back({ 0,'A'+i-26 });}
        for (int i=52;i<62;++i)
            {pair_vec.push_back({ 0,'0'+i-52 });}
        
        for(int i=0;i<len;++i)
            if(s[i]>='a'&&s[i]<='z')
                ++pair_vec[s[i]-'a'].first;
            else if(s[i]>='A'&&s[i]<='Z')
                ++pair_vec[s[i]-'A'+26].first;
            else
                ++pair_vec[s[i]-'0'+52].first;

        sort(pair_vec.rbegin(), pair_vec.rend());
            
        for (int i=0;i<62;++i)
        for (int j=0;j<pair_vec[i].first;++j)
            s1.push_back(pair_vec[i].second);
            //cout<<pair_vec[i].second;

        
        return s1;
        
    }
};