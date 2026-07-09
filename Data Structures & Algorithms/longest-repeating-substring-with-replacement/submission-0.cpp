class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int n= s.size();
        int l=0;
        int maxfr=0;
        int ans=0;
        int r=0;
        for(int r=0; r<n; r++){
            mp[s[r]]++;
            maxfr=max(maxfr, mp[s[r]]);
            while((r-l+1)-maxfr>k){
                mp[s[l]]--;
                l++; 
            }
        ans=max(ans, (r-l+1));
        
        }
        return ans;
    }
};
