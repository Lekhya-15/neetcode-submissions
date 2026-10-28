class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        if(n<=k) return n;
        int len=0;int m=0;int l=0;int maxlen=0;

        unordered_map<int,int> map;

        for(int r=0;r<n;r++){
            map[s[r]]++;
            if(map[s[r]]>=m) m=map[s[r]];
            len=r-l+1-m;

            while(len>k){
                map[s[l]]--;
                l++;
                len=r-l+1-m;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
        
    }
};
