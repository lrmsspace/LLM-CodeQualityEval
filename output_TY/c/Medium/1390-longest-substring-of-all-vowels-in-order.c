/**https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/ */
//A string is considered beautiful if it satisfies the following conditions:
//	Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
//	The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
//For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
//Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
//Output: 13
//Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
//Example 2:
//Input: word = "aeeeiiiioooauuuaeiou"
//Output: 5
//Explanation: The longest beautiful substring in word is "aeiou" of length 5.
//Example 3:
//Input: word = "a"
//Output: 0
//Explanation: There is no beautiful substring, so return 0.
// 
//Constraints:
//	1 <= word.length <= 5 * 105
//	word consists of characters 'a', 'e', 'i', 'o', and 'u'.
int longestBeautifulSubstring(char * word){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    i=0;j=0;k=0;l=0;m=0;n=0;o=0;p=0;q=0;r=0;s=0;t=0;u=0;v=0;w=0;x=0;y=0;z=0;
    while(word[i]!='\0'){
        if(word[i]=='a'){
            j=i;
            while(word[j]=='a'){
                j++;
            }
            i=j;
            if(word[i]=='e'){
                k=i;
                while(word[k]=='e'){
                    k++;
                }
               i=k;
            }
        }
    }
    return 0;
}