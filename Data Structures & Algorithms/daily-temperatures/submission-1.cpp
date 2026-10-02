class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        vector<int> res(temp.size(),0);

        for(int i=0;i<temp.size();i++){
            while(!st.empty() && st.top().first < temp[i]){
                res[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({temp[i],i});
        }

        return res;
    }
};
