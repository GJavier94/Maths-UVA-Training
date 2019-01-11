#include <bits/stdc++.h>

using namespace std;

#define inf 1 << 30
struct Node{
     int id, length;
     Node(int a, int b):id(a), length(b){}
     bool operator <(const Node& b) const{
           return length > b.length;
     }
};
vector<vector<Node> > adj;
vector<int> visit;
vector<int> dis;
vector<int> ans;
void init(int n)
{
     adj.assign(n, vector<Node>());
     visit.assign(n, 0);
     dis.assign(n, inf);
     ans.clear();
     ans.push_back(1);
}
void link(int a, int b, int l)
{
     adj[a].push_back(Node(b, l));
     adj[b].push_back(Node(a, l));
}
void bfs()
{
     priority_queue<Node> que;
     que.push(Node(1, 0)); // start from node 1
     int curDis = 0;
     dis[1] = 0;
     while (que.size())
     {
           int cur = que.top().id;
           que.pop();
           visit[cur] = 1;
           for (int i = 0; i < adj[cur].size(); i++)
           {
                Node tmp = adj[cur][i];
                dis[tmp.id] = min(dis[tmp.id], dis[cur] + tmp.length);
                if (!visit[tmp.id])
                {
                     que.push(Node(tmp.id, dis[tmp.id]));
                }
           }
     }
}
void checkTheLast(double &maxi)
{
     for (int i = 1; i < adj.size(); i++)
     {
           for (int j = 0; j < adj[i].size(); j++)
           {
                int connect = adj[i][j].id;
                double tmp = (dis[i] + dis[connect] + adj[i][j].length) / 2.;
                if (tmp > maxi)
                {
                     maxi = tmp;
                     if (tmp == dis[i] or tmp == dis[connect])
                     {
                           ans.clear();
                           ans.push_back(tmp == dis[i] ? i : connect);
                     }
                     else
                     {
                           ans.clear();
                           ans.push_back(i);
                           ans.push_back(connect);
                     }
                }
           }

     }
}
int main()
{
     int nodeN, edgeN;
     int testCase = 1;
     while (cin >> nodeN >> edgeN and nodeN + edgeN){
           init(nodeN + 1);
           for (int i = 0; i < edgeN; i++)
           {
                int node1, node2, len;
                cin >> node1 >> node2 >> len;
                link(node1, node2, len);
           }
           bfs();
           double maxi = 0;
           checkTheLast(maxi);

           cout << "System #" << testCase++ << endl;
           cout << fixed << setprecision(1);
           if (ans.size() < 2)
           {
                cout << "The last domino falls after " << maxi
                           << " seconds, at key domino " << ans[0] << "." << endl;
           }
           else
           {
                cout << "The last domino falls after " << maxi
                           << " seconds, between key dominoes " << ans[0] << " and "
                           << ans[1] << "." << endl;
           }
           cout << endl;
     }
     return 0;
}