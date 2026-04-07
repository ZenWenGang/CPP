#define _CRT_SECURE_NO_WARNINGS 1
#include <unordered_set>
#include <set>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

const size_t N = 1000000; // 百万级数据
int test_performance() {
    vector<int> v;
    v.reserve(N);
    srand(time(0));
    // 生成随机数据，减少重复
    for (size_t i = 0; i < N; ++i) {
        v.push_back(rand() + i);
    }

    // 1. 插入性能对比
    size_t begin1 = clock();
    set<int> s;
    for (auto e : v) s.insert(e);
    size_t end1 = clock();
    cout << "set 插入耗时：" << end1 - begin1 << "ms" << endl;

    size_t begin2 = clock();
    unordered_set<int> us;
    us.reserve(N); // 预分配哈希桶空间，减少扩容
    for (auto e : v) us.insert(e);
    size_t end2 = clock();
    cout << "unordered_set 插入耗时：" << end2 - begin2 << "ms" << endl;

    // 2. 查找性能对比
    size_t begin3 = clock();
    int cnt1 = 0;
    for (auto e : v) {
        if (s.find(e) != s.end()) cnt1++;
    }
    size_t end3 = clock();
    cout << "set 查找耗时：" << end3 - begin3 << "ms" << endl;

    size_t begin4 = clock();
    int cnt2 = 0;
    for (auto e : v) {
        if (us.find(e) != us.end()) cnt2++;
    }
    size_t end4 = clock();
    cout << "unordered_set 查找耗时：" << end4 - begin4 << "ms" << endl;

    // 3. 删除性能对比
    size_t begin5 = clock();
    for (auto e : v) s.erase(e);
    size_t end5 = clock();
    cout << "set 删除耗时：" << end5 - begin5 << "ms" << endl;

    size_t begin6 = clock();
    for (auto e : v) us.erase(e);
    size_t end6 = clock();
    cout << "unordered_set 删除耗时：" << end6 - begin6 << "ms" << endl;

    return 0;
}

int main() {
    test_performance();
    return 0;
}