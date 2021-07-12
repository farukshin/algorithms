## Подсчитываем частоту встречаемости слов

```
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string filter_trim(const string &s)
{
    const char *forbidden {".,:; "};
    const auto indexStart (s.find_first_not_of(forbidden));
    const auto indexEnd (s.find_last_not_of(forbidden));
    return s.substr(indexStart, indexEnd - indexStart + 1);
}

int main() {
	
	map<string, size_t> words;
	int max_word_len {0};
	
	string s;
	while(cin>>s)
	{
	    auto filtered (filter_trim(s));
	    max_word_len = max<int>(max_word_len, filtered.length());
	    ++words[filtered];
	}
	
	vector<pair<string, size_t>> word_count;
	word_count.reserve(words.size());
	move(begin(words), end(words), back_inserter(word_count));
	
	sort(begin(word_count), end(word_count),
        [](const auto &a, const auto &b){
            return a.second > b.second;
	});
	
	for(const auto &[word, count] : word_count)
	    cout<< word<<" "<<count<<"\n";
	
	return 0;
}

```