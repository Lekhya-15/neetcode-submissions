class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;

        for(int i=0;i<n-1;i++){
            //odd
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;r++;ans++;
            }
            
            //even
            if(s[i]==s[i+1]){
                l=i;r=i+1;
                while(l>=0 && r<n && s[l]==s[r]){
                    l--;r++;ans++;
                }
            }
        }
        return ans+1;
    }
};
