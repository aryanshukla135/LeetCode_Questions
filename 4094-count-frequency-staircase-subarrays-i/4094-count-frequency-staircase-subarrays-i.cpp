class Solution {
public:
    int countStaircase(vector<int>& nums) {

        int n = nums.size();
        long long cnt = 0;

        for(int i = 0; i < n; i++){

            vector<int> freq;               // counts in order of first appearance
            unordered_map<int,int> pos;     // value -> index inside freq

            for(int j = i; j < n; j++){

                int num = nums[j];

                if(pos.find(num) == pos.end()){

                    pos[num] = freq.size();
                    freq.push_back(1);

                }

                else freq[pos[num]]++;

                // check if freq looks like 1, 2, 3, ..., k
                bool ok = true;

                for(int t = 0; t < freq.size(); t++){

                    if(freq[t] != t + 1){

                        ok = false;
                        break;

                    }

                }

                if(ok) cnt++;

            }
        }

        return cnt;
        
    }
};