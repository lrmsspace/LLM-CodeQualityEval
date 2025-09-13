/**https://leetcode.com/problems/erect-the-fence/ */
//You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
//Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.
//Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.
// 
//Example 1:
//Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
//Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
//Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.
//Example 2:
//Input: trees = [[1,2],[2,2],[4,2]]
//Output: [[4,2],[2,2],[1,2]]
//Explanation: The fence forms a line that passes through all the trees.
// 
//Constraints:
//	1 <= trees.length <= 3000
//	trees[i].length == 2
//	0 <= xi, yi <= 100
//	All the given positions are unique. 
class Solution {
    public:
        vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
            int n = trees.size();
            if (n <= 3) return trees; // If there are 3 or fewer trees, they all form the fence
            
            // Find the bottom-left point (with lowest y-coordinate, and leftmost in case of tie)
            int bottomLeft = 0;
            for (int i = 1; i < n; i++) {
                if (trees[i][1] < trees[bottomLeft][1] || 
                    (trees[i][1] == trees[bottomLeft][1] && trees[i][0] < trees[bottomLeft][0])) {
                    bottomLeft = i;
                }
            }
            
            // Swap the bottom-left point with the first point
            swap(trees[0], trees[bottomLeft]);
            
            // Sort the remaining points by polar angle with respect to the bottom-left point
            vector<int>& p0 = trees[0];
            sort(trees.begin() + 1, trees.end(), [&p0](const vector<int>& p1, const vector<int>& p2) {
                int orientation = getOrientation(p0, p1, p2);
                if (orientation == 0) {
                    // If collinear, sort by distance from p0
                    return getDistance(p0, p1) < getDistance(p0, p2);
                }
                return orientation > 0;
            });
            
            // Include collinear points at the end
            int i = n - 1;
            while (i >= 1 && getOrientation(p0, trees[n-1], trees[i]) == 0) i--;
            
            // Reverse the order of collinear points
            for (int l = i + 1, r = n - 1; l < r; l++, r--) {
                swap(trees[l], trees[r]);
            }
            
            // Build the convex hull using a stack
            vector<vector<int>> hull;
            hull.push_back(trees[0]);
            hull.push_back(trees[1]);
            
            for (int i = 2; i < n; i++) {
                while (hull.size() > 1 && getOrientation(hull[hull.size()-2], hull.back(), trees[i]) < 0) {
                    hull.pop_back();
                }
                hull.push_back(trees[i]);
            }
            
            return hull;
        }
        
    private:
        // Returns the orientation of three points (p, q, r):
        // 0 -> collinear, 1 -> clockwise, -1 -> counterclockwise
        static int getOrientation(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
            int val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
            if (val == 0) return 0;  // collinear
            return (val > 0) ? 1 : -1; // clockwise or counterclockwise
        }
        
        // Returns the squared distance between two points
        static int getDistance(const vector<int>& p, const vector<int>& q) {
            return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
        }
    };
    