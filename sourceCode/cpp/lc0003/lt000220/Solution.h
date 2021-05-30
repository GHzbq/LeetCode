//
// Created by zhangbaqing on 2021/4/17.
//
// 220. 存在重复元素III
// https://leetcode-cn.com/problems/contains-duplicate-iii/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::set;
using std::min;
using std::max;
using std::unordered_map;

#if false

// abs(nums[i]-nums[j]) <= t &&
// abs(i-j) <= k
// 维护一个最多只有k个元素的滑动窗口
// 这个滑动窗口里保存的是，当前元素x左侧的k个元素(如果有的话！)
// 这就限制了i,j的范围，一定在k之内
// 接下来，我们只需要在这k个元素中，找到一个y，使得 abs(x-y) <= t 即可
// 换一种思路：只需要在滑动窗口找一个大于等于x-t的元素y(x-t<=y)，使其满足 y <= x+t
// 这是怎么来的呢，
// abs(x-y) <= t
// -t <= x-y && x-y <= t // 将y分别移动一下，就有了
// y <= x+t  && x-t <= y
//
// 不得不说，想出这个思路的人，数学不错！
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        int n = nums.size();
        std::set<int> res;
        for (int i = 0; i < n; ++i) {
            // 这里的nums[i]就是元素x
            // set.lower_bound方法，在set里寻找第一个不小于给定值的元素
            // 细节问题：nums[i]-t可能会溢出
//            auto it = res.lower_bound(nums[i] - t);
            // 这样处理一下，就不会溢出了
            auto it = res.lower_bound(std::max(nums[i], INT_MIN + t) - t);
//            if (it != res.end() && (*it <= nums[i] + t)) {
            if (it != res.end() && (*it <= std::min(nums[i], INT_MAX - t) + t)) {
                // 找到了这个合适的y，返回true
                return true;
            }
            // 把当前元素放入滑动窗口中
            res.insert(nums[i]);
            // 当元素超过k个，那么就移除最早放进去的哪个
            // 这里解释一下，为什么有等号
            // 其实滑动窗口里，应该只保存k-1个元素，
            // 当i等于k，或者大于k时，应该删除最早放入滑动窗口的元素
            if (i >= k) {
                res.erase(nums[i - k]);
            }
        }
        return false;
    }
};

#endif

#if true

// 桶更牛逼！
// 按照元素的大小进行分桶，维护一个滑动窗口元素对应的元素
// 对于元素x，其影响的区间为[x-t, x+t]，所以我们可以设定桶的大小为t+1
// 如果两个元素属于同一个桶，直接返回true；
// 如果两个元素属于相邻桶，需要校验他们的差值是否不超过t
// 否则，进入下一次循环
// 其实，桶里最多只会有一个元素，我们可以使用哈希表来作为桶
// 实现方面，我们将int范围内的每个整数表示为：x=(t+1)*a+b, 其中 0 <= b < t;
// 这样x就会落在a这个桶里
class Solution {
public:
    int getID(int x, long w) {
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }

    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long x = nums[i];
            int id = getID(x, t + 1ll);
            if (mp.count(id)) {
                return true;
            }
            if (mp.count(id - 1) && abs(x - mp[id - 1]) <= t) {
                return true;
            }
            if (mp.count(id + 1) && abs(x - mp[id + 1]) <= t) {
                return true;
            }
            mp[id] = x;
            if (i >= k) {
                mp.erase(getID(nums[i - k], t + 1ll));
            }
        }
        return false;
    }
};

#endif


#if flase
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
