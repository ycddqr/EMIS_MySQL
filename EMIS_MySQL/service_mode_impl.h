#ifndef SERVICE_MODE_IMPL_H
#define SERVICE_MODE_IMPL_H

#include "service_mode.h"

class ServiceModeImpl : public ServiceMode
{
public:
	void load(vector<Department>&);
	void save(vector<Department>&);
};

#endif
