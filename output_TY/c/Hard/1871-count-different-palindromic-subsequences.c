/**https://leetcode.com/problems/count-different-palindromic-subsequences/ */
//Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of a string is obtained by deleting zero or more characters from the string.
//A sequence is palindromic if it is equal to the sequence reversed.
//Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.
// 
//Example 1:
//Input: s = "bccb"
//Output: 6
//Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
//Note that 'bcb' is counted only once, even though it occurs twice.
//Example 2:
//Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
//Output: 104860361
//Explanation: There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 109 + 7.
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either 'a', 'b', 'c', or 'd'.
int countPalindromicSubsequences(char * s){ 
    int n=strlen(s);
    int dp[n][n][4];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][i][s[i]-'a']=1;
    }
    for(int i=n-2;i>=0;i--){
 for(int j=i+1;j<n;j++){
  for(int k=0;k<4;k++){
   dp[i][j][k]=dp[i+1][j][k]+dp[i][j-1][k]-dp[i+1][j-1][k];
  }
  for(int k=0;k<4;k++){
    if(s[i]==s[j]&&s[i]=='a'+k){
   dp[i][j][k]+=dp[i+1][j-1][k]+1;
    }else{
   for(int l=0;l<4;l++){
    if(l!=k){
     dp[i][j][k]+=dp[i+1][j-1][l];
    }
   }
    }
  }
 }
    }
    return dp[0][n-1][3];
}