#ifndef SERVICE_VIEW_IMPL_H
#define SERVICE_VIEW_IMPL_H

#include "service_view.h"
#include "service_ctrl_impl.h"

class ServiceViewImpl : public ServiceView
{
	ServiceCtrl *srcCtrl;
public:
	ServiceViewImpl(void){ srcCtrl = new ServiceCtrlImpl; };
	~ServiceViewImpl(void){ delete srcCtrl; };
	void menuSrc(void);
	void addDept(void);
	void delDept(void);
	void listDept(void);
	void addEmp(void);
	void delEmp(void);
	void modEmp(void);
	void listEmp(void);
	void listAllEmp(void);
};

#endif
