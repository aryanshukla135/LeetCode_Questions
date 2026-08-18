class Solution {
private:
    int solve(vector<int> & quantities , int mid ){
        int m = quantities.size();
        int temp =0 ;
        for(int i =0 ; i<m ;i++){
            int val = (quantities[i]+mid-1)/mid;
            temp += val;
        }
        return temp;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int ans = 0 ;
        int l= 1; 
        int h = *max_element(quantities.begin(),quantities.end());
        while(l<=h){
            int mid = l + (h-l)/2;
            int total = solve(quantities,mid);

            if(total<=n){
                ans = mid ;
                h = mid-1 ;

            }else{
                l = mid +1 ;
            }
        }
        return ans ;
    }
};