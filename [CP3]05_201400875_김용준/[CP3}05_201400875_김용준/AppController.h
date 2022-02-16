#pragma once

#include "MagicSquare.h"

typedef struct {
	int appController;
}
AppController;


AppController* AppController_New();void AppController_Delete(AppController* appController);
void AppController_Run(AppController* appController);

void AppController_ShowBoard();




