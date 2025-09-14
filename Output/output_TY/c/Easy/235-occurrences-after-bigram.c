/**https://leetcode.com/problems/occurrences-after-bigram/ */
//Given two strings first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.
//Return an array of all the words third for each occurrence of "first second third".
// 
//Example 1:
//Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
//Output: ["girl","student"]
//Example 2:
//Input: text = "we will we will rock you", first = "we", second = "will"
//Output: ["we","rock"]
// 
//Constraints:
//	1 <= text.length <= 1000
//	text consists of lowercase English letters and spaces.
//	All the words in text a separated by a single space.
//	1 <= first.length, second.length <= 10
//	first and second consist of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findOcurrences(char * text, char * first, char * second, int* returnSize){
    char **ans = (char**)malloc(sizeof(char*)*1000);
    char *p = text;
    char *q = first;
    char *r = second;
    int i = 0;
    while(*p){
        if(strncmp(p,q,strlen(q))==0){
            p+=strlen(q);
            if(strncmp(p,r,strlen(r))==0){
                ans[i] = (char*)malloc(sizeof(char)*100);
                strncpy(ans[i],p+strlen(r),strlen(p)-strlen(r));
                ans[i][strlen(p)-strlen(r)]='\0';
                i++;
            }
        }
    }
    *returnSize = i;
    return ans;
}   