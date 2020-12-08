/*
H-index series
274: non-sorted array
275: sorted array
*/


// Approach 1: Comparison sort based 
// using built-in sort in the beginning
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for(int i = 0; i < n; i++){
            int tmp_h = n - i;
            if(citations[i] >= tmp_h) return tmp_h;
        }
        return 0;
    }
};


// Approach 2: Counting Sort
// Counting sort is a non-comparison sorting algorithm
// recall that comparison sort has a lower bound of O(n*logn)
// Time complexity: O(n+k), k: the range of non-negative key values
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // construct a vector to calculate the frequency of citation
        vector<int> count(n+1, 0);
        for(auto& c : citations){
            if(c >= n) count[n]++;
            else count[c]++;
        }

        // accumulate the number of paper from the end 
        // whenever the num of paper is larger than the value of citation
        // it's the largest h-index
        int numOfPaper = 0;
        for(int i = n; i >= 0; i--){
            numOfPaper += count[i];
            if(numOfPaper >= i) return i;
        }
        return 0;
    }
};

// Appraoch 3: (sorted array) Binary search
// if sorted, we can do a binary search to reduce the time complexity
// from O(n) to O(logn)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(!n) return 0;
        int left = 0, right = n-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(citations[mid] == n - mid) return n - mid;
            else if(citations[mid] < n - mid) left = mid + 1;
            else if(citations[mid] > n - mid) right = mid - 1;
        }
        return n - left;
    }
};