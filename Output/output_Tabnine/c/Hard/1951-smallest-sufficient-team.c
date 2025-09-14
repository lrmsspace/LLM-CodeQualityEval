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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestSufficientTeam(char** req_skills, int req_skillsSize, char*** people, int peopleSize, int* peopleColSize, int* returnSize) {
    int n = peopleSize;
    int m = req_skillsSize;
    int* skill_count = (int*)calloc(m, sizeof(int));
    int* dp = (int*)calloc(1 << n, sizeof(int));
    int* parent = (int*)calloc(1 << n, sizeof(int));
    int* res = (int*)calloc(n, sizeof(int));
    int min_size = INT_MAX;
    for (int i = 0; i < peopleSize; i++) {
        for (int j = 0; j < peopleColSize[i]; j++) {
            for (int k = 0; k < m; k++) {
                if (strcmp(people[i][j], req_skills[k]) == 0) {
                    skill_count[k]++;
                    break;
                }
            }
        }
    }
    
    for (int i = 0; i < (1 << n); i++) {
        int size = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                size += skill_count[j];
            }
        }
        dp[i] = size;
        parent[i] = -1;
    }
    
    for (int i = 1; i < (1 << n); i++) {
        int min_val = INT_MAX;
        int min_idx = -1;
        for (int j = 0; j < (1 << n); j++) {
            if (dp[j] < min_val && (i & j) == 0) {
                min_val = dp[j];
                min_idx = j;
            }
        }
        if (min_idx!= -1) {
            parent[i] = min_idx;
        }
    }
    
    int cur = (1 << n) - 1;
    int cur_size = dp[cur];
    while (cur!= -1) {
        for (int i = 0; i < n; i++) {
            if (cur & (1 << i)) {
                res[cur_size - 1] = i;
                cur_size--;
                cur = parent[cur];
                break;
            }
        }
    }
    
    *returnSize = cur_size;
    return res;
    
}