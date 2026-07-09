class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
       unordered_set<char>m;
       int l=0;
       int res=0;
       for(int r=0; r<n;r++){
        while(m.find(s[r])!=m.end()){
            // to check if exist i set 
            m.erase(s[l]);
            l++;
        }
        m.insert(s[r]);
        res=max(res, (int)m.size());
       }
       return res;
    }
};
