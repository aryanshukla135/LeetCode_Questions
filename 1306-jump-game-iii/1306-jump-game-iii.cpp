class Solution {
private: 
   bool f(vector<int> & arr , int i , vector<bool> & vis){
       
       if(i<0 || i>=arr.size()) return false; 
       if(arr[i] == 0) return true ;


        bool pos = false ;
        bool neg = false ;

        if(i+arr[i] <arr.size() && !vis[i]){
            vis[i] = true ;
            pos = f(arr,i+arr[i],vis);
            vis[i]=false;

        }
        if(i-arr[i] >= 0 && !vis[i]){
            vis[i] = true ;
            neg = f(arr,i-arr[i],vis);
            vis[i]=false;
        } 
        return neg || pos ;
   }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);
        return f(arr,start,vis);
    }
};