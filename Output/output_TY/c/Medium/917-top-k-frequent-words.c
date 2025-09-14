/**https://leetcode.com/problems/top-k-frequent-words/ */
//Given an array of strings words and an integer k, return the k most frequent strings.
//Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
// 
//Example 1:
//Input: words = ["i","love","leetcode","i","love","coding"], k = 2
//Output: ["i","love"]
//Explanation: "i" and "love" are the two most frequent words.
//Note that "i" comes before "love" due to a lower alphabetical order.
//Example 2:
//Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
//Output: ["the","is","sunny","day"]
//Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
// 
//Constraints:
//	1 <= words.length <= 500
//	1 <= words[i].length <= 10
//	words[i] consists of lowercase English letters.
//	k is in the range [1, The number of unique words[i]]
// 
//Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    int i,j,n,m,t,k1,k2;
    char **res;
    int *cnt;
    cnt = (int*)malloc(sizeof(int)*500);
    for(i=0;i<500;i++) cnt[i]=0;
    for(i=0;i<wordsSize;i++){
        n=strlen(words[i]);
        for(j=0;j<n;j++){
            t=words[i][j]-'a';
            cnt[t]++;
        }
    }
    res = (char**)malloc(sizeof(char*)*k);
    for(i=0;i<k;i++){
        k1=0;
        for(j=1;j<500;j++){
            if(cnt[j]>cnt[k1]) k1=j;
        }
        cnt[k1]=-1;
        res[i] = (char*)malloc(sizeof(char)*(k1+1));
        for(j=0;j<=k1;j++) res[i][j]=j+'a';
    }
    return res;
}