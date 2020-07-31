#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main(cli::array<String^>^ args)
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Application::Run(gcnew Trabajo_Parcial::MyForm());
	}