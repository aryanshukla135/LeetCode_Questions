class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st ;
        string ans = "";
        for(int i =0 ; i<n ; i++){
            int val = num[i] - '0';
            while(!st.empty() && k > 0 && st.top() > val){
                st.pop();
                k--;
            }
            if(st.empty() && val == 0){
                continue;
            }
            st.push(val);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans += (st.top() + '0');
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans == ""){
            return "0";
        }

        return ans ;
    }
};