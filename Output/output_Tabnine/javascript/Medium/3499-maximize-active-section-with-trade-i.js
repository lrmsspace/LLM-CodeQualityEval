/*
 You are given a binary string s of length n, where:
 '1' represents an active section.
 '0' represents an inactive section.
 You can perform at most one trade to maximize the number of active sections in s. In a trade, you:
 Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
 Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
 Return the maximum number of active sections in s after making the optimal trade.
 Note: Treat s as if it is augmented with a '1' at both ends, forming t = '1' + s + '1'. The augmented '1's do not contribute to the final count.
 Example 1:
 Input: s = "01"
 Output: 1
 Explanation:
 Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.
 Example 2:
 Input: s = "0100"
 Output: 4
 Explanation:
 String "0100" → Augmented to "101001".
 Choose "0100", convert "101001" → "100001" → "111111".
 The final string without augmentation is "1111". The maximum number of active sections is 4.
 Example 3:
 Input: s = "1000100"
 Output: 7
 Explanation:
 String "1000100" → Augmented to "110001001".
 Choose "000100", convert "110001001" → "110000001" → "111111111".
 The final string without augmentation is "1111111". The maximum number of active sections is 7.
 Example 4:
 Input: s = "01010"
 Output: 4
 Explanation:
 String "01010" → Augmented to "1010101".
 Choose "010", convert "1010101" → "1000101" → "1111101".
 The final string without augmentation is "11110". The maximum number of active sections is 4.
 Constraints:
 1 <= n == s.length <= 105
 s[i] is either '0' or '1'
*/

/**
 * @param {string} s
 * @return {number}
 */
var maxActiveSectionsAfterTrade = function(s) {
    let n = s.length;
    let left = 0;
    let right = n - 1;
    let count = 0;
    
    // Count the number of active sections
    while (left <= right && s[left] === '1') {
        left++;
        count++;
    }
    
    while (left <= right && s[right] === '1') {
        right--;
        count++;
    }
    let maxCount = count;
    let leftStart = 0;
    let rightStart = n - 1;
    let leftEnd = 0;
    let rightEnd = n - 1;
    let leftCount = 0;
    let rightCount = 0;
    let leftMaxCount = 0;
    let rightMaxCount = 0;

    // Perform the trade    
    while (left <= right) { 
        if (s[left] === '0' && s[left - 1] === '1') {
            leftStart = left;
            leftEnd = left;
            leftCount = 0;
            while (left >= 0 && s[left] === '0') {
                left--;
                leftCount++;
            }
        }
        if (s[right] === '1' && s[right + 1] === '0') {
            rightStart = right;
            rightEnd = right;
            rightCount = 0;
            while (right < n && s[right] === '1') {
                right++;
                rightCount++;
            }
        }
        if (leftCount + rightCount > maxCount) {
            maxCount = leftCount + rightCount;
            leftMaxCount = leftCount;
            rightMaxCount = rightCount;

            if (leftStart === 0 && rightStart === n - 1) {
                break;
            }
        }

        if (leftStart === 0) {
            left = leftEnd + 1;
        } else if (rightStart === n - 1) {
            right = rightStart - 1;
        } else {
            left = Math.min(leftStart - 1, rightStart + 1);
            right = Math.max(leftEnd + 1, rightStart - 1);
        }
    }   
    return maxCount + leftMaxCount + rightMaxCount;
    
};