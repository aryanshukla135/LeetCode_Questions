class Solution {

public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        // int l = 1;
        // int h = n;
        sort(grades.begin(),grades.end());


        // int ans =0;
        // while(l<=h){
        //     int mid = l+(h-l)/2;
        //     int cnt = countgrades(grades);
        //     if(cnt>=mid){
        //         ans = mid ;
        //         l = mid+1 ;
        //     }else{
        //         h = mid-1 ;
        //     }
        // }
          
        int prev =grades[0];
        int j =0 ;
        int cnt = 1;
        int sum = 0 ;
        for(int i =1 ; i<n ; i++){
             sum += grades[i];
             if(sum > prev){
                if(i-j > cnt){
                   cnt++;
                   prev = grades[i];
                   j = i ;
                   sum =0;
                }
             }
        }
       return cnt ;
    }
};