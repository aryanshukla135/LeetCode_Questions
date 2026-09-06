class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int cnt =1;
        int j = n-1 ;
    
        for(int i = n-2 ; i>=0 ; i--){
            int diff = position[i+1]-position[i];
            if(diff <= distance || speed[i] > speed[j]){
                continue;
            }
    
            cnt++;
            j= i;
            
        }
        return cnt ;
    }
};