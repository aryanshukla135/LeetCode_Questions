class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {

        string s1 = bitset<32>(nums[0]).to_string();
        s1 = s1.substr(s1.find('1'));

        string s2 = bitset<32>(nums[1]).to_string();
        s2 = s2.substr(s2.find('1'));

        string s3 = bitset<32>(nums[2]).to_string();
        s3 = s3.substr(s3.find('1'));

        int ans = 0;

        ans = max(ans, stoi(s1 + s2 + s3, nullptr, 2));
        ans = max(ans, stoi(s1 + s3 + s2, nullptr, 2));
        ans = max(ans, stoi(s2 + s1 + s3, nullptr, 2));
        ans = max(ans, stoi(s2 + s3 + s1, nullptr, 2));
        ans = max(ans, stoi(s3 + s1 + s2, nullptr, 2));
        ans = max(ans, stoi(s3 + s2 + s1, nullptr, 2));

        return ans;
    }
};