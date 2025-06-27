#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int numEdges, V, numWeights;
        cin >> V >> numEdges >> numWeights;
        
        int minOdd = INT_MAX;
        vector<int> evens, odds;
        
        for (int i = 0; i < numWeights; i++) {
            int w;
            cin >> w;
            if (w % 2 == 0) {
                evens.push_back(w);
            } else {
                minOdd = min(minOdd, w);
                odds.push_back(w);
            }
        }

        long long totalOddSum = accumulate(odds.begin(), odds.end(), 0LL);
        long long totalEvenSum = accumulate(evens.begin(), evens.end(), 0LL);

        vector<int> graph[V + 1];
        for (int i = 0; i < numEdges; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<pair<int, int>> q1;
        q1.push({1, 0});
        vector<vector<int>> dist(V + 1, vector<int>(2, -1));
        dist[1][0] = 0;

        while (!q1.empty()) {
            int levelSize = q1.size();
            for (int i = 0; i < levelSize; i++) {
                auto [currNode, currDist] = q1.front();
                q1.pop();

                bool nextEven = ((currDist + 1) % 2 == 0);
                for (auto adjNode : graph[currNode]) {
                    if (nextEven && dist[adjNode][0] == -1) {
                        q1.push({adjNode, currDist + 1});
                        dist[adjNode][0] = currDist + 1;
                    }
                    if (!nextEven && dist[adjNode][1] == -1) {
                        q1.push({adjNode, currDist + 1});
                        dist[adjNode][1] = currDist + 1;
                    }
                }
            }
        }

        for (int i = 1; i <= V; i++) {
            int p = 0;
            if (odds.size() % 2 == 0) {
                if (dist[i][0] != -1 && dist[i][0] <= totalEvenSum + totalOddSum) {
                    p = 1;
                }
                if (!odds.empty() && dist[i][1] != -1 && dist[i][1] <= totalEvenSum + totalOddSum - minOdd) {
                    p = 1;
                }
            } else {
                if (dist[i][0] != -1 && dist[i][0] <= totalEvenSum + totalOddSum - minOdd) {
                    p = 1;
                }
                if (dist[i][1] != -1 && dist[i][1] <= totalEvenSum + totalOddSum) {
                    p = 1;
                }
            }
            cout << p;
        }
        cout << endl;
    }

    return 0;
}
