#include "Student.h"
/* ��ǻ�� ���α׷���3 6��������	
               201400875 ����� */

int main(void)
{
	AppController* appController = AppController_New(); // ������ ���α׷���ü ����
	AppController_Run(appController); // ����
	AppController_Delete(appController); // ����

	return 0;
}

// ���ο����� ���̻� �ڵ带 �˷����� �ʰ�, �̸� ¥���� ������� �ൿ�ϰ� �ϰԸ� ���ִ� �ڵ带 §��.