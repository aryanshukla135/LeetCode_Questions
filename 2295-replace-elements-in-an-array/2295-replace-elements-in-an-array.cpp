class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
         int n = nums.size();
         int m = operations.size();

         unordered_map<int,int> op;
         for(int i =0 ; i< m; i++){
            op[operations[i][0]] = operations[i][1];
         }
         unordered_map<int,int> numtoidx ;

         for(int i =0 ; i<n ; i++){
            numtoidx[nums[i]]= i ;
         }

         vector<int> result(n);
         for(int i =0 ; i<m ; i++){
             if(numtoidx.count(operations[i][0])){
                result[numtoidx[operations[i][0]]] = operations[i][1];
                numtoidx[operations[i][1]] = numtoidx[operations[i][0]] ;
             }
         }
         for(int i =0 ; i<n ; i++){
            if(result[i] == 0){
                result[i] = nums[i];
           }
         }
         
         return result;
    }
};