#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct s_list {
	int count;
	list<int> t_list;
};

struct s_object {
	int count;
	list<int>::iterator y;
	list<s_list>::iterator x;
};

class counter {
private:
	vector<s_object> m_vector;
	list<s_list> m_list;
	list<s_list>::iterator zero;
public:
	counter(int n) {
		list<int> init;
		for (int i = 0; i < n; ++i) {
		    init.push_back(i);
		}
		s_list a;
		a.count = 0;
		a.t_list = init;
		m_list.push_back(a);
		list<s_list>::iterator first_list = m_list.begin();
		zero = m_list.begin();
		list<int>::iterator inner_list = m_list.begin()->t_list.begin();
		s_object b;
		b.count = 0;
		b.x = first_list;
		for (int i = 0; i < n; ++i) {
			b.y = inner_list;
			m_vector.push_back(b);
			inner_list++;
		}
		return;
	}

	void increment(int i) {
		m_vector[i].count++;
		list<int>::iterator y = m_vector[i].y;
		list<s_list>::iterator x = m_vector[i].x;
		list<s_list>::iterator z = x;
		if(++z == m_list.end()) {
			if (x != m_vector[i].x)
				x = m_vector[i].x;
			s_list a;
			a.count = m_vector[i].count;
			a.t_list.push_back(i);
			m_list.push_back(a);
			m_vector[i].x = (--(m_list.end()));
			m_vector[i].y = (--(m_list.end()))->t_list.begin();
			(*(x)).t_list.erase(y);
			if((*(x)).t_list.empty() && (*(x)).count != 0) {
				m_list.erase(x);
			}
		}
		else if((*(++x)).count != m_vector[i].count) {
			if (x != m_vector[i].x)
				x = m_vector[i].x;
			s_list a;
			a.count = m_vector[i].count;
			a.t_list.push_back(i);
			x++;
			m_vector[i].x = m_list.insert(x, a);
			m_vector[i].y = (--x)->t_list.begin();
			x--;
			(*(x)).t_list.erase(y);
			if((*(x)).t_list.empty() && (*(x)).count != 0) {
				m_list.erase(x);
			}
		}
		else {
			if (x != m_vector[i].x)
				x = m_vector[i].x;
			(*(x)).t_list.erase(y);
			(*(++x)).t_list.push_back(i);
			m_vector[i].y = (--(*(x)).t_list.end());
			m_vector[i].x = x;
			if((*(--x)).t_list.empty() && (*(x)).count != 0) {
				m_list.erase(x);
			}
		}
		return;
	}

	void decrement(int i) {
		m_vector[i].count--;
		list<int>::iterator y = m_vector[i].y;
		list<s_list>::iterator x = m_vector[i].x;
		if(x == m_list.begin()) {
			if (x != m_vector[i].x)
				x = m_vector[i].x;
			s_list a;
			a.count = m_vector[i].count;
			a.t_list.push_back(i);
			m_vector[i].x = m_list.insert(x, a);
			m_vector[i].y = m_list.begin()->t_list.begin();
			(*(x)).t_list.erase(y);
			if((*(x)).t_list.empty() && (*(x)).count != 0) {
				m_list.erase(x);
			}
		}
		else if ((*(--x)).count != m_vector[i].count){
			if (x != m_vector[i].x)
				x = m_vector[i].x;
			s_list a;
			a.count = m_vector[i].count;
			a.t_list.push_back(i);
			m_vector[i].x = m_list.insert(x, a);
			m_vector[i].y = m_vector[i].x->t_list.begin();
			(*(x)).t_list.erase(y);
			if((*(x)).t_list.empty() && (*(x)).count != 0) {
				m_list.erase(x);
			}
		}
		else {
			if (x != m_vector[i].x)
				x = m_vector[i].x;
			(*(x)).t_list.erase(y);
			(*(--x)).t_list.push_back(i);

			m_vector[i].y = --((*(x)).t_list.end());
			m_vector[i].x = x;
			list<s_list>::iterator hl = x;

			if((*(++x)).t_list.empty() && (*(x)).count != 0) {
				m_list.erase(x);
			}
		}
		return;
	}

	void reset(int i) {
		if (m_vector[i].count == 0)
			return;
		m_vector[i].count = 0;
		m_vector[i].x->t_list.erase(m_vector[i].y);
		zero->t_list.push_back(i);
		if (m_vector[i].x->t_list.empty() && (*m_vector[i].x).count != 0) {
			m_list.erase(m_vector[i].x);
		}
		m_vector[i].x = zero;
		m_vector[i].y = (--(zero->t_list).end());
		return;
	}

	int count(int i) {
		return m_vector[i].count;
	}

	int findMax() {
		list<s_list>::iterator it = (--m_list.end());
		if (it->t_list.empty())
			it--;
		return (it)->count;
	}

	int numMax() {
		list<s_list>::iterator it = (--m_list.end());
		if (it->t_list.empty())
			it--;
		return (it)->t_list.size();
	}

	void printMax()	{
		list<s_list>::iterator i = (--m_list.end());
		if (i->t_list.empty())
			i--;
		for (list<int>::iterator it = (i)->t_list.begin();
			it != (i)->t_list.end(); ++it) {
			cout << *it << endl;
		}
     	return;
	}
};
