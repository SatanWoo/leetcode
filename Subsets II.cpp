// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题还算可以吧，突然发现原来数字子串的递归可以这么酷。这里的做法我大致说下：
// 比如我要或者[1, 2, 3]这个数组的Subsets, 我可以先构建一个[0, 0, 0]的位图。
// 然后利用这个位图进行递归即可。每次把一位设置成0 或者 1， 分别代表选中或者不选中。
// 当遍历到最后的时候，利用这个位图，重新构建一个拥有正确结果的vector即可，比如[1, 0, 0]
// 代表选中1，而2，3都没被选中；同理[1，0，1]代表1， 3被选中，2没有。

// 但是这道题有点复杂，因为存在可以重复的数字，所以我这里用了一个set来进行过滤判断。
// 但是Set如果直接过滤vector太麻烦了，我就利用了bitmap来创建string， 这样的话set就能快速判断
// 然后利用这个set进行vector重建即可。

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        std::sort(S.begin(), S.end());
        
        int size = S.size();
        
        vector<vector<int>>result;
        vector<int> bitMap(size);
        
        set<string> uniqueSubsets;
        
        recursivelySubsets(S, uniqueSubsets, bitMap, 0);
        buildSubsetsFromSets(uniqueSubsets, result);
        
        return result;
    }
    
    void buildSubsetsFromSets(set<string>& sets, vector<vector<int>> &result)
    {
        
        set<string>::iterator si;
        for (si = sets.begin(); si != sets.end(); si++) 
        {
            vector<int> temp;
            string s = *si;
            for (int i = 0; i < s.length();i ++)
            {
                int k = s[i] - '0';
                temp.push_back(k);
            }
            result.push_back(temp);
        }
    }
    
    void recursivelySubsets(vector<int>& S, set<string>& sets, vector<int> bitMap, int startIndex)
    {
        if (startIndex == S.size()) 
        {
            string temp = "";
            for (int i = 0; i < bitMap.size(); i++) 
            {
                if (bitMap[i] != 0) temp += S[i] + '0';
            }
                
            sets.insert(temp);
            return;
        }
        
        bitMap[startIndex] = 0;
        recursivelySubsets(S, sets, bitMap, startIndex + 1);
        bitMap[startIndex] = 1;
        recursivelySubsets(S, sets, bitMap, startIndex + 1);
    }
};