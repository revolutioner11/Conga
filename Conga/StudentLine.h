#pragma once

#include <string>
#include <iostream>

using namespace std;

class StudentLine
{
public:
	struct Node
	{
	public:
		string Name;
		string Uni;
		Node* pPrev;
		Node* pNext;

		Node(const string& Name, const string& Uni, Node* pPrev = nullptr, Node* pNext = nullptr)
			: Name(Name), Uni(Uni), pPrev(pPrev), pNext(pNext)
		{
		}
		void Free()
		{
			Name.clear();
			Uni.clear();
			pPrev = nullptr;
			pNext = nullptr;
		}
	};

public:
	StudentLine();
	StudentLine(const StudentLine & Other);
	StudentLine& operator=(const StudentLine& Other);
	~StudentLine();

	bool operator==(const StudentLine& Other) const;
	bool operator!=(const StudentLine& Other) const;

public:
	bool Merge(const StudentLine& Other);							// MERGE
	void AddEnd(const string& Name, const string& Uni);				// APPEND
	void RemoveFirst();												// REMOVE FIRST
	void RemoveLast();												// REMOVE LAST
	StudentLine Remove(const string& Name);							// REMOVE
	void Print() const;
	bool isEmpty() const;
	void Free();

private:
	bool isCompatable(const string& FrontUni, const string& BachUni) const;
	void AddAfter(const string& Name, const string& Uni);
	void CreateFirstNode(const string& Name, const string& Uni);

private:
	Node* pFirst;
	Node* pLast;
	size_t Length;
};

