/**https://leetcode.com/problems/longest-mountain-in-array/ */
//You may recall that an array arr is a mountain array if and only if:
//	arr.length >= 3
//	There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//	
//		arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//	
//	
//Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.
// 
//Example 1:
//Input: arr = [2,1,4,7,3,2,5]
//Output: 5
//Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
//Example 2:
//Input: arr = [2,2,2]
//Output: 0
//Explanation: There is no mountain.
// 
//Constraints:
//	1 <= arr.length <= 104
//	0 <= arr[i] <= 104
// 
//Follow up:
//	Can you solve it using only one pass?
//	Can you solve it in O(1) space?
int longestMountain(int* arr, int arrSize){
    int i, j, k, n, m, a, b, c, d, e, f, g, h, t, r, s, u, v, w, x, y, z;
    i = 0;
    j = 0;
    k = 0;
    n = 0;
    m = 0;
    a = 0;
    b = 0;
    c = 0;
    d= 0;
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    t = 0;
    r = 0;
    s = 0;
    u = 0;
    v = 0;
    w = 0;
    x = 0;
    y = 0;
    z = 0;
        for(i = 1; i < arrSize; i++){
            if(arr[i] > arr[i-1]){
                if(j == 0){
                    j = 1;
                }
                if(j == 1){
                    j = 2;
                }
                if(j == 2){
                    j = 2;
                }
            }
            else if(arr[i] < arr[i-1]){
                if(j == 0){
                    j = 0;
                }
                else if(j == 1){
                    j = 1;
                }
            }
        }
        return ans;
}