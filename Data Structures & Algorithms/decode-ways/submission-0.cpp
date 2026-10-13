class Solution {
public:
    int numDecodings(string s) { 
        vector<int> dp(s.length(),0);
        if(s[0]!='0') dp[0]=1;
        else return 0;

        for(int i=1;i<s.length();i++){
            int x=10*(s[i-1]-'0')+(s[i]-'0');
            if(i==1){
                if(s[i]!='0') dp[i]=dp[i-1]+(x<=26 && x>10);
                else dp[i]=(x<=26 && x>=10);
                continue;
            }

            if(s[i]!='0'){
            dp[i]=dp[i-1]+(x<=26 && x>10)*dp[i-2];
            }
            else dp[i]=(x<=26 && x>=10)*dp[i-2];
        }
        return dp[s.length()-1];
    }
};
