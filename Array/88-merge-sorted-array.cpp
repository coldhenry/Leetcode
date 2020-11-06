/*
1st Approach: merge and sort
Time Complexity: O(klogk) k = m + n
Space Compleity: O(k)
Problem: didn't take advantage of "sorted" array
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[i+m] = nums2[i];
        } 
        sort(nums1.begin(), nums1.end());
}

/*
2st Approach: merge from the back
KEY: to save an extra memory for overwriting
Time Complexity: O(k) k = m + n
Space Compleity: O(1)
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p = m+n-1;
    int ptr1 = m-1;
    int ptr2 = n-1;
    while(p >= 0){
        if(ptr1 >=0 && ptr2 >= 0){
            nums1[p--] = nums1[ptr1] >= nums2[ptr2] ? nums1[ptr1--] : nums2[ptr2--];
        } else {
            if(ptr1 >= 0) nums1[p--] = nums1[ptr1--];
            else if(ptr2 >= 0) nums1[p--] = nums2[ptr2--];
        }
    }
}