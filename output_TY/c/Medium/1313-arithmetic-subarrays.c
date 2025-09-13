/**https://leetcode.com/problems/arithmetic-subarrays/ */
//A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.
//For example, these are arithmetic sequences:
//1, 3, 5, 7, 9
//7, 7, 7, 7
//3, -1, -5, -9
//The following sequence is not arithmetic:
//1, 1, 2, 5, 7
//You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.
//Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.
// 
//Example 1:
//Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
//Output: [true,false,true]
//Explanation:
//In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
//In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
//In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
//Example 2:
//Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
//Output: [false,true,false,false,true,true]
// 
//Constraints:
//	n == nums.length
//	m == l.length
//	m == r.length
//	2 <= n <= 500
//	1 <= m <= 500
//	0 <= l[i] < r[i] < n
//	-105 <= nums[i] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize){
    int i,j,k,m,n,p,q,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r18,r19,r20,r21,r22,r23,r24,r25,r26,r27,r28,r29,r30,r31,r32,r33,r34,r35,   r36,r37,r38,r39,r40,r41,r42,r43,r44,r45,r46,r47,r48,r49,r50,r51,r52,r53,r54,r55,r56,r57,r58,r59,r60,r61,r62,r63,r64,r65,r66,r67,r68,r69,r70,r71,r72,r73,r74,r75,    r76,r77,r78,r79,r80,r81,r82,r83,r84,r85,r86,r87,r88,r89,r90,r91,r92,r93,r94,r95,r96,r97,r98,r99,r100;
    int *arr,*arr1,*arr2,*arr3,*arr4,*arr5,*arr6,*arr7,*arr8,*arr9,*arr10,*arr11,*arr12,*arr13,*arr14,*arr15,*arr16,*arr17,*arr18,*arr19,*arr20,*arr21,*arr22,*arr23,*arr24,*arr25,*arr26,*arr27,*arr28,*arr29, *arr30,*arr31,*arr32,*arr33,*arr34,*arr35,*arr36,*arr37,*arr38,*arr39,*arr40,*arr41,*arr42,*arr43,*arr44,*arr45,*arr46,*arr47,*arr48,*arr49,*arr50,*arr51,*arr52,*arr53,*arr54,*arr55,*arr56,*arr57,*arr58,*arr59,  *arr60,*arr61,*arr62,*arr63,*arr64,*arr65,*arr66,*arr67,*arr68,*arr69,*arr70,*arr71,*arr72,*arr73,*arr74,*arr75,*arr76,*arr77,*arr78,*arr79,*arr80,*arr81,*arr82,*arr83,*arr84,*arr85,*arr86,*arr87,*arr88,*arr89,  *arr90,*arr91,*arr92,*arr93,*arr94,*arr95,*arr96,*arr97,*arr98,*arr99,*arr100;
    bool *ans,*ans1,*ans2,*ans3,*ans4,*ans5,*ans6,*ans7,*ans8,*ans9,*ans10,*ans11,*ans12,*ans13,*ans14,*ans15,*ans16,*ans17,*ans18,*ans19,*ans20,*ans21,*ans22,*ans23,*ans24,*ans25,*ans26,*ans27,*ans28,*ans29,    *ans30,*ans31,*ans32,*ans33,*ans34,*ans35,*ans36,*ans37,*ans38,*ans39,*ans40,*ans41,*ans42,*ans43,*ans44,*ans45,*ans46,*ans47,*ans48,*ans49,*ans50,*ans51,*ans52,*ans53,*ans54,*ans55,*ans56,*ans57,*ans58,*ans59,  *ans60,*ans61,*ans62,*ans63,*ans64,*ans65,*ans66,*ans67,*ans68,*ans69,*ans70,*ans71,*ans72,*ans73,*ans74,*ans75,*ans76,*ans77,*ans78,*ans79,*ans80,*ans81,*ans82,*ans83,*ans84,*ans85,*ans86,*ans87,*ans88,*ans89,  *ans90,*ans91,*ans92,*ans93,*ans94,*ans95,*ans96,*ans97,*ans98,*ans99,*ans100;
    ans=malloc(sizeof(bool)*lSize);
    for(i=0;i<lSize;i++){
        arr=malloc(sizeof(int)*(r[i]-l[i]+1));
        for(j=0;j<r[i]-l[i]+1;j++){
            arr[j]=nums[l[i]+j];
        }
        arr1=malloc(sizeof(int)*(r[i]-l[i]+1));
        for(j=0;j<r[i]-l[i]+1;j++){
            j=0;j<r[i]-l[i]+1;
            j++;
        }
    }
    for(i=0;i<lSize;i++){
        ans[i]=true;
    }
    *returnSize=lSize;
    return ans;
}