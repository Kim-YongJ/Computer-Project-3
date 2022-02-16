#include "Student.h"
/* 컴퓨터 프로그래밍3 6주차과제	
               201400875 김용준 */

int main(void)
{
	AppController* appController = AppController_New(); // 실행할 프로그램객체 생성
	AppController_Run(appController); // 실행
	AppController_Delete(appController); // 삭제

	return 0;
}

// 메인에서는 더이상 코드를 알려주지 않고, 미리 짜여진 수순대로 행동하게 하게만 해주는 코드를 짠다.