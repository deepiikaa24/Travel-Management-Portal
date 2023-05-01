#include <stdio.h>
#include <string.h>


struct user {
    char place[100];
    int nooftickets;
    int price;
};

struct login{
    char username[100];
    char password[100];
};

int getFileSize(FILE* fp) {
    if (fp == NULL) {
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    
    return ftell(fp);
}
void adduser()
{
    struct login i;
    char username[100];
    char password[100];
    FILE *fp ; 
    fp = fopen("fileName.txt", "a");
    printf("\n ENTER a username ");
	scanf("%s", i.username);
    printf("\n ENTER a password ");
    scanf("%s", i.password);
    int fSize = getFileSize(fp);
    if (fSize > 0) {
        fprintf(fp, "\n");
    } else if (fSize == -1) {
        printf("\n File is null ");
    }
    fprintf(fp, "%s,%s", i.username, i.password);
    fclose(fp);
}


int login()
{
    struct login i;
    FILE *fp ;
    fp = fopen("fileName.txt", "r");
	char c[100],t1[100],t2[100];
	printf("\n ENTER username and password ");
	scanf("%s",t1);
	scanf("%s",t2);
	strcat(strcat(t1,","),t2);
	while(fgets(c,100,fp)!=NULL)
	{
		
		char *v=strtok(c,"\n");
	 	if(strcmp(v,t1)==0)
		{
		printf("\n Successfuly logged in ");
        return 1;
		break;
		}
    }

	
	
    fclose(fp);
    
        }



void BookTicket()
{
    struct user s[2];
    int i;
    FILE *fp ;
    char a[100];
    char tb[100]=".txt";
    printf("\n ENTER the username ");
    scanf("%s",a);
    strcat(a,tb);
    fp = fopen(a, "w");
    printf("\n ENTER the name of your destination and the Number of tickets ");
    for(i=0;i<1;i++)
    {scanf("%s",&s[i].place);   
    scanf("%d",&s[i].nooftickets);
    if(strcmp(s[i].place,"Thailand")==0)
    {
        s[i].price=0+s[i].nooftickets*30000;
    }
    else if((strcmp(s[i].place,"Malaysia")==0))
    {
        s[i].price=0+s[i].nooftickets*45000;
    }
    else if((strcmp(s[i].place,"Sri Lanka")==0))
    {
        s[i].price=0+s[i].nooftickets*25000;
    }
    else if((strcmp(s[i].place,"Nepal")==0))
    {
        s[i].price=0+s[i].nooftickets*32000;
    }
    else if((strcmp(s[i].place,"Singapore")==0))
    {
        s[i].price=0+s[i].nooftickets*50000;
    }
    else if((strcmp(s[i].place,"Bali")==0))
    {
        s[i].price=0+s[i].nooftickets*55000;
    }
    else if((strcmp(s[i].place,"Mauritius")==0))
    {
        s[i].price=0+s[i].nooftickets*65000;
    }
    else if((strcmp(s[i].place,"Dubai")==0))
    {
        s[i].price=0+s[i].nooftickets*40000;
    }
    else if((strcmp(s[i].place,"Maldives")==0))
    {
        s[i].price=0+s[i].nooftickets*60000;
    }
    
     fwrite(&s[i], sizeof(s[i]),1,fp);}
    fclose(fp);
    }

void CheckTicket()
{
    char a[100];
    struct user s[7];
    int i;
    printf("\n Enter the username ");
    scanf("%s",&a);
    char tb[100]=".txt";
    strcat(a,tb);
    FILE *fp;
    fp = fopen(a, "r");
    for (i=0; i<1; i++)
   {
      fread (&s[i], sizeof (s[i]) ,1,fp);
      printf("\n Destination  = %s\n", s[i].place);
      printf("\n No. of tickets  = %d\n", s[i].nooftickets);
      printf("\n Price %d\n",s[i].price);
   }

        
    
    fclose(fp);
}     
void CancelTicket()
{
    char a[100];
    struct user s[7];
    int i;
    printf("\n ENTER the username");
    scanf("%s",&a);
    char tb[100]=".txt";
    strcat(a,tb);
    FILE *fp;
    fp = fopen(a, "r");
    for (i=0; i<1; i++)
   {
       fread (&s[i], sizeof (s[i]) ,1,fp);
       printf(" \n %d will be refunded ",s[i].price);
   }
   fclose(fp);
   int c=remove(a);
   if(c==0)
   {
    printf("\n Your ticket is cancelled ");
   }
}
void ChangePassword()
{
	struct login i;
	FILE *fp, *fp2;
	fp = fopen("fileName.txt", "r+");
	char line[100],t1[100],t2[100];
	printf("\n ENTER your username ");
	scanf("%s",t1);
    printf("\n ENTER new password ");
	scanf("%s",t2);

	while(fgets(line, 100, fp) != NULL) {
		if (strstr(line, t1)) {
			printf("\n User found %s ", t1);
			strcat(t1,",");
			strcat(t2,"\n");
			strcat(t1,t2);
			// without the below line, fputs write in the next line
			fseek(fp, -strlen(line), SEEK_CUR);
			fputs(t1, fp);
			break;
		}
    	}
}
void showbrochure()
{
    FILE *fp;
    fp = fopen("brochure.txt", "r+");
    char ch[1000];
    while(fgets(ch,1000,fp)!=NULL)
    {
        printf("%s",ch);
    }

}

int main()
{
    int d;
    int ch1,ch2;
    int stop1=0;
    int stop2=0;
    printf("\n WELCOME TO THOMAS COOK TOURS AND TRAVELS" );
    printf("\n ENTER 1 if you're a new user, ENTER 2 if you would like to login, ENTER 3 to view our exciting brochure ");
    scanf("%d",&ch1);
    switch (ch1)
    {
	case 1:
		adduser();
        break;
	case 2:
		d=login();
		if(d==1) {
        		while(stop2!=1)
                {
                printf("\n ENTER 1 to book tickets, ENTER 2 to check tickets , ENTER 3 to change password , ENTER 4 to cancel ticket and ENTER 5 to log out ");
			   scanf("%d",&ch2);
			    if(ch2==1)
                {
					printf("\n ENTER the username ");
                    char ch3[1000];
                    scanf("%s",ch3);
                    FILE *fp ;
                    char tb[100]=".txt";
                    strcat(ch3,tb);
                    fp = fopen(ch3, "r");
                    if(fp==NULL)
                    {
                    printf("\n You can now book your tickets ");
                    BookTicket();
                    }
                    else
                    {printf("\n Sorry, please try again ");}}
			    else if(ch2==2)
					{CheckTicket();}
					
			    else if(ch2==3)
					{ChangePassword();}
                else if(ch2==4)
                    {CancelTicket();}
			        
                else if(ch2==5)
                    {stop2=1;}
            }
    
			} 
        break;
    case 3 :
          {showbrochure();
          break;}
    case 4 :
    break;
          
    }
    }
