## pq-лошадь

```

int bfs(pair<int, int> start, pair<int, int> finish, const int & m, const int & n, const int & p, const int & q, map<pair<int, int>, pair<int, int>> &chield)
{
	struct step
	{
	    int x;
	    int y;
	    int d;
	};

    queue<step> que;
    que.push({start.first, start.second, 0});

    pair<int, int> run[8] = {{p, -q}, {p, q}, {-p, -q}, {-p, q}, {q, p}, {q, -p}, {-q, p}, {-q, -p}};
    int MAXARR = max(m,n)+1;
    bool used[MAXARR][MAXARR] = {false};

    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        if (cur.x == finish.first && cur.y == finish.second)
        {
        	//chield[{finish.first, finish.second}]= {cur.x, cur.y};
        	return cur.d;
        }

        for (auto r : run)
            if (cur.x + r.first <= m && cur.x + r.first >= 1 && cur.y + r.second <= n && cur.y + r.second >= 1 && !used[cur.x + r.first][cur.y + r.second])
            {
                used[cur.x + r.first][cur.y + r.second] = true;
                que.push({cur.x + r.first, cur.y + r.second, cur.d + 1});
                chield[{cur.x + r.first, cur.y + r.second}]= {cur.x, cur.y};
            }
    }

    return -1;
}

void pq_horse(const int & m, const int & n, const int & p, const int & q, pair<int, int> & start, pair<int, int> &finish, int &ans, stack<pair<int, int>> &st)
{
	map<pair<int, int>, pair<int, int>> chield;
	ans = bfs(start, finish, m, n, p, q, chield);

	if(ans == -1)
    	{while(!st.empty()) st.pop(); return;}

    st.push(finish);
    pair<int, int> cur = finish;
    while(cur != start)
    {
    	cur = chield[{cur.first, cur.second}];
    	st.push({cur.first, cur.second});
    }
}

```
