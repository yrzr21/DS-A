#include <vector>
#include <iostream>
using namespace std;

/* 求目标数组中，满足和大于target的最小长度的子数组 */
/* 每个数组元素均>0 */

int minSubArrayLen(int target, std::vector<int> &nums)
{
    /* 流程：l指针指向第一个元素，r不断右移，期间计算sum，直到>target，记录长度
            r右移，sum - nums[l] >= target?，是：
                    l++; 继续判断并循环
                否:
                    l++，r继续不断右移，期间...
            直到r抵达终点
     */
    int sum = 0, l = 0, minLen = 1000000, len = 0;
    for (int r = 0; r < nums.size(); r++)
    {
        sum += nums[r];
        if (sum < target)
            continue;
        // sum>=target
        while (l <= r && sum - nums[l] >= target)
            sum -= nums[l++];
        // l抵达临界，更新 minLen
        minLen = (minLen > r - l + 1) ? (r - l + 1) : minLen;
    }
    return minLen > nums.size() ? 0 : minLen;
}

int main()
{
    int target;
    vector<int> nums;
    cin >> target;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int rt = minSubArrayLen(target, nums);
    cout << rt << endl;
}