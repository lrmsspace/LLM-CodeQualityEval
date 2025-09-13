/**https://leetcode.com/problems/single-number-ii/ */
//Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.
// 
//Example 1:
//Input: nums = [2,2,3,2]
//Output: 3
//Example 2:
//Input: nums = [0,1,0,1,0,1,99]
//Output: 99
// 
//Constraints:
//	1 <= nums.length <= 3 * 104
//	-231 <= nums[i] <= 231 - 1
//	Each element in nums appears exactly three times except for one element which appears once.
int singleNumber(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
    n = 0;
    o = 0;
    p = 0;
    q = 0;
    r =0;
    s = 0;
    t = 0;
    u = 0;
    v = 0;
    w = 0;
    x = 0;
    y = 0;
    z = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            j++;
        }
        else if(nums[i] == 1){
            k++;
        }
        else if(nums[i] == 2){
            l++;
        }
        else if(nums[i] == 3){
            m++;
        }
       else if(nums[i] == 4){
          n++;
       }
    }
    if(j%3 == 0){
        return 0;
    }
    else if(k%3 == 0){
        return 1;
    }
    else if(l%3 == 0){
        return 2;
    }
    else if(m%3 == 0){
        return 3;
    }
    else if(n%3 == 0){
        return 4;
    }
    return 0;

}