#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "tools.h"

class Employee
{
	int m_iId;
	int m_iAge;
	char m_strName[20];
	char m_cSex;
public:
	Employee(void){};
	Employee(const char*,char,int);
	void setId(int);
	void setAge(int);
	void setName(const char*);
	void setSex(char);
	int getId(void);
	int getAge(void);
	char *getName(void);
	char getSex(void);
	friend ostream& operator << (ostream& os,const Employee& emp);
	friend istream& operator >> (istream& os,Employee& emp);
};

#endif
