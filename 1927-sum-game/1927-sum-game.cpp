class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int left = 0, right = 0;
        int leftsum = 0, rightsum = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                left++;
            else
                leftsum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                right++;
            else
                rightsum += num[i] - '0';
        }

        // Equal number of '?'
        if (left == right) {
            return leftsum != rightsum;
        }

        // Difference in number of '?'
        int qdiff = left - right;
        int sdiff = leftsum - rightsum;

        
        return 2 * sdiff + 9 * qdiff != 0;
    }
};