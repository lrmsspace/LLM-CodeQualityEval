/**https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/ */
//You are given a 0-indexed integer array nums. You can rearrange the elements of nums to any order (including the given order).
//Let prefix be the array containing the prefix sums of nums after rearranging it. In other words, prefix[i] is the sum of the elements from 0 to i in nums after rearranging it. The score of nums is the number of positive integers in the array prefix.
//Return the maximum score you can achieve.
// 
//Example 1:
//Input: nums = [2,-1,0,1,-3,3,-3]
//Output: 6
//Explanation: We can rearrange the array into nums = [2,3,1,-1,-3,0,-3].
//prefix = [2,5,6,5,2,2,-1], so the score is 6.
//It can be shown that 6 is the maximum score we can obtain.
//Example 2:
//Input: nums = [-2,-3,0]
//Output: 0
//Explanation: Any rearrangement of the array will result in a score of 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	-106 <= nums[i] <= 106
int maxScore(int* nums, int numsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[numsSize];
    int b[numsSize];
    int c[numsSize];
    int d[numsSize];
    int e[numsSize];
    int f[numsSize];
    int g[numsSize];
    int h[numsSize];
    int max=0;
    for(i=0;i<numsSize;i++){
        a[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        b[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        c[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        d[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        e[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        f[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        g[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        h[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            for(k=0;k<numsSize;k++){
                for(l=0;l<numsSize;l++){
                    for(m=0;m<numsSize;m++){
                        for(n=0;n<numsSize;n++){
                           for(o=0;o<numsSize;o++)   {
                            for(p=0;p<numsSize;p++){
                                for(q=0;q<numsSize;q++){
                                    for(r=0;r<numsSize;r++){
                                        for(s=0;s<numsSize;s++){
                                            for(t=0;t<numsSize;t++){
                                                for(u=0;u<numsSize;u++){
                                                    for(v=0;v<numsSize;v++){
                                                        for(w=0;w<numsSize;w++){
                                                            for(x=0;x<numsSize;x++){
                                                                for(y=0;y<numsSize;y++){
                                                                    for(z=0;z<numsSize;z++){
                                                                       int sum=0;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            }
                        }
                    }
                }
            }
        }
    }
    return max;
}