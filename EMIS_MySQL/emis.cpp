#include "emis.h"

int mgrid = 1000,deptid = 2000,empid = 3000;

Emis Emis::emis;

Emis::Emis(void)
{
	mgrView = new ManagerViewImpl;
}

Emis::~Emis(void)
{
	delete mgrView;
}

Emis& Emis::get_emis(void)
{
	return emis;
}

void Emis::start_emis(void)
{
	for(;;)
	{
		system("clear");
		cout << "欢迎进入企业管理系统" << endl;
		cout << "1.登录超级管理员系统" << endl;
		cout << "2.登录业务管理系统" << endl;
		cout << "3.退出" << endl;
		switch(get_cmd('1','3'))
		{
			case '1': mgrView->loginManager(); break;
			case '2': mgrView->loginService(); break;
			case '3': return;
		}
	}
}

