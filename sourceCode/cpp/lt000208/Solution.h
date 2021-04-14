//
// Created by zhangbaqing on 2021/4/14.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <vector>
#include <unordered_set>

using std::string;

#if false

class Trie {
private:
    std::unordered_set<std::string> s;
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        s.insert(word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return s.find(word) != s.end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        for (const auto &word : s) {
            if (prefix.compare(word.substr(0, prefix.size())) == 0) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
#endif

#if true

// 前缀树
class Trie {
private:
    std::vector<Trie *> children;
    bool isEnd;

    Trie *searchPrefix(std::string word) {
        Trie *node = this;
        int index = 0;
        for (const auto &item : word) {
            index = item - 'a';
            if (node->children[index] == nullptr) {
                return nullptr;
            }
            node = node->children[index];
        }
        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false) {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        int index = 0;
        for (const auto &item : word) {
            index = item - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = searchPrefix(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
#endif

#if false
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
#endif

#endif //LEETCODE_SOLUTION_H
