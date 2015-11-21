//first 
void shiftLeftString(char* s,int n)
{
	int lefter = s[0];
	for(int i=1;i<n;i++)
	{
		s[i-1]=s[i];
	}
	s[n-1]=lefter;
}

void leftRotateString(char* s,int length, int pos)
{
	while(pos--)
	{
		shiftLeftString(s,length);
	}
}

//second 
void reverseString(char* s,int from, int to)
{
	while(from < to)
	{
		char t = s[from];
		s[from] = s[to];
		s[to] = t;
		from++;
		to--;
	}
}

void leftRotateString(char* s,int length, int pos)
{
	reverseString(s,0,m-1);
	reverseString(s,m,n-1);
	reverseString(s,0,n-1);

}

// new work
void leftRotateContent(char *s,int length)
{
		reverseString(s,0,length-1);
		int i=0;
		int begin;
		int end;
		while(s[i])
		{
			if(s[i] != ' ' )
			{
				begin=i;
				while(s[i]&&s[i]!=' ')
				{
					i++;
				}
				i=i-1;
				end=i;
			}
			reverseString(s,begin,end);
			i++;
		}
}


