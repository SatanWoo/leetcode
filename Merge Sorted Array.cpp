// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题没难度，类似于Merge sort 即可。

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int indexA = 0, indexB = 0;
        
        vector<int> temp;
        
        while(indexA < m && indexB < n)
        {
            if (A[indexA] > B[indexB]) temp.push_back(B[indexB++]);
            else temp.push_back(A[indexA++]);
        }
        
        for (int i = indexA; i < m;i++) temp.push_back(A[i]);
        for (int i = indexB; i < n;i++) temp.push_back(B[i]);
        
        for (int i = 0 ; i < temp.size(); i++) A[i] = temp[i];
    }
};