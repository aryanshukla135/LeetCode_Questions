class Solution {
private: 
    string removeSpace(string & s){
        int n = s.length();
        string str  = "";
        for(int i =0 ; i<n ; i++){
            char ch = s[i];
            if(ch != ' '){
                str.push_back(ch);
            }
        }
        return str;
    }

    int solve(string & s){
        int n = s.length();
        string str = removeSpace(s);
        vector<int> nums;
        int num =0 ;

        for(int i =0 ; i<str.length() ; i++){
            char ch = str[i];
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }else{
                if(ch == '+'){
                   nums.push_back(num);
                }if(ch == '-'){
                   nums.push_back(-num);
                }if(ch == '*'){
                    int j = i+1;
                    int val = 0;
                    while(j < str.length() && isdigit(str[j])){
                         val = val * 10 + (str[j] - '0');
                         j++;
                    }
                    i = j;           
                    nums.push_back(num * val );
                }if(ch == '/'){
                    int j = i+1;
                    int val = 0;
                    while(j < str.length() && isdigit(str[j])){
                         val = val * 10 + (str[j] - '0');
                         j++;
                    }
                    i = j;
                    nums.push_back(num / val );
                }
                num = 0;
            } 
        }
        int total = 0 ;
        for(int i =0 ; i<nums.size() ; i++){
            total += nums[i];
        }
        return total ;

    }
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st ;
        int num = 0;
        int op = '+';

        for(int i =0 ; i<= n ; i++){
            char ch = s[i];
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }
            if(i == n || (!isdigit(ch) && ch != ' ' )){

                if(op == '+'){
                  st.push(num);
                }if(op == '-'){
                  st.push(-num);
                }if(op == '*'){
                  int val = st.top();
                  st.pop();
                  st.push(val * num);
                }if(op == '/'){
                  int val = st.top();
                  st.pop();
                  st.push(val / num);
                }
                op = s[i];
                num = 0;
            }
        }
        int total =0 ;
        while(!st.empty()){
            total += st.top();
            st.pop();
        }
        return total;

    }
};