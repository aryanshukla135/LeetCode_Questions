class Solution {
private: 
    bool canweplace(vector<int>& position,int mid ,int m){
        int n = position.size();
        int cntball = 1 ;
        int lastplaced = position[0];

        for(int i =1 ; i<n ; i++){
            if(position[i] - lastplaced >= mid){
                cntball++;
                lastplaced = position[i];
            }
        }
        return cntball>=m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int s = 1;
        int e = position[n-1]-position[0];
        int ans = 0;

        while(s<=e){
            int mid = s+ (e-s)/2;
            if(canweplace(position,mid,m)){
                ans = mid ;
                s = mid +1;
            }else{
                e = mid-1;
            }
        }
        return ans ;

    }
};