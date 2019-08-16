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

void Conga::Do()
{
	string Command, FuncName, Name, Uni, Index1, Index2;

	do
	{
		getline(cin, Command, '\n');
		
		FuncName = DeleteFirstWord(Command);
		
		if (FuncName == "append")
		{
			Name = DeleteFirstWord(Command);
			Uni = DeleteFirstWord(Command);
			Index1 = DeleteFirstWord(Command);
			Append(Name, Uni, stoul(Index1));
			continue;
		}
		if (FuncName == "removeLast")
		{
			RemoveLast(stoul(Command));
			continue;
		}
		if (FuncName == "removeFirst")
		{
			RemoveFirst(stoul(Command));
			continue;
		}
		if (FuncName == "remove")
		{
			Name = DeleteFirstWord(Command);
			Index1 = DeleteFirstWord(Command);
			Remove(Name, stoul(Index1));
			continue;
		}
		if (FuncName == "merge")
		{
			Index1 = DeleteFirstWord(Command);
			Index2 = DeleteFirstWord(Command);
			Merge(stoul(Index1), stoul(Index2));
			continue;
		}
		if (FuncName == "print")
		{
			Print();
			continue;
		}

	} while (FuncName != "quit");	
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
	if (isLegal(Index))
		Lines[Index].AddEnd(Name, Uni);
}

void Conga::RemoveLast(const size_t Index)
{
	if (isLegal(Index))
	{
		Lines[Index].RemoveLast();

		if (Lines[Index].isEmpty())
			RemoveEmptyLine(Index);
	}
}

void Conga::RemoveFirst(const size_t Index)
{
	if (isLegal(Index))
	{
		Lines[Index].RemoveFirst();

		if (Lines[Index].isEmpty())
			RemoveEmptyLine(Index);
	}
}

void Conga::Remove(const string& Name, const size_t Index)
{
	if (isLegal(Index))
	{
		StudentLine NewLine = Lines[Index].Remove(Name);

		if (NewLine.isEmpty())
			return;
		else
			AddLine(NewLine);
	}
}

void Conga::Merge(const size_t Index1, const size_t Index2)
{
	if (isLegal(Index1) && isLegal(Index2))
	{
		if (Lines[Index1].Merge(Lines[Index2]))
		{
			Lines[Index2].Free();
			RemoveEmptyLine(Index2);
		}
	}
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
	Allocated = 1;
	Taken = 1;
	Lines = new StudentLine[Allocated];
}

void Conga::RemoveEmptyLine(const size_t Index)
{
	if (isLegal(Index))
	{
		ShiftBack(Index);
		CheckAllocated();
	}
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

bool Conga::isLegal(const size_t& Index) const
{
	if (Index < Taken)
	{
		return true;
	}
	else
	{
		cout << "Line number " << Index << " does not exist!\n";
		return false;
	}
}

string Conga::DeleteFirstWord(string& Sentence) const
{
	size_t Index = Sentence.find_first_of(' ');
	string Word = Sentence.substr(0, Index);
	Sentence.erase(0, Index + 1);
	return Word;
}
