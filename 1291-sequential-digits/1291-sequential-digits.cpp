class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string strt = to_string(low);
        string end = to_string(high);

        vector<int> result;
        for (int len = strt.size(); len <= end.size(); len++) {
            int first = 1;
            while (first + len - 1 <= 9) {
                string str(len, '0');
                str[0] = first + '0';
                for (int i = 1; i < len; i++) {
                    str[i] = str[i - 1] + 1;
                }
                int num = stoi(str);
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
                first++;
            }
        }

        return result;
    }
};