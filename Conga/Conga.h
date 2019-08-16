#pragma once

#include "StudentLine.h"

class Conga
{
public:
	Conga();
	Conga(const Conga& Other);
	Conga& operator=(const Conga& Other);
	~Conga();

public:
	bool operator==(const Conga& Other) const;
	bool operator!=(const Conga& Other) const;

public:
	void Do();

private:
	Conga(size_t Allocated, size_t Taken);

	void Free();
	void Copy(const Conga& Other);
	void Create();
	void RemoveEmptyLine(const size_t Index);
	void AddLine(const StudentLine& Line);
	void ShiftBack(const size_t EmptyIndex);
	void CheckAllocated();
	void CheckCapacity();
	bool isLegal(const size_t& Index) const;
private:
	string DeleteFirstWord(string& Sentence) const;

private:
	void Append(const string& Name, const string& Uni, const size_t Index);
	void RemoveLast(const size_t Index);
	void RemoveFirst(const size_t Index);
	void Remove(const string& Name, const size_t Index);
	void Merge(const size_t Index1, const size_t Index2);
	void Print() const;

private:
	StudentLine* Lines;
	size_t Allocated;
	size_t Taken;
};

