//
// Created by zhangbaqing on 2021/3/23.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <stack>
#include <queue>

using std::vector;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

#if false

/**
 * 解法一：
 * 思路：通过观察示例，我们发现，这其实描述的是一颗树，那么我们使用深度优先遍历，将数据拿出来单独存储即可
 *      并用一个指针(迭代器)标记在为遍历数据起始位置，当需要读取的时候，让指针(迭代器)后移一个单位
 *      对于hasNext操作，只需要判断指针是否走到数据尾端即可；
 * */
class NestedIterator {
private:
    std::vector<int> data;
    std::vector<int>::iterator cur;

    void dfs(const std::vector<NestedInteger> &);

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        cur = data.begin();
    }

    int next() {
        return *cur++;
    }

    bool hasNext() {
        return cur != data.end();
    }
};

void NestedIterator::dfs(const std::vector<NestedInteger> &nestedList) {
    for (auto &item : nestedList) {
        if (item.isInteger()) {
            data.push_back(item.getInteger());
        } else {
            dfs(item.getList());
        }
    }
}

#endif

#if true

/**
 * 解法二：
 * 思路：借助栈，将深度优先遍历转化为循环
 *      初始时，直接将<nestedList.begin(), nestedList.end()>入栈
 *      hasNext操作：当栈不为空或者栈顶元素不是整数，进入循环：
 *         取栈顶元素，
 *            如果列表为空，出栈
 *            如果列表第一个元素isInteger，返回true，否则将列表第一个元素入栈
 *         hasNext，保证栈顶一定是个整数，要么返回false
 *      next操作，只要hasNext返回true，直接取栈顶元素就好了；
 * */
class NestedIterator {
private:
    std::stack<std::pair<std::vector<NestedInteger>::iterator, std::vector<NestedInteger>::iterator>> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        return s.top().first++->getInteger();
    }

    bool hasNext() {
        while (!s.empty()) {
            auto &p = s.top();
            if (p.first == p.second) {
                // 列表遍历完了，出栈
                s.pop();
                continue;
            }
            if (p.first->isInteger()) {
                return true;
            }
            // 当前元素为列表，将其入栈，并让指针(迭代器)指向下一个元素
            auto &lst = p.first++->getList();
            s.emplace(lst.begin(), lst.end());
        }
        return false;
    }
};

#endif

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

#endif //LEETCODE_SOLUTION_H
