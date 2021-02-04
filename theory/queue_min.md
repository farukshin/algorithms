## Очередь для нахождения минимума за O(1)

```
stack< pair<int,int> > s1, s2;

int min_queue_getMin()
{
	if (s1.empty() && s2.empty())
		return 0;
	else if (s1.empty() || s2.empty())
		return s1.empty() ? s2.top().second : s1.top().second;
	else
		return min(s1.top().second, s2.top().second);
}

void min_queue_pop()
{
	if (s2.empty())
		while (!s1.empty()) {
			int element = s1.top().first;
			s1.pop();
			int minima = s2.empty() ? element : min (element, s2.top().second);
			s2.push (make_pair (element, minima));
		}
	if(!s2.empty())
		s2.pop();
}

void min_queue_add(int new_element)
{
	int minima = s1.empty() ? new_element : min (new_element, s1.top().second);
	s1.push ({new_element, minima});
}
```
