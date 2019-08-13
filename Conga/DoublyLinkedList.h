#pragma once

template <class T>
class DoublyLinkedList
{
public:
	struct Node
	{
	public:
		T Data;
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
	void Append(const T& Data);
	T& RemoveFirst();
	T& RemoveLast();



private:
	void Free()

private:
	Node* pFirst;
	Node* pLast;
	size_t Length;



};