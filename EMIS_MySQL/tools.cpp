#include "tools.h"
#include <getch.h>
#include "emis.h"

char get_cmd(char start,char end)
{
	puts("--------------------------");
	printf("请输入指令:");
	
	clear_stdin();
	for(;;)
	{
		char cmd = getch();
		if(start <= cmd && cmd <= end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}

void anykey_continue(void)		//	按任意键继续 功能
{
	clear_stdin();				//	清除输入缓冲区
	puts("按任意键继续...");
	getch();					//	获取任意按键
}

void clear_stdin(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
}

// 安全的字符串输入		数据过长返回NULL

char* get_str_chinese(char* str,size_t size)
{
	if(NULL == str || 1 >= size)
		return NULL;

	// 清理输入缓冲区
	clear_stdin();

	// 以安全的方式读取size-1个字符
	fgets(str,size,stdin);

	// 计算字符串的长度
	size_t len = strlen(str);

	if('\n' == str[0])
	{
		puts("输入为空！");
		return NULL;
	}
	// 判断最后一个字符是否是\n
	if('\n' == str[len-1])
		// 删除'\n'
		str[len-1] = '\0';
	else
	{
		puts("输入数据过长！");
		return NULL;
	}
	return str;	
}

char* get_str(char* str,size_t size)
{
	clear_stdin();							//	清除输入缓冲区
	size_t cnt = 0;
	while(cnt < size)						//	当输入个数小于总长度-1，进入循环
	{
		str[cnt] = getch();				//	获取按键
		
		if(10 == str[cnt])				//	遇到换行退出循环
		{
			break;
		}
		/*
		else if(27 == str[cnt])			//	遇到esc退出
		{
			return "\27";
		}
		*/
		else if(127 == str[cnt])			//	按下删除键，删除上一个字符
		{
			if(cnt > 0)
				cnt--;						//	删除时长度减1
			printf("\b \b");				//	光标向前移动
		}
		else
		{
			printf("%c",str[cnt]);
			cnt++;							//	输入字符正确，长度加1
		}
	}
	if(0 == cnt)
	{
		puts("输入数据为空！");
		return NULL;
	}
	if(size == cnt)
	{
		printf("\n");
		puts("输入数据过长！");
		return NULL;
	}
	str[cnt] = '\0';						//	在字符串最后加\0
	printf("\n");
	return str;
}
// 安全的密码输入
char* get_pwd(char* passwd,size_t size)
{
	clear_stdin();							//	清除输入缓冲区
	size_t cnt = 0;
	while(cnt < size)						//	当输入个数小于总长度-1，进入循环
	{
		passwd[cnt] = getch();				//	获取按键
		if(10 == passwd[cnt])				//	遇到换行退出循环
		{
			break;
		}
		/*
		else if(27 == str[cnt])			//	遇到esc退出
		{
			return "\27";
		}
		*/
		else if(127 == passwd[cnt])			//	按下删除键，删除上一个字符
		{
			if(cnt > 0)
				cnt--;						//	删除时长度减1
			printf("\b \b");				//	光标向前移动
		}
		else
		{
			cnt++;							//	输入字符正确，长度加1
			printf("*");					//	输入字符时显示*
		}
	}
	if(0 == cnt)
	{
		puts("输入数据为空！");
		return NULL;
	}
	if(size == cnt)
	{
		printf("\n");
		puts("输入数据过长！");
		return NULL;
	}
	passwd[cnt] = '\0';						//	在字符串最后加\0
	printf("\n");
	return passwd;
}

//	生产唯一管理员id
int get_mgrid(void)
{
	return ++mgrid;
}

//	生产唯一部门id
int get_deptid(void)
{
	return ++deptid;
}

//	生产唯一员工id
int get_empid(void)
{
	return ++empid;
}



