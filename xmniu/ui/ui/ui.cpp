// ui.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "RobotForm.h"

using namespace ui;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
    RobotForm^ robotForm = gcnew RobotForm();
	Application::Run(robotForm);
	return 0;
}
