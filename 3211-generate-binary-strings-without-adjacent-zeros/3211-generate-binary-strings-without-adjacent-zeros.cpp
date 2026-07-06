class Solution {
private:
    bool isvalid(string curr){
        int n = curr.size();
        for(int i =0 ; i < n-1 ; i++){
            if(curr[i] == '0' && curr[i+1]=='0'){
                return false ;
            }
        }
        return true ;
    }
    void solve(int n , string curr,vector<string> & ans){
        if(curr.length()==n){
            if(isvalid(curr)){
                ans.push_back(curr);
            }
            return ;
        }

        curr.push_back('0');
        solve(n,curr,ans);
        curr.pop_back();
        curr.push_back('1');
        solve(n,curr,ans);
        curr.pop_back(); 
    }
public:
    vector<string> validStrings(int n) {
        string curr ="";
        vector<string>ans ;
        solve(n,curr,ans);
        return ans ;
    }
};
