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

void Conga::Print() const
{
	for (size_t i = 0; i < Taken; ++i)
	{
		cout << "Line" << i << ": ";
		Lines[i].Print();
		cout << endl;
	}
}

void Conga::Merge(const size_t Index1, const size_t Index2)
{
	// engouh
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
