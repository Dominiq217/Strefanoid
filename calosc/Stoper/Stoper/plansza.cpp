#include "plansza.h"


using namespace Stoper;


[STAThreadAttribute]

int main(array<String ^> ^args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Stoper::plansza formularz;
	Application::Run(%formularz);
	return 0;
}