class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> map;
        while(true){
            if(map.contains(n)) return false;
            map[n]=1;
            int sum=0;
            while(n){
                sum+=(n%10)*(n%10);
                n=n/10;
            }
            n=sum;
            if(sum==1) return true;
        }
    }
};
