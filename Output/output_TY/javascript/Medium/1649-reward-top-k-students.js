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
/**
 * @param {string[]} positive_feedback
 * @param {string[]} negative_feedback
 * @param {string[]} report
 * @param {number[]} student_id
 * @param {number} k
 * @return {number[]}
 */
var topStudents = function(positive_feedback, negative_feedback, report, student_id, k) {
    var map = new Map();
    for(var i=0;i<positive_feedback.length;i++){
        map.set(positive_feedback[i],3);
    }
    for(var i=0;i<negative_feedback.length;i++){
        map.set(negative_feedback[i],-1);
    }
    var arr = [];
    for(var i=0;i<report.length;i++){
        var temp = report[i].split(" ");
        var sum = 0;
        for(var j=0;j<temp.length;j++){
            if(map.has(temp[j])){
                sum+=map.get(temp[j]);
            }
        }
    }
    arr.push([student_id[i],sum]);
    arr.sort(function(a,b){
        return b[1]-a[1];
    });
    var ans = [];
    for(var i=0;i<k;i++){
        ans.push(arr[i][0]);
    }
    return ans;
};