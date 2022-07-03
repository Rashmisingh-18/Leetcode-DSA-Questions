/* Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).
  
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true */

class Solution {
public:
    
    double distance(vector<int>& p1, vector<int>& p2){
        return sqrt((p2[0] - p1[0])*(p2[0] - p1[0]) + (p2[1] - p1[1])*(p2[1] - p1[1]));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<double> len;
        
        for(int i=0; i<4; i++){
            for(int j=i+1; j<4; j++){
                double curr = distance(points[i], points[j]);
                if(curr != 0){
                    len.insert(curr);
                }
                else{
                    return false;
                }
            }
        }
        return len.size() == 2;
    }
};
