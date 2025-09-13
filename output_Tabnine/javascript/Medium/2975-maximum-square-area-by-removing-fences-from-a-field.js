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

/**
 * @param {number} m
 * @param {number} n
 * @param {number[]} hFences
 * @param {number[]} vFences
 * @return {number}
 */
var maximizeSquareArea = function(m, n, hFences, vFences) {
    // Sort the fences in ascending order
    hFences.sort((a, b) => a - b);
    vFences.sort((a, b) => a - b);
    
    // Initialize variables
    let maxArea = 0;
    let left = 1;
    let right = Math.min(hFences[0] - 1, vFences[0] - 1);
    let mid;
    let area;
    let mod = 1e9 + 7;
    let leftFence = hFences[0];
    let rightFence = vFences[0];
    let leftIndex = 0;
    let rightIndex = 0;

    // Binary search for the maximum area
    while (left <= right) {
        mid = Math.floor((left + right) / 2);
        area = calculateArea(mid, leftFence, rightFence, leftIndex, rightIndex);
        
        // Update maxArea and pointers
        if (area > maxArea) {
            maxArea = area;
        }
        
        if (area >= mid * mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return maxArea % mod;
    
};