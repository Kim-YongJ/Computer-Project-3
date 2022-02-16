#pragma once
#include "Postfix.h"
#include "Common.h"
#include "Stack.h"
#include "AppView.h"
typedef struct _AppController AppController;

AppController* AppController_New(void);
void AppController_Delete(AppController* _this);
void AppController_Run(AppController* _this);