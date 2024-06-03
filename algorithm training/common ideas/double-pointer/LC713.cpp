#include <vector>
#include <iostream>
using namespace std;

/* 返回目标数组内，乘积严格小于k的连续子数组的数目 */
/* k>=0，元素>=0 */
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    /* l、r指向第一个元素，r不断右移，期间记录[l,r]区间元素的乘积product
        当product>k，product/=nums[l++]>=k
        当product<k，统计count
        r继续右移
     */
    int l = 0, product = 1, count = 0;
    for (size_t r = 0; r < nums.size(); r++)
    {
        product *= nums[r];
        while (l <= r && product >= k)
            product /= nums[l++];
        count += r - l + 1;
    }
    return count;
}

int main()
{
    int k, n;
    cin >> k >> n;
    std::vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int rt = numSubarrayProductLessThanK(nums, k);
    cout << rt << endl;
}