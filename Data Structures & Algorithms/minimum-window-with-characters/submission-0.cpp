class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        unordered_map<char,int>mp;
        int minlen=INT_MAX;
        int l=0;
        int st=0;
        for(char ch : t){
            mp[ch]++;
        }
        for(int r=0; r<m; r++){
             
            if(mp[s[r]]>0){
                n--;
            }
            mp[s[r]]--;
            
            while(n==0){
                int windowsz= r-l+1;// ourcount of map values become 0
             if(windowsz<minlen){
                minlen=windowsz;
                st=l ;
             }
             mp[s[l]]++;
             if(mp[s[l]]>0){
                n++;
             }
             l++;
            }

        }
        if(minlen==INT_MAX){
            return "";
        }
        return s.substr(st, minlen);
        
    }
};
