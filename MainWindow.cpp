#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#include "MainWindow.h"
using namespace System;
using namespace System::Windows::Forms;
int main()
{
	srand(time(0));
	Application::EnableVisualStyles();
	KF2PD::MainWindow form;
	Application::Run(% form);
}
