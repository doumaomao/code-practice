char* strrev(const char* str)
{
	if (NULL == str)
	{
		return str;
	}
	char* tmp = new char[strlen(str)+1];
	strcpy(tmp,str);
	char* ret  = tmp;
	char* p = tmp + strlen(str)-1;
	
	while(p>tmp)
	{
		*p = *p + *tmp;
		*tmp = *p - *tmp; //*tmp = *p
		*p = *p - *tmp; //*p = *tmp

		--p;
		++tmp;
	}

	return ret;


}