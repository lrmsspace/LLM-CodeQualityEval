/**https://leetcode.com/problems/maximize-distance-to-closest-person/ */
//You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).
//There is at least one empty seat, and at least one person sitting.
//Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
//Return that maximum distance to the closest person.
// 
//Example 1:
//Input: seats = [1,0,0,0,1,0,1]
//Output: 2
//Explanation: 
//If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
//If Alex sits in any other open seat, the closest person has distance 1.
//Thus, the maximum distance to the closest person is 2.
//Example 2:
//Input: seats = [1,0,0,0]
//Output: 3
//Explanation: 
//If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
//This is the maximum distance possible, so the answer is 3.
//Example 3:
//Input: seats = [0,1]
//Output: 1
// 
//Constraints:
//	2 <= seats.length <= 2 * 104
//	seats[i] is 0 or 1.
//	At least one seat is empty.
//	At least one seat is occupied.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int left = 0, right = n - 1;
        while (left < n && seats[left] == 0) ++left;
        while (right >= 0 && seats[right] == 0) --right;
        
        int maxDist = 0;
        while (left < right) {
            if (seats[left] == 1) {
                maxDist = max(maxDist, left);
                ++left;
            } else if (seats[right] == 1) {
                maxDist = max(maxDist, right);
                --right;
            } else {
                maxDist = max(maxDist, (left + 1) / 2);
                ++left;
                --right;
            }
        }
        
        return max(maxDist, left) + max(maxDist, n - right - 1);
        
    }
};