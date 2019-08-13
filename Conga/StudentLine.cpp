#include "StudentLine.h"


StudentLine::StudentLine()
{
	Free();
}

StudentLine::StudentLine(const StudentLine& Other)
{
	Free();
	Merge(Other);
}

StudentLine& StudentLine::operator=(const StudentLine& Other)
{
	if (*this!=Other)
	{
		Free();
		Merge(Other);
	}
}

StudentLine::~StudentLine()
{
	Free();
}

bool StudentLine::operator==(const StudentLine& Other) const
{
	return false;
}

bool StudentLine::operator!=(const StudentLine& Other) const
{
	return !(*this==Other);
}

void StudentLine::Merge(const StudentLine& Other)
{
	if (Other.Length == 0)
		return;

	Node* pCurrent = Other.pFirst;

	for (size_t i = 1; i <= Other.Length; ++i)
	{
		AddEnd(pCurrent->Name, pCurrent->Uni);
		pCurrent = pCurrent->pNext;
		Length++;
	}
}

void StudentLine::AddEnd(const string& Name, const string& Uni)
{
	Node* NewNode = new Node(Name, Uni, pLast);
	pLast->pNext = NewNode;
	pLast = NewNode;
	Length++;
}

   //Node* NewNode = new Node(Name, Uni, pLast);
  //pFirst->pPrev = NewNode;
 //pFirst = NewNode;
//Length++;


void StudentLine::RemoveFirst()
{
	Node* NewNode = pFirst;
	pFirst->pNext->pPrev = nullptr;
	pFirst = pFirst->pNext;
	NewNode->Free();
}

void StudentLine::RemoveLast()
{
	Node* NewNode = pLast;
	pLast->pPrev->pNext = nullptr;
	pLast = pLast->pPrev;
	NewNode->Free();
}

StudentLine StudentLine::Remove(const string& Name, const string& Uni)
{
	Node* pCurrent = pFirst;

	size_t i = 1;
	while (i <= Length)
	{
		if (pCurrent->Name == Name && pCurrent->Uni == Uni)
		{

		}


		++i;
	}
}

void StudentLine::Free()
{

}
