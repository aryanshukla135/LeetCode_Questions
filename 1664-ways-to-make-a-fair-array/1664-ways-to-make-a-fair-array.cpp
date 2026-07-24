class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int evenidx = 0;
        int oddidx = 0 ;
        for(int i =0 ; i<n ; i++){
            if(i%2 == 0 ){
                evenidx += nums[i];
            }else{
                oddidx += nums[i];
            }
        }
        int totaleven = evenidx ;
        int totalodd = oddidx ;
        int cnt =0 ;
        int preveven =0 ;
        int prevodd = 0;
 for (int i = 0; i < n; i++) {

          
            int rightEven = evenidx - preveven;
            int rightOdd = oddidx - prevodd;

            if (i % 2 == 0)
                rightEven -= nums[i];
            else
                rightOdd -= nums[i];

            
            int newEven = preveven + rightOdd;
            int newOdd = prevodd + rightEven;

            if (newEven == newOdd)
                cnt++;

        
            if (i % 2 == 0)
                preveven += nums[i];
            else
                prevodd += nums[i];
        }
        return cnt ;
    }
};
// 2+6 = 1+4
// 8 = 5 
// take two variable for previous odd and even indes sum 