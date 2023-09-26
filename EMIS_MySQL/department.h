#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "employee.h"
#include "tools.h"

class Department
{
	int m_iId;
	char m_strName[20];
public:
	vector<Employee> empArr;
	Department(void){};
	Department(const char*);
	~Department(void);
	void setId(int);
	void setName(char*);
	int getId(void);
	char *getName(void);
	friend ostream& operator << (ostream& os,const Department& dp);
	friend istream& operator >> (istream& is,Department& dp);
};

#endif
