/**https://leetcode.com/problems/smallest-sufficient-team/ */
//In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.
//Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.
//	For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
//Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.
//It is guaranteed an answer exists.
// 
//Example 1:
//Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
//Output: [0,2]
//Example 2:
//Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
//Output: [1,2]
// 
//Constraints:
//	1 <= req_skills.length <= 16
//	1 <= req_skills[i].length <= 16
//	req_skills[i] consists of lowercase English letters.
//	All the strings of req_skills are unique.
//	1 <= people.length <= 60
//	0 <= people[i].length <= 16
//	1 <= people[i][j].length <= 16
//	people[i][j] consists of lowercase English letters.
//	All the strings of people[i] are unique.
//	Every skill in people[i] is a skill in req_skills.
//	It is guaranteed a sufficient team exists.
class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int n=req_skills.length;
        Map<String,Integer> map=new HashMap<>();
        for(int i=0;i<n;i++){
            map.put(req_skills[i],i);
        }
        int m=people.size();
        int[] dp=new int[1<<n];
        Arrays.fill(dp,m);
        dp[0]=0;
        int[] prev=new int[1<<n];
        for(int i=0;i<m;i++){
            List<String> list=people.get(i);
            int mask=0;
            for(String s:list){
                mask=mask|(1<<map.get(s));
           }
        } 
        for(int mask=0;mask<(1<<n);mask++){
            for(int sub=mask;sub>0;sub=(sub-1)&mask){
                if(dp[sub]!=m){
                    dp[mask]=Math.min(dp[mask],dp[sub]+dp[mask-sub]);
                }
            }
        }
        return dp[(1<<n)-1]; 
    }
}