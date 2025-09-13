/**https://leetcode.com/problems/best-position-for-a-service-centre/ */
//A delivery company wants to build a new service center in a new city. The company knows the positions of all the customers in this city on a 2D-Map and wants to build the new center in a position such that the sum of the euclidean distances to all customers is minimum.
//Given an array positions where positions[i] = [xi, yi] is the position of the ith customer on the map, return the minimum sum of the euclidean distances to all customers.
//In other words, you need to choose the position of the service center [xcentre, ycentre] such that the following formula is minimized:
//Answers within 10-5 of the actual value will be accepted.
// 
//Example 1:
//Input: positions = [[0,1],[1,0],[1,2],[2,1]]
//Output: 4.00000
//Explanation: As shown, you can see that choosing [xcentre, ycentre] = [1, 1] will make the distance to each customer = 1, the sum of all distances is 4 which is the minimum possible we can achieve.
//Example 2:
//Input: positions = [[1,1],[3,3]]
//Output: 2.82843
//Explanation: The minimum possible sum of distances = sqrt(2) + sqrt(2) = 2.82843
// 
//Constraints:
//	1 <= positions.length <= 50
//	positions[i].length == 2
//	0 <= xi, yi <= 100
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        const double EPS = 1e-7;
        const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n = positions.size();
        double x = 0, y = 0;
        for (const auto& position : positions) {
            x += position[0];
            y += position[1];
        }
        x /= n;
        y /= n;
        double step = 100;
        double res = DBL_MAX;
        while (step > EPS) {
            bool found = false;
            for (const auto& dir : dirs) {
                double nx = x + dir[0] * step;
                double ny = y + dir[1] * step;
                double tmp = 0;
                for (const auto& position : positions) {
                    tmp += sqrt(pow(nx - position[0], 2) + pow(ny - position[1], 2));
                }
                if (tmp < res) {
                    res = tmp;
                    x = nx;
                    y = ny;
                    found = true;
                    break;
                }
            }
            if (!found) {
                step /= 2;
            }
        }
        return res; 
    }
};