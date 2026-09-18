class Solution {
private:
    pair<int,int> findMaxMin(int ind , int j ,string & s){
        int maxi = 0;
        int mini = INT_MAX ;
        vector<int> freq(26,0);
        for(int i = ind; i<=j ; i++){
            freq[s[i]-'a']++;
        }
        for(int i =0 ; i< 26 ; i++){
            maxi = max(maxi,freq[i]);
        }
        for(int i =0 ;i<26 ; i++){
            if(freq[i] != 0){
                mini = min(mini,freq[i]);
            }
        }
        return {maxi,mini};
    }
public:
    int beautySum(string s) {
        int n = s.length();
        
        // for(int i =0; i<n ; i++){
        //     freq[s[i]-'a']++;
        //     auto it = findMaxMin(i,freq);
        //     maxi[i] = it.first;
        //     mini[i] = it.second;
        // }
        // for(int i : maxi){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(int i : mini){
        //     cout<<i<<" ";
        // }
        int ans =0;
        for(int i =0 ; i<n; i++){
            for(int j = i ; j<n ; j++){
                auto it = findMaxMin(i,j,s);
                int maxi = it.first;
                int mini = it.second;
                ans += (maxi-mini);

            }
        }
        return ans ;
    }
};