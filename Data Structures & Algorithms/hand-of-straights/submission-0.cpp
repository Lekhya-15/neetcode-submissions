class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n=hand.size();
        if(n%k) return false;
        int num=n/k;

        map<int,int> mp;
        for(int i:hand) mp[i]++;

        for(auto [x,y]:mp){
            if(mp[x]==0) continue;
            for(int i=x+1;i<x+k;i++){
                if(mp[i]<y) return false;
                mp[i]-=y;
            }
            mp[x]=0;
        }
        return true;
    }
};
