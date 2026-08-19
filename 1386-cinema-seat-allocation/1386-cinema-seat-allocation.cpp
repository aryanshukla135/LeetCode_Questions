class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mp ;
        for(auto it: reservedSeats){
            int row  = it[0];
            int col = it[1];

            mp[row].push_back(col);
        }
        int cnt = 0;
        for(auto it : mp ){
            unordered_set<int> st ;
            int m = it.second.size();
            vector<int> temp = it.second;
            for(int i =0 ; i<m ; i++){
                st.insert(temp[i]);
            }
            if(!st.count(2) && !st.count(3) && !st.count(4) &&!st.count(5)){
                cnt++;
                st.insert(2);
                st.insert(3);
                st.insert(4);
                st.insert(5);
            }
            if(!st.count(4) && !st.count(5) && !st.count(6) &&!st.count(7)){
                cnt++;
                st.insert(4);
                st.insert(5);
                st.insert(6);
                st.insert(7);
            }
            if(!st.count(6) && !st.count(7) && !st.count(8) &&!st.count(9)){
                cnt++;
                st.insert(6);
                st.insert(7);
                st.insert(8);
                st.insert(9);
            }
        }
        int rem = n - mp.size();
        if(rem > 0){
            cnt += rem*2;
        }
        return cnt ;
    }
};