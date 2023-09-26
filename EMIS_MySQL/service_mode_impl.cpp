#include "service_mode_impl.h"
#include "emis.h"
#include "my_sql.h"

//  加载 MySQL 中数据到 deptArr
void ServiceModeImpl::load(vector<Department>& deptArr)
{
	//	deptArr 部门数据
	Mysql dept_mysql(IP,USER,PWD,DEPARTMENT_DB);  //  搞Mysql对象
	MYSQL_RES *dept_res = dept_mysql.show(DEPARTMENT_TABLE);  //  获取 表department 的二维表
	MYSQL_ROW dept_row;  //  获取行首地址
	while((dept_row = dept_mysql.get_row(dept_res)))
	{
		Department dept;  //  临时变量保存数据
		//  row[i] 按照数据库中数据排列顺序
		dept.setId(atoi(dept_row[0]));
		deptid = dept.getId();
		dept.setName(dept_row[1]);
		//  存入向量 deptArr
		deptArr.push_back(dept);
	}
	//  员工数据
	Mysql emp_mysql(IP,USER,PWD,EMPLOYEE_DB);  //  搞Mysql对象
	MYSQL_RES *emp_res = emp_mysql.show(EMPLOYEE_TABLE);  //  获取 表employee 的二维表
	MYSQL_ROW emp_row;  //  获取行首地址
	while((emp_row = emp_mysql.get_row(emp_res)))
	{
		Employee emp;  //  临时变量保存数据
		//  row[i] 按照数据库中数据排列顺序
		emp.setId(atoi(emp_row[0]));
		empid = emp.getId();
		emp.setAge(atoi(emp_row[1]));
		emp.setName(emp_row[2]);
		emp.setSex(atoi(emp_row[3]));
		int dept_id = atoi(emp_row[4]);  //  员工所属部门ID
		//  存入向量 deptArr 的 empArr
		for(size_t i = 0; i < deptArr.size(); i++)
		{
			if(dept_id == deptArr[i].getId())
			{
				//  找到部门
				deptArr[i].empArr.push_back(emp);
				break;
			}
		}
	}
}

//  保存 deptArr、empArr 到 MySQL 表department employee
void ServiceModeImpl::save(vector<Department>& deptArr)
{
	//  先把 员工 存入 employee
	Mysql emp_mysql(IP,USER,PWD,EMPLOYEE_DB);  //  搞个Mysql对象
	Mysql dept_mysql(IP,USER,PWD,DEPARTMENT_DB);  //  搞个Mysql对象
	char buf[4096] = {};
	sprintf(buf,"truncate %s;",EMPLOYEE_TABLE);  //  清空表
	emp_mysql.input(buf);
	sprintf(buf,"truncate %s;",DEPARTMENT_TABLE);  //  清空表
	dept_mysql.input(buf);
	//  遍历所有部门
	for(size_t i = 0; i < deptArr.size(); i++)
	{
		//  遍历部门中所有员工，存入
		for(size_t j = 0; j < deptArr[i].empArr.size(); j++)
		{
			int sex = 0;
			if('w' == deptArr[i].empArr[j].getSex())
				sex = 0;
			else
				sex = 1;
			sprintf(buf,"insert into %s values(%d,%d,\"%s\",%d,%d);",EMPLOYEE_TABLE,deptArr[i].empArr[j].getId() ,deptArr[i].empArr[j].getAge(),deptArr[i].empArr[j].getName(), sex,deptArr[i].getId());
			emp_mysql.input(buf);
		}
		//  保存部门数据
		sprintf(buf,"insert into %s values(%d,\"%s\");",DEPARTMENT_TABLE,deptArr[i].getId() ,deptArr[i].getName());
		dept_mysql.input(buf);
	}
}

