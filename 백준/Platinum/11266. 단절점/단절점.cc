#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX_SIZE 100001
using namespace std;

int back[MAX_SIZE], dfn[MAX_SIZE], c_num, child[MAX_SIZE];
vector<int> ap_nodes;
stack<int> st;
int bcc_count;

void BicompDfs(int u, int parent, vector<vector<int>> &graph)
{
  dfn[u] = back[u] = ++c_num;
  st.push(u);
  int children = 0;

  for (int i = 0; i < graph[u].size(); i++)
  {
    int v = graph[u][i];
    if (v == parent)
      continue; // 부모 노드는 건너뛰기

    if (dfn[v] == 0)
    { // 아직 방문하지 않은 노드
      children++;
      BicompDfs(v, u, graph);
      back[u] = min(back[u], back[v]);

      if ((parent != -1 && back[v] >= dfn[u]) || (parent == -1 && children > 1))
      {
        // 단절점 찾기
        // u가 ap_nodes에 없으면 push_back하기
        if (find(ap_nodes.begin(), ap_nodes.end(), u) == ap_nodes.end())
          ap_nodes.push_back(u);
        while (st.top() != v)
        {
          st.pop();
        }
        st.pop();
        bcc_count++;
      }
    }
    else
    {
      back[u] = min(back[u], dfn[v]);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int v, e;
  cin >> v >> e;

  vector<vector<int>> graph(MAX_SIZE);
  for (int j = 0; j < e; j++)
  {
    int src, dst;
    cin >> src >> dst;

    graph[src].push_back(dst);
    graph[dst].push_back(src); // 양방향 추가
  }

  memset(dfn, 0, sizeof(dfn));
  memset(back, 0, sizeof(back));
  ap_nodes.clear();
  c_num = 0;
  bcc_count = 0;

  for (int i = 1; i <= e; i++)
  {
    if (dfn[i] == 0)
    {
      BicompDfs(i, -1, graph);
      if (!st.empty())
      {
        bcc_count++;
        while (!st.empty())
          st.pop();
      }
    }
  }

  sort(ap_nodes.begin(), ap_nodes.end());
  cout << ap_nodes.size() << " ";
  cout << '\n';
  for (int i : ap_nodes)
  {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
