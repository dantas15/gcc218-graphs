#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct TreeNode
{
  string name;
  unsigned id;
  TreeNode *leftChild;
  TreeNode *rightChild;
};

#define TRUE 1
#define FALSE 0
#define MAX_NODES 310

char visited[MAX_NODES];
int adjacency[MAX_NODES][MAX_NODES];

void depthFirstSearch(const unsigned);
TreeNode *insert(TreeNode *, const string &);
int findId(TreeNode *, const string &);

unsigned nodeCounter;
unsigned numNodes, numEdges;

int main(int argc, char **argv)
{

  int u, v, i, j;
  TreeNode *tree = nullptr;
  string name1, name2, connection;

  cin >> numNodes >> numEdges;
  int tmp = numEdges;
  while (tmp--)
  {

    cin >> name1 >> connection >> name2;
    tree = insert(tree, name1);
    tree = insert(tree, name2);

    u = findId(tree, name1);
    v = findId(tree, name2);

    adjacency[u][v] = adjacency[v][u] = 1;
  }

  int ans = 0;

  for (i = 1; i <= numNodes; ++i)
    if (!visited[i])
      ans++, depthFirstSearch(i);

  cout << ans << endl;

  return 0;
}

void depthFirstSearch(const unsigned vertex)
{

  unsigned i;
  visited[vertex] = TRUE;
  for (i = 1; i <= numNodes; ++i)
    if (adjacency[vertex][i])
      if (!visited[i])
        depthFirstSearch(i);
}

TreeNode *insert(TreeNode *root, const string &str)
{

  if (!root)
  {

    root = new TreeNode;
    root->leftChild = root->rightChild = nullptr;
    root->name = str;
    root->id = ++nodeCounter;
  }
  else if (root->name > str)
    root->leftChild = insert(root->leftChild, str);
  else if (root->name < str)
    root->rightChild = insert(root->rightChild, str);

  return root;
}

int findId(TreeNode *root, const string &str)
{

  if (!root)
    return -1;

  if (root->name > str)
    return findId(root->leftChild, str);
  else if (root->name < str)
    return findId(root->rightChild, str);
  else
    return root->id;
}
