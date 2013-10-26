// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题我自己的思路是类似取局部最小值，然后每次都把局部最小值剔除，这样循环到最后就能得到所有最小值
// 不过只能过小数据，大数据悲剧，虽然我个人觉得在mac运行是瞬间出来的。

// 在后面会放上看出题解的思路。

class Solution {
public:
    int getLeftNeighbour(int index, vector<int> ratings, vector<int> candy, int currentMin) {
    if (index - 1 < 0) return 10000;
    else if (candy[index - 1] <= currentMin) return 10000;
    return ratings[index-1];
}

int getRightNeighbour(int index, vector<int> ratings, vector<int> candy, int currentMin) {
    if (index + 1 >= ratings.size()) return 10000;
    else if (candy[index + 1] <= currentMin) return 10000;
    return ratings[index+1];
}

int candy(vector<int> &ratings) {
    int size = ratings.size();
    vector<int> candy(size,10000);
    bool stillContainsBig = false;
    // 分配局部最小值
    for (int i = 0; i < size;i++) {
        int value = ratings[i];
        int left = getLeftNeighbour(i, ratings, candy, -1);
        int right = getRightNeighbour(i, ratings, candy, -1);
        
        if (value <= left && value <= right)
            candy[i] = 1;
        else {
            stillContainsBig = true;
            candy[i] = 10000;
        }
    }
    
    int currentMin = 1;
    while(stillContainsBig) {
        stillContainsBig = false;
        for (int i = 0; i < size;i++) {
            if (candy[i] <= currentMin) continue;
            int value = ratings[i];
            int left = getLeftNeighbour(i, ratings, candy, currentMin);
            int right = getRightNeighbour(i, ratings, candy, currentMin);
            
            if (value <= left && value <= right)
                candy[i] = currentMin+1;
            else {
                stillContainsBig = true;
                candy[i] = 10000;
            }
        }
        currentMin++;
    }

    int sum = 0;
    for (int i = 0; i < candy.size();i++) sum += candy[i];
    return sum;
}

};



// 题解思路，就是简单的来回扫两次即可，思路很简单，不赘述了，
// 扫两次的原因是类似于 2 3 2 1 4这样一遍不能成功的
class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        vector<int>candy(size, 1);
        
        int minCandy = 1;
        for (int i = 1; i < size ;i++) {
            if (ratings[i] > ratings[i-1]) minCandy++;
            else minCandy = 1;
            candy[i] = minCandy;
        }
        
        minCandy = 1;
        for (int i = size - 2;i >= 0;i--) {
            if (ratings[i] > ratings[i+1]) minCandy++;
            else minCandy = 1;
            candy[i] = max(minCandy,candy[i]);
        }
        
        int sum = 0;
        for (int i = 0; i < candy.size();i++) {
            sum += candy[i];
        }
        return sum;
    }
};