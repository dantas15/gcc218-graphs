#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main() {
  int
    peopleInCommunity, // n
    friendShipEdges, // m
    minFriendsToBeInvited; // k

  cin >> peopleInCommunity >> friendShipEdges >> minFriendsToBeInvited;

  // while (!cin.eof()) { /* In case of reading an input as a file */
  while (cin) {
    // considering the vertices start with 1 to n (total amount of people in the community)
    vector<int>* adjList = new vector<int>[peopleInCommunity+1];
    int* degree =  new int[peopleInCommunity+1];

    // initializing the degree
    for(int i = 1; i <= peopleInCommunity; i++) {
      degree[i] = 0;
    }

    int u, v;

    for (int i = 0; i < friendShipEdges; i++) {
      cin >> u >> v; // reading all edges (u <-> v)

      // avoiding repeated vertices and updating their degree (or valency)
      if (find(adjList[u].begin(), adjList[u].end(), v) != adjList[u].end())
        continue;

      // in the case of undirected graphs
      adjList[u].push_back(v); // u -> v
      adjList[v].push_back(u); // v -> u

      degree[u]++;
      degree[v]++;
    }

    // PQ with everyone with less than K friends
    priority_queue<pair<int, int>> PQ;
    for (int i = 1; i <= peopleInCommunity; i++) {
      if (degree[i] < minFriendsToBeInvited) {
        PQ.push({ degree[i], i });
      }
    }

    while (!PQ.empty()) {
      // element <first, second>
      int aux = PQ.top().second;
      PQ.pop();

      for (auto it = adjList[aux].begin(); it != adjList[aux].end(); it++) {
        if (--degree[*it] == minFriendsToBeInvited-1) {
          PQ.push({ degree[*it], *it });
        }
      }
    }

    // Output
    bool first = true;
    for (int i = 1; i <= peopleInCommunity; i++) {
      if (degree[i] >= minFriendsToBeInvited) {
        if (!first) {
          cout << " ";
        }
        cout << i;
        first = false;
      }
    }

    if (first) {
      cout << 0;
    }

    cout << endl;

    cin
      >> peopleInCommunity // n
      >> friendShipEdges // m
      >> minFriendsToBeInvited; // k
  }
  return 0;
}