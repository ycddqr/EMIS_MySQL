#include "service_ctrl_impl.h"


ServiceCtrlImpl::ServiceCtrlImpl(void)
{
	srcMode = new ServiceModeImpl;
	srcMode->load(deptArr);
}

ServiceCtrlImpl::~ServiceCtrlImpl(void)
{
	srcMode->save(deptArr);
	delete srcMode;
}

bool ServiceCtrlImpl::addDept(Department& dept)
{
	//	在deptArr中查找是否重命名
	for(size_t i = 0; i < deptArr.size(); i++)
	{
		if(!strcmp(deptArr[i].getName(),dept.getName()))
			return false;
	}
	dept.setId(get_deptid());
	deptArr.push_back(dept);
	return true;
}

bool ServiceCtrlImpl::delDept(int id)
{
	vector<Department>::iterator it = deptArr.begin();
	for(; it != deptArr.end(); it++)
	{
		if(id == it->getId())
		{
			deptArr.erase(it);
			return true;
		}
	}
	return false;
}

vector<Department>& ServiceCtrlImpl::listDept(void)
{
	return deptArr;
}

bool ServiceCtrlImpl::addEmp(int dept_id,Employee& emp)
{
	for(size_t i = 0; i < deptArr.size(); i++)
	{
		if(dept_id == deptArr[i].getId())
		{
			emp.setId(get_empid());
			deptArr[i].empArr.push_back(emp);
			return true;
		}
	}
	return false;
}

bool ServiceCtrlImpl::delEmp(int id)
{
	for(size_t i = 0; i < deptArr.size(); i++)
	{
		for(vector<Employee>::iterator it = deptArr[i].empArr.begin(); it != deptArr[i].empArr.end(); it++)
		{
			if(id == it->getId())
			{
				deptArr[i].empArr.erase(it);
				return true;
			}
		}
	}
	return false;
}

bool ServiceCtrlImpl::modEmp(int id,Employee& emp)
{
	if(id != emp.getId())
	{
		for(size_t i = 0; i < deptArr.size(); i++)
		{
			for(vector<Employee>::iterator it = deptArr[i].empArr.begin(); it != deptArr[i].empArr.end(); it++)
			{
				if(emp.getId() == it->getId())
					return false;	//	有id相等的员工，修改失败
			}
		}
	}
	for(size_t i = 0; i < deptArr.size(); i++)
	{
		for(vector<Employee>::iterator it = deptArr[i].empArr.begin(); it != deptArr[i].empArr.end(); it++)
		{
			if(id == it->getId())
			{
				deptArr[i].empArr.erase(it);
				deptArr[i].empArr.insert(it,emp);
				return true;
			}
		}
	}
	return false;
}

Department *ServiceCtrlImpl::listEmp(int dept_id)
{
	for(size_t i = 0; i < deptArr.size(); i++)
	{
		if(deptArr[i].getId() == dept_id)
			return &deptArr[i];
	}
	return NULL;
}

vector<Department>& ServiceCtrlImpl::listAllEmp(void)
{
	return deptArr;
}

