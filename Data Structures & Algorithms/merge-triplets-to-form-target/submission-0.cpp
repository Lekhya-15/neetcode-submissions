class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();

        vector<int> j={0,0,0};
        for(auto v:triplets){
            if(v[0]<=target[0] && v[1]<=target[1] && v[2]<=target[2]){
                for(int i=0;i<3;i++){
                    if(v[i]==target[i]) j[i]=1;
                }
            }
        }

        for(int i:j){
            if(i==0) return i;
        }
        return 1;
    }
};
