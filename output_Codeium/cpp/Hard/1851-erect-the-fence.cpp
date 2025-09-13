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
        vector<vector<int>> res;
        if (trees.empty()) return res;
        if (trees.size() <= 2) return trees;
        int n = trees.size();
        vector<int> next(n), prev(n);
        for (int i = 0; i < n; ++i) {
            next[i] = (i + 1) % n;
            prev[i] = (i - 1 + n) % n;
        }
        for (int i = 0; i < n; ++i) {
            int j = next[i];
            while (ccw(trees[i], trees[j], trees[next[j]]) > 0) {
                j = next[j];
            }
            next[i] = j;
            prev[j] = i;
        }
        int start = 0;
        for (int i = 1; i < n; ++i) {
            if (trees[i][1] < trees[start][1])
                start = i;
            else if (trees[i][1] == trees[start][1] && trees[i][0] < trees[start][0])
                start = i;
        }
        int p = start;
        do {
            res.push_back(trees[p]);
            p = next[p];
        } while (p != start);
        return res;
    }
    int ccw(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
        
    }
};