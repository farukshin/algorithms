## Медиана онлайн

```
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;

int n,first=0,i=0;

while(cin>>n)
{
    i++;
	if(i==1)
	{
		first=n;
		printf("%d\n",n);
		continue;
	}
	else if(i==2)
	{
		minq.push(max(first, n));
		maxq.push(min(first, n));
	}
	else if (n < maxq.top())
		maxq.push(n);
	else 
		minq.push(n);
		
	if(maxq.size() > minq.size() +1 )
    {
		auto cur = maxq.top();
		maxq.pop();
		minq.push(cur);
	}
	else if(minq.size() > maxq.size() + 1)
	{
		auto cur = minq.top();
		minq.pop();
		maxq.push(cur);
	}
		
	int med;
	if(maxq.size() == minq.size())
		med = (maxq.top() + minq.top())/2;
	else if(maxq.size() > minq.size()) 
		med = maxq.top();
	else if(minq.size() > maxq.size()) 
		med = minq.top();
	printf("%d\n",med);
}
```