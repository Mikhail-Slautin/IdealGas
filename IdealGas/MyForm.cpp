#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Diagnostics;
[STAThreadAttribute]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	IdealGas::MyForm form;
	Application::Run(% form);
}

