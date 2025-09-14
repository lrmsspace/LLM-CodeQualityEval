/**https://leetcode.com/problems/valid-square/ */
//Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
//The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
//A valid square has four equal sides with positive length and four equal angles (90-degree angles).
// 
//Example 1:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
//Output: true
//Example 2:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
//Output: false
//Example 3:
//Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
//Output: true
// 
//Constraints:
//	p1.length == p2.length == p3.length == p4.length == 2
//	-104 <= xi, yi <= 104
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> v;
        v.push_back(pow(pow(abs(p1[0]-p2[0]),2)+pow(abs(p1[1]-p2[1]),2),0.5));
        v.push_back(pow(pow(abs(p1[0]-p3[0]),2)+pow(abs(p1[1]-p3[1]),2),0.5));
        v.push_back(pow(pow(abs(p1[0]-p4[0]),2)+pow(abs(p1[1]-p4[1]),2),0.5));
        v.push_back(pow(pow(abs(p2[0]-p3[0]),2)+pow(abs(p2[1]-p3[1]),2),0.5));
        v.push_back(pow(pow(abs(p2[0]-p4[0]),2)+pow(abs(p2[1]-p4[1]),2),0.5));
        v.push_back(pow(pow(abs(p3[0]-p4[0]),2)+pow(abs(p3[1]-p4[1]),2),0.5));
        sort(v.begin(),v.end());
        return v[0]>0&&v[0]==v[1]&&v[1]==v[2]&&v[2]==v[3]&&v[3]==v[4]&&v[4]==v[5];
    }
};