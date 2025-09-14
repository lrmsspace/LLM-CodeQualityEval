/**https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/ */
//You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.
//The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).
//Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.
// 
//Example 1:
//Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
//Output: 1
//Explanation: source can be transformed the following way:
//- Swap indices 0 and 1: source = [2,1,3,4]
//- Swap indices 2 and 3: source = [2,1,4,3]
//The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
//Example 2:
//Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
//Output: 2
//Explanation: There are no allowed swaps.
//The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.
//Example 3:
//Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
//Output: 0
// 
//Constraints:
//	n == source.length == target.length
//	1 <= n <= 105
//	1 <= source[i], target[i] <= 105
//	0 <= allowedSwaps.length <= 105
//	allowedSwaps[i].length == 2
//	0 <= ai, bi <= n - 1
//	ai != bi
class Solution {
    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;
        // Create a map to store the original indices of each number
        Map<Integer, Integer> originalIndex = new HashMap<>();
        for (int i = 0; i < n; i++) {
            originalIndex.put(source[i], i);
        }
        
        // Create a union-find data structure to track the connected components
        UnionFind unionFind = new UnionFind(n);
        for (int[] swap : allowedSwaps) {
            int x = originalIndex.get(swap[0]);
            int y = originalIndex.get(swap[1]);
            unionFind.union(x, y);
        }
        
        // Count the number of elements in each connected component
        Map<Integer, Integer> componentCount = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int root = unionFind.find(i);
            componentCount.put(root, componentCount.getOrDefault(root, 0) + 1);
        }
        
        // Calculate the minimum Hamming distance
        int minHammingDistance = 0;
        for (int[] swap : allowedSwaps) {
            int x = originalIndex.get(swap[0]);
            int y = originalIndex.get(swap[1]);
            if (unionFind.find(x)!= unionFind.find(y)) {
                // Swap the elements in the two connected components
                int count = componentCount.get(unionFind.find(x));
                minHammingDistance += count * (componentCount.get(unionFind.find(y)) - 1);
                unionFind.union(x, y);
            }
        }
        
        for (int i = 0; i < n; i++) {
            int root = unionFind.find(i);
            minHammingDistance += (componentCount.get(root) - 1) * (n - componentCount.get(root));
        }
        
        return minHammingDistance;
        
    }
}