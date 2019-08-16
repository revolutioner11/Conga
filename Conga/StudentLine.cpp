#include "StudentLine.h"


StudentLine::StudentLine()
{
	Length = 0;
	Free();
}

StudentLine::StudentLine(const StudentLine& Other)
{
	Length = 0;
	Free();
	Merge(Other);
}

StudentLine& StudentLine::operator=(const StudentLine& Other)
{
	if (*this != Other)
	{
		Free();
		Merge(Other);
	}

	return *this;
}

StudentLine::~StudentLine()
{
	Free();
}

bool StudentLine::operator==(const StudentLine& Other) const
{
	if (Length != Other.Length)
	{
		return false;
	}

	Node* pThis = pFirst;
	Node* pOther = Other.pFirst;

	for (size_t i = 1; i <= Length; ++i)
	{
		if (pThis->Name != pOther->Name 
			|| pThis->Uni != pOther->Uni)
		{
			return false;
		}
		pThis = pThis->pNext;
		pOther = pOther->pNext;
	}

	return true;
}

bool StudentLine::operator!=(const StudentLine& Other) const
{
	return !(*this==Other);
}

bool StudentLine::Merge(const StudentLine& Other)
{
	if (Other.Length == 0)
		return true;

	if (Length > 0 && !isCompatable(pLast->Uni, Other.pFirst->Uni))
	{
		cout << "Action Denied! Incompatible people!\n";
		return false;
	}

	Node* pCurrent = Other.pFirst;

	for (size_t i = 1; i <= Other.Length; ++i)
	{
		AddAfter(pCurrent->Name, pCurrent->Uni);
		pCurrent = pCurrent->pNext;
	}
	return true;
}

void StudentLine::AddEnd(const string& Name, const string& Uni)
{
	if (Length == 0)
	{
		CreateFirstNode(Name, Uni);
		return;
	}

	if (isCompatable(pLast->Uni, Uni))
	{
		AddAfter(Name, Uni);
	}
	else
	{
		cout << "Action Denied! Incompatible people!\n";
	}
}

// Must check if the line is null -> to be removed
void StudentLine::RemoveFirst()
{
	if (Length == 1)
	{
		pFirst->Free();
		pFirst = nullptr;
		pLast = nullptr;
		Length--;

		return;
	}

	Node* NewNode = pFirst;
	pFirst->pNext->pPrev = nullptr;
	pFirst = pFirst->pNext;
	NewNode->Free();
	Length--;
}

// Must check if the line is null -> to be removed
void StudentLine::RemoveLast()
{
	if (Length == 1)
	{
		pFirst->Free();
		pFirst = nullptr;
		pLast = nullptr;

		return;
	}

	Node* NewNode = pLast;
	pLast->pPrev->pNext = nullptr;
	pLast = pLast->pPrev;
	NewNode->Free();
	Length--;
}

// Must check if the returned and the given lines are null -> to be removed
StudentLine StudentLine::Remove(const string& Name)
{
	Node* pCurrent = pFirst;
	StudentLine NewLine;
	size_t i = 1;
	while (i <= Length)
	{
		if (pCurrent->Name == Name)
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
		pCurrent = pCurrent->pNext;
	}

	return NewLine;
}

void StudentLine::Print() const
{
	if (Length == 0)	// should not happen!?
	{
		cout << "empty line\n";
		return;
	}

	Node* pCurrent = pFirst;

	cout << "Line: ";
	for (size_t i = 1; i <= Length; ++i)
	{
		cout << "(" << pCurrent->Name << ", " << pCurrent->Uni << ")";
		if (i != Length)
			cout << " - ";
		pCurrent = pCurrent->pNext;
	}
}

bool StudentLine::isEmpty() const
{
	return !Length;
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

bool StudentLine::isCompatable(const string& FrontUni, const string& BackUni) const
{
	if ((FrontUni == BackUni)
		|| (FrontUni == "fmi" && BackUni == "unss")
		|| (FrontUni == "unss" && BackUni == "tu")
		|| (FrontUni == "tu" && BackUni == "fmi"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// this function does not do compatability check
// because MERGE need only the first check
void StudentLine::AddAfter(const string& Name, const string& Uni)
{
	if (Length == 0)
	{
		CreateFirstNode(Name, Uni);
		return;
	}

	Node* NewNode = new Node(Name, Uni, pLast);
	pLast->pNext = NewNode;
	pLast = NewNode;
	Length++;
}

void StudentLine::CreateFirstNode(const string& Name, const string& Uni)
{
	if (Length != 0)					// should NOT happen at all
	{
		cout << "ERROR! WRONG SIZE!\n";
		return;
	}

	Node* NewNode = new Node(Name, Uni);
	pFirst = NewNode;
	pLast = NewNode;
	Length++;

	return;
}

