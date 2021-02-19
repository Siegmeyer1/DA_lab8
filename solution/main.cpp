#include <iostream>
#include <vector>
#include <algorithm>
#include "interval.h"

bool comp1(interval &a, interval& b) {
    return a.finish > b.finish;
}

bool comp2(interval &a, interval& b) {
    return a.id < b.id;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long N;
    double L, R, M, cur = 0;
    std::cin >> N;
    std::vector<interval> intervals;
    std::vector<interval> answer;
    for (unsigned long i = 0; i < N; ++i) {
        std::cin >> L >> R;
        intervals.emplace_back(interval(L, R));
        intervals.back().id = i;
    }
    std::sort(intervals.begin(), intervals.end(), comp1);
    std::cin >> M;

    //long long exception = -1;
    while(true) {
        unsigned long i = 0;
        for (;i < intervals.size(); ++i) {
            //if (i == exception) continue;
            if ((intervals[i].start  <= cur) && (intervals[i].finish > cur)) {
                answer.push_back(intervals[i]);
                cur = intervals[i].finish;
                //if (cur == 0) exception = (long long)i;
                break;
            }
        }
        if ((i == intervals.size()) || cur >= M) break;
    }
    if (cur < M) {
        std::cout << 0 << '\n';
        return 0;
    }
    std::sort(answer.begin(), answer.end(), comp2);
    std::cout << answer.size() << '\n';
    for (auto & interval : answer) {
        std::cout << interval.start << ' ' << interval.finish << '\n';
    }

    return 0;
}