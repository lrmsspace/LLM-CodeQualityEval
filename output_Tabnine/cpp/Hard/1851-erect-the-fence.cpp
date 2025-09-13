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
        if (trees.size() <= 1) return trees;
        
        int leftmost = 0;
        for (int i = 1; i < trees.size(); i++)
            if (trees[i][0] < trees[leftmost][0])
                leftmost = i;
        
        int current = leftmost;
        do {
            res.push_back(trees[current]);
            int next = (current + 1) % trees.size();
            for (int i = 0; i < trees.size(); i++)
                if (orientation(trees[current], trees[i], trees[(i + 1) % trees.size()]) < 0)
                    next = i;
            
            current = next;
        } while (current!= leftmost);
        
        return res;
        
    }
};