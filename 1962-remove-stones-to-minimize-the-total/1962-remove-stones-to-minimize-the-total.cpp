class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();

        priority_queue<int> pq ;

        for(int i =0 ; i< n; i++){
            pq.push(piles[i]);
        }

        while(k>0){
           int it = pq.top();
           pq.pop();
           k--;
           int val  = it - it/2;
           pq.push(val);
        }

        int sum =0 ;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }

        return sum ;
    }
};