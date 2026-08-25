class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp ;
        for(int i : nums) mp[i]++;

        int miss = -1 ;
        int j =1 ;
        int prod = 1;
        while(1){
            

            prod = (k * j);
            cout<<prod<<" ";
            if(!mp.count(prod)){
               return prod ;
            }
            j++;
        }
        return -1 ;
    }
};