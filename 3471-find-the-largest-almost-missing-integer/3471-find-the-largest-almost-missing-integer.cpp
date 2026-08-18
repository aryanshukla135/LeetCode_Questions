class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<char,int> mp ;
        
        int element = -1 ; 
        for(int i : nums){
            mp[i]++;
        }
        if(k ==1 ){
            for(auto it : mp){
                if(it.second == 1){
                    int val = it.first;
                    element = max(element,val);

                }
            }
            return element; 
        }
        if(k == n){
            element = *max_element(nums.begin(),nums.end());
        }else{
            int first = nums[0];
        int last = nums[n-1];

        if(mp[first] == 1 && mp[last] == 1){
             element = max(first,last);
             return element;
        }
        if(mp[first] == 1 && mp[last] != 1){
            element = first ;
            return element;
        }
        if(mp[first] != 1 && mp[last] == 1){
            element = last ;
            return element;
        }
        }
       return element ;
    }
};