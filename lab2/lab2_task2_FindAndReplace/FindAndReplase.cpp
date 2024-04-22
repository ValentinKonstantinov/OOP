
#include "FindAndReplase.h"
//стандартным алгоритмом!!!!!!
std::string FindAndReplace(std::string const& subject, std::string const& search, std::string const& replace)
{
	if (subject.size() == 0 || search.size() == 0)
	{
		return subject;
	}
	//сделать один search и 2 append
	std::boyer_moore_searcher searcher(search.begin(), search.end());
	std::string result;
	auto foundIt = subject.begin();
	auto it = subject.begin();
	do
	{
		it = std::search(foundIt, subject.end(), searcher);
		if (subject.end() >= it + search.length())
		{
			result.append(foundIt, it);
			result.append(replace);
			foundIt = it + search.length();
		}
	} while (it != subject.end());
	result.append(foundIt, subject.end());
	return result;
}
