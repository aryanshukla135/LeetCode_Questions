class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        vector<vector<int>> x(2) ;
        vector<vector<int>> y(2) ;

        x[0]={rec1[0],rec1[2]};
        x[1]={rec2[0],rec2[2]};

        y[0]={rec1[1],rec1[3]};
        y[1]={rec2[1],rec2[3]};

        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        bool xoverlap = false;
        bool yoverlap = false;

        if(x[0][1] > x[1][0]){
            xoverlap = true ;
        }
        if(y[0][1] > y[1][0]){
            yoverlap = true ;
        }
        return xoverlap && yoverlap;
    }
};