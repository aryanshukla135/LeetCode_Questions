class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st ;
        for(int& i : nums){
            st.insert(i);
        }
        int longestcons = 0 ;
        if(n==0){
            return longestcons;
        }
        for(auto & it : st){
    
            if(!st.count(it-1)){
              int x = it ;
              int cnt =1 ;
              while(st.count(x+1)){
                cnt++;
                x++;
            }
            longestcons = max(longestcons,cnt);
            } 
        }
        return longestcons;
    }
};
// 2 = 2
//  3 = 3 
// 