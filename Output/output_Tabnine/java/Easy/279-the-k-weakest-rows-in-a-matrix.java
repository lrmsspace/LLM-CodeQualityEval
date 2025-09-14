/**https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/ */
//You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.
//A row i is weaker than a row j if one of the following is true:
//	The number of soldiers in row i is less than the number of soldiers in row j.
//	Both rows have the same number of soldiers and i < j.
//Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
// 
//Example 1:
//Input: mat = 
//[[1,1,0,0,0],
// [1,1,1,1,0],
// [1,0,0,0,0],
// [1,1,0,0,0],
// [1,1,1,1,1]], 
//k = 3
//Output: [2,0,3]
//Explanation: 
//The number of soldiers in each row is: 
//- Row 0: 2 
//- Row 1: 4 
//- Row 2: 1 
//- Row 3: 2 
//- Row 4: 5 
//The rows ordered from weakest to strongest are [2,0,3,1,4].
//Example 2:
//Input: mat = 
//[[1,0,0,0],
// [1,1,1,1],
// [1,0,0,0],
// [1,0,0,0]], 
//k = 2
//Output: [0,2]
//Explanation: 
//The number of soldiers in each row is: 
//- Row 0: 1 
//- Row 1: 4 
//- Row 2: 1 
//- Row 3: 1 
//The rows ordered from weakest to strongest are [0,2,3,1].
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	2 <= n, m <= 100
//	1 <= k <= m
//	matrix[i][j] is either 0 or 1.
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int n = mat[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            int countA = 0;
            int countB = 0;
            for (int i = 0; i < n; i++) {
                if (mat[a][i] == 1) countA++;
                if (mat[b][i] == 1) countB++;
            }
            if (countA == countB) return b - a;
            return countA - countB;
        });
        
        for (int i = 0; i < mat.length; i++) {
            pq.offer(new int[]{i, countSoldiers(mat[i])});
            if (pq.size() > k) pq.poll();
        }
        
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = pq.poll()[0];
        }
        
        return result;
        
    }
}