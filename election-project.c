#include<stdio.h>

int main()
{
	printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                Voting Machine                     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("                                                   TN ELECTIONS 2021");
    printf("\n\t\t\t----------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\tPOLLING BOOTH FOR VOTER ID 5400 TO 5600");
	char name[20];
	int i,j,ID;
	int Id_exist=0;
	char res;

	FILE *fp1,*fp2,*fp3,*fp4;
	fp1=fopen("ID's.txt","r");
	printf("\n\nENTER NAME : ");
	scanf("%s",name);
	printf("\nENTER ID NO. : ");
	scanf("%d",&ID);
	if(ID<5400 || ID>5600){
        printf("\n\nINVALID ID :| \n\n");
        return 0;
	}
	int arr[200];
	for( i=0;i<200;i++)
	fscanf(fp1,"%d",&arr[i]);
	fclose(fp1);
	for( j=0;j<i;j++)
	{
		if(ID==arr[j])
		{
			arr[j]=0;
			Id_exist=1;
		}
	}
	fp1=fopen("ID's.txt","w");
		for(i=0;i<200;i++)
		fprintf(fp1,"%d\n",arr[i]);
		fclose(fp1);

	if(Id_exist==0)
	{
		printf("\n\nYOU HAVE ALREADY CASTED YOUR VOTE :| \n\n");
		return 0;
	}
	int c=0,party;
	do
	{
	c++;
	printf("\nLIST OF PARTIES CONTESTING \n\n");
	printf("1-MNM\n");
	printf("2-DMK\n");
	printf("3-ADMK\n");
	printf("\nENTER YOUR CHOICE : ");
	scanf("%d",&party);
	}while((party<1 || party>3));
	int count;
	if(party==1)
	{
		fp2=fopen("MNM.txt","r");
		fscanf(fp2,"%d",&count);
		count++;
		fclose(fp2);
		fp2=fopen("MNM.txt","w");
		fprintf(fp2,"%d",count);
		fclose(fp2);
	}
	else if(party==2)
	{
		fp3=fopen("DMK.txt","r");
		fscanf(fp3,"%d",&count);
		count++;
		fclose(fp3);
		fp3=fopen("DMK.txt","w");
		fprintf(fp3,"%d",count);
		fclose(fp3);
	}
	else if(party==3)
	{
		fp4=fopen("ADMK.txt","r");
		fscanf(fp4,"%d",&count);
		count++;
		fclose(fp4);
		fp4=fopen("ADMK.txt","w");
		fprintf(fp4,"%d",count);
		fclose(fp4);
	}
	getchar();
	printf("\nYOU HAVE CASTED YOUR VOTE SUCCESSFULLY :) \n");

	printf("\nDO YOU WANT TO SEE THE RESULTS? (Y/N) : ");
	scanf("%c",&res);
	int mnm,dmk,admk;
	if(res=='y'|| res=='Y')
	{
		fp2=fopen("MNM.txt","r");
		fscanf(fp2,"%d",&mnm);
		fclose(fp2);
		fp3=fopen("DMK.txt","r");
		fscanf(fp3,"%d",&dmk);
		fclose(fp3);
		fp4=fopen("ADMK.txt","r");
		fscanf(fp4,"%d",&admk);
		fclose(fp4);
		printf("\nNO. OF VOTES CASTED TO EACH PARTY \n\n");
		printf("MNM = %d\n",mnm);
		printf("DMK = %d\n",dmk);
		printf("ADMK = %d\n",admk);
		return 0;
	}
	else
	printf("\nTHANK YOU FOR CASTING YOUR VOTE \n");
}
