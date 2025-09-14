/**https://leetcode.com/problems/sum-of-beauty-of-all-substrings/ */
//The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
//	For example, the beauty of "abaacc" is 3 - 1 = 2.
//Given a string s, return the sum of beauty of all of its substrings.
// 
//Example 1:
//Input: s = "aabcb"
//Output: 5
//Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
//Example 2:
//Input: s = "aabcbaa"
//Output: 17
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters.
int beautySum(char * s){
    int i,j,k,l,sum=0,max,min;
    for(i=0;s[i];i++){
        int freq[26]={0};
        for(j=i;s[j];j++){
            freq[s[j]-'a']++;
            max=min=s[j]-'a';
            for(k=0;k<26;k++){
                if(freq[k]>freq[max])
                    max=k;
            }
        }
    }
    return sum;
}