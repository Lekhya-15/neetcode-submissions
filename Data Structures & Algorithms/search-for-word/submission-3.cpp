class Solution {
public:
    bool backtrack(int i,int j,string path,string word,vector<vector<char>> board,map<pair<int,int>,int>& map){
        if(board[i][j]==word[path.length()]){
        path.push_back(board[i][j]);
        map[{i,j}]=1;

        if(path == word){
            return true;
        }

        if(i<board.size()-1 && !map[{i+1,j}]){
            int x=backtrack(i+1,j,path,word,board,map);
            if(x) return x;
        }

        if(j<board[0].size()-1 && !map[{i,j+1}]){
            int y=backtrack(i,j+1,path,word,board,map);
            if(y) return y;
        }

        if(i>0 && !map[{i-1,j}]){
            int x=backtrack(i-1,j,path,word,board,map);
            if(x) return x;
        }

        if(j>0 && !map[{i,j-1}]){
            int y=backtrack(i,j-1,path,word,board,map);
            if(y) return y;
        }
        map[{i,j}]=0;
        
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        string path;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                map<pair<int,int>,int> map;
                int n=backtrack(i,j,path,word,board,map);
                if(n) return n;
                path="";
            }
        }

        return false;
    }
};
