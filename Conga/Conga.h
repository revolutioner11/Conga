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

	void Print() const;
	void Merge(const size_t Index1, const size_t Index2);

private:
	void Free();
	void Copy(const Conga& Other);
	void Create();
private:
	StudentLine* Lines;
	size_t Allocated;
	size_t Taken;
};

