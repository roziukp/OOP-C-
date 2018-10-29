#pragma once
#include <string>
#include <vector>
using namespace std;

template <class T>
struct Node {
	int a;
	T value;
	vector<Node*> first;
	Node(int k, const T& c, int stage);
};

template <class T>
class SkipList
{
public:
	SkipList();
	~SkipList();

	void print();
	Node<T>* find(int valk);

	void input(int valk, T newValue);
	void crossout(int valk);
	void delete_list();
private:
	Node<T>* head;
	Node<T>* null;

	int randomLevel();
	int createNode(const vector<Node<T>*>& v);
	Node<T>* makenewNode(int k, T val, int stage);

	float chance;
	int maxLevel;
};

template <class T>
Node<T>::Node(int k, const T& v, int level)
	: a(k), value(v)
{
	for (int i = 0; i < level; ++i) first.emplace_back(nullptr);
}

// constructor
template <class T>
SkipList<T>::SkipList() : chance(0.5), maxLevel(16)
{
	int headk = numeric_limits<int>::min();
	head = new Node<T>(headk, 0, maxLevel);

	int nullk = numeric_limits<int>::max();
	null = new Node<T>(nullk, 0, maxLevel);

	for (size_t i = 0; i < head->first.size(); ++i)
		head->first[i] = null;
}
// destructor
template <class T>
SkipList<T>::~SkipList()
{
	delete head;
	delete null;
}

template <class T>
int SkipList<T>::randomLevel()
{
	int v = 1;
	while ((((double)std::rand() / RAND_MAX)) < chance && abs(v) < maxLevel)
		v += 1;
	return abs(v);
}

template <class T>
int SkipList<T>::createNode(const vector<Node<T>*>& v)
{
	int curStage = 1;
	int nilKey = numeric_limits<int>::max();

	if (v[0]->a == nilKey)
		return curStage;

	for (size_t i = 0; i < v.size(); ++i)
		if (v[i] != nullptr && v[i]->a != nilKey)
			++curStage;
		else
			break;

	return curStage;
}

template <class T>
Node<T>* SkipList<T>::find(int valk)
{
	Node<T>* x = head;
	int curMax = createNode(head->first);

	for (int i = curMax; i-- > 0;)
		while (x->first[i] != nullptr && x->first[i]->a < valk)
			x = x->first[i];
	x = x->first[0];

	if (x->a == valk)
		return x;
	else
		return nullptr;
}

template <class T>
void SkipList<T>::print()
{
	Node<T>* list = head;
	while (list->first[0] != null)
	{
		cout << list->first[0]->a << ") " << list->first[0]->value << endl;
		list = list->first[0];
	}
}

template <class T>
Node<T>* SkipList<T>::makenewNode(int key, T val, int level)
{
	return new Node<T>(key, val, level);
}

template <class T>
void SkipList<T>::delete_list()
{
	delete head;
	delete null;
	SkipList();
}

template <class T>
void SkipList<T>::input(int valk, T newValue)
{
	
	Node<T>* x = nullptr;
	x = find(valk);
	if (x)
	{
		x->value = newValue;
		return;
	}

	vector<Node<T>*> update(head->first);
	unsigned int currentMaximum = createNode(head->first);
	x = head;


	for (unsigned int i = currentMaximum; i-- > 0;)
	{
		while (x->first[i] != nullptr && x->first[i]->a < valk)
			x = x->first[i];
		update[i] = x;
	}
	x = x->first[0];

	
	int newNodeLevel = 1;
	if (x->a != valk)
	{
		newNodeLevel = randomLevel();
		int currentLevel = createNode(update);

		if (newNodeLevel > currentLevel)
			for (int i = currentLevel + 1; i < newNodeLevel; ++i)
				update[i] = head;
		x = makenewNode(valk, newValue, newNodeLevel);
	}

	
	for (int i = 0; i < newNodeLevel; ++i)
	{
		x->first[i] = update[i]->first[i];
		update[i]->first[i] = x;
	}
}

template <class T>
void SkipList<T>::crossout(int searchKey)
{
	vector<Node<T>*> update(head->first);
    Node<T>* x = head;
	unsigned int currentMaximum = createNode(head->first);

	for (unsigned int i = currentMaximum; i-- > 0;)
	{
		while (x->first[i] != nullptr && x->first[i]->a < searchKey)
			x = x->first[i];
		update[i] = x;
	}
	x = x->first[0];

	
	if (x->a == searchKey)
	{
		for (size_t i = 0; i < update.size(); ++i)
		{

			if (update[i]->first[i] != x)
				break;
			update[i]->first[i] = x->first[i];
		}
		delete x;
	}
}

