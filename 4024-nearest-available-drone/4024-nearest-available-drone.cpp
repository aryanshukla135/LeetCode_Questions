class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int mindis = -1 ;
        int mini = INT_MAX;
        int tx = target[0];
        int ty = target[1];
    
        

        for(int i =0 ; i<n ; i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];

            int dis = abs(tx-x) + abs(ty-y);
            if(dis<=range && dis<mini ){
                mini = dis;
                mindis = i ;
            
            }
        }
        return mindis ;
    }
};