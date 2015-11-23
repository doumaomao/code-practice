int maxpalindrome(char* s,int length)
{
	int i,j,max,c;
	if(s==0 || length < 1)
	{
		return 0;
	}
	max = 0;

	for(i=0;i<length;i++)
	{
		for(j=0;(i-j>=0)&&(i+j<n);j++)
		{
			if(s[i-j] != s[i+j])
			{
				break;
			}
			c = j*2+1;
		}
		if(c>max)
			max = c;


		for(j=0;(i-j>=0)&&(i+j+1<n);j++)
		{
			if(s[i-j] != s[s+j+1])
				break;
			c = j*2+2;
		}
		if(c > max)
			max = c;
	}
	return max;
}
