class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        sort(str.begin(),str.end());
        int val1 = str[str.length()-1]-'0';
        int val2 = str[str.length()-2]-'0';

        return val1*val2;
    }
};