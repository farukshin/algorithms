## Стек для нахождения минимума за O(1)

```
struct stack_min{
	stack<pair<int,int>> st;

	int minimum()
	{
		int minima = st.size()>0 ? st.top().second : 0;
		return minima;
	};

	void push(int new_element)
	{
		int minima = st.empty() ? new_element : min (new_element, st.top().second);
		st.push (make_pair (new_element, minima));
	};

	void pop()
	{
		if(st.size()>0)
		{
			int result = st.top().first;
			st.pop();
		}
	};

	int top()
	{
		int result = st.top().first;
		return result;
	};

	int size()
	{
		int result = st.size();
		return result;
	};
};

```
