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
    public int[][] outerTrees(int[][] trees) {
        int n = trees.length;
        if (n <= 1) return trees;
        Arrays.sort(trees, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        int[] lower = new int[n];
        int[] upper = new int[n];
        int lowerSize = 0, upperSize = 0;
        for (int i = 0; i < n; i++) {
            while (lowerSize >= 2 && cross(trees[lower[lowerSize - 2]], trees[lower[lowerSize - 1]], trees[i]) < 0) lowerSize--;
            lower[lowerSize++] = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            while (upperSize >= 2 && cross(trees[upper[upperSize - 2]], trees[upper[upperSize - 1]], trees[i]) < 0) upperSize--;
            upper[upperSize++] = i;
        }
        Set<int[]> resultSet = new HashSet<>();
        for (int i = 0; i < lowerSize; i++) resultSet.add(trees[lower[i]]);
        for (int i = 1; i < upperSize - 1; i++) resultSet.add(trees[upper[i]]);
        return resultSet.toArray(new int[resultSet.size()][]);        
    }
}