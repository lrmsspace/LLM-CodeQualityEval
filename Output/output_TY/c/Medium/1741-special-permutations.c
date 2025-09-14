/**https://leetcode.com/problems/special-permutations/ */
//You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:
//	For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
//Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [2,3,6]
//Output: 2
//Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
//Example 2:
//Input: nums = [1,4,3]
//Output: 2
//Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums.
// 
//Constraints:
//	2 <= nums.length <= 14
//	1 <= nums[i] <= 109
int specialPerm(int* nums, int numsSize){   
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, j1, k1, l1, m1, n1, o1, p1, q1, r1, s1, t1, u1, v1, w1, x1, y1, z1,a1, b1, c1, d1, e1, f1, g1, h1, j2, k2, l2, m2, n2, o2, p2, q2, r2, s2, t2, u2, v2, w2, x2, y2, z2,a2, b2, c2, d2, e2, f2, g2, h2, j3, k3, l3, m3, n3, o3, p3, q3, r3, s3, t3, u3, v3, w3, x3, y3, z3,a3, b3, c3, d3, e3, f3, g3, h3, j4, k4, l4, m4, n4, o4, p4, q4, r4, s4, t4, u4, v4, w4, x4, y4, z4,a4, b4, c4, d4, e4, f4, g4, h4, j5, k5     , j5
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(i==j){
                continue;
            }
            for(k=0;k<numsSize;k++){
                if(i==k||j==k){
                    continue;
                }
                for(l=0;l<numsSize;l++){
                    if(i==l||j==l||k==l){
                        continue;
                    }
                }
            }
        }
    }
    return 0;
}