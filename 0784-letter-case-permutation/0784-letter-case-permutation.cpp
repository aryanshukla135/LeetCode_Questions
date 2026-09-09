class Solution {
private:
    void solve(string & s , vector<string> & ans , string curr, int ind  ){
        if(ind >= s.length()){
            ans.push_back(curr);
            return ;
        }
        if(isdigit(s[ind])){
            curr.push_back(s[ind]);
            solve(s,ans,curr,ind+1);
            curr.pop_back();
        }
        
        else{
            curr.push_back(tolower(s[ind]));
            solve(s,ans,curr,ind+1);
            curr.pop_back();

            curr.push_back(toupper(s[ind]));
            solve(s,ans,curr,ind+1);
            curr.pop_back();
        }

    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans ;
        string curr ="";
        solve(s,ans,curr,0);
        return ans ;
    }
};