/*
 There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.
 Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).
 Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.
 Since the answer may be large, return it modulo 109 + 7.
 Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.
 Example 1:
 Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
 Output: 4
 Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
 Example 2:
 Input: m = 6, n = 7, hFences = [2], vFences = [4]
 Output: -1
 Explanation: It can be proved that there is no way to create a square field by removing fences.
 Constraints:
 3 <= m, n <= 109
 1 <= hFences.length, vFences.length <= 600
 1 < hFences[i] < m
 1 < vFences[i] < n
 hFences and vFences are unique.
*/

int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize, int* vFences, int vFencesSize) {
    int i, j, k, l, max = -1, mod = 1000000007;
    int* h = (int*)malloc(sizeof(int) * (hFencesSize + 2));
    int* v = (int*)malloc(sizeof(int) * (vFencesSize + 2));
    h[0] = 1;
    v[0] = 1;
    for (i = 0; i < hFencesSize; i++)
        h[i + 1] = hFences[i];
    h[i + 1] = m;
    for (i = 0; i < vFencesSize; i++)
        v[i + 1] = vFences[i];
    v[i + 1] = n;
    for (i = 0; i < hFencesSize + 1; i++)
        for (j = i + 1; j < hFencesSize + 2; j++)
            for (k = 0; k < vFencesSize + 1; k++)
                for (l = k + 1; l < vFencesSize + 2; l++)
                    if (h[i] - h[j] == v[k] - v[l] || h[j] - h[i] == v[k] - v[l])
                        if (max < (h[i] - h[j]) * (h[i] - h[j]))
                            max = (h[i] - h[j]) * (h[i] - h[j]);
    free(h);
    free(v);
    if (max == -1)
        return -1;
    else
        return max % mod;    
}