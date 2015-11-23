//permutation
#include<iostream>
#include<string>
//first 全排列

void alllistString(char* str,char* perBegin)
{
	if(str == NULL || perBegin ==NULL)
	{
		return;
	}

	if(*perBegin == '\0')
	{
		count<<str<<endl;
	}
	else
	{
		for(char *pch=perBegin; *pch != '\0'; ++pch)
		{
			char temp = *pch;
			*pch = *perBegin;
			*perBegin = temp;

			alllistString(str,perBegin+1);

			temp = *pch;
			*pch = *perBegin;
			*perBegin = temp;
		}
	}

	
}

//second全组合位图思想
void allcombinationString(char* str)
{
	if(str == NULL)
	{
		return ;
	}
	int len = strlen(str);
	int n = 1<<len;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<len;j++)
		{
			int temp = i;
			if(temp & (1<<j))//对应位置上为1，这输出字符
			{
				printf("%c",*(str+j));
			}
		}
		printf("\n");
	}
}



