#include<stdio.h>
#include<stdlib.h>
//计算txt文件中的字符数
void CharCount(char FileNum[100])
{
	int n1=0;
	FILE*pc=fopen(FileNum,"r");
	if(pc==NULL)
	{
		printf("open filed!");
		exit(1);
	}
	else
	{
	//循环遍历，字符数存入n1
		while(getc(pc)!=EOF)
			n1++;
		printf("字符数：%d",n1);
		fclose(pc);
	}
}
//计算txt文件中的单词数
void WordCount(char filtxt2[100])
{
	char ch1,ch2;
	int n2=0;
	FILE*pw=fopen(filtxt2,"r");
	if(pw==NULL)
	{
		printf("erro on open file!");
		exit(1);
	}
	ch1=getc(pw);
	ch2=getc(pw);
	while(true)
	{
		//判断是否连续两个逗号或两个空格
		if((ch1!=' '&&ch1!=',')&&(ch2==' '||ch2==','))
		{
			n2++;
		}
		//判断最后一个是否为空
		if((ch1!=' '&&ch1!=',')&&ch2==EOF)
		{
			n2++;
		}
		if(ch2==EOF)
			break;
		ch1=ch2;
		ch2=getc(pw);
	}
	printf("单词数：%d",n2);
	fclose(pw);
}
//判断输入是否符合条件，调用函数
void Determine(char par[3],char FileNum[100])
{
	if(par[0]=='-'&&par[1]=='c')
		CharCount(FileNum);
	else if(par[0]=='-'&&par[1]=='w')
		WordCount(FileNum);
	else
	{
		printf("erro on input operator!!!!!!!");
		exit(1);
	}
}
//主函数
int main()
{
	char par[3],FileNum[100];
	printf("请输入parameter:\n");
	scanf("%s",par);
	//char Filename[]="C://Users//Vinkylee//Desktop//软件工程//实验一Wordcount";
	printf("请输入input_file_name：\n");
	scanf("%s", FileNum);
	Determine(par,FileNum);
	return 0;
}