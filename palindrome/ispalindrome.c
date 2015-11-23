bool ispalindrome(char* s, int length)
{
	if(s==null || length < 1)
	{
		return false;
	}

	const char* front,*back;

	front = s;
	back = s + n - 1;

	while(front < back)
	{
		if( *front != *back)
		{
			return false;
		}
		++front;
		--back;
	}
	return true;
}
