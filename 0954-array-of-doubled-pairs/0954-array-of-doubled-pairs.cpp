class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());

        unordered_map <int,int> mp ;

        for(int i: arr ) mp[i]++;
        for(int i =0 ; i<n; i++){
            int val = arr[i] ;
            if(mp[val]>0 && mp[2*val] >0){
                mp[val]--;
                mp[2*val]--;
            }
        }
        for(auto it: mp){
            if(it.second >0) return false;
        }

        return true ;

    }
};
// 1 2 4 4 8 16 
// i = 0 arr[1] =2* arr[0]
// i = 1 arr[3] = 2*arr[2]
// i = 2 arr[5] = 2*arr[4]

// for i indx i+1 must be double ofr each i 
