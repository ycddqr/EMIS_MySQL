#ifndef SERVICE_CTRL_H
#define SERVICE_CTRL_H

#include "department.h"
#include "tools.h"

class ServiceCtrl
{
public:
	virtual ~ServiceCtrl(void){};
	virtual bool addDept(Department&) = 0;
	virtual bool delDept(int) = 0;
	virtual vector<Department>& listDept(void) = 0;
	virtual bool addEmp(int,Employee&) = 0;
	virtual bool delEmp(int) = 0;
	virtual bool modEmp(int,Employee&) = 0;
	virtual Department *listEmp(int) = 0;
	virtual vector<Department>& listAllEmp(void) = 0;
};

#endif
