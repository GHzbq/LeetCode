//
// Created by zhangbaqing on 2021/4/14.
//
// 剑指offer09 两个栈实现队列
// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <stack>
#include <queue>

#if false

// 他也不知道啊，我就用队列呗
class CQueue {
private:
    std::queue<int> q;
public:
    CQueue() {

    }

    void appendTail(int value) {
        q.emplace(value);
    }

    int deleteHead() {
        if (q.empty()) {
            return -1;
        } else {
            int front = q.front();
            q.pop();
            return front;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
#endif

#if true

// 老老实实用两个栈实现呗
// 栈的特性：  先进后出
// 队列的特性：先进先出
//
// 入队列时，全往s1添加，
// 取对头元素时，从s2取，
// 如果s2为空，将s1所有元素导入s2，再从s2取
// 如果s1也空，返回-1
class CQueue {
private:
    std::stack<int> s1;
    std::stack<int> s2;
public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.emplace(value);
    }

    int deleteHead() {
        if (!s2.empty()) {
            int top = s2.top();
            s2.pop();
            return top;
        } else if (!s1.empty()) {
            while (!s1.empty()) {
                s2.emplace(s1.top());
                s1.pop();
            }
            int top = s2.top();
            s2.pop();
            return top;
        } else {
            return -1;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
#endif

#if false
class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {

    }

    int deleteHead() {

    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
#endif

#endif //LEETCODE_SOLUTION_H
