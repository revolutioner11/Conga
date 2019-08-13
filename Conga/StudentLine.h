#pragma once

#include <string>

class StudentLine
{
public:
	struct Node
	{
	public:
		string
		Node* pPrev;
		Node* pNext;

		Node(const T& Data, Node* pPrev = nullptr, Node* pNext = nullptr)
			: Data(Data), pPrev(pPrev), pNext(pNext)
		{
		}
	};

public:
	DoublyLinkedList();
	DoublyLinkedList(DoublyLinkedList const& OtherDLL);
	DoublyLinkedList& operator=(const DoublyLinkedList& OtherDLL);
	~DoublyLinkedList();

	void Merge(DoublyLinkedList const& OtherDLL);
	//void AddFront(const T& Data);
	void AddEnd(const T& Data);				// This will be our APPEND
	void RemoveFirst();
	void RemoveLast();
	void RemoveAt();



private:
	void Free()

private:
	Node* pFirst;
	Node* pLast;
	size_t Length;
};

