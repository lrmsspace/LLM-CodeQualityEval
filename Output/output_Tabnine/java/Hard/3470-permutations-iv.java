/*
 Given two integers, n and k, an alternating permutation is a permutation of the first n positive integers such that no two adjacent elements are both odd or both even.
 Return the k-th alternating permutation sorted in lexicographical order. If there are fewer than k valid alternating permutations, return an empty list.
 Example 1:
 Input: n = 4, k = 6
 Output: [3,4,1,2]
 Explanation:
 The lexicographically-sorted alternating permutations of [1, 2, 3, 4] are:
 [1, 2, 3, 4]
 [1, 4, 3, 2]
 [2, 1, 4, 3]
 [2, 3, 4, 1]
 [3, 2, 1, 4]
 [3, 4, 1, 2] ← 6th permutation
 [4, 1, 2, 3]
 [4, 3, 2, 1]
 Since k = 6, we return [3, 4, 1, 2].
 Example 2:
 Input: n = 3, k = 2
 Output: [3,2,1]
 Explanation:
 The lexicographically-sorted alternating permutations of [1, 2, 3] are:
 [1, 2, 3]
 [3, 2, 1] ← 2nd permutation
 Since k = 2, we return [3, 2, 1].
 Example 3:
 Input: n = 2, k = 3
 Output: []
 Explanation:
 The lexicographically-sorted alternating permutations of [1, 2] are:
 [1, 2]
 [2, 1]
 There are only 2 alternating permutations, but k = 3, which is out of range. Thus, we return an empty list [].
 Constraints:
 1 <= n <= 100
 1 <= k <= 1015
*/

class Solution {
    public int[] permute(int n, long k) {
        // Initialize the result array
        int[] result = new int[n];
        
        // Initialize the first element of the result array
        result[0] = 1;
        
        // Calculate the number of elements to be skipped
        long skip = k - 1;
        
        // Calculate the number of elements to be swapped
        int swapCount = 0;
        for (int i = 1; i < n; i++) {
            // If the current element is odd, skip the next element
            if (result[i - 1] % 2 == 1) {
                skip--;
                continue;
            }
            
            // If the current element is even, skip the next two elements
            if (result[i - 1] % 2 == 0) {
                skip -= 2;
                continue;
            }
            
            // If the current element is not odd or even, skip the next two elements
            skip -= 2;
            
            // Calculate the index of the next element to be swapped
            int swapIndex = (int) (skip / (n - i));
            
            // Swap the current element with the next element
            int temp = result[i];
            result[i] = result[i + swapIndex];
            result[i + swapIndex] = temp;
            
            // Increment the swap count
            swapCount++;
            // If the swap count reaches the number of elements to be swapped, break the loop
            if (swapCount == swapCount) {
                break;
            }
        }
        return result;
        
    }
}