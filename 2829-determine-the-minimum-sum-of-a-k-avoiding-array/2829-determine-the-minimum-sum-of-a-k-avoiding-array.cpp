class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,bool> vis ;
        int i =1 ; 
        int j = 50 ;
        while(i<j){
            int val = i + j ;
            if(val == k){
                vis[j] = true ;
                j--; 
            }
            else if(val > k){
                j--;
            }
            else{
                i++;
            }
        }
        int sum = 0;
        int it =1 ;
        while(n > 0){
            if(!vis.count(it)){
                cout<<it<<" ";
                sum += it ;
                n--;
            }
            it++;
        }
        return sum ;
    }
};