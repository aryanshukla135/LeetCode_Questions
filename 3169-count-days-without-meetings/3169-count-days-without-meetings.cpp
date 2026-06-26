class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        long long occupied = 0;

        int start = meetings[0][0];
        int end = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            if (meetings[i][0] <= end) {
               
                end = max(end, meetings[i][1]);
            } else {
               
                occupied += (end - start + 1);
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }

       
        occupied += (end - start + 1);

        return days - occupied;
    }
};