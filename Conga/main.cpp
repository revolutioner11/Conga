#include "Conga.h"

int main()
{
	StudentLine SL1;
	StudentLine SL3;
	
	SL1.AddEnd("Tosho", "tu");
	SL1.AddEnd("Mitio", "fmi");
	SL1.AddEnd("Gregor", "unss");
	SL1.AddEnd("petko", "unss");
	SL1.AddEnd("Ivanushka", "fmi");
	SL1.AddEnd("Cecko", "unss");
	SL1.AddEnd("Goran", "tu");


	
	cout << endl;
	StudentLine SL2 = SL1;
	SL3 = SL1;

	SL1.Print();

	cout << endl;

// -------------------------------- //

	SL1.RemoveFirst();

	SL2.RemoveLast();
	SL3.Merge(SL2);

	SL1.Print();
	SL2.Print();
	SL3.Print();

// -------------------------------- //
	cout << endl;

	SL1 = SL3.Remove("petko", "unss");
	SL1 = SL3.Remove("Tosho", "tu");
	SL1 = SL3.Remove("Tosho", "tu");

	SL1.Print();
	SL2.Print();
	SL3.Print();

	char c;
	cin >> c;

	return 0;
}