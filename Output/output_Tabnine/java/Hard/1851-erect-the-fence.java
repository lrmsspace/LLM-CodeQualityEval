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
        if (n <= 2) return trees;
        
        int[] leftmost = new int[n];
        int[] rightmost = new int[n];
        int[] lowest = new int[n];
        int[] highest = new int[n];
        
        Arrays.fill(leftmost, Integer.MAX_VALUE);
        Arrays.fill(rightmost, Integer.MIN_VALUE);
        Arrays.fill(lowest, Integer.MAX_VALUE);
        Arrays.fill(highest, Integer.MIN_VALUE);
        
        int leftmostIndex = 0;
        int rightmostIndex = 0;
        int lowestIndex = 0;
        int highestIndex = 0;
        
        for (int i = 0; i < n; i++) {
            int x = trees[i][0];
            int y = trees[i][1];
            
            if (x < leftmost[leftmostIndex]) {
                leftmost[leftmostIndex] = x;
                leftmostIndex = i;
            }
            if (x > rightmost[rightmostIndex]) {
                rightmost[rightmostIndex] = x;
                rightmostIndex = i;
            }
            if (y < lowest[lowestIndex]) {
                lowest[lowestIndex] = y;
                lowestIndex = i;
            }
            if (y > highest[highestIndex]) {
                highest[highestIndex] = y;
                highestIndex = i;
            }
        }
        
        List<int[]> result = new ArrayList<>();
        
        // Add the leftmost tree
        result.add(trees[leftmostIndex]);
        
        // Add the trees on the lowest line
        for (int i = lowestIndex; i!= leftmostIndex; i = (i + 1) % n) {
            result.add(trees[i]);
        }
        
        // Add the rightmost tree
        result.add(trees[rightmostIndex]);
        
        // Add the trees on the highest line
        for (int i = highestIndex; i!= rightmostIndex; i = (i + 1) % n) {
            result.add(trees[i]);
        }
        
        return result.toArray(new int[result.size()][]);
        
    }
}