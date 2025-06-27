#include <bits/stdc++.h>
using namespace std;

class disjointSet {
    vector<int> parent;
   
public:
vector<vector<int>> members;
    vector<int> fallTime; 
    disjointSet(int V) {
        parent.resize(V + 1, 0);
        members.resize(V + 1);
        fallTime.resize(V + 1, -1);
        for (int i = 1; i <= V; i++) {
            parent[i] = i;
            members[i].push_back(i);
        }
    }

    int findUpar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }

    void unionBySize(int u, int v, int time) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v) return; 

        if (members[ulp_u].size() < members[ulp_v].size()) swap(ulp_u, ulp_v);

        if (findUpar(1) == ulp_u) {
            for (auto it : members[ulp_v]) {
                fallTime[it] = time;
            }
        }
        if (findUpar(1) == ulp_v) {
            for (auto it : members[ulp_u]) {
                fallTime[it] = time;
            }
        }

        for (auto monkey : members[ulp_v]) {
            members[ulp_u].push_back(monkey);
        }
        members[ulp_v].clear();
        parent[ulp_v] = ulp_u;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> hands(n + 1, vector<int>(2, -1));
    for (int i = 1; i <= n; i++) {
        cin >> hands[i][0] >> hands[i][1];
    }

    vector<pair<int,int>> deleted_edges;
    map<pair<int,int>, int> edge;
    for (int i = 1; i <= n; i++) {
        if (hands[i][0] != -1)
            edge[{min(i, hands[i][0]), max(i, hands[i][0])}]++;
        if (hands[i][1] != -1)
            edge[{min(i, hands[i][1]), max(i, hands[i][1])}]++;
    }
    for (int i = 0; i < m; i++) {
        int monkey, hand;
        cin >> monkey >> hand;
        int toMonkey = hands[monkey][hand-1];
        if (toMonkey == -1) continue; 
        edge[{min(monkey, toMonkey), max(monkey, toMonkey)}]--;
        deleted_edges.push_back({monkey, toMonkey});
    }
    disjointSet ds(n + 1);

    for (auto it = edge.begin(); it != edge.end(); ++it) {
        if (it->second > 0) {
            int u = it->first.first;
            int v = it->first.second;
            ds.unionBySize(u, v, -1); 
        }
    }

    for (int i = m - 1; i >= 0; --i) {
        int u = deleted_edges[i].first;
        int v = deleted_edges[i].second;
        ds.unionBySize(u, v, i);
    }

    for (int i = 1; i <= n; ++i) {
        cout << ds.fallTime[i] << "\n";
    }
    return 0;
}
