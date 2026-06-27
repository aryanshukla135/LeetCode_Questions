class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         int n = letters.size();

         if(letters[n-1]<=target){
            return letters[0];
         }

         int s=0;
         int e= n-1 ;
         char ans ;
         while(s<=e){
            int mid = (s+e)/2;

            if(letters[mid] >target){
                ans = letters[mid];
                e = mid-1;
            }else{
                s=mid+1;
            }
         }
       return ans ;

    }
};