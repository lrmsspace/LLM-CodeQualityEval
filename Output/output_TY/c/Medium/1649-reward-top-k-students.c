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
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topStudents(char ** positive_feedback, int positive_feedbackSize, char ** negative_feedback, int negative_feedbackSize, char ** report, int reportSize, int* student_id, int student_idSize, int k, int* returnSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100001], b[100001], c[100001], d[100001], e[100001], f[100001], g[100001], h[100001], jj[100001], kk[100001], ll[100001], mm[100001], nn[100001], oo[100001], pp[100001], qq[100001], rr[100001], ss[100001], tt[100001], uu[100001], vv[100001], ww[100001], xx[100001], yy[100001], zz[100001];
    for(i=0;i<positive_feedbackSize;i++){
        for(j=0;j<reportSize;j++){
            if(strstr(report[j],positive_feedback[i])){
                a[student_id[j]]+=3;
            }
        }
    }
    for(i=0;i<negative_feedbackSize;i++){
        for(j=0;j<reportSize;j++){
            if(strstr(report[j],negative_feedback[i])){
                a[student_id[j]]--;
            }
        }
    }
    for(i=0;i<100001;i++){
        b[i]=a[i];
        c[i]=student_id[i];
    }
    for(i=0;i<100001;i++){
        for(j=0;j<100001;j++){
            if(b[i]>b[j]){
                t=b[i];
                b[i]=b[j];
                b[j]=t;
                t=c[i];
                c[i]=c[j];
                c[j]=t;
            }
        }
    }
    for(i=0;i<k;i++){
        jj[i]=c[i];
    }
    for(i=0;i<k;i++){
        kk[i]=jj[i];
    }
    *returnSize=k;
    return jj;
}