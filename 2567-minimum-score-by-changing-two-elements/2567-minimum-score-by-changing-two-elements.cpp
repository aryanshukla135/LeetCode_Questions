class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> temp1 = nums;
        vector<int>temp2 = nums;
        vector<int> temp3= nums ;
        int ans = INT_MAX;

        // possbility 1
        temp1[0] = temp1[2];
        temp1[1] = temp1[2];

        ans = min(ans,temp1[n-1] - temp1[0]);

        // possiblity 2 

        temp2[n-1] = temp2[n-3];
        temp2[n-2] = temp2[n-3];
        ans = min(ans,temp2[n-1] - temp2[0]);


        // [pssiblity] 3 

        temp3[n-1] = temp3[n-2];
        temp3[0] = temp3[1];
        sort(temp3.begin(),temp3.end());
        ans = min(ans,temp3[n-1] - temp3[0]);


       return ans;        
      
    }
};

// 1 4 5 7 8  -> 4 4 5 7 7 

// 1 3 4 
// 1 4 9  100 101 102 
// 1 2 3 4 100 101 
