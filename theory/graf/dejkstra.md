## Алгоритм Дейкстры

Алгоритм для нахождения кратчайшего расстояния от одной из вершин графа до всех остальных. Алгоритм работает только для графов без рёбер отрицательного веса.

```

void dejkstra(const vector<vector<pair<int, ll>>>& ss, const int& countNode, const int& start, vector<ll>& dist, vector<int>& parrent) {

    dist.resize(countNode);
    fill(dist.begin(), dist.end(), LLONG_MAX);
    dist[start] = 0;

    parrent.resize(countNode);
    fill(parrent.begin(), parrent.end(), -1);
    parrent[start] = -1;

    priority_queue< pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > q;
    //priority_queue< pair<ll, int> > q;
    q.push({ 0, start });

    while (!q.empty())
    {

        auto u = q.top();
        q.pop();
        int curNode = u.second;
        ll curLen = u.first;
        if (curLen > dist[curNode])
            continue;

        for (auto chield : ss[curNode])
        {
            int to = chield.first, len = chield.second;
            if (dist[to] > dist[curNode] + len)
            {
                dist[to] = dist[curNode] + len;
                q.push({ dist[to], to });
                parrent[to] = curNode;
            }
        }
    }
}

```
