#pragma once

#include "RBTree.hpp"

namespace my_set
{
	template<class K>

	class set
	{
		struct SetketOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	public:
		typedef typename RBTree<K, K, SetketOfT>::iterator iterator;
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return  _t.end();
		}

		std::pair<iterator, bool> Insert(const K& k)
		{
			return _t.Insert(k);
		}

	private:
		RBTree<K, K, SetketOfT> _t;
	};
	using namespace std;
	void test_set()
	{
		set<int> s;
		s.Insert(3);
		s.Insert(4);
		s.Insert(1);
		s.Insert(2);
		s.Insert(5);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}