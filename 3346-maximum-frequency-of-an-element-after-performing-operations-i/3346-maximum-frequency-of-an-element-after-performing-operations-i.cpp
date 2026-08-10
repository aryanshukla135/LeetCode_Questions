class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
         int n = nums.size();
         int maxans =0;
         sort(nums.begin(),nums.end());
         unordered_map<int,int> mp;
         for(int i : nums){
            mp[i]++;
         }

         for(int i = nums[0] ; i<= nums.back() ; i++){
             int idx1 = lower_bound(nums.begin(),nums.end(), i-k) - nums.begin();
             int idx2 = upper_bound(nums.begin(),nums.end(),i+k)-nums.begin()-1;

             int numOfOperation =  (idx2 - idx1 + 1 ) - mp[i];
             maxans = max(maxans,min(numOfOperation,numOperations) + mp[i]) ;

         }
         return maxans ;

    }
};

// brute force 
/*
i->0 to n 
for each value apply the numsOperation on element every element 
and after that count maxnumber of same frequency 

*/