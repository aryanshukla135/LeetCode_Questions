class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result ;
        deque<int> dq ;
        
        for(int i =0 ; i<nums.size() ; i++){

            int val = nums[i];
            while(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < val){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i  >= k - 1 ){
                result.push_back(nums[dq.front()]) ;
            }
        }
        return result;
    }
};