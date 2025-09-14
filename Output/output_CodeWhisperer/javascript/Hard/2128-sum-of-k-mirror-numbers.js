/**https://leetcode.com/problems/sum-of-k-mirror-numbers/ */
//A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.
//	For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
//	On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
//Given the base k and the number n, return the sum of the n smallest k-mirror numbers.
// 
//Example 1:
//Input: k = 2, n = 5
//Output: 25
//Explanation:
//The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
//  base-10    base-2
//    1          1
//    3          11
//    5          101
//    7          111
//    9          1001
//Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
//Example 2:
//Input: k = 3, n = 7
//Output: 499
//Explanation:
//The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
//  base-10    base-3
//    1          1
//    2          2
//    4          11
//    8          22
//    121        11111
//    151        12121
//    212        21212
//Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
//Example 3:
//Input: k = 7, n = 17
//Output: 20379000
//Explanation: The 17 smallest 7-mirror numbers are:
//1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
// 
//Constraints:
//	2 <= k <= 9
//	1 <= n <= 30
/**
 * @param {number} k
 * @param {number} n
 * @return {number}
 */
var kMirror = function(k, n) {
    let ans = 0;
    let arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, 212, 222, 232, 242, 252, 262, 272, 282, 292, 303, 313, 323, 333, 343, 353, 363, 373, 383, 393, 404, 414, 424, 434, 444, 454, 464, 474, 484, 494, 505, 515, 525, 535, 545, 555, 565, 575, 585, 595, 606, 616, 626, 636, 646, 656, 666, 676, 686, 696, 707, 717, 727, 737, 747, 757, 767, 777, 787, 797, 808, 818, 828, 838, 848, 858, 868, 878, 888, 898, 909, 919, 929, 939, 949, 959, 969, 979, 989, 999];
    for (let i = 0; i < n; i++) {
        ans += arr[i];
    }
    return ans;
};