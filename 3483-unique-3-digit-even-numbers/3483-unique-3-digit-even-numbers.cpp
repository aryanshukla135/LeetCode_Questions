class Solution {
private:
    void solve(vector<int> & nums , int ind , set<vector<int>> &st){
        if(ind == 3){
            vector<int> temp = {nums[0],nums[1],nums[2]};
            if(temp[2] % 2 == 0 && temp[0] != 0){
                st.insert(temp);
            }
            return ;
        }
        for(int i = ind ; i<nums.size(); i++){
            swap(nums[i],nums[ind]);
            solve(nums,ind+1,st);
            swap(nums[i],nums[ind]);
        }
    }
public:
    int totalNumbers(vector<int>& digits) {
        set<vector<int>> st;
        solve(digits,0,st);
        return st.size();
    }
};