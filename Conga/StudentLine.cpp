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
	Length--;
}

void StudentLine::RemoveLast()
{
	Node* NewNode = pLast;
	pLast->pPrev->pNext = nullptr;
	pLast = pLast->pPrev;
	NewNode->Free();
	Length--;
}

// Must check if the returned and the given lines are null -> to be removed
StudentLine StudentLine::Remove(const string& Name, const string& Uni)
{
	Node* pCurrent = pFirst;
	StudentLine NewLine;
	size_t i = 1;
	while (i <= Length)
	{
		if (pCurrent->Name == Name && pCurrent->Uni == Uni)
		{
			if (i == 1)
			{
				RemoveFirst();
				break;
			}

			if (i == Length)
			{
				RemoveLast();
				break;
			}

			// Here we set the new Line
			NewLine.pFirst = pCurrent->pNext;
			NewLine.pLast = pLast;
			NewLine.Length = Length - i;

			// Here we set the old line
			pLast = pCurrent->pPrev;
			Length = i - 1;

			// Here we remove the current and nullify its pointers
			pCurrent->pPrev = nullptr;
			pCurrent->pNext = nullptr;
			pLast->pNext = nullptr;
			NewLine.pFirst->pPrev = nullptr;
			pCurrent->Free();
		}
		++i;
	}

	return NewLine;
}

void StudentLine::Free()
{
	while (Length != 0)
	{
		RemoveFirst();
	}

	pFirst = nullptr;
	pLast = nullptr;
}
