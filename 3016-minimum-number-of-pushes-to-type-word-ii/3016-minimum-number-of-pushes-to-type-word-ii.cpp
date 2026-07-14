class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        priority_queue<pair<int,char>> pq ;
        unordered_map<char,int> mp ;

        for(int i =0 ; i< n ; i++){
            mp[word[i]]++;
        }

        for(auto it : mp ){
            int cnt = it.second ;
            char ch = it.first ;
            pq.push({cnt,ch});
        }
        int cnt =0;
        int times =1 ;
        int ans = 0 ;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans +=it.first*times;
            cnt++;
            if(cnt == 8 ){
                cnt =0 ;
                times++;
            }
            
        }
        return ans ;
    }

};