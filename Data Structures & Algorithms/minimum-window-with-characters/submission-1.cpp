class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m>n) return "";

        int len=0;int l=0;int lmin=0;int minlen=n+1;
        unordered_map<char,int> map;
        for(char c:t) map[c]++;

        for(int r=0;r<n;r++){
            if(map.count(s[r])){
                if(map[s[r]]>0) len++;
                map[s[r]]--;
            }

            while(len>m){
                if(map.count(s[l])){
                    map[s[l]]++;
                    if(map[s[l]]>0) len--;
                }
                l++;
            }

            while(len==m){
                if(!map.count(s[l])) l++;
                else{
                    if(map[s[l]]<0){
                        map[s[l]]++;
                        l++;
                    }
                    else break;
                }
            }
            if(r-l+1<minlen && len==m){
                lmin=l;minlen=r-l+1;
            }
        }
        if(minlen>n) return "";
        return s.substr(lmin,minlen);
    }
};
