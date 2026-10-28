class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;

        unordered_map<char,int> map;
        int n=s1.length();

        for(char c : s1) map[c]++;

        int len=0;
        for(int r=0;r<s2.length();r++){
            if(map.count(s2[r])){
                if(map[s2[r]]>0) len++;
                map[s2[r]]--;
            }
            if(r-n>=0 && map.count(s2[r-n])){
                map[s2[r-n]]++;
                if(map[s2[r-n]]>0) len--;
            }
            if(r>=n-1 && len==n) return true;
        }
        return false;
    }
};
