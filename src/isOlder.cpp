/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	int i, len1, len2, num1, dob1_char = 0, dob2_char = 0, j, date1 = 0, date2 = 0, month1 = 0, month2 = 0, year1 = 0, year2 = 0;
	for (len1 = 0; dob1[len1] != '\0'; len1++);
	for (len2 = 0; dob2[len2] != '\0'; len2++);
	year1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + dob1[9] - '0';
	year2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + dob2[9] - '0';
	month1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
	month2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
	date1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
	date2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
	if ((month1 == 1) || (month1 == 3) || (month1 == 5) || (month1 == 7) || (month1 == 8) || (month1 == 10) || (month1 == 12))
	{
		if (date1 > 31)
			return -1;
	}
	else if ((month1 == 4) || (month1 == 6) || (month1 == 9) || (month1 == 11))
	{
		if (date1 > 30)
			return -1;
	}
	else if (month1 == 2)
	{
		if (year1 % 4 == 0)
		{
			if (year1 % 100 == 0)
			{
				if (year1 % 400 == 0)
				{
					if (date1 > 29)
						return -1;
				}
				else
				{
					if (date1 > 28)
						return -1;
				}
			}
			else
			{
				if (date1 > 29)
					return -1;
			}
		}
		else
		{
			if (date1 > 28)
				return -1;
		}
	}
	else
		return -1;
	if ((month2 == 1) || (month2 == 3) || (month2 == 5) || (month2 == 7) || (month2 == 8) || (month2 == 10) || (month2 == 12))
	{
		if (date2 > 31)
			return -1;
	}
	else if ((month2 == 4) || (month2 == 6) || (month2 == 9) || (month2 == 11))
	{
		if (date2 > 30)
			return -1;
	}
	else if (month2 == 2)
	{
		if (year1 % 4 == 0)
		{
			if (year1 % 100 == 0)
			{
				if (year1 % 400 == 0)
				{
					if (date2 > 29)
						return -1;
				}
				else
				{
					if (date2 > 28)
						return -1;
				}
			}
			else
			{
				if (date2 > 29)
					return -1;
			}
		}
		else
		{
			if (date2 > 28)
				return -1;
		}
	}
	else
		return -1;
	for (i = 0, j = 0; i < len1, j<len2; i++, j++)
	{
		if (dob1[i] - '0' <= 9)
			dob1_char++;
		else
			return -1;
		if (dob2[j] - '0' <= 9)
			dob2_char++;
		else
			return -1;
	}
	if (len1 == 10 && len2 == 10)
	{
		if (dob1_char == 10 && dob2_char == 10)
		{
			if (year1 == year2)
			{
				if (month1 > 12 || month2 > 12)
					return -1;
				else if (month1 == month2)
				{
					if (date1 < date2)
						return 1;
					else if (date1 > date2)
						return 2;
					else
						return 0;
				}
				else if (month1 < month2)
					return 1;
				else
					return 2;
			}
			else if (year1 < year2)
				return 1;
			else
				return 2;
		}
		else
			return -1;
	}
	else
		return -1;
}
