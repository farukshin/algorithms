# RobotPath
```
class RoboPath{
public:
	int n=0,m=0;

	map<char, vector<char>> nextStepsMap={
		{'R', {'R', 'D' }},
		{'L', {'L', 'U' }},
		{'U', {'U', 'R' }},
		{'D', {'D', 'L' }},
		{'$', {'D', 'L', 'U', 'R'}}
	};

	map<char, pair<int, int>> mp={
		{'R', {0, 1 }},
		{'L', {0, -1}},
		{'D', {1, 0 }},
		{'U', {-1, 0}}
	};

	vector<pair<int, int>> run = {
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0}
	};
	vector<char> steps = {'L', 'R', 'D', 'U'};


	vector<vector<char>> v;
	vector<vector<int>> used;

	pair<int,int> start = {-5, -5};
	pair<int,int> finish = {-5, -5};

	set<pair<char, char>> trueStep;

	void init();
	void loadMap();
	void bfs(pair<int,int> node);
	bool checkNextStep(pair<int,int> next, pair<int,int> node, char cmd, char lastCmd);
	void initTrueStep();

};

bool RoboPath::checkNextStep(pair<int,int> next, pair<int,int> node, char cmd, char lastCmd)
{
	bool inTable = (next.first >= 0 && next.first < n && next.second >= 0 && next.second < m);
	if(!inTable)
		return false;

	bool isStep = !used[next.first][next.second] && (v[next.first][next.second] == 'D' || v[next.first][next.second] == '.');

	return isStep;
}

void RoboPath::bfs(pair<int, int> node)
{
	queue<tuple<pair<int,int> , int, string>> q;
	q.push({node, 0, ""});
	used[node.first][node.second] = true;

	pair<int, int> dot;
	int len;
	string command="";

	while(!q.empty())
	{
		auto cur = q.front();
		q.pop();

		tie(dot, len, command) = cur;
		if(dot == finish)
			{cout<< command; return;}

		char lastCmd = (command==""? '$' : command[command.length()-1]);


		for(auto cmd : nextStepsMap[lastCmd])
		{
			pair<int,int> next = {dot.first + mp[cmd].first, dot.second + mp[cmd].second};
			if(checkNextStep(next, node, cmd, lastCmd) && !used[next.first][next.second])
			{
				used[next.first][next.second] = true;
				q.push({next, len+1, command+cmd});
			}
		}
	}
	cout<< "NO SOLUTION";
}

void RoboPath::init()
{
	v.resize(n, vector<char> (m, '.'));
	used.resize(n, vector<int>(m, false));
}

void RoboPath::initTrueStep()
{
	trueStep.insert({ 'L' , 'U' });
	trueStep.insert({ 'R' , 'D' });
	trueStep.insert({ 'U' , 'R' });
	trueStep.insert({ 'D' , 'L' });

	trueStep.insert({ 'L' , 'L' });
	trueStep.insert({ 'R' , 'R' });
	trueStep.insert({ 'U' , 'U' });
	trueStep.insert({ 'D' , 'D' });
}

void RoboPath::loadMap()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>v[i][j];
			if(v[i][j] == 'S')
				start = {i,j};
			else if(v[i][j] == 'D')
				finish = {i,j};
			else if(v[i][j] == '*')
				used[i][j] = true;
		}
}
```
