## Алгоритм Дейкстры

Алгоритм для нахождения кратчайшего расстояния от одной из вершин графа до всех остальных. Алгоритм работает только для графов без рёбер отрицательного веса.

```

void dejkstra(const vector<vector<pair<int, int>>>& ss, const int& countNode, const int& start, vector<ll>& dist) {

    dist.resize(countNode, LONG_LONG_MAX);
    dist[0] = 0;

    priority_queue< pair<ll, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        auto u = q.top();
        q.pop();
        int cur = u.second;
        if (-u.first > dist[cur])
            continue;

        for (auto chield : ss[cur])
        {
            int to = chield.first, len = chield.second;
            if (dist[to] > dist[cur] + len)
            {
                dist[to] = dist[cur] + len;
                q.push(make_pair(-dist[to], to));
            }
        }
    }
}

```
