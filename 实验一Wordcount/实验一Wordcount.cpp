#include<stdio.h>
#include<stdlib.h>
//����txt�ļ��е��ַ���
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
	//ѭ���������ַ�������n1
		while(getc(pc)!=EOF)
			n1++;
		printf("�ַ�����%d",n1);
		fclose(pc);
	}
}
//����txt�ļ��еĵ�����
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
		//�ж��Ƿ������������Ż������ո�
		if((ch1!=' '&&ch1!=',')&&(ch2==' '||ch2==','))
		{
			n2++;
		}
		//�ж����һ���Ƿ�Ϊ��
		if((ch1!=' '&&ch1!=',')&&ch2==EOF)
		{
			n2++;
		}
		if(ch2==EOF)
			break;
		ch1=ch2;
		ch2=getc(pw);
	}
	printf("��������%d",n2);
	fclose(pw);
}
//�ж������Ƿ�������������ú���
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
//������
int main()
{
	char par[3],FileNum[100];
	printf("������parameter:\n");
	scanf("%s",par);
	//char Filename[]="C://Users//Vinkylee//Desktop//�������//ʵ��һWordcount";
	printf("������input_file_name��\n");
	scanf("%s", FileNum);
	Determine(par,FileNum);
	return 0;
}