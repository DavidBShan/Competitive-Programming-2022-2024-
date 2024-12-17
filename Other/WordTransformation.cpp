#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor] && dfs(neighbor, adj, visited, recStack)) {
            return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    map<string, int> wordToIndex;
    vector<string> words(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> words[i];
        wordToIndex[words[i]] = i;
    }

    vector<int> adj[2*n];
    for (int i = 0; i < n; i++) {
        adj[wordToIndex[words[2*i]]].push_back(wordToIndex[words[2*i+1]]);
    }

    vector<bool> visited(2*n, false), recStack(2*n, false);
    for (int i = 0; i < 2*n; i++) {
        if (!visited[i] && dfs(i, adj, visited, recStack)) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}