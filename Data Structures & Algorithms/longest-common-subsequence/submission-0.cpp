class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>> seq(m,vector<int>(n,0));

        if(text1[0]==text2[0]) seq[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(i==0){
                    seq[i][j]=max((int)(text1[i]==text2[j]),seq[i][j-1]);
                    continue;
                }
                if(j==0){
                    seq[i][j]=max((int)(text1[i]==text2[j]),seq[i-1][j]);
                    continue;
                }
                seq[i][j]=max({seq[i-1][j-1]+(text1[i]==text2[j]),seq[i-1][j],seq[i][j-1]});
            }
        }

        return seq[m-1][n-1];
    }
};
