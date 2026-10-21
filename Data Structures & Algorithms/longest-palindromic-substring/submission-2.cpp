class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int m=0;
        string t="";
        if(n==1) return s;

        for(int i=0;i<s.length()-1;i++){
            //odd
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;r++;
            }
            l++;r--;
            if(r-l+1>m){
                m=r-l+1;
                t=s.substr(l,r-l+1);
            }
            //even
            if(s[i]==s[i+1]){
                l=i;r=i+1;
                while(l>=0 && r<n && s[l]==s[r]){l--;r++;
                }
                l++;r--;
                if(r-l+1>m){
                m=r-l+1;
                t=s.substr(l,r-l+1);
                }
            }
            
        }
        return t;
    }
};
