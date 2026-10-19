class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> dict;
        for(auto st:wordDict) dict[st]=1;

        for(int i=0;i<=s.length();i++){
            for(int j=i;j>=0;j--){
                if(dict.count(s.substr(0,j)) && dict.count(s.substr(j,i-j))){
                    dict[s.substr(0,i)]=1;
                    break;
                }
            }
        }

        return dict.count(s);
    }
};
