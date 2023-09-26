#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

char get_cmd(char start,char end);				//	只输入start到end之间的字符
void anykey_continue(void);						//	按任意键继续 功能
void clear_stdin(void);							//	清理输入缓冲区
char* get_str_chinese(char* str,size_t size);	//	安全输入中文
char* get_str(char* str,size_t size);			//	安全输入字符串
char* get_pwd(char* passwd,size_t size);		//	安全的密码输入

//	生产唯一管理员id
int get_mgrid(void);
//	生产唯一部门id
int get_deptid(void);
//	生产唯一员工id
int get_empid(void);

#endif
