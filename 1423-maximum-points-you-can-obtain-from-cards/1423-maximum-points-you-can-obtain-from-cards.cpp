class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxsum = INT_MIN;
        int sum =0 ;
        int i =0 ;
        
        for( ; i<k ; i++){
            sum += cardPoints[i];
        }
        i--;
        maxsum = sum ;
        int j = n-1 ;
        while(n-j <= k){
            sum -= cardPoints[i];
            sum +=cardPoints[j];
            i--;
            j--;
            maxsum = max(maxsum,sum);
        }
        return maxsum ;

    }
};