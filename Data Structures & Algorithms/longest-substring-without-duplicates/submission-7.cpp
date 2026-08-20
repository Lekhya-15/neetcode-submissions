class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> map;
        int n=s.length();

        int l=0;int r=0;
        int len=0;

        while(r<n){
            if(map.contains(s[r])){
                
                l=max(map[s[r]]+1,l);
            }
            map[s[r]]=r;
            r++;
            len=max(len,r-l);
        }

        return len;

    }
};
