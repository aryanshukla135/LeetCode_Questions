class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();

        int cnt =0 ;
        for(int i =0 ; i<n ; i++){
            bool temp = true ;
            for(int j = 0 ; j< m ; j++){
                int val = abs(arr1[i]-arr2[j]);
                if(val <= d){
                    temp = false;
                    break;
                }
            }
            if(temp){
                cnt++;
            }
        }
        return cnt ;
    }
};