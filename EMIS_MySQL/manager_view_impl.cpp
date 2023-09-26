#include "manager_view_impl.h"


ManagerViewImpl::ManagerViewImpl(void)
{
	mgrCtrl = new ManagerCtrlImpl;
	srcView = new ServiceViewImpl;
}

ManagerViewImpl::~ManagerViewImpl(void)
{
	delete mgrCtrl;
	delete srcView;
}

void ManagerViewImpl::loginManager(void)
{
	char id[20] = {};
	char pwd[20] = {};
	cout << "请输入超级管理员ID：";
	if(!get_str(id,sizeof(id)))
	{
		cout << "登录失败！请重新登录。" << endl;
		anykey_continue();
		return;
	}
	cout << "请输入超级管理员密码：";
	if(!get_pwd(pwd,sizeof(pwd)))
	{
		cout << "登录失败！请重新登录。" << endl;
		anykey_continue();
		return;
	}
	if(!strcmp(id,"root") && !strcmp(pwd,"1234"))
	{
		menuMgr();
		return;
	}
	cout << "ID或密码错误！" << endl;
	sleep(2);
}

void ManagerViewImpl::loginService(void)
{
	int id = 0;
	char pwd[20] = {};
	cout << "请输入管理员ID：";
	cin >> id;
	clear_stdin();
	cout << "请输入密码：";
	if(!get_pwd(pwd,sizeof(pwd)))
	{
		cout << "登录失败！请重新登录。" << endl;
		anykey_continue();
		return;
	}
	//	遍历 mgrArr 找id
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(size_t i = 0; i < mgrArr.size(); i++)
	{
		if(id == mgrArr[i].getId() && !strcmp(pwd,mgrArr[i].getPwd()))
		{
			//	登录成功
			srcView->menuSrc();
			return;
		}
	}
	cout << "ID或密码错误！" << endl;
	sleep(2);
}

void ManagerViewImpl::menuMgr(void)
{
	for(;;)
	{
		system("clear");
		cout << "欢迎进入超级管理子系统" << endl;
		cout << "1.添加管理员" << endl;
		cout << "2.删除管理员" << endl;
		cout << "3.列出管理员" << endl;
		cout << "4.退出" << endl;
		switch(get_cmd('1','4'))
		{
			case '1': addMgr(); break;
			case '2': delMgr(); break;
			case '3': listMgr(); break;
			case '4': return;
		}
	}
}

void ManagerViewImpl::addMgr(void)
{
	char name[20] = {},pwd[20] = {},repwd[20] = {};
	cout << "请输入管理员用户名：";
	if(!get_str(name,sizeof(name)))
	{
		cout << "创建失败！请重新创建。" << endl;
		anykey_continue();
		return;
	}
	cout << "请输入管理员密码：";
	if(!get_pwd(pwd,sizeof(pwd)))
	{
		cout << "创建失败！请重新创建。" << endl;
		anykey_continue();
		return;
	}
	cout << "请再次输入管理员密码：";
	if(!get_pwd(repwd,sizeof(repwd)))
	{
		cout << "创建失败！请重新创建。" << endl;
		anykey_continue();
		return;
	}
	if(strcmp(pwd,repwd))
	{
		cout << "两次密码不同，添加失败！" << endl;
		sleep(1);
		return;
	}
	Manager mgr(name,pwd);
	if(mgrCtrl->addMgr(mgr))
		cout << "添加管理员成功！" << endl;
	else
		cout << "已有该用户名，添加失败！" << endl;
	sleep(1);
}

void ManagerViewImpl::delMgr(void)
{
	int id = 0;
	cout << "请输入要删除的管理员id：";
	cin >> id;
	if(mgrCtrl->delMgr(id))
		cout << "删除管理员成功！" << endl;
	else
		cout << "id有误，删除管理员失败！" << endl;
	sleep(1);
}

void ManagerViewImpl::listMgr(void)
{
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(size_t i = 0; i < mgrArr.size(); i++)
	{
		cout << mgrArr[i] << endl;
	}
	anykey_continue();
}

