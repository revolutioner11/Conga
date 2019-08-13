#pragma once

#include <string>

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
	};

public:
	StudentLine();
	StudentLine(const StudentLine & Other);
	StudentLine& operator=(const StudentLine& Other);
	~StudentLine();

	bool operator==(const StudentLine& Other) const;
	bool operator!=(const StudentLine& Other) const;
	void Merge(const StudentLine& Other);
	void AddEnd(const string& Name, const string& Uni);				// This will be our APPEND
	void RemoveFirst();
	void RemoveLast();
	void Remove(const string& Name, const string& Uni);
private:
	void Free();

private:
	Node* pFirst;
	Node* pLast;
	size_t Length;
};

