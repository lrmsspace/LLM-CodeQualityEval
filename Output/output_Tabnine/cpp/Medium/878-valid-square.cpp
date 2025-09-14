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
        // Calculate the distances between each pair of points and check if they are equal
        double d1 = dist(p1, p2);
        double d2 = dist(p1, p3);
        double d3 = dist(p1, p4);
        double d4 = dist(p2, p3);
        double d5 = dist(p2, p4);
        double d6 = dist(p3, p4);
        
        if (d1!= d2 || d1!= d3 || d1!= d4 || d1!= d5 || d1!= d6) {
            return false;
        }
        
        // Calculate the side length of the square
        double side = d1;
        
        // Check if the side length is a positive integer
        if (side <= 0 || side!= floor(side)) {
            return false;
        }
        
        // Check if the angles between the sides are 90 degrees

        return isPerpendicular(p1, p2, p1, p3) && isPerpendicular(p1, p2, p1, p4) &&
            isPerpendicular(p2, p3, p2, p4) && isPerpendicular(p3, p4, p1, p4);
        
    }
};