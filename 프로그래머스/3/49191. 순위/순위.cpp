#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    std::unordered_map<int, std::vector<int>> win, defeat;
    for (const auto& ele : results)
    {
        win[ele[0]].push_back(ele[1]);
        defeat[ele[1]].push_back(ele[0]);
    }

    std::vector<std::unordered_set<int>> counts(n + 1);
    std::function<void(int, int, std::unordered_map<int, std::vector<int>>&)> dfs = [&](int target, int num, std::unordered_map<int, std::vector<int>>& graph) {

        if (target != num)
        {
            if (counts[target].end() != counts[target].find(num))
            {
                return;
            }
            counts[target].insert(num);
        }

        for (const auto& ele : graph[target])
        {
            dfs(ele, num, graph);
        }
    };

    for (int i = 1; i <= n; ++i)
    {
        dfs(i, i, win);
        dfs(i, i, defeat);
    }

    for (int i = 1; i < counts.size(); ++i)
    {
        if (counts[i].size() == n - 1)
        {
            answer++;
        }
    }

    return answer;
}