class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>mp1;
        unordered_map<char, int> mp2;
        int n=s1.size();
        int m= s2.size();
        for(int i=0; i<n; i++){
            mp1[s1[i]]++;
            if(mp1==mp2){
                return true;
            }
        }
        if(m<n){
            return false;
        }
        for(int j=0;j<n; j++){
            mp2[s2[j]]++;
            if(mp1==mp2){
                return true;
            }
        }
        for(int r=n; r<m; r++){
            mp2[s2[r-n]]--;
            if(mp2[s2[r-n]]==0){
                mp2.erase(s2[r-n]);

            }
            mp2[s2[r]]++;
            if(mp1== mp2){
                return true;
            }
        } 
        return false;
    }
};
