/**https://leetcode.com/problems/reward-top-k-students/ */
//You are given two string arrays positive_feedback and negative_feedback, containing the words denoting positive and negative feedback, respectively. Note that no word is both positive and negative.
//Initially every student has 0 points. Each positive word in a feedback report increases the points of a student by 3, whereas each negative word decreases the points by 1.
//You are given n feedback reports, represented by a 0-indexed string array report and a 0-indexed integer array student_id, where student_id[i] represents the ID of the student who has received the feedback report report[i]. The ID of each student is unique.
//Given an integer k, return the top k students after ranking them in non-increasing order by their points. In case more than one student has the same points, the one with the lower ID ranks higher.
// 
//Example 1:
//Input: positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
//Output: [1,2]
//Explanation: 
//Both the students have 1 positive feedback and 3 points but since student 1 has a lower ID he ranks higher.
//Example 2:
//Input: positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is not studious","the student is smart"], student_id = [1,2], k = 2
//Output: [2,1]
//Explanation: 
//- The student with ID 1 has 1 positive feedback and 1 negative feedback, so he has 3-1=2 points. 
//- The student with ID 2 has 1 positive feedback, so he has 3 points. 
//Since student 2 has more points, [2,1] is returned.
// 
//Constraints:
//	1 <= positive_feedback.length, negative_feedback.length <= 104
//	1 <= positive_feedback[i].length, negative_feedback[j].length <= 100
//	Both positive_feedback[i] and negative_feedback[j] consists of lowercase English letters.
//	No word is present in both positive_feedback and negative_feedback.
//	n == report.length == student_id.length
//	1 <= n <= 104
//	report[i] consists of lowercase English letters and spaces ' '.
//	There is a single space between consecutive words of report[i].
//	1 <= report[i].length <= 100
//	1 <= student_id[i] <= 109
//	All the values of student_id[i] are unique.
//	1 <= k <= n
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<int, int> points;
        for (int i = 0; i < positive_feedback.size(); i++) {
            points[hash(positive_feedback[i])] = 3;
        }
        for (int i = 0; i < negative_feedback.size(); i++) {
            points[hash(negative_feedback[i])] = -1;
        }
        vector<int> res;
        for (int i = 0; i < report.size(); i++) {
            int id = student_id[i];
            int point = 0;
            istringstream iss(report[i]);
            string word;
            while (iss >> word) {
                point += points[hash(word)];
            }
            if (res.size() < k) {
                res.push_back(id);
                points[id] = point;
            } else {
                if (point > points[res.back()] || (point == points[res.back()] && id < res.back())) {
                    res.pop_back();
                    res.push_back(id);
                    points[id] = point;
                }
            }
            sort(res.begin(), res.end(), [&](int a, int b) {
                return points[a] > points[b] || (points[a] == points[b] && a < b);
            });
        }
        return res;        
    }
};