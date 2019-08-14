#include "StudentLine.h"

int main()
{
	StudentLine SL1;
	
	
	SL1.AddEnd("Tosho", "tu");
	SL1.AddEnd("Mitio", "fmi");
	SL1.AddEnd("Gregor", "unss");
	SL1.AddEnd("petko", "unss");
	SL1.AddEnd("Ivanushka", "fmi");
	SL1.AddEnd("Cecko", "unss");
	SL1.AddEnd("Goran", "tu");


	SL1.Print();


	return 0;
}