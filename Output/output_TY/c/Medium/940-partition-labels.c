/**https://leetcode.com/problems/partition-labels/ */
//You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
//Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
//Return a list of integers representing the size of these parts.
// 
//Example 1:
//Input: s = "ababcbacadefegdehijhklij"
//Output: [9,7,8]
//Explanation:
//The partition is "ababcbaca", "defegde", "hijhklij".
//This is a partition so that each letter appears in at most one part.
//A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
//Example 2:
//Input: s = "eccbbbbdec"
//Output: [10]
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize){
    int i,j,k;
    int len=strlen(s);
    int *arr=(int *)malloc(sizeof(int)*26);
    for(i=0;i<26;i++)
    {
        arr[i]=-1;
    }
    for(i=0;i<len;i++)
    {
        arr[s[i]-'a']=i;
    }
    int *res=(int *)malloc(sizeof(int)*len);
    *returnSize=0;
    for(i=0;i<len;i++)
    {
        if(arr[s[i]-'a']==i)
        {
            res[*returnSize]=1;
            (*returnSize)++;
        }
        else
        {
            j=i;
            while(j<=arr[s[i]-'a'])
            {
                res[*returnSize]++;
                j++;
            }
            (*returnSize)++;
            i=j-1;
        }
    }
    return res;
}