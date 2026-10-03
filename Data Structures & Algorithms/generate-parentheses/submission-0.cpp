class Solution {
public:
    
    void backtrack(int n,int k,int l, string path,vector<string>& ans){
        if(2*n==path.length()){
            ans.push_back(path);
            return;
        }

        if(n>k){
        path.push_back('(');
        backtrack(n,k+1,l,path,ans);
        path.pop_back();
        }

        if(k>l){
            path.push_back(')');
            backtrack(n,k,l+1,path,ans);
            path.pop_back();
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        backtrack(n,0,0,path,ans);
        return ans;
    }
};