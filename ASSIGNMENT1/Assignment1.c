/*
 ============================================================================
 Name        : Sets.c
 Author      : Poorva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	char name[25];
	char cric[25];
	char badm[25];
	int i,j,k,no,nc,nb,count;
	printf("Enter number of students\n");
	scanf("%d",&no);
	for(i=0;i<no;i++)
	{
		printf("Enter initial of name\n");
		scanf("%s",&name[i]);
	}
	printf("Enter number of students playing cricket\n");
	scanf("%d",&nc);
	for(i=0;i<nc;i++)
	{
		printf("Enter initial of name\n");
		scanf("%s",&cric[i]);
	}
	printf("Enter number of students paying badminton\n");
	scanf("%d",&nb);
	for(i=0;i<nb;i++)
	{
		printf("Enter initial of name\n");
		scanf("%s",&badm[i]);
	}
	printf("List of students : \nS : ");
	printf("{");
	for(i=0;i<no;i++)
	{
		if(i<(no-1))
			printf("%c,",name[i]);
		else
			printf("%c",name[i]);
	}
	printf("}\n");
	printf("Students playing Cricket :\nA : ");
	printf("{");
	for(i=0;i<nc;i++)
	{
		if(i<(nc-1))
			printf("%c,",cric[i]);
		else
			printf("%c",cric[i]);
	}
	printf("}\n");
	printf("Students playing Badminton :\nB : ");
	printf("{");
	for(i=0;i<nb;i++)
	{
		if(i<(nb-1))
			printf("%c,",badm[i]);
		else
			printf("%c",badm[i]);
	}
	printf("}\n");
	printf("Students playing both :\nC : ");
	printf("{");
	for(i=0;i<nc;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(cric[i]==badm[j])
			{
				if(i<(nc-1))
					printf("%c,",cric[i]);
				else
					printf("%c",cric[i]);
			}
			else
				continue;
		}
	}
	printf("}\n");
	printf("Students playing only Cricket :\nA-B : ");
	printf("{");
	for(i=0;i<nc;i++)
	{
		count=0;
		for(j=0;j<nb;j++)
		{
			if(cric[i]==badm[j])
				count++;
			else
				continue;
		}
		if(count==0)
		{
			if(i<(nc-1))
				printf("%c,",cric[i]);
			else
				printf("%c",cric[i]);
		}
	}
	printf("}\n");
	printf("Students playing only Badminton :\nB-A : ");
	printf("{");
	for(i=0;i<nb;i++)
	{
		count=0;
		for(j=0;j<nc;j++)
		{
			if(badm[i]==cric[j])
				count++;
			else
				continue;
		}
		if(count==0)
		{
			if(i<(nb-1))
				printf("%c,",badm[i]);
			else
				printf("%c",badm[i]);
		}
	}
	printf("}\n");
	printf("Students playing neither Cricket nor Badminton :\n(A U B U C)' : ");
	printf("{");
	for(i=0;i<no;i++)
	{
		count=0;
		for(j=0;j<nc;j++)
		{
			if(name[i]==cric[j])
				count++;
			else
				continue;
		}
		for(k=0;k<nb;k++)
		{
			if(name[i]==badm[k])
				count++;
			else
				continue;
		}
		if(count==0)
		{
			if(i<(no-1))
				printf("%c,",name[i]);
			else
				printf("%c",name[i]);
		}
	}
	printf("}\n");
	printf("Students playing either cricket or badminton or both :\n(A U B U C) : ");
	printf("{");
	for(i=0;i<nc;i++)
		printf("%c,",cric[i]);
	for(i=0;i<nb;i++)
	{
		count=0;
		for(j=0;j<nc;j++)
			{
			if(badm[i]==cric[j])
				count++;
			}
		if(count==0)
		{
			if(i<(nb-1))
				printf("%c,",badm[i]);
			else
				printf("%c",badm[i]);
		}
	}
	printf("}\n");
	return 0;
}
