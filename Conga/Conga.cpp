#include "Conga.h"

Conga::Conga()
{
	Create();
}

Conga::Conga(const Conga& Other)
{
	Lines = nullptr;
	Copy(Other);
}

Conga& Conga::operator=(const Conga& Other)
{
	if (Other == *this)
	{
		Free();
		Copy(Other);
	}
		
	return *this;
}

Conga::~Conga()
{
	Free();
}

bool Conga::operator==(const Conga& Other) const
{
	for (size_t i = 0; i < Taken; ++i)
	{
		if (Lines[i] != Other.Lines[i])
			return false;
	}
	return true;
}

bool Conga::operator!=(const Conga& Other) const
{
	return !(*this == Other);
}

void Conga::Do(string Command)
{
	// TO DO: take commands
}

Conga::Conga(size_t Allocated, size_t Taken)
{
	this->Allocated = Allocated;
	this->Taken = Taken;
	Lines = new StudentLine[Allocated];
}

void Conga::Print() const
{
	for (size_t i = 0; i < Taken; ++i)
	{
		cout << "Line" << i << ": ";
		Lines[i].Print();
		cout << endl;
	}
}

void Conga::Append(const string& Name, const string& Uni, const size_t Index)
{
	Lines[Index].AddEnd(Name, Uni);
}

void Conga::RemoveLast(const size_t Index)
{
	Lines[Index].RemoveLast();

	if (Lines[Index].isEmpty())
		RemoveEmptyLine(Index);
}

void Conga::RemoveFirst(const size_t Index)
{
	Lines[Index].RemoveFirst();

	if (Lines[Index].isEmpty())
		RemoveEmptyLine(Index);
}

void Conga::Remove(const string& Name, const size_t Index)
{
	StudentLine NewLine = Lines[Index].Remove(Name);

	if (NewLine.isEmpty())
		return;
	else
		AddLine(NewLine);
}

void Conga::Merge(const size_t Index1, const size_t Index2)
{
	Lines[Index1].Merge(Lines[Index2]);
	Lines[Index2].Free();
	RemoveEmptyLine(Index2);
}

void Conga::Free()
{
	delete[] Lines;
	Lines = nullptr;
	Allocated = 0;
	Taken = 0;
}

void Conga::Copy(const Conga& Other)
{
	Free();

	Allocated = Other.Allocated;
	Taken = Other.Taken;
	Lines = new StudentLine[Allocated];
	for (size_t i = 0; i < Taken; ++i)
	{
		Lines[i] = Other.Lines[i];
	}
}

void Conga::Create()
{
	Allocated = 4;
	Taken = 0;
	Lines = new StudentLine[Allocated];
}

void Conga::RemoveEmptyLine(const size_t Index)
{
	ShiftBack(Index);
	CheckAllocated();
}

void Conga::AddLine(const StudentLine& Line)
{
	CheckCapacity();

	Lines[Taken] = Line;
	Taken++;
}

void Conga::ShiftBack(const size_t EmptyIndex)
{
	for (size_t i = EmptyIndex; i < Taken - 1; ++i)
	{
		Lines[i] = Lines[i + 1];
	}
	Lines[Taken - 1].Free();
	Taken--;
}

void Conga::CheckAllocated()
{
	if (Allocated >= Taken * 2)
	{
		Conga NewConga(Allocated / 2, Taken);
		for (size_t i = 0; i < Taken; i++)
		{
			NewConga.Lines[i] = Lines[i];
		}

		Copy(NewConga);
	}

	return;
}

void Conga::CheckCapacity()
{
	if (Allocated == Taken)			// can happen only before add line
	{
		Conga NewConga(Allocated * 2, Taken);
		for (size_t i = 0; i < Taken; i++)
		{
			NewConga.Lines[i] = Lines[i];
		}

		Copy(NewConga);
	}

	return;
}
