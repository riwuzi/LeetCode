class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (strcmp(&s[0],&t[0]) == 0)
            return true;
        else
            return false;
    }
};