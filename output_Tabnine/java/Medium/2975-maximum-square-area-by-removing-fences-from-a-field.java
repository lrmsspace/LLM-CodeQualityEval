/*
 There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.
 Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).
 Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.
 Since the answer may be large, return it modulo 109 + 7.
 Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.
 Example 1:
 Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
 Output: 4
 Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
 Example 2:
 Input: m = 6, n = 7, hFences = [2], vFences = [4]
 Output: -1
 Explanation: It can be proved that there is no way to create a square field by removing fences.
 Constraints:
 3 <= m, n <= 109
 1 <= hFences.length, vFences.length <= 600
 1 < hFences[i] < m
 1 < vFences[i] < n
 hFences and vFences are unique.
*/

class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        int mod = (int) 1e9 + 7;
        int[] left = new int[n + 1];
        int[] right = new int[n + 1];
        int[] up = new int[m + 1];
        int[] down = new int[m + 1];
        
        for (int i = 0; i < hFences.length; i++) {
            left[hFences[i]] = Math.max(left[hFences[i]], i + 1);
            right[n - hFences[i] + 1] = Math.max(right[n - hFences[i] + 1], i + 1);     
            up[vFences[i]] = Math.max(up[vFences[i]], i + 1);
            down[m - vFences[i] + 1] = Math.max(down[m - vFences[i] + 1], i + 1);
            // Subtract 1 because the fences are inclusive  
            left[hFences[i]]--;
            right[n - hFences[i] + 1]--;
            up[vFences[i]]--;
            down[m - vFences[i] + 1]--;
        }   
        int maxArea = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                maxArea = Math.max(maxArea, (right[j] - left[j] + 1) * (down[i] - up[i] + 1));
            }
        }
        return maxArea % mod;   
        
    }
}