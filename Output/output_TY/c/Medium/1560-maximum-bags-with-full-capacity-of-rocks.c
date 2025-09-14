/**https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/ */
//You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. The ith bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.
//Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.
// 
//Example 1:
//Input: capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
//Output: 3
//Explanation:
//Place 1 rock in bag 0 and 1 rock in bag 1.
//The number of rocks in each bag are now [2,3,4,4].
//Bags 0, 1, and 2 have full capacity.
//There are 3 bags at full capacity, so we return 3.
//It can be shown that it is not possible to have more than 3 bags at full capacity.
//Note that there may be other ways of placing the rocks that result in an answer of 3.
//Example 2:
//Input: capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
//Output: 3
//Explanation:
//Place 8 rocks in bag 0 and 2 rocks in bag 2.
//The number of rocks in each bag are now [10,2,2].
//Bags 0, 1, and 2 have full capacity.
//There are 3 bags at full capacity, so we return 3.
//It can be shown that it is not possible to have more than 3 bags at full capacity.
//Note that we did not use all of the additional rocks.
// 
//Constraints:
//	n == capacity.length == rocks.length
//	1 <= n <= 5 * 104
//	1 <= capacity[i] <= 109
//	0 <= rocks[i] <= capacity[i]
//	1 <= additionalRocks <= 109
int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[capacitySize], b[capacitySize], c[capacitySize], d[capacitySize], e[capacitySize], f[capacitySize], g[capacitySize], h[capacitySize], i[capacitySize], j[capacitySize], k[capacitySize], l[capacitySize], m[capacitySize], n[capacitySize];
    for (i = 0; i < capacitySize; i++) {
        a[i] = capacity[i] - rocks[i];
    }
    for (i = 0; i < capacitySize; i++) {
        b[i] = a[i];
    }
    for (i = 0; i < capacitySize; i++) {
        c[i] = a[i];
    }
    for (i = 0; i < capacitySize; i++) {
        if (c[i] > mid) {
            mid = c[i];
        }
    }
    for (i = 0; i < capacitySize; i++) {
        if (b[i] <= mid) {
            count++;
        }
    }
    return count;
}