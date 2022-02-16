#pragma once
#include "Common.h"

typedef struct _AppController AppController;

AppController* AppController_New(void);
void AppController_Delete(AppController* _this);
void AppController_Run(AppController* _this);