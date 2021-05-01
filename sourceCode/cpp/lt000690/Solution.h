//
// Created by zhangbaqing on 2021/5/1.
//
// 690. 员工的重要性

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <unordered_map>
#include <vector>
#include <iostream>

using std::vector;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

#if true


class Solution {
public:
    int getImportance(vector<Employee *> &employees, int id) {
        // 可以搞一个map嘛
        // key为id，value为Employee
        // 第一遍循环，先将employees全部插入map中，
        // 第二遍循环，dfs查询该员工所有的员工
        // 这样可能会有重复计算的问题，但暂时先忽略叭
        std::unordered_map<int, Employee *> m;
        for (auto &employee : employees) {
            m.insert(std::make_pair(employee->id, employee));
        }
        return dfs(m, id);
    }

private:
    int dfs(std::unordered_map<int, Employee *> &m, int id);

    // 调试用的
    void printEmployee(std::unordered_map<int, Employee *> &m) {
        for (auto &p : m) {
            auto &employee = p.second;
            std::cout << "id: " << employee->id << " import: " << employee->importance << " sub: ";
            for (auto subId: employee->subordinates) {
                std::cout << subId << " ";
            }
            std::cout << std::endl;

        }
    }
};

int Solution::dfs(std::unordered_map<int, Employee *> &m, int id) {
    int ret = 0;
    Employee *employee = m[id];
    if (employee == nullptr) {
        return ret;
    } else {
        ret += employee->importance;
    }
    for (auto subId : employee->subordinates) {
        ret += dfs(m, subId);
    }
    return ret;
}

#endif

#endif //LEETCODE_SOLUTION_H
