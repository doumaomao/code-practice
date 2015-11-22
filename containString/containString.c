// 如何最快判断短字符串b中的所有字符都在长字符串a中

//first

bool stringContain(char *a, char* b, int alength, int blength)
{
	int flag;
	for(int i=0;i < blength; i++)
	{
		flag = false;
		for(int j=0;j < alength; j++)
		{
			if(a[j] == b[i])
			{
				flag = true;
			}
		}
	}
	return flag;
}


//second
bool stringContain2(char* a, char* b, int alength, int blength)
{
	//fake code
	sort(a);
	sort(b);
	int pa=0;
	int pb=0;
	int flag  = false;
	for(pa=0,pb=0;pb<blength;pb++)
	{
		while(a[pa] < b[pb])
		{
			pa++;
		}
		if(a[pa] == b[pb])
		{
			flag =  true;
		}
		if(a[pa] > b[pb] || pa>=alength)
		{
			flag = false;
			return flag;
		}
	}
	return flag;
}

//third 
bool stringContain3(char * a,char * b,int alength,int blength)
{
	const int p[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,
						43,47,53,59,61,67,71,73,79,83,89,97,101};
	int f=1;
	for(int i=0;i< alength;i++)
	{
		int x=p[a[i]-'A'];
		if(f%x)
		{
			f = f*x;
		}
	}

	for(int j=0;j<blength;j++)
	{
		int x=p[b[j]-'A'];
		if(f%x)
		{
			return false;
		}
	}
	return true;
	
}

//fourth
//hash 位图思想
bool stringContain4(char * a,char * b,int alength,int blength)
{
	int hash=0;
	for(int i=0;i<alength;i++)
	{
		hash = hash | (1<< (a[i]-'A'));
	}
	for(int i=0;i<blength;i++)
	{
		if((hash && (1<<(b[i]-'A'))) == 0)
		{
			return false;
		}
	}
	return true;
}