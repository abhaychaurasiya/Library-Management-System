// header files declaration
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
// functions declaration
void returnfunc(void);
void mainmenu(void);
void add_a_book(void);
void delete_a_book(void);
void edit_a_book(void);
void search_a_book(void);
void issue_section(void);
void book_record(void);
void Password();
void takeexit(void);
int getdata();
int checkid(int);
int time(void);
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
};
struct books a;
// global variables declaration
FILE *fp,*ft,*fs;
int s;
char findbook;
char category[][20]={"Action","Adventure","Comic","Novel","Crime","Drama","Historical","Mystery","Science-Fiction","Biography"};
// main function
int main()
{
   time();
   gotoxy(0,3);
   textbackground(BLACK);
   textcolor(YELLOW);
   printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
   gotoxy(0,4);
   printf("------------------------------------------");
  // Password();
   mainmenu();
   getch();
   return 0;
}
// exp. of time
int time(void)
{
time_t t;
time(&t);     c
gotoxy(42,2);
printf("Date and time: %s",ctime(&t));
return 0 ;
}
// exp. of password
/*void Password(void)
{
	int i,choice;
    char username[15];
    char password[10];
    system("cls");
	gotoxy(17,5);
    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
    gotoxy(17,6);
    printf("------------------------------------------");
    time();
    gotoxy(25,8);
    printf("!! Password Protected !!");
    gotoxy(28,10);
    printf("Enter username: ");
    scanf("%s",&username);
    gotoxy(28,12);
    printf("Enter password: ");
    for(i=0;i<4;i++)
	{
	password[i]=getch();
	printf("*");
	}
    //scanf("%d",&password);
	gotoxy(28,14);
	printf("Press enter to login...");
	getch();
	 if(strcmp(username,"abhay")==0)
	  {
	   if(strcmp(password,"1234")==0)
		{
		gotoxy(28,16);
	printf("!! Welcome !!   Login Successfully!");
	gotoxy(28,18);
		printf("Press any key to continue...");
		getch();
		mainmenu();
	}
		else
		{
		 gotoxy(28,16);
	 printf("wrong password !");
	 gotoxy(28,18);
		 printf("try again? Yes or No");
	 if(getch()=='y')
	 Password();
	 if(getch()=='n')
	 exit(0);
	}
    }
    else if(strcmp(username,"abhinav")==0)
	{
	if(strcmp(password,"1234")==0)
		{
		gotoxy(28,16);
	printf("!! Welcome !!   Login Successfully!");
	gotoxy(28,18);
		printf("Press any key to continue...");
		getch();
		mainmenu();
	}
		else
		{
	 gotoxy(28,16);
	 printf("wrong password !");
	 gotoxy(28,18);
		 printf("try again? Yes or No");
	 if(getch()=='y')
	 Password();
	 if(getch()=='n')
	 exit(0);
	}
    }
    else if(strcmp(username,"ansh")==0)
	{
	if(strcmp(password,"1234")==0)
		{
	gotoxy(28,16);
	printf("!! Welcome !!   Login Successfully!");
	gotoxy(28,18);
		printf("Press any key to continue...");
		getch();
		mainmenu();
	}
		else
		{
	 gotoxy(28,16);
	 printf("wrong password !");
	 gotoxy(28,18);
		 printf("try again? Yes or No");
	}
	if(getch()=='y')
	Password();
	if(getch()=='n')
	exit(0);
    }
	else
	{
    gotoxy(28,16);
    printf("User doesn't exist !");
    gotoxy(28,18);
    printf("try again?  Yes or No : ");
    }
	if(getch()=='y')
    Password();
	if(getch()=='n')
    exit(0);
} */
// exp. of main menu
void mainmenu()
{
   clrscr();
	int i;
	gotoxy(17,5);
    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
    gotoxy(17,6);
    printf("------------------------------------------");
	time();
	gotoxy(28,8);
	printf("  || MAIN MENU ||");
	gotoxy(28,9);
	printf("-------------------");
	gotoxy(28,11);
	printf("1. Add A Book");
	gotoxy(28,12);
	printf("2. Delete A Book");
	gotoxy(28,13);
	printf("3. Search A Book");
	gotoxy(28,14);
	printf("4. Book-Issue Section");
	gotoxy(28,15);
	printf("5. View Book Record");
	gotoxy(28,16);
	printf("6. Edit Book Record");
	gotoxy(28,17);
	printf("7. Exit");
	gotoxy(28,19);
	printf("0. Change Theme : Black or White");
	gotoxy(28,22);
	printf("Select your choice: ");
	switch(getch())
	{
	case '1':
		add_a_book();
		break;
	case '2':
		delete_a_book();
		break;
	case '3':
		search_a_book();
	    break;
	case '4':
		issue_section();
	    break;
	case '5':
		book_record();
		break;
	case '6':
		edit_a_book();
		break;
	case '7':
	    {
		takeexit();
	    }
	case '0':
	    {
	    clrscr();
	    gotoxy(17,5);
	    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
	    gotoxy(17,6);
	    printf("------------------------------------------");
	   time();
	   gotoxy(28,8);
	   printf("  || THEMES ||");
	   gotoxy(28,9);
	   printf("-----------------");
	   gotoxy(28,11);
	     printf("1. Black Theme");
	     gotoxy(28,13);
	       printf("2. White Theme");
	       switch(getch())
	       {
		case '1':
		   textbackground(BLACK);
		   textcolor(YELLOW);
		   mainmenu();
		break;
		case '2':
		   textbackground(WHITE);
		   textcolor(BLUE);
		   mainmenu();
		default:
		{
		gotoxy(20,24);
		printf("ERROR : Please select from options which are mentioned above!");
		if(getch())
		mainmenu();
		}
	       }
	    }
	default:
		{
		gotoxy(15,22);
		printf("ERROR : Please select from options which are mentioned above!");
		if(getch())
		mainmenu();
		}
    }
}
// exp. of add a book
void add_a_book(void)
{
    clrscr();
	int i;
	gotoxy(17,5);
    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
    gotoxy(17,6);
    printf("------------------------------------------");
	time();
	gotoxy(22,8);
	printf("   || SELECT  BOOK CATEGORY ||");
	gotoxy(22,9);
	printf("---------------------------------");
	gotoxy(20,11);
	printf("1. Action");
	gotoxy(20,13);
	printf("2. Adventure");
	gotoxy(20,15);
	printf("3. Comic");
	gotoxy(20,17);
	printf("4. Novel");
	gotoxy(20,19);
	printf("5. Crime");
	gotoxy(40,11);
	printf("6. Drama");
	gotoxy(40,13);
	printf("7. Historical");
	gotoxy(40,15);
	printf("8. Mystery");
	gotoxy(40,17);
	printf("9. Science-Fiction");
	gotoxy(40,19);
	printf("10. Biography");
	gotoxy(23,22);
	printf("0. Back to main menu");
	gotoxy(23,25);
	printf("Enter Your Choice :");
	scanf("%d",&s);
	if(s==0)
	mainmenu() ;
	clrscr();
	fp=fopen("Books.txt","ab+");
	if(getdata()==1)
	{
	a.cat=category[s-1];
	fseek(fp,0,SEEK_END);
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
	gotoxy(22,20);
	printf("Book Added Successfully !");
	gotoxy(22,22);
	printf("Want to add more ? Yes or No : ");
	if(getch()=='n')
	    mainmenu();
	else
	    clrscr();
	    add_a_book();
	}
}
// exp of getdata
int getdata()
{
	clrscr();
	int t;
	gotoxy(17,5);
	printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
	gotoxy(17,6);
	printf("------------------------------------------");
	time();
	gotoxy(22,8);
	printf("   Enter Book Information : ");
	gotoxy(22,9);
	printf("------------------------------");
	gotoxy(15,11);
	printf("Category:    %s",category[s-1]);
	gotoxy(15,13);
	printf("Book ID:     ");
	scanf("%d",&t);
	if(checkid(t) == 0)
	{
		gotoxy(22,15);
		printf("Error : The book id already exists !");
		getch();
		mainmenu();
		return 0;
	}
	a.id=t;
	gotoxy(15,14);
	printf("Book Name:   ");
	scanf("%s",a.name);
	gotoxy(15,15);
	printf("Author:      ");
	scanf("%s",a.Author);
	gotoxy(15,16);
	printf("Quantity:    ");
	scanf("%d",&a.quantity);
	gotoxy(15,17);
	printf("Price:       ");
	scanf("%f",&a.Price);
	gotoxy(15,18);
	printf("Rack No:     ");
	scanf("%d",&a.rackno);
	return 1;
}
// exp of checkid
int checkid(int t)
{
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.id==t)
	return 0;
    return 1;
}
// exp. of detete a book
void delete_a_book()
{
    clrscr();
    int d;
    char another='y';
    while(another=='y')
    {
	clrscr();
	gotoxy(17,5);
    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
    gotoxy(17,6);
    printf("------------------------------------------");
	time();
	gotoxy(22,8);
	    printf("Enter the Book ID to delete: ");
	scanf("%d",&d);
	fp=fopen("Books.txt","rb+");
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	    if(a.id==d)
	    {
	    gotoxy(15,10);
		printf("The Book is available !");
		gotoxy(15,12);
		printf("Book name is:      %s",a.name);
		gotoxy(15,13);
		printf("Rack No. is :      %d",a.rackno);
		findbook='t';
	    }
	}
	if(findbook!='t')
	{
		gotoxy(22,10);
	    printf("No record is found !");
	    if(getch())
	    mainmenu();
	}
	if(findbook=='t' )
	{
		gotoxy(20,16);
	    printf("Do you want to delete it ? Yes or No : ");
	    if(getch()=='y')
	    {
		ft=fopen("test.txt","wb+");
		rewind(fp);
		while(fread(&a,sizeof(a),1,fp)==1)
		{
		    if(a.id!=d)
		    {
			fseek(ft,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,ft);
		    }
		}
		fclose(ft);
		fclose(fp);
		remove("Books.txt");
		rename("test.txt","Books.txt");
		fp=fopen("Books.txt","rb+");
		if(findbook=='t')
		{
			gotoxy(22,18);
		    printf("The record is sucessfully deleted");
		gotoxy(22,20);
		    printf("Delete another record? Yes or No : ");
		}
		if(getch()=='y')
	    delete_a_book();
	    }
	else
	mainmenu();
	fflush(stdin);
	another=getch();
	}
	}
    mainmenu();
}
// exp. of search a book
void search_a_book()
{
    clrscr();
    int d;
	gotoxy(17,5);
    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
    gotoxy(17,6);
    printf("------------------------------------------");
	time();
	gotoxy(22,8);
	printf("   || SELECT SEARCH OPTION ||");
    gotoxy(22,9);
    printf("--------------------------------");
    gotoxy(22,11);
    printf("1. Search By ID");
    gotoxy(22,13);
    printf("2. Search By Name");
    gotoxy(22,15);
	printf("Enter Your Choice : ");
    fp=fopen("Books.txt","rb+");
    rewind(fp);
    switch(getch())
    {
	  case '1':
	{
	    clrscr();
		gotoxy(17,5);
    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
    gotoxy(17,6);
    printf("------------------------------------------");
	time();
	gotoxy(22,8);
	    printf("   || Search Books By Id ||");
	    gotoxy(22,9);
	    printf("------------------------------");
	    gotoxy(22,11);
	    printf("Enter the book id: ");
	    scanf("%d",&d);
	    while(fread(&a,sizeof(a),1,fp)==1)
	    {
		if(a.id==d)
		{
		    getch();
		    gotoxy(15,13);
		    printf("The Book is available");
		    gotoxy(15,15);
		    printf("ID:       %d",a.id);
		    gotoxy(15,16);
		    printf("Name:     %s",a.name);
		    gotoxy(15,17);
		    printf("Author:   %s ",a.Author);
		    gotoxy(15,18);
		    printf("Qantity:  %d ",a.quantity);
		    gotoxy(15,19);
		    printf("Price:    Rs.%.2f",a.Price);
		    gotoxy(15,20);
		    printf("Rack No:  %d ",a.rackno);
		    findbook='t';
	    }
	    }
	    if(findbook!='t')
	    {
	    gotoxy(22,13);
		printf("No Record Found !");
	    }
	    gotoxy(22,22);
	    printf("Try another search? Yes or No : ");
	    if(getch()=='y')
	    search_a_book();
	    else
	    mainmenu();
	    break;
	}
	case '2':
	{
	    char s[20];
	    clrscr();
	gotoxy(17,5);
    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
    gotoxy(17,6);
    printf("------------------------------------------");
	time();
	gotoxy(22,8);
	    printf("   || Search Books By Name ||");
	    gotoxy(22,9);
	    printf("--------------------------------");
	    gotoxy(22,11);
	    printf("Enter Book Name: ");
	    scanf("%s",s);
	    int d=0;
	    while(fread(&a,sizeof(a),1,fp)==1)
	    {
		if(strcmp(a.name,(s))==0)
		{
			gotoxy(15,13);
		    printf("The Book is available !");
		    gotoxy(15,15);
		    printf("ID:       %d",a.id);
		    gotoxy(15,16);
		    printf("Name:     %s",a.name);
		    gotoxy(15,17);
		    printf("Author:   %s",a.Author);
		    gotoxy(15,18);
		    printf("Qantity:  %d",a.quantity);
		    gotoxy(15,19);
		    printf("Price:    Rs.%.2f",a.Price);
		    gotoxy(15,20);
		    printf("Rack No:  %d ",a.rackno);
		}
	    }
	    if(d==0)
	    {
	    gotoxy(15,13);
		printf("No Record Found !");
	    }
	    gotoxy(15,22);
	    printf("Try another search? Yes or No : ");
	    if(getch()=='y')
	    search_a_book();
	    else
	    mainmenu();
	    break;
	}
	default :
	getch();
	search_a_book();
    }
    fclose(fp);
}
// exp. of issue section
void issue_section(void)
{
    int t;
    clrscr();
	gotoxy(17,5);
    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
    gotoxy(17,6);
    printf("------------------------------------------");
	time();
	gotoxy(22,8);
    printf("   || ISSUE SECTION ||");
    gotoxy(22,9);
    printf("-------------------------");
    gotoxy(22,11);
    printf("1. Issue a Book");
    gotoxy(22,13);
    printf("2. View Issued Book");
    gotoxy(22,15);
    printf("3. Search Issued Book");
    gotoxy(22,17);
    printf("4. Clear Issue Record");
    gotoxy(22,19);
    printf("Enter a Choice: ");
    switch(getch())
    {
	case '1':  // issue a book
		{
		clrscr();
		int c=0;
		char another='y';
		while(another=='y')
		{
			clrscr();
			gotoxy(17,5);
		    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
		    gotoxy(17,6);
		   printf("------------------------------------------");
		   time();
		   gotoxy(22,8);
			printf("   || Issue Book section ||");
			gotoxy(22,9);
			printf("------------------------------");
			gotoxy(22,11);
		    printf("Enter the Book Id:    ");
			scanf("%d",&t);
			fp=fopen("Books.txt","rb");
			fs=fopen("Issue.txt","ab+");
			if(checkid(t)==0)
			{
			    gotoxy(15,13);
			    printf("The book is available !");
			    gotoxy(15,15);
			    printf("Book name :           %s",a.name);
			    gotoxy(15,16);
			    printf("Books are in stock :  %d",a.quantity);
			    gotoxy(15,17);
			    printf("Enter Borrower name:  ");
			    scanf("%s",a.stname);
			    gotoxy(15,19);
			    printf("The Book of ID %d is issued to Mr. %s !",a.id,a.name);
			    fseek(fs,sizeof(a),SEEK_END);
			    fwrite(&a,sizeof(a),1,fs);
			    fclose(fs);
			    c=1;
			}
			if(c==0)
			{
			gotoxy(22,13);
			printf("No record found !");
			}
			gotoxy(22,21);
			printf("Issue any more ? Yes or No :");
			fflush(stdin);
			another=getche();
			fclose(fp);
		}
		break;
	}
	case '2': // view issued books
	{
		clrscr();
		int j=14;
		gotoxy(17,5);
		printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
		gotoxy(17,6);
		printf("------------------------------------------");
		time();
		gotoxy(22,8);
		printf("   || Issued book list ||");
		gotoxy(22,9);
		printf("----------------------------");
		gotoxy(5,11);
		printf("BORROWER NAME");
		gotoxy(30,11);
		printf("CATEGORY");
		gotoxy(45,11);
		printf("ID");
		gotoxy(60,11);
		printf("BOOK NAME");
		gotoxy(2,12);
		printf("----------------------------------------------------------------------");
	       fs=fopen("Issue.txt","rb");
		while(fread(&a,sizeof(a),1,fs)==1)
		{
			gotoxy(5,j);
			printf("%s",a.stname);
			gotoxy(30,j);
			printf("%s",a.cat);
			gotoxy(45,j);
			printf("%d",a.id);
			gotoxy(60,j);
			printf("%s",a.name);
			j=j+1;
		}
		fclose(fs);
		returnfunc();
	}
	break;
	case '3': // search issed book
		{
		clrscr();
		gotoxy(17,5);
		printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
		gotoxy(17,6);
		printf("------------------------------------------");
		time();
		gotoxy(22,8);
		printf("Enter Book ID: ");
		int p,c=0;
		char another='y';
		while(another=='y')
		{
			scanf("%d",&p);
			fs=fopen("Issue.txt","rb");
			while(fread(&a,sizeof(a),1,fs)==1)
			{
				if(a.id==p)
				{
					gotoxy(10,10);
					printf("The Book has taken by : Mr. %s",a.stname);
					getch();
					gotoxy(10,12);
					printf("The Book has taken by : Mr. %s",a.stname);
					c=1;
				}
			}
			fflush(stdin);
			fclose(fs);
			if(c==0)
			{
				gotoxy(22,10);
				printf("No Record Found !");
			}
			gotoxy(22,14);
			printf("Try Another Search? Yes or No : ");
			another=getch();
		}
	}
	break;
	case '4': // clear issue record
	{
		clrscr();
		int b;
		FILE *fg;
		char another='y';
		gotoxy(17,5);
		printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
		gotoxy(17,6);
		printf("------------------------------------------");
		time();
		while(another=='y')
		{
			gotoxy(22,8);
			printf("Enter book id to remove : ");
			scanf("%d",&b);
			fs=fopen("Issue.txt","rb+");
			while(fread(&a,sizeof(a),1,fs)==1)
			{
				if(a.id==b)
				{
					gotoxy(10,10);
					printf("The Book has taken by : Mr. %s",a.stname);
					findbook='t';
				}
				if(findbook=='t')
				{
					gotoxy(10,12);
					printf("Do You Want to Remove it? Yes or No :");
					if(getch()=='y')
					{
						fg=fopen("record.txt","wb+");
						rewind(fs);
						while(fread(&a,sizeof(a),1,fs)==1)
						{
							if(a.id!=b)
							{
							fseek(fs,0,SEEK_CUR);
							fwrite(&a,sizeof(a),1,fg);
							}
						}
						fclose(fs);
						fclose(fg);
						remove("Issue.txt");
						rename("record.txt","Issue.txt");
						gotoxy(10,14);
						printf("This issue record is cleared.");
				       }
				}
				if(findbook!='t')
				{
					gotoxy(10,10);
					printf("No Record Found !");
				}
			}
			gotoxy(22,16);
			printf("Delete any more? Yes or No :");
			another=getch();
		}
	}
	default:
		{
		gotoxy(22,8);
		printf("Wrong Entry !");
	getch();
	issue_section();
		}
	break;
   }
returnfunc();
}
// exp. of view book record
void book_record(void)
{
    clrscr();
    int i=0,j;
    gotoxy(17,5);
    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
    gotoxy(17,6);
    printf("------------------------------------------");
   time();
    gotoxy(25,8);
    printf("   || BOOK LIST ||");
    gotoxy(25,9);
    printf("---------------------");
    gotoxy(2,11);
    printf("CATEGORY");
    gotoxy(15,11);
    printf("ID");
    gotoxy(23,11);
    printf("BOOK NAME");
    gotoxy(38,11);
    printf("AUTHOR");
    gotoxy(50,11);
    printf("QUANTITY");
    gotoxy(62,11);
    printf("PRICE");
    gotoxy(72,11);
    printf("RACK NO.");
    gotoxy(1,12);
    printf("-------------------------------------------------------------------------------");
    j=14;
    fp=fopen("Books.txt","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
	gotoxy(2,j);
	printf("%s",a.cat);
	gotoxy(15,j);
	printf("%d",a.id);
	gotoxy(23,j);
	printf("%s",a.name);
	gotoxy(38,j);
	printf("%s",a.Author);
	gotoxy(50,j);
	printf("%d",a.quantity);
	gotoxy(62,j);
	printf("%.2f",a.Price);
	gotoxy(72,j);
	printf("%d",a.rackno);
	j=j+1;
	i=i+a.quantity;
      }
      gotoxy(22,25);
      printf("Total Books = %d",i);
      fclose(fp);
      returnfunc();
}
// exp. of edit a book
void edit_a_book(void)
{
	clrscr();
	int c=0;
	int d,e;
	gotoxy(17,5);
    printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
    gotoxy(17,6);
    printf("------------------------------------------");
	time();
	gotoxy(22,8);
	printf("|| BOOK EDIT SECTION ||");
	char another='y';
	while(another=='y')
	{
	gotoxy(22,10);
		printf("Enter Book Id to be edited : ");
		scanf("%d",&d);
		fp=fopen("Books.txt","rb+");
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			gotoxy(15,10);
			printf("The book is availble !");
			gotoxy(15,12);
			printf("Which data you want to modify ? ");
			gotoxy(15,14);
		    printf("1. ID");
		    gotoxy(15,15);
		    printf("2. Name");
		    gotoxy(15,16);
		    printf("3. Author");
		    gotoxy(15,17);
		    printf("4. Quantity");
		    gotoxy(15,18);
		    printf("5. Price");
		    gotoxy(15,19);
		    printf("6. Rack No.");
		    gotoxy(15,20);
		    printf("7. Full Record");
			switch(getch())
			{
				case '1':
				       clrscr();
					gotoxy(17,5);
					printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
					gotoxy(17,6);
					printf("------------------------------------------");
					time();
					gotoxy(22,8);
					printf("Enter new Book ID:   ");
					scanf("%d",a.id);
				break;
				case '2':
					clrscr();
					gotoxy(17,5);
					printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
					gotoxy(17,6);
					printf("------------------------------------------");
					time();
					gotoxy(22,8);
					printf("Enter new name:      ");
				    scanf("%s",a.name);
				break;
				case '3':
				       clrscr();
					gotoxy(17,5);
					printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
					gotoxy(17,6);
					printf("------------------------------------------");
					time();
					gotoxy(22,8);
					printf("Enter new Author:    ");
				    scanf("%s",a.Author);
				break;
				case '4':
				       clrscr();
					gotoxy(17,5);
					printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
					gotoxy(17,6);
					printf("------------------------------------------");
					time();
					gotoxy(22,8);
					printf("Enter new quantity:  ");
				    scanf("%d",&a.quantity);
				break;
				case '5':
					clrscr();
					gotoxy(17,5);
					printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
					gotoxy(17,6);
					printf("------------------------------------------");
					time();
					gotoxy(22,8);
					printf("Enter new price:     ");
				    scanf("%f",&a.Price);
				break;
				case '6':
					clrscr();
					gotoxy(17,5);
					printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
					gotoxy(17,6);
					printf("------------------------------------------");
					time();
					gotoxy(22,8);
					printf("Enter new rackno:    ");
				    scanf("%d",&a.rackno);
				break;
				case '7':
					clrscr();
					gotoxy(17,5);
					printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
					gotoxy(17,6);
					printf("------------------------------------------");
					time();
					gotoxy(15,8);
					printf("Enter new Book ID:   ");
					scanf("%d",a.id);
					gotoxy(15,9);
					printf("Enter new name:      ");
				    scanf("%s",a.name);
				    gotoxy(15,10);
				    printf("Enter new Author:    ");
				    scanf("%s",a.Author);
				    gotoxy(15,11);
				    printf("Enter new quantity:  ");
				    scanf("%d",&a.quantity);
				    gotoxy(15,12);
				    printf("Enter new price:     ");
				    scanf("%f",&a.Price);
				    gotoxy(15,13);
				    printf("Enter new rackno:    ");
				    scanf("%d",&a.rackno);
				break;
				default :
					{
					gotoxy(15,22);
			    printf("ERROR : Please select from options which are mentioned above!");
			if(getch())
			    mainmenu();
			    }
			}
			    gotoxy(22,15);
				printf("The record is modified Successfully !");
				fseek(fp,ftell(fp)-sizeof(a),0);
				fwrite(&a,sizeof(a),1,fp);
				fclose(fp);
				c=1;
			if(c==0)
			    gotoxy(22,15);
				printf("No record found !");
		}
		gotoxy(22,17);
		printf("Modify another Record ? Yes or No :");
		fflush(stdin);
		another=getch();
	}
		returnfunc();
 }
// exp. of return to main menu
void returnfunc(void)
{
    {
    gotoxy(22,25);
	printf("Press ENTER to return to main menu");
    }
    a:
    if(getch()==13)
    mainmenu();
    else
    goto a;
}
// exp. of take exit
void takeexit(void)
{
		clrscr();
		gotoxy(17,5);
		printf("   || PROJECT : BOOKSTORE MANAGEMENT ||");
		gotoxy(17,6);
		printf("------------------------------------------");
		time();
		gotoxy(25,8);
		printf("   || CONTRIBUTERS ||");
		gotoxy(25,9);
		printf("------------------------");
		gotoxy(18,11);
		printf("1. Abhay Chaurasiya        1850510001");
		gotoxy(18,13);
		printf("2. Abhinav Yadav           1850510002");
		gotoxy(18,15);
		printf("3. Ansh Saini              1850510008");
		gotoxy(18,17);
		printf("4. Bhaskar Tiwari          1850510012");
		gotoxy(18,19);
		printf("5. Suraj Pratap Singh      19BCS905");
		gotoxy(18,21);
		printf("6. Samarjeet               19BCS903");
		gotoxy(27,24);
		printf("|| THANK YOU ||");
		getch();
		exit(0);
}
