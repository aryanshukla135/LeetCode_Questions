class Solution {
private:
    long long solve(vector<int> & batteries , long long mid){
        int n = batteries.size();
        long long sum =0 ;
        for(int i : batteries){
            sum += min(mid,(long long)i);
        }
        return sum;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
         int m = batteries.size();
         long long  sum = 0 ;
         for(int i :batteries ){
            sum += i ;
         }
         long long  l =1;
         long long  h = sum ;
         long long  ans = 0;
         while(l<=h){
            long long  mid = l +(h-l)/2;
            long long  totalmin = solve(batteries,mid);
            if(totalmin >=(long long)n*mid){
                ans = mid ;
                l = mid +1 ;
            }else{
                h = mid -1 ;
            }
         }
         return ans ;
    }
};