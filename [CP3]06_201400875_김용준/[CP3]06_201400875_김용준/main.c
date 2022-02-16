#include "AppController.h"

int main(void)
{
	AppController* appController = AppController_New();
	AppController_Run(appController);
	AppController_Delete(appController);

	return 0;
}