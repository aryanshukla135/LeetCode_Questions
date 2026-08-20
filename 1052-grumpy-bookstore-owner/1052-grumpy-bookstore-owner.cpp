class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
         int n = customers.size();
         int sum = 0;

         // total sum when not grummy
         for(int i =0 ; i<n ; i++){
            if(grumpy[i] == 0 ){
                sum += customers[i];
                customers[i] =0 ;
            }
         }
         int maxsum =0;
         int j = 0;
         int ssum =0 ;
         for(int i =0 ; i<n ; i++){
            ssum += customers[i];
            if(i-j+1>minutes){
                ssum -= customers[j];
                j++;
            }
            maxsum = max(maxsum,ssum);
         }
        return sum+maxsum ;

    }
};