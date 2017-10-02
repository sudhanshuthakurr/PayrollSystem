
//                         PAYROLL SYSTEM BY SUDHANSHU SINGH

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<ctype.h>
#include<process.h>
#include<dos.h>

  class LINES
   { public:   void LINE_HOR(int,int,int,char);
	       void LINE_VER(int,int,int,char);
	       void BOX(int,int,int,int,char);
	       void CLEARUP(void);
	       void CLEARDOWN(void);
   };


  class MENU
   { private:  void EDIT_MENU(void);
	       void INTRODUCTION(void);

     public:   void MAIN_MENU(void);
   };


   class EMPLOYEE
    { private: void ADD_RECORD(int,char[],char[],char[],int,
		int,int,char[],char,char,char,float,float);
	       void MODIFY_RECORD(int,char[],char[],char[],
	       char[],char,char,char,float,float);
	       void DELETE_RECORD(int);
	       int LASTCODE(void);
	       int CODEFOUND(int);
	       int RECORDNO(int);
	       int FOUND_CODE(int);
	       void DISPLAY_RECORD(int);
	       int VALID_DATE(int,int,int);
	       int code,dd,mm,yy;
	       char name[26],address[31],phone[10],desig[16];
	       char grade,house,convense;
	       float loan ,basic;

      public:  void NEW_EMPLOYEE(void);
	       void MODIFICATION(void);
	       void DELETION(void);
	       void DISPLAY(void);
	       void LIST(void);
	       void SALARY_SLIP(void);

   };


 void MENU :: MAIN_MENU(void)
   {
      char ch;
      EMPLOYEE E;
      LINES L;
      L.CLEARUP();
      while(1)
      {
	 clrscr();
	 L.BOX(24,7,53,9,218);
	 L.BOX(10,5,71,21,218);
	 L.BOX(11,6,70,20,219);
	 gotoxy(28,8);
	 cout<<"Employee Payroll System";
	 gotoxy(30,11);
	 cout<<"1:ENTER NEW RECORDS";
	 gotoxy(30,12);
	 cout<<"2:DISPLAY RECORDS";
	 gotoxy(30,13);
	 cout<<"3:LIST OF RECORDS";
	 gotoxy(30,14);
	 cout<<"4:SALARY SLIP ";
	 gotoxy(30,15);
	 cout<<"5:EDIT RECORDS";
	 gotoxy(30,16);
	 cout<<"0:QUIT";
	 gotoxy(30,18);
	 cout<<"ENTER YOUR CHOICE:";
	 ch=getch();
	 if(ch==27 || ch=='0')
		break;
	 else if(ch =='1')
	      E.NEW_EMPLOYEE();
	    else if(ch == '2')
	      E.DISPLAY();
		else if(ch=='3')
		    E.LIST();
		      else if(ch=='4')
			 E.SALARY_SLIP();
			   else if(ch== '5')
			      EDIT_MENU();
      }
    L.CLEARUP();
  }

 //this funtion control all the funtion int edit menu
  void MENU :: EDIT_MENU(void)
    {
       char ch;
       LINES L;
       EMPLOYEE E;
       while(1)
       {
	   clrscr();
	   L.BOX(28,8,49,10,218);
	   L.BOX(10,5,71,21,218);
	   L.BOX(11,6,70,20,219);
	   gotoxy(31,9);
	   cout<<"EMPLOYEE RECORD EDIT MENU";
	   gotoxy(30,13);
	   cout<<"1: DELETE RECORD";
	   gotoxy(30,14);
	   cout<<"2: MODIFY RECORD";
	   gotoxy(30,15);
	   cout<<"0: EXIT";
	   gotoxy(30,17);
	   cout<<"ENTER YOUR CHOICE :";
	   ch=getch();
	   if(ch==27 || ch=='0')
		break;
	   else if(ch=='1')
		 E.DELETION();
	      else if(ch=='2')
		 E.MODIFICATION();
       }
      L.CLEARDOWN();
 }

// this funtion draws the horizontal line

   void LINES :: LINE_HOR(int column1,int column2,int row,char c)
   {
	    for(column1;column1<=column2;column1++)
	      {
		  gotoxy(column1,row);
		  cout<<c;
	      }
   }

// this funtion draws the vertical line

   void LINES :: LINE_VER(int row1,int row2,int column,char c)
   {
	    for(row1;row1<=row2;row1++)
	      {
		  gotoxy(column,row1);
		  cout<<c;
	      }
   }

 //This funtion raws the box

  void LINES :: BOX(int column1,int row1,int column2,int row2,char c)
  {
	  char ch=218;
	  char c1,c2,c3,c4;
	  char l1=196,l2=179;
	  if(c==ch)
	  {   c1=218;
	      c2=191;
	      c3=192;
	      c4=217;
	      l1=196;
	      l2=179;
	  }
	  else
	  {   c1=c;
	      c2=c;
	      c3=c;
	      c4=c;
	      l1=c;
	      l2=c;
	  }
	  gotoxy(column1,row1);
	  cout<<c1;
	  gotoxy(column2,row1);
	  cout<<c2;
	  gotoxy(column1,row2);
	  cout<<c3;
	  gotoxy(column2,row2);
	  cout<<c4;
	  column1++;
	  column2--;
	  LINE_HOR(column1,column2,row1,l1);
	  LINE_HOR(column1,column2,row2,l1);
	  column1++;
	  column2--;
	  LINE_VER(row1,row2,column1,l2);
	  LINE_VER(row1,row2,column2,l2);
     }

 //This funtion clear the screen line by line upward

 void LINES :: CLEARUP(void)
 {
      for(int i=25;i>=1;i--)
	{
	    delay(20);
	    gotoxy(1,i);
	    clreol();
	}
  }

 //This funtion clear the screen line by line downward

 void LINES :: CLEARDOWN(void)
 {
      for(int i=1;i<=25;i++)
	{
	    delay(20);
	    gotoxy(1,i);
	    clreol();
	}
  }

//This funtion adds the given data in the employee's file
  void EMPLOYEE :: ADD_RECORD(int ecode,char ename[16],char eaddress[31],
		   char ephone[10],int d,int m,int y,char edesig[16],char
		   egrade,char ehouse,char econv,float eloan,float ebasic)

  {   fstream file;
      file.open("EMPLOYEE.DAT",ios::app);
      code=ecode;
      strcpy(name,ename);
      strcpy(address,eaddress);
      strcpy(phone,ephone);
      dd=d;
      mm=m;
      yy=y;
      strcpy(desig,edesig);
      grade=egrade;
      house=ehouse;
      convense=econv;
      loan=eloan;
      basic=ebasic;
      file.write((char*) this,sizeof(EMPLOYEE));
      file.close();
   }

// this function modify the given data in the employee's file
 void EMPLOYEE :: MODIFY_RECORD(int ecode,char ename[16],char eaddress[31],
		   char ephone[10],char edesig[16],char egrade,char
		   ehouse,char econv,float eloan,float ebasic)
   {
       int recno;
       recno=RECORDNO(ecode);
       fstream file;
       file.open("EMPLOYEE.DAT",ios::out,ios::ate);//eof upon opening of file
       strcpy(name,ename);
       strcpy(address,eaddress);
       strcpy(phone,ephone);
       strcpy(desig,edesig);
       grade=egrade;
       house=ehouse;
       convense=econv;
       loan=eloan;
       basic=ebasic;
       int location;
       location=(recno-1)*sizeof(EMPLOYEE);
       file.seekp(location);           //put pointer
       file.write((char*) this,sizeof(EMPLOYEE));
      file.close();
   }

  // This funtion deletes the record in the employee file
  // for the givin employee code
  void EMPLOYEE :: DELETE_RECORD(int ecode)
    {
	fstream file;
	file.open("EMPLOYEE.DAT",ios::in);
	fstream temp;
	temp.open("temp.dat",ios::out);
	file.seekg(0,ios::beg);   //get pointer
	while(!file.eof())
	{
	   file.read((char*) this,sizeof(EMPLOYEE));
	   if(file.eof())
	      break;
	   if(code!=ecode)
	    temp.write((char*) this,sizeof(EMPLOYEE));
	}
	file.close();
	temp.close();
	file.open("EMPLOYEE.DAT",ios::out);
	temp.open("temp.dat",ios::in);
	temp.seekg(0,ios::beg);
	while(!temp.eof())
	{
	       temp.read((char*) this,sizeof(EMPLOYEE));
	       if(temp.eof())
		    break;
	       file.write((char*) this,sizeof(EMPLOYEE));
	}
	file.close();
	temp.close();
   }

  //this funtion returns the last employee's code

  int EMPLOYEE :: LASTCODE(void)
   {
       fstream file;
       file.open("EMPLOYEE.DAT",ios::in);
       file.seekg(0,ios::beg);
       int count=0;
       while (file.read((char*) this,sizeof(EMPLOYEE)))
	    count=code;
       file.close();
       return count;
   }

 // this funtion returns 0 if the given code not found
  int EMPLOYEE :: FOUND_CODE(int ecode)
   {
	fstream file;
	file.open("EMPLOYEE.DAT",ios::in);
	file.seekg(0,ios::beg);
	int found=0;
	while (file.read((char*) this,sizeof(EMPLOYEE)))
	{
	    if(code==ecode)
	     {
	       found=1;
	       break;
	     }
	}
	file.close();
	return found;
    }

 //this funtion returns record no. of the given code

 int EMPLOYEE ::RECORDNO(int ecode)
   {   fstream file;
       file.open("EMPLOYEE.DAT",ios::in);
       file.seekg(0,ios::beg);
       int recno=0;
       while (file.read((char*) this,sizeof(EMPLOYEE)))
       {
	   recno++;
	   if(code==ecode)
	       break;
       }
       file.close();
       return recno;
   }

 // this funtion display the list if the employees
 void EMPLOYEE :: LIST(void)
    {   clrscr();
	int row=6,found=0,flag=0;
	char ch;
	gotoxy(31,2);
	cout<<"LIST OF EMPLOYEES";
	gotoxy(1,3);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout<<"CODE    NAME     PHONE   DOJ    DESIGATION     GRADE	  SALARY";
	gotoxy(1,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	fstream file;
	file.open("EMPLOYEE.DAT",ios::in);
	file.seekg(0,ios::beg);
	while (file.read((char*) this,sizeof(EMPLOYEE)))
	{
	      flag=0;
	      delay(20);
	      found =1;
	      gotoxy(2,row);
	      cout<<code;
	      gotoxy(6,row);
	      cout<<name;
	      gotoxy(31,row);
	      cout<<phone;
	      gotoxy(40,row);
	      cout<<dd<<"/"<<mm<<"/"<<yy;
	      gotoxy(52,row);
	      cout<<desig;
	      gotoxy(69,row);
	      cout<<grade;
	      if(grade!='E')
	       {
		    gotoxy(74,row);
		    cout<<basic;
	       }
	      else
	       {
		    gotoxy(76,row);
		    cout<<"-";
	       }
	       if(row==23)
	       {
		   flag=1;
		   row=6;
		   gotoxy(1,25);
		   cout<<"press any key to continue or press <ESC> to exit";
		   ch=getch();
		   if(ch==27)
		      break;
		   clrscr();
		   gotoxy(31,2);
		   cout<<"LIST OF EMPLOYEES AND RECORDS";
		   gotoxy(30,3);
		   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		   gotoxy(1,4);
		   cout<<"CODE   NAME	    PHONE    DOJ      DESIGATION   GRADE     SALARY";
		   gotoxy(1,5);
		   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	       }
	       else
		   row++;
	  }
	  if(!found)
	  {  gotoxy(5,10);
	     cout<<"Searched records not found";
	  }
	  if(!flag)
	  {  gotoxy(1,25);
	     cout<<"Press any key to continue...";
	     getche();
	  }
	  file.close();
     }

    //this funtion display the record of the employees
    void EMPLOYEE :: DISPLAY_RECORD(int ecode)
     {
       fstream file;
       file.open("EMPLOYEE.DAT",ios::in);
       file.seekg(0,ios::beg);
       while (file.read((char*) this,sizeof(EMPLOYEE)))
       {
	  if(code==ecode)
	  {   gotoxy(5,5);
	      cout<<"Employee code # "    <<code;
	      gotoxy(5,6);
	      cout<<"~~~~~~~~~~~~~~~~~~~~";
	      gotoxy(5,7);
	      cout<<"Name               :"<<name;
	      gotoxy(5,8);
	      cout<<"Address		:"<<address;
	      gotoxy(5,9);
	      cout<<"Phone no.		:"<<phone;
	      gotoxy(5,11);
	      cout<<"JOINING DATE";
	      gotoxy(5,12);
	      cout<<"~~~~~~~~~~~~~~~~~~~~";
	      gotoxy(5,13);
	      cout<<"Day 		:"<<dd;
	      gotoxy(5,14);
	      cout<<"Month		:"<<mm;
	      gotoxy(5,15);
	      cout<<"Year		:"<<yy;
	      gotoxy(5,17);
	      cout<<"Designation	:"<<desig;
	      gotoxy(5,18);
	      cout<<"Grade		:"<<grade;
	      if(grade!='E')
	      {
		   gotoxy(5,19);
		   cout<<"House(y/n)	:"<<house;
		   gotoxy(5,20);
		   cout<<"Convense(y/n)	:"<<convense;
		   gotoxy(5,22);
		   cout<<"Basic Salary	:"<<basic;
	      }
	      gotoxy(5,21);
	      cout<<"Loan		:"<<loan;
	  }
       }
       file.close();
     }


    // This funtion give code for the display of the record

   void EMPLOYEE :: DISPLAY(void)
    { 	 clrscr();
	 char t1[10];
	 int t2,ecode;
	 gotoxy(72,2);
	 cout<<"<0>=EXIT";
	 gotoxy(15,4);
	 cout<<"Enter the code number of employee : ";
	 gets(t1);
	 t2=atoi(t1);
	 ecode=t2;
	 if(ecode==0)
	    return;
	 clrscr();
	 if(!FOUND_CODE(ecode))
	 {
	     gotoxy(5,5);
	     cout<<"\7record not found";
	     getch();
	     return;
	 }
	DISPLAY_RECORD(ecode);
	gotoxy(5,25);
	cout<<"Press any key to continue...";
	getch();
    }
   // This funtion give data for the modification of the employee record
   void EMPLOYEE :: MODIFICATION(void)
    {
	clrscr();
	char ch,egrade,ehouse='N',econv='N';
	char ename[26],eaddress[31],ephone[10],edesig[16],t1[10];
	float t2=0.0,eloan=0.0,ebasic=0.0;
	int ecode,valid;
	gotoxy(72,2);
	cout<<"<0>=EXIT";
	gotoxy(5,5);
	cout<<"Enter the code of the employee";
	gets(t1);
	t2= atoi(t1);
	ecode=t2;
	if(ecode==0)
	   return;
	clrscr();
	if(!FOUND_CODE(ecode))
	    {
		 gotoxy(5,5);
		 cout<<"\7Record not found";
		 getch();
		 return;
	     }
	gotoxy(72,2);
	cout<<"<0>=EXIT";
	gotoxy(22,3);
	cout<<"MODIFICATION OF THE EMPLOYEE RECORD";
	DISPLAY_RECORD(ecode);
	do
	{     gotoxy(5,24);clreol();
	      cout<<"Do you want to modify this record(y/n)";
	      ch=getche();
	      ch=toupper(ch);
	      if(ch=='0')
		  return;
	}  while(ch!='Y' && ch!='N');
	if(ch=='N')
	    return;
	clrscr();
	fstream file;
	file.open("EMPLOYEE.DAT",ios::in);
	file.seekg(0,ios:: beg);
	while(file.read((char*) this ,sizeof(EMPLOYEE)));
	//{
	     //if(code==ecode)
	    // return;
	//}
	file.close();
	gotoxy(5,5);
	cout<<"Employee Code #"<<ecode;
	gotoxy(5,6);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(40,5);
	cout<<"JOINING DATE :";
	gotoxy(40,6);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(55,5);
	cout<<dd<<"/"<<mm<<"/"<<yy;
	gotoxy(5,7);
	cout<<"Name			:";
	gotoxy(5,8);
	cout<<"Address			:";
	gotoxy(5,9);
	cout<<"Phone no.		:";
	gotoxy(5,10);
	cout<<"designation		:";
	gotoxy(5,11);
	cout<<"Grade			:";
	gotoxy(5,14);
	cout<<"Loan			:";

	do
	{
	   valid=1;
	   gotoxy(5,25);clreol();
	   cout<<"Enter the name of the employee or <ENTER> FOR NO CHANGE";
	   gotoxy(20,7);clreol();
	   gets(ename);
	   strupr(ename);
	   if(ename[0]=='0')
		 return;
	   if(strlen(ename)>25)
	   {  valid=0;
	      gotoxy(5,25);clreol();
	      cout<<"\7Enter correctly (Range:1..25)";
	      getch();

	    }
	 } while(!valid);

	if(strlen(ename)==0)
	 {     strcpy(ename,name);
	       gotoxy(20,7);
	       cout<<ename;
	 }
	 do
	 {
	   valid=1;
	   gotoxy(5,25);clreol();
	   cout<<"Enter the Address of the employee or <ENTER> FOR NO CHANGE";
	   gotoxy(20,8);clreol();
	   gets(eaddress);
	   strupr(eaddress);
	   if(eaddress[0]=='0')
		 return;
	   if(strlen(eaddress)>25)
	   {  valid=0;
	      gotoxy(5,25);clreol();
	      cout<<"\7Enter correctly (Range:1..30)";
	      getch();

	    }
	 } while(!valid);
	 if(strlen(eaddress)==0)
	 {
	      strcpy(eaddress,address);
	      gotoxy(20,8);
	      cout<<eaddress;
	  }
	do
	{
	   valid=1;
	   gotoxy(5,25);clreol();
	   cout<<"Enter the Phone no. of the employee or <ENTER> FOR NO CHANGE";
	   gotoxy(20,9);clreol();
	   gets(ephone);
	   if(ephone[0]=='0')
		 return;
	   if((strlen(ephone)<7 && strlen(ephone)>0) || (strlen(ephone)>9))
	   {  valid=0;
	      gotoxy(5,25);clreol();
	      cout<<"\7Enter correctly ";
	      getch();

	    }
	 } while(!valid);
	 if(strlen(ephone)==0)
	 {
	     strcpy(ephone,phone);
	     gotoxy(20,9);
	     cout<<ephone;
	 }
	 do
	 {
	   valid=1;
	   gotoxy(5,25);clreol();
	   cout<<"Enter the Designation of the employee or <ENTER> FOR NO CHANGE";
	   gotoxy(20,10);clreol();
	   gets(edesig);
	   strupr(edesig);
	   if(edesig[0]=='0')
		 return;
	   if(strlen(edesig)>15)
	   {  valid=0;
	      gotoxy(5,25);clreol();
	      cout<<"\7Enter correctly (Range:1..15)";
	      getch();

	    }
	 } while(!valid);
	 if(strlen(edesig)==0)
	 {
	    strcpy(edesig,desig);
	    gotoxy(20,10);
	    cout<<edesig;
	 }
       do
       {   valid=1;
	   gotoxy(5,25);clreol();
	   cout<<"Enter the Grade of the employee(A,B,C,D,E) or <ENTER> FOR NO CHANGE";
	   gotoxy(20,11);clreol();
	   egrade=getche();
	   egrade=toupper(egrade);
	   if(egrade=='0')
		  return;
	   if(egrade==13)
	   {
	       egrade=grade;
	       gotoxy(20,11);
	       cout<<grade;
	    }

	 }  while(egrade< 'A' || egrade >'E');
	 if(egrade!='E')
	 {
	      gotoxy(5,12);
	      cout<<"House(y/n)	    :";
	      gotoxy(5,13);
	      cout<<"Convense(y/n)  :";
	      gotoxy(5,15);
	      cout<<"Basic salary   :";
	      do
	      {  gotoxy(5,25);clreol();
		 cout<<"ALLOTED HOUSE ALLOWANCE ?or <ENTER> FOR NO CHANGE";
		 gotoxy(20,12);clreol();
		 ehouse=getche();
		 ehouse=toupper(ehouse);
		if(ehouse=='0')
		  return;
		if(egrade==13)
		 {
		    ehouse=house;
		    gotoxy(20,12);
		    cout<<ehouse;
		 }

		 }  while(ehouse!='Y' && ehouse!='N');
       do
       {
	   gotoxy(5,25);clreol();
	   cout<<"ALLOTED CONVENSE ALLOWANCE or <ENTER> FOR NO CHANGE";
	   gotoxy(20,13);clreol();
	   econv=getche();
	   econv=toupper(econv);
	   if(econv=='0')
		  return;
	   if(econv==13)
	   {
	       econv=convense;
	       gotoxy(20,13);
	       cout<<econv;
	    }

	 }  while(econv!='Y' && econv!='N');

      }
     do
     {
	   valid=1;
	   gotoxy(5,25);clreol();
	   cout<<"ENTER LOAN AMOUNT or <ENTER> FOR NO CHANGE";
	   gotoxy(22,14);clreol();
	   gets(t1);
	   t2=atof(t1);
	   eloan=t2;
	   if(eloan>50000)
	   {
		 valid=0;
		 gotoxy(5,25);clreol();
		 cout<<"\7SHOULD NOT GREATER THAN 50000";
		 getch();
	   }
       }while(!valid);
       if(strlen(t1)==0)
       {    eloan=loan;
	    gotoxy(22,14);
	    cout<<eloan;
       }
       if(egrade!='E')
       {
	 do
	   {
	      valid=1;
	      gotoxy(5,25);clreol();
	      cout<<"ENTER BASIC SALARY or <ENTER> FOR NO CHANGE";
	      gotoxy(22,15);clreol();
	      gets(t1);
	      t2=atof(t1);
	      ebasic=t2;
	      if(t1[0]=='0')
		 return;
	      if(ebasic>50000)
		{
		 valid=0;
		 gotoxy(5,25);clreol();
		 cout<<"\7SHOULD NOT GREATER THAN 50000";
		 getch();
		}
	   }while(!valid);
		if(strlen(t1)==0)
		  { ebasic=basic;
		    gotoxy(22,15);
		    cout<<ebasic;
		  }
       }
       gotoxy(5,25);clreol();
       do
       {  gotoxy(5,18);clreol();
	  cout<<"Do you want to save (y/n)";
	  ch=getche();
	  ch=toupper(ch);
	  if(ch=='0')
	      return;
       }while(ch!='Y' && ch!='N');
       if(ch=='N')
	  return;
       MODIFY_RECORD(ecode,ename,eaddress,ephone,edesig,egrade,ehouse,econv,eloan,ebasic);
       gotoxy(5,23);
       cout<<"\7record Modified";
       gotoxy(5,25);
       cout<<"Press any key to continue...";
       getch();
   }
  // This funtion give code no of the employee to delete the employee record
    void EMPLOYEE :: DELETION(void)
    {
       clrscr();
       char t1[10],ch;
       int t2,ecode;
       gotoxy(72,2);
       cout<<"<0>=EXIT";
       gotoxy(5,5);
       cout<<"Enter code of the employee ";
       gets(t1);
       t2=atoi(t1);
       ecode=t2;
       if(ecode==0)
	   return;
       clrscr();
       if(!FOUND_CODE(ecode))
	{
	     gotoxy(5,5);
	     cout<<"\7Record not found";
	     getch();
	     return;
	}
       gotoxy(72,2);
       cout<<"<0>=EXIT";
       gotoxy(24,3);
       cout<<"DELETION OF THE EMPLOYEE RECORD ";
       DISPLAY_RECORD(ecode);
       do
	{  gotoxy(5,24);clreol();
	   cout<<"Do you want to delete this record (y/n)";
	   ch=getche();
	   ch=toupper(ch);
	   if(ch=='0')
		return;
	}while(ch!='Y' && ch!='N');
	if(ch=='N')
	   return;
	DELETE_RECORD(ecode);
	LINES L;
	L.CLEARDOWN();
	gotoxy(5,23);
	cout<<"\7Record Deleted";
	gotoxy(5,25);
	cout<<"Press any key to continue...";
	getch();
     }
    //This funtion returns 0 if the given data is invalid
    int EMPLOYEE :: VALID_DATE(int d1,int m1,int y1)
      {
	 int valid=1;
	 if(d1>31 || d1<1)
		valid=0;
	else
	if(((y1%4)!=0 && m1==2 && d1<28) || ((y1%4)==0 && m1==2 && d1>29))
		valid=0;
	else
	if((m1==4 || m1==6 || m1==9 || m1==11) && d1>30)
		valid=0;
	return valid;
    }

   //This funtion prints the salary slip for the employee
   void EMPLOYEE :: SALARY_SLIP(void)
    {
       clrscr();
       char t1[10];
       int t2,ecode,valid;
       gotoxy(72,2);
       cout<<"<0>=EXIT";
       gotoxy(5,5);
       cout<<"Enter code of the employee ";
       gets(t1);
       t2=atoi(t1);
       ecode=t2;
       if(ecode==0)
	   return;
       clrscr();
       if(!FOUND_CODE(ecode))
	{
	     gotoxy(5,5);
	     cout<<"\7Record not found";
	     getch();
	     return;
	}
	fstream file;
	file.open("EMPLOYEE.DAT",ios::in);
	file.seekg(0,ios::beg);
	while(file.read((char*) this,sizeof(EMPLOYEE)))
	 {
	     if(code==ecode)
	      break;
	 }
	file.close();
	int d1,m1,y1;
	struct date d;
	getdate(&d);
	d1=d.da_day;
	m1=d.da_mon;
	y1=d.da_year;
	char *mon[12]={"January","February","March","April","May","June","July","August","September","November","December"};
	LINES L;
	L.BOX(2,1,79,25,218);
	gotoxy(31,2);
	cout<<"KURUKSHETRA UNIVERSITY";
	L.LINE_HOR(3,78,3,196);
	gotoxy(34,4);
	cout<<"SALARY SLIP";
	gotoxy(60,4);
	cout<<"Date:  "<<d1<<"/"<<m1<<"/"<<y1;
	gotoxy(34,5);
	cout<<mon[m1-1]<<" , "<<y1;
	L.LINE_HOR(3,78,6,196);
	gotoxy(6,7);
	cout<<"Employee Name : "<<name;
	gotoxy(6,8);
	cout<<"Designation   : "<<desig;
	gotoxy(67,8);
	cout<<"Grade : " <<grade;
	L.BOX(6,9,75,22,218);
	L.LINE_HOR(10,71,20,196);
	int days,hours;
	if(grade=='E')
	 {
	      do
		{   valid=1;
		    gotoxy(10,21);
		    cout<<"ENTER THE NO. OF DAYS WORKED IN THE MONTH:";
		    gotoxy(10,11);
		    cout<<"No. of days	:";
		    gets(t1);
		    t2=atoi(t1);
		    days=t2;
		    if(!VALID_DATE(days,m1,y1))
		    {    valid=0;
			 gotoxy(10,21);
			 cout<<"\7ENTER CORRECTLY ";
			 getch();
			 gotoxy(10,11);
			 cout<<"		";
		    }
		}while(!valid);
		do
		{
		    valid=1;
		    gotoxy(10,21);
		    cout<<"ENTER THE NO. OF HOURS WORKED OVER TIME ";
		    gotoxy(10,13);
		    cout<<"No. of hours	:";
		    gets(t1);
		    t2=atoi(t1);
		    days=t2;
		    if(hours>8 || hours<0)
		    {    valid=0;
			 gotoxy(10,21);
			 cout<<"\7ENTER CORRECTLY ";
			 getch();
			 gotoxy(10,13);
			 cout<<"		";
		    }
		}while(!valid);
		gotoxy(10,21);
		cout<<"					";
		gotoxy(10,11);
		cout<<"					";
		gotoxy(10,13);
		cout<<"					";
	   }
	   gotoxy(10,10);
	   cout<<"Basic Salary		 Rs.";
	   gotoxy(10,12);
	   cout<<"ALLOWANCE";
	   if(grade!='E')
	   {
		gotoxy(12,13);
		cout<<"HRA	: Rs.";
		gotoxy(12,14);
		cout<<"CA	: Rs.";
		gotoxy(12,15);
		cout<<"DA	: Rs.";
	   }
	   else
	   {    gotoxy(12,13);
		cout<<"OT	: Rs.";
	   }
	   gotoxy(10,17);
	   cout<<"DEDUCTIONS";
	   gotoxy(12,18);
	   cout<<"LD	 : Rs.";
	   if(grade!='E')
	   {    gotoxy(12,19);
		cout<<"PF	: Rs.";
	   }
	   gotoxy(10,21);
	   cout<<"NET SALARY		: Rs.";
	   gotoxy(6,24);
	   cout<<"CASHIER";
	   gotoxy(68,24);
	   cout<<"EMPLOYEE";
	   float HRA=0.0,CA=0.0,DA=0.0,PF=0.0,LD=0.0,OT=0.0,allowance,deduction,netsalary;
	   if(grade!='E')
	   {
		 if(house=='Y')
		     HRA=(5*basic)/100;
		 if(convense=='Y')
		     CA=(2*basic)/100;
		 DA=(5*basic)/100;
		 PF=(2*basic)/100;
		 LD=(15*loan)/100;
		 allowance=HRA+CA+DA;
		 deduction=PF+LD;
	   }
	   else
	   {
		 basic=days*30;
		 LD=(15*loan)/100;
		 OT=hours*10;
		 allowance=OT;
		 deduction=LD;
	   }
	   netsalary=(basic+allowance)-deduction;
	   gotoxy(36,10);
	   cout<<basic;
	   if(grade!='E')
	   {
		  gotoxy(22,13);
		  cout<<HRA;
		  gotoxy(22,14);
		  cout<<CA;
		  gotoxy(22,15);
		  cout<<DA;
		  gotoxy(22,19);
		  cout<<PF;
	   }
	  else
	  {
		  gotoxy(22,13);
		  cout<<OT;
	  }
	  gotoxy(22,18);
	  cout<<LD;
	  gotoxy(33,15);
	  cout<<"Rs."<<allowance;
	  gotoxy(33,19);
	  cout<<"Rs."<<deduction;
	  gotoxy(36,21);
	  cout<<netsalary;
	  gotoxy(2,1);
	  getch();
      }


     //This function give data to add in the file
  void EMPLOYEE :: NEW_EMPLOYEE(void)
    {
      clrscr();
      char ch,egrade,ehouse='N',econv='N';
      char ename[26],eaddress[31],ephone[10],edesig[16],t1[10];
      float t2=0.0,eloan=0.0,ebasic=0.0;
      int d,m,y,ecode,valid;
      gotoxy(72,2);
      cout<<"<0>=EXIT";
      gotoxy(28,3);
      cout<<"ADDITION OF NEW EMPLOYEE";
      gotoxy(5,5);
      cout<<"Employee Code #";
      gotoxy(5,6);
      cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
      gotoxy(5,7);
      cout<<"Name     	     :";
      gotoxy(5,8);
      cout<<"Address	     :";
      gotoxy(5,9);
      cout<<"Phone no.	     :";
      gotoxy(5,11);
      cout<<"JOINING DATE";
      gotoxy(5,12);
      cout<<"~~~~~~~~~~~~~~~~~~~~";
      gotoxy(5,13);
      cout<<"Day 	      :";
      gotoxy(5,14);
      cout<<"Month		:";
      gotoxy(5,15);
      cout<<"Year		:";
      gotoxy(5,17);
      cout<<"Designation	:";
      gotoxy(5,18);
      cout<<"Grade		:";
      gotoxy(5,21);
      cout<<"Loan		:";
      ecode=LASTCODE()+1;
      if(ecode==1)
      {
	 ADD_RECORD(ecode,"null","null","null",0,0,0,"null",'n','n','n',0.0,0.0);
	 DELETE_RECORD(ecode);
      }
      gotoxy(21,5);
      cout<<ecode;
      do
      {         valid=1;
		gotoxy(5,25);clreol();
		cout<<"Enter the name of the Employee:";
		gotoxy(20,7);clreol();
		gets(ename);
		strupr(ename);
		if(ename[0]=='0')
		   return;
		if(strlen(ename)<1 || strlen(ename)>25)
		  {  valid=0;
		     gotoxy(5,25);
		     clreol();
		     cout<<"\7Enter correctly (Range: 1..25)";
		     getch();
		   }
       }while(!valid);
       do
       { 	valid=1;
		gotoxy(5,25);clreol();
		cout<<"Enter the address of the employee:";
		gotoxy(20,8);clreol();
		gets(eaddress);
		strupr(eaddress);
		if(eaddress[0]=='0')
		   return;
		if(strlen(eaddress)<1 || strlen(eaddress)>30)
		  {  valid=0;
		     gotoxy(5,25);
		     clreol();
		     cout<<"\7Enter correctly (Range: 1..30)";
		     getch();
		   }
	 }while(!valid);

	 do
	 { 	valid=1;
		gotoxy(5,25);clreol();
		cout<<"Enter Phone no. of the employee or press <ENTER> for none:";
		gotoxy(20,9);clreol();
		gets(ephone);
		if(ephone[0]=='0')
		   return;
		if(strlen(ephone)<7 && strlen(ephone)>0 || strlen(ephone)>9)
		  {  valid=0;
		     gotoxy(5,25);
		     clreol();
		     cout<<"\7Enter correctly ";
		     getch();
		   }
	 }while(!valid);
	 if(strlen(ephone)==0)
		strcpy(ephone,"-");
	 char tday[3],tmonth[3],tyear[5];
	 int td;
	 do
	 {    valid=1;
	      do
	      {	gotoxy(5,25);clreol();
		cout<<"ENTER DAY OF JOINING:";
		gotoxy(13,13);clreol();
		gets(tday);
		td=atoi(tday);  // converts string to integer
		d=td;
		if(tday[0]=='0')
		   return;

	      }while(d==0);

	 do
	 {    	gotoxy(5,25);clreol();
		cout<<"ENTER MONTH OF JOINING:";
		gotoxy(13,14);clreol();
		gets(tmonth);
		td=atoi(tmonth);  // converts string to integer
		m=td;
		if(tmonth[0]=='0')
		   return;

	 }	while(m==0);

	 do
	 {    	gotoxy(5,25);clreol();
		cout<<"ENTER YEAR OF JOINING:";
		gotoxy(13,15);clreol();
		gets(tyear);
		td=atoi(tyear);  // converts string to integer
		y=td;
		if(tyear[0]=='0')
		   return;

	 }	while(y==0);
	 if(d>31 || d<1)
	     valid=0;
	 else
	 if(((y%4)!=0 && m==2 && d>28) || ((y%4)==0 &&m==2 && d>29))
		valid =0;
	 else
	 if(m==4 || m==6 || m==9 || m==11 && d>30)
		valid=0;
	 else
	 if(y<1990 || y>2020)
		valid=0;
	 if(!valid)
	 {   valid=0;
	     gotoxy(5,25);clreol();

	     cout<<"\7Enter correctly";
	     getch();
	     gotoxy(13,14);clreol();
	     gotoxy(13,15);clreol();
	  }
      } while(!valid);
      do
      {      valid=1;
	     gotoxy(5,25);clreol();
	     cout<<"Enter the designation of the employee";
	     gotoxy(20,17);clreol();
	     gets(edesig);
	     strupr(edesig);
	     if(edesig[0]=='0')
		   return;
	     if(strlen(edesig)<1 || strlen(edesig)>15)
	     {
	       valid=0;
	       gotoxy(5,25);clreol();
	       cout<<"\7Enter correctly (range1..15)";
	       getch();

	      }
	} while(!valid);
	do
	{    	gotoxy(5,25);clreol();
		cout<<"Enter grade of the employee (A,B,C,D,E)";
		gotoxy(20,18);clreol();
		egrade=getche();
		egrade=toupper(egrade);
		if(egrade=='0')
		   return;

	 }  while(egrade<'A' || egrade>'E');
	 if(egrade!='E')
	 {
	    gotoxy(5,19);
	    cout<<"House(y/n)";
	    gotoxy(5,20);
	    cout<<"Covense(y/n)";
	    gotoxy(5,22);
	    cout<<"Basic salary	     :";
	 do
	  {
	    gotoxy(5,25);clreol();
	    cout<<"ENTER IF HOUSE ALLOWANCE IS ALLOTED TO THE EMPLOYEE OR NOT";
	    gotoxy(22,19);clreol();
	    ehouse=getche();
	    ehouse=toupper(ehouse);
	    if(ehouse=='0')
	       return;

	 }  while(ehouse!='Y' && ehouse!='N');

	 do
	  {
	    gotoxy(5,25);clreol();
	    cout<<"ENTER IF CONVENSE ALLOWANCE IS ALLOTED TO THE EMPLOYEE OR NOT";
	    gotoxy(22,20);clreol();
	    econv=getche();
	    econv=toupper(econv);
	    if(econv=='0')
	       return;

	 }  while(econv!='Y' && econv!='N');
	 do
	  { valid=1;
	    gotoxy(5,25);clreol();
	    cout<<"ENTER LOAN AMOUNT IF ISSUED";
	    gotoxy(22,21);clreol();
	    gets(t1);
	    t2=atof(t1);  //string to floating point
	    eloan=t2;
	    if(eloan>50000)
	    {    valid=0;
		 gotoxy(5,25);clreol();
		 cout<<"\7SHOULD NOT GREATER THAN 50000";
		 getch();
	    }
	   } while(!valid);
	if(egrade!='E')
	{
	  do
	  { valid=1;
	    gotoxy(5,25);clreol();
	    cout<<"ENTER BASIC SALARY OF THE EMPLOYEE";
	    gotoxy(22,22);clreol();
	    gets(t1);
	    t2=atof(t1);  //string to floating point
	    ebasic=t2;
	    if(t1[0]=='0')
		return;
	    if(ebasic>50000)
	    {    valid=0;
		 gotoxy(5,25);clreol();
		 cout<<"\7SHOULD NOT GREATER THAN 50000";
		 getch();
	    }
	   } while(!valid);
       }
       gotoxy(5,25);clreol();
       do
       {    gotoxy(5,24);clreol();
	    cout<<"Do you want to save (y/n)";
	    ch=getche();
	    ch=toupper(ch);
	    if(ch=='0')
	      return;
	}while(ch!='Y' && ch!='N');
	if(ch=='N')
	   return;
	ADD_RECORD(ecode,ename,eaddress,ephone,d,m,y,edesig,egrade,ehouse,econv,eloan,ebasic);
    }
    }
  //MAIN FUNCTION CALLING MAIN MENU
  void main()
  {
  clrscr();
  MENU menu;
  menu.MAIN_MENU();
  }