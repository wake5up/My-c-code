#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#if 0
//进程等待
//wait(int* status);
int main()
{
	pid_t pid=fork();
	if(pid<0)
	{
		printf("fork error");
		exit(-1);
	}
	else if(0==pid)
	{
		sleep(5);
		exit(0);
	}
	//pid_t wait(int *status);  status保存子进程的pid，然后返回pid
	wait(NULL);//等待子进程先退出，再执行父进程
	while(1)
	{
		printf("i am parent\n");
		sleep(1);
	}
	return 0;
}
#endif
#if 0
//进程等待:阻塞情况
int main()
{
	pid_t pid=fork();	
	if(pid<0)
	{
		printf("fork error");
		exit(-1);
	}
	else if(0==pid)
	{
		sleep(5);
		exit(0);
	}
	//pid_t waitpid(pid_t pid,int *status,int options);
	//可以等待任意一个子进程退出/等待指定子进程退出
	//pid:-1：等待任意子进程    >0：等待指定子进程
	//options： 0：阻塞等待子进程退出   WNOHANG：将waitpid设置为非阻塞
	//返回值：>0：退出的子进程的pid       ==0：当前没有子进程退出 
	//       <0：出错（pid非自己的子进程）
	int ret=waitpid(-1,NULL,0);
	if(ret<0)
	{
		printf("wait error");
	}
	printf("%d--%d\n",ret,pid);
	printf("i am parent\n");
	return 0;
}
#endif
int main()
{
	pid_t pid=fork();	
	if(pid<0)
	{
		printf("fork error");
		exit(-1);
	}
	else if(0==pid)
	{
		sleep(3);
		exit(0);
	}
	int ret,*statu;
	while(ret=waitpid(-1,&statu,WNOHANG)==0)
	{
		printf("wait!!!\n");
		sleep(1);
	}
	if(ret<0)
	{
		printf("waitpid error");
		return -1;
	}
	printf("pid:%d--%d\n",ret,pid);
	if(WIFEXITED(statu))
	{
		printf("pid:%d\n",WIFEXITED(statu));
	}
	while(1)
	{
		printf("i am parent\n");
		sleep(1);
	}
	return 0;
}
