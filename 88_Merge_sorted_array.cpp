#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = 0;
            int j = 0;
            int qelem;
            queue<int> q;
    
            while (i < m && j < n) { // <-- make sure j < n
                int elem1 = nums1[i];
                int elem2 = nums2[j];
    
                if (q.empty()) {
                    if (elem1 < elem2) {
                        i++;
                    } else if (elem1 > elem2) {
                        q.push(nums1[i]);
                        nums1[i] = nums2[j];
                        i++;
                        j++;
                    } else if (i + 1 < m + n) {
                        // we ensure we do not go out of bounds
                        q.push(nums1[i + 1]);
                        nums1[i + 1] = nums1[i];
                        i += 2;
                        j++;
                    } else {
                        // fallback: just treat as greater
                        q.push(nums1[i]);
                        nums1[i] = nums2[j];
                        i++;
                        j++;
                    }
                } else {
                    int qelem = q.front();  // peek, don't pop yet
                    int elem2 = nums2[j];
                    int elem1 = nums1[i];   // current value at i
    
                    // Decide what to do without losing anything
                    if (qelem < elem2) {
                        q.pop();              // now it's safe
                        q.push(nums1[i]);     // save current before overwriting
                        nums1[i] = qelem;
                        i++;
                    } else if (qelem > elem2) {
                        q.push(nums1[i]);     // again, save before overwrite
                        nums1[i] = elem2;
                        j++;
                        i++;
                    } else {
                        // qelem == elem2
                        if (i + 1 < m + n) {
                            q.push(nums1[i]);       // backup first
                            q.push(nums1[i + 1]);   // also backup next value
                            nums1[i] = qelem;
                            nums1[i + 1] = elem2;
                            i += 2;
                            j++;
                            q.pop();                // remove used qelem
                        } else {
                            nums1[i] = qelem;
                            i++;
                            j++;
                            q.pop();  // remove used qelem
                        }
                    }
    
                }
            }
    
            if (i < m - 1){
                for(int x = i; x < m; x++){
                    q.push(nums1[x]);
                }
            }
    
            // Second part: finish merging
            while (i < m + n) {
                int elem1 = !q.empty() ? q.front() : INT_MAX;
                int elem2 = (j < n) ? nums2[j] : INT_MAX;
    
                if (q.empty() && j >= n) break; // nothing to merge
                if (!q.empty() && j >= n){
                    nums1[i] = q.front();
                    i++;
                    q.pop();
                    continue;
                }
    
                if (q.empty()) {
                    nums1[i] = elem2;
                    j++;
                    i++;
                } else if (j >= n) {
                    nums1[i] = elem1;
                    q.pop();
                    i++;
                } else if (elem1 < elem2) {
                    nums1[i] = elem1;
                    q.pop();
                    i++;
                } else if (elem1 > elem2) {
                    nums1[i] = elem2;
                    j++;
                    i++;
                } else {
                    if (i + 1 < m + n) {
                        nums1[i] = elem1;
                        nums1[i + 1] = elem2;
                        i += 2;
                        j++;
                        q.pop();
                    } else {
                        // fallback: fill with elem1 if only one space left
                        nums1[i] = elem1;
                        i++;
                        q.pop();
                        j++;
                    }
                }
            }
        }
    };