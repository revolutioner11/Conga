#include "Conga.h"

int main()
{
	Conga C1;

	
	C1.Append("Tosho", "tu", 0);
	C1.Append("Mitio", "fmi", 0);
	C1.Append("Gregor", "unss", 0);
	C1.Append("petko", "unss", 0);
	C1.Append("Ivanushka", "fmi", 0);		// not in
	C1.Append("Cecko", "unss", 0);
	C1.Append("Goran", "tu", 0);

	C1.Remove("petko", 0);
	
	C1.Append("AAZZ", "fmi", 1);
	C1.RemoveFirst(1);
	C1.RemoveLast(0);
	C1.Remove("Mitio", 0);
	C1.Merge(1, 2);					// broken

	C1.Print();



// -------------------------------- //

	char c;
	cin >> c;

	return 0;
}