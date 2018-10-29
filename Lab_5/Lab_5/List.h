#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#define MaxLev 2
using namespace std;

template <class T>
struct Node
{
	T a;
	Node **x;
	Node(T &a, int stage);
	~Node();
};

template <class T>
class SkipList
{
private: 
	Node<T>*first;
	T a;
	int stage;
public:
	SkipList();
	int Check();
	bool Number_elements(T &value);
	void AddElement(T &value);
	void Delete(T &value);
	void DeleteSkipList();
	void Print();
	~SkipList();
};

template <class T>
Node<T>::Node(T &a,int stage)
{
	x = new Node <T> *[stage + 1];
	memset(x, 0, sizeof(Node*)*(stage + 1));
	this->a = a;
}

template <class T>
Node<T>::~Node()
{
	delete[]x;
}

template <class T>
int SkipList<T>::Check()
{
	return stage;
}

template <class T>
SkipList<T>::SkipList()
{
	first = new Node<T>(a,MaxLev);
	stage = 0;
}

template <class T>
SkipList<T>::~SkipList()
{
	delete first;
}

template <class T>
bool SkipList<T>::Number_elements( T &value)
{
	Node <T>*h = first;
	for (int i = stage; i >= 0; i--)
	{
		while (h->x[i] != NULL && h->x[i]->a < value)
			h = h->x[i];
	}
	h = h->x[0];
	return h != NULL && h->a == value;
}

template <class T>
void SkipList<T>::Print()
{
	if (SkipList::Check() == 0)
		cout << "\nThe List is Empty!\n";
	else
	{
		Node<T> *h = first->x[0];
		while (h != NULL)
		{
			cout << h->a;
			h = h->x[0];
			if (h != NULL)
				cout << ";";
		}
		cout << endl;
	}
}

template <class T>
void SkipList<T>::Delete(T &value)
{
		Node<T>*h = first;
		Node<T>*z[MaxLev + 1];
		memset(z, NULL, sizeof(Node<T>*) * (MaxLev + 1));
		for (int i = stage; i >= 0; i--)
		{
			while (h->x[i] != NULL && h->x[i]->a < value)
				h = h->x[i];
			z[i] = h;
		}
		h = h->x[0];
		if (h->a == value)
		{
			for (int i = 0; i <= stage; i++)
			{
				if (z[i]->x[i] != h)
					break;
				z[i]->x[i] = h->x[i];
			}
			delete h;
			while (stage > 0 && first->x[stage] == NULL)
			{
				stage--;
			}
		}
}

template <class T>
void SkipList<T>::AddElement(T &value)
{
		Node<T> *h = first;
		Node<T> *z[MaxLev + 1];
		memset(z, NULL, sizeof(Node<T>*) * (MaxLev + 1));
		for (int i = stage; i >= 0; i--)
		{
			while (h->x[i] != NULL && h->x[i]->a < value)
			{
				h = h->x[i];
			}
			z[i] = h;
		}
		h = h->x[0];
		if (h == NULL || h->a != value)
		{
			int lvl = random();
			if (lvl > stage)
			{
				for (int i = stage + 1; i <= lvl; i++)
				{
					z[i] = first;
				}
				stage = lvl;
			}
			h = new Node<T>(value, lvl);
			for (int i = 0; i <= lvl; i++)
			{
				h->x[i] = z[i]->x[i];
				z[i]->x[i] = h;
			}
		}
	
}

float frand()
{
	return (float)rand() / RAND_MAX;
}
int random()
{
	static bool first = true;
	if (first)
	{
		srand((unsigned)time(NULL));
		first = false;
	}
	int lvl = (int)(log(frand()) / log(1. - 0.5));
	return lvl < MaxLev ? lvl : MaxLev;
}

template <class T>
void SkipList<T>::DeleteSkipList()
{
	if (SkipList::Check() == 0)
		cout << "\nThe List is Empty!\n";
	else
	{
		delete first;
		first = new Node<T>(a, MaxLev);
		stage = 0;
	}
}