#include "service_view_impl.h"

void ServiceViewImpl::menuSrc(void)
{
	for(;;)
	{
		system("clear");
		cout << "---------欢迎进入管理员子系统----------" << endl;
		cout << "1、增加部门  2、删除部门  3、列出所有部门" << endl;
		cout << "4、增加员工  5、删除员工  6、修改员工信息" << endl;
		cout << "7、列出部门员工  8、列出所有员工  9、退出" << endl;
		switch(get_cmd('1','9'))
		{
			case '1': addDept();break;
			case '2': delDept();break;
			case '3': listDept();break;
			case '4': addEmp();break;
			case '5': delEmp();break;
			case '6': modEmp();break;
			case '7': listEmp();break;
			case '8': listAllEmp();break;
			case '9': return;
		}
		anykey_continue();
	}
}

void ServiceViewImpl::addDept(void)
{
	cout << "请输入要添加的部门名：";
	char name[20] = {};
	if(!get_str_chinese(name,sizeof(name))) return;
	Department dept(name);
	if(srcCtrl->addDept(dept))
	{
		cout << "添加成功！" << endl;
	}
	else
	{
		cout << "已有重名部门，添加失败！" << endl;
	}
}

void ServiceViewImpl::delDept(void)
{
	cout << "请输入要删除的部门ID：";
	int id = 0;
	clear_stdin();
	cin >> id;
	if(srcCtrl->delDept(id))
		cout << "删除成功！" << endl;
	else
		cout << "未找到该部门，删除失败！" << endl;
}

void ServiceViewImpl::listDept(void)
{
	vector<Department>& deptArr = srcCtrl->listDept();
	for(size_t i = 0; i < deptArr.size(); i++)
		cout << deptArr[i] << endl;
}

void ServiceViewImpl::addEmp(void)
{
	cout << "请输入员工姓名：";
	char name[20] = {};
	if(!get_str(name,sizeof(name)))
	{
		cout << "添加失败！" << endl;
		return;
	}
	cout << "员工年龄：";
	int age = 0;
	cin >> age;
	clear_stdin();
	if(age < 18 || age > 65)
	{
		cout << "输入年龄不合法，添加失败！" << endl;
		return;
	}
	cout << "员工性别(1男/0女)：";
	int sex = -1;
	cin >> sex;
	clear_stdin();
	if(sex != 0 && sex != 1)
	{
		cout << "输入不合法，添加失败！" << endl;
		return;
	}
	if(1 == sex)
		sex = 'm';
	else
		sex = 'w';
	cout << "请输入员工的部门ID：";
	int dept_id = 0;
	cin >> dept_id;
	clear_stdin();
	Employee emp(name,sex,age);
	if(srcCtrl->addEmp(dept_id,emp))
		cout << "添加成功！" << endl;
	else
		cout << "未找到该部门，添加失败！" << endl;
}

void ServiceViewImpl::delEmp(void)
{
	cout << "请输入要删除员工ID：";
	int id = 0;
	cin >> id;
	clear_stdin();
	if(srcCtrl->delEmp(id))
		cout << "删除成功！" << endl;
	else
		cout << "未找到该员工，删除失败！" << endl;
}

void ServiceViewImpl::modEmp(void)
{
	cout << "请输入要修改的员工ID：";
	int id = 0;
	cin >> id;
	clear_stdin();
	cout << "请输入修改后的员工ID：";
	int new_id = 0;
	cin >> new_id;
	clear_stdin();
	cout << "请输入修改后员工姓名：";
	char name[20] = {};
	if(!get_str(name,sizeof(name)))
	{
		cout << "修改失败！" << endl;
		return;
	}
	cout << "修改后员工年龄：";
	int age = 0;
	cin >> age;
	clear_stdin();
	if(age < 18 || age > 65)
	{
		cout << "输入年龄不合法，修改失败！" << endl;
		return;
	}
	cout << "修改后员工性别(1男/0女)：";
	int sex = -1;
	cin >> sex;
	clear_stdin();
	if(sex != 0 && sex != 1)
	{
		cout << "输入不合法，修改失败！" << endl;
		return;
	}
	if(1 == sex)
		sex = 'm';
	else
		sex = 'w';
	Employee emp(name,sex,age);
	emp.setId(new_id);
	if(srcCtrl->modEmp(id,emp))
		cout << "修改成功！" << endl;
	else
		cout << "未找到该员工或修改的员工ID已存在，修改失败！" << endl;
}

void ServiceViewImpl::listEmp(void)
{
	cout << "请输入要列出员工的部门ID：";
	int id = 0;
	cin >> id;
	clear_stdin();
	Department *dept = srcCtrl->listEmp(id);
	if(NULL == dept)
	{
		cout << "未找到该部门！" << endl;
		return;
	}
	for(size_t i = 0; i < dept->empArr.size(); i++)
		cout << dept->empArr[i] << endl;
}

void ServiceViewImpl::listAllEmp(void)
{
	vector<Department>& deptArr = srcCtrl->listAllEmp();
	for(size_t i = 0; i < deptArr.size(); i++)
	{
		for(size_t j = 0; j < deptArr[i].empArr.size(); j++)
		{
			cout << deptArr[i].empArr[j] << endl;
		}
	}
}

