// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题还算可以吧，突然发现原来数字子串的递归可以这么酷。这里的做法我大致说下：
// 比如我要或者[1, 2, 3]这个数组的Subsets, 我可以先构建一个[0, 0, 0]的位图。
// 然后利用这个位图进行递归即可。每次把一位设置成0 或者 1， 分别代表选中或者不选中。
// 当遍历到最后的时候，利用这个位图，重新构建一个拥有正确结果的vector即可，比如[1, 0, 0]
// 代表选中1，而2，3都没被选中；同理[1，0，1]代表1， 3被选中，2没有。

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        std::sort(S.begin(), S.end());
        
        int size = S.size();
        vector<vector<int>> result;
        
        vector<int> bitMap(size);
        recursivelySubsets(S, result, bitMap, 0);
        
        return result;
    }
    
    void recursivelySubsets(vector<int> &S, vector<vector<int>> &result, vector<int> bitMap, int startIndex)
    {
        if (startIndex == S.size()) 
        {   
            vector<int> temp;
            for (int i = 0; i < bitMap.size(); i++)
            {
                if (bitMap[i] != 0) temp.push_back(S[i]);
            }
            result.push_back(temp);
            return;
        }
        
        bitMap[startIndex] = 0;
        recursivelySubsets(S, result, bitMap, startIndex + 1);
        bitMap[startIndex] = 1;
        recursivelySubsets(S, result, bitMap, startIndex + 1);
        
    }
};