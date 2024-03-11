#include "MyForm.h"

using namespace Muzyka;


[STAThreadAttribute]

int main(array<String ^> ^args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Muzyka::MyForm formularz;
	Application::Run(%formularz);
	return 0;
}