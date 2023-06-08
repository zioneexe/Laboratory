#include "CTable.h"

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace OOPLab11;

[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OOPLab11::MyForm form;
	Application::Run(% form);
	return 0;
}