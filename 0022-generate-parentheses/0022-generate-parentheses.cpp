class Solution {
private:
    bool isvalid(string & s){
        int n = s.length();
         stack<char> st ;
         for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }else{
                if(!st.empty()){
                    char t = st.top();
                    if((t == '(' && ch == ')') || (t == '[' && ch == ']') || (t == '{' && ch == '}')){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
         }
         return st.empty();
    }
    void solve(int n , vector<string> & ans , int i ,string curr ){
        if(i >= 2*n){
            if(isvalid(curr)){
                ans.push_back(curr);
            }
            return ;  
        }
        curr.push_back('(');
        solve(n,ans,i+1,curr);
        curr.pop_back();
        curr.push_back(')');
        solve(n,ans,i+1,curr);
        curr.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
          vector<string> ans ;
          string curr ;
          solve(n,ans,0,curr);
          return ans ;
    }
};