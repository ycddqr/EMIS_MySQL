#ifndef SERVICE_CTRL_IMPL_H
#define SERVICE_CTRL_IMPL_H

#include "service_ctrl.h"
#include "service_mode_impl.h"

class ServiceCtrlImpl : public ServiceCtrl
{
	ServiceMode *srcMode;
	vector<Department> deptArr;
public:
	ServiceCtrlImpl(void);
	~ServiceCtrlImpl(void);
	bool addDept(Department&);
	bool delDept(int);
	vector<Department>& listDept(void);
	bool addEmp(int,Employee&);
	bool delEmp(int);
	bool modEmp(int,Employee&);
	Department *listEmp(int);
	vector<Department>& listAllEmp(void);
};

#endif
