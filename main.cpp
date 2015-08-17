#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
char square[100][100];
void menu();
void design();
void initiate();
void diary(char u[32]);
void initiate()
{
  for(int i=32,j=1;i<127;i++,j++)
	square[0][j]=i;
  for(i=32,j=1;i<127;i++,j++)
	square[j][0]=i;
  for(int k=1;k<95;k++)
	  {
	  for(j=1,i=32+(k-1);i<127;i++,j++)
		 {
		 square[k][j]=i;
		 }
		if(i>=127)
		  {
		  for(i=32,j=(j-1);j<95;j++,i++)
			 {
			  square[k][j]=i;
			 }
		  }
	 }

}
class entry
{
  protected:
  char diary[1100];
  char username[32];
  public:
  char date[8];
};
class newentry:public entry
{
  public:
  newentry(char u[32])
	{
	 strcpy(username,u);
	 cout<<"Enter date in MMDDYYYY format..(For example to write 20 jan 2012 write as ja202012)\n";
	 gets(date);
	 int j,x,posx,posy,n,m;
 char *temp,*body,*tem,*key;
 temp=new char[1000];
 key=new char[100];
 cout<<"enter diary entry for the day (End the diary entry by | and please no enter key :-) )\n";
 cin.get(temp,1000,'|');
 x=strlen(temp);
 tem=new char[x];
 strcpy(tem,temp);
 delete temp;
 cout<<endl;

 randomize();
 for(int i=0;i<99;i++)
  {
 for(int k=0;k<=10000;k++)
		j=random(95);
 j=j+32;
  key[i]=j;
	}

	cout<<endl<<endl;
	body=new char[x+100];
	for(i=0;i<50;i++)
		body[i]=key[i];

		for(n=0,m=0;m<x;m++,n++)
		{
			 if(n==100)
					n=0;
			for(i=0;i<95;i++)
			{
				  if(square[0][i]==key[n])
			  {	posx=i;
					break;
			  }
			}
			for(i=0;i<95;i++)
			{
				if(square[i][0]==tem[m])
				{
				  posy=i;
				  break;
				}
			}

			body[50+m]=square[posy][posx];

		}

	for(i=50;i<100;i++)
		body[x+i]=key[i];
 strcpy(diary,body);
 delete (tem);
 delete(key);
 delete(body);
 }
};
class oldentry:public entry
{
  public:
  int comp(char a[32])
		{
		  int k;
		  k=strcmp(a,username);
		  return k;
		}
  void initiate()
	  {
		decrypt();
		cout<<endl;
	  }
	void decrypt()
	{
	char *body2,*key2,*lol;
	int i,j,n,posx,posy;
  key2=new char[101];
  j=strlen(diary);
  lol=new char[j-99];
  body2=new char[j+1];
  strcpy(body2,diary);
  for(i=0;i<50;i++)
		key2[i]=body2[i];
	i=j-49;
  for(n=50;n<100;i++,n++)
	  {
	  key2[n]=body2[i];
	  }
	  key2[100]='\0';
      j=strlen(body2);
	i=j-99;
  for(j=0,n=0;j<i;j++,n++)
	  {
		  if(n==100)
			 n=0;
		 for(int k=0;k<95;k++)
			{
				  if(square[0][k]==key2[n])
			  {	posx=k;
					break;
			  }
			}
		 for(k=0;k<95;k++)
			 {
				  if(square[k][posx]==body2[j+50])
					 {
						 posy=k;
						 break;
					 }

			 }
		  lol[j]=square[posy][0];

	  }
  cout<<endl<<endl;
  for(int k=0;k<i;k++)
	  {
	  diary[k]=lol[k];
     cout<<diary[k];
	  }
  delete body2;delete key2;delete lol;
	}

};
class user
{
 protected:
 char name[130],password[132];
 int age;
 public:
 char username[8];
};
 class exist:public user
	{
	  public:
	  void decrypt(char str[132])
	  { //cout<<endl<<"decryption start";
		 char *body2,*key2,*lol;
		 int i,j,n,posx,posy;
		 key2=new char[100];
		 j=strlen(str);
		 //cout<<"value of j is \n"<<j;
		 lol=new char[j-99];
		 body2=new char[j+1];
		 strcpy(body2,str);
		 for(i=0;i<50;i++)
		  {
			key2[i]=body2[i];
		  }

		 for(n=50;n<100;i++,n++)
		  {
			key2[n]=body2[i];         //key is copied back
		  }
		 i=j-99;
		 //cout<<"the value od i is\n\n\n"<<i;
		 for(j=0,n=0;j<i;j++,n++)//decrypting using the key
			{
			  if(n==100)
				  {
				  n=0;
				  }
			  for(int k=0;k<95;k++)
					{
						if(square[0][k]==key2[n])
						 {
						  posx=k;
						  break;
						 }
					}
				for(k=0;k<95;k++)
					{
						if(square[k][posx]==body2[j+50])
						 {
						 posy=k;
						 break;
						 }

					 }
			 lol[j]=square[posy][0];

			}  //decrypted succesfully


	  for(int m=0;m<i;m++)  //strcpy(str,lol);
		 {
		 str[m]=lol[m];
		 }
		 str[i]='\0';
	  delete body2;
	  delete key2;
	  delete lol;
	  }
	  void initiate()
	  {
		decrypt(name);
		decrypt(password);
		cout<<endl;

	  }
	  int comp(char a[32])
		{
		  int k;
		  k=strcmp(a,password);
        
		  return k;
		}
	};
 class neu:public user
 {
	public:
	void encrypt(char str[232]);
	neu()
	{
		int i,j,l,k;
	  char cpassword[8];
	  cout<<"Enter Your First Name\n";
	  gets(name);
	  here:
	  cout<<"Enter a username (max 8 characters)\n";
	  gets(username);
	  if(strlen(username)>8||strlen(username)==0)
		 {
		  cout<<"Username too long or too short\n";
		  goto here;
		 }
	  ofstream a;
	  a.open(username,ios::noreplace|ios::binary|ios::out );
	  if(!a)
		 {
		 cout<<"Username already exists\n";
		 goto here;;
		 }
		 ha:
	  cout<<"Enter a password (Max 32 min 8 chars)\n";
	  for(i=0;i<32;i++)
	  {
		password[i]=getch();

		 if(password[i]==13)
		 {
		 password[i]='\0';
			 break;
		 }
		 cout<<"*";
	  }
	  if(strlen(password)<8)
		 {
		  cout<<"Passord too short\n";
		  goto ha;
		 }
	  cout<<"\nConfirm Your password\n";
		 for(i=0;i<32;i++)
	  {
		cpassword[i]=getch();

		 if(cpassword[i]==13)
		 {
		 cpassword[i]='\0';
			 break;
		 }
		 cout<<"*";
	  }
		 j=strcmp(password,cpassword);
		 if(j!=0)
			{
			 cout<<"\n The entered password doesnt match";
			 goto ha;
			}
		  delete cpassword;
	  cout<<"\nEnter age\n";
	  cin>>age;

	  human:
	  randomize();
	  for(k=0;k<1000;k++)
	 {
	  j=random(11);
	 }
	cout<<j<<" * ";
	for(k=0;k<1000;k++)
	{
	randomize();
	i=(rand()%10);
	}
	cout<<i<<" = "<<endl;
	cin>>k;
	l=j*i;
	if(l==k) {}
	else
	{
		cout<<"sorry entered answer doesnot matched\n";
		goto human;
	}
	  encrypt(name);

	  encrypt(password);
	}

  };

  void neu::encrypt(char str[238])
	 {
	  int j,x,posx,posy,n,m;
	  char *tem,*key,*body;
	  key=new char[100];
	  x=strlen(str);
	  tem=new char[x];
	  strcpy(tem,str);//str has been copied in tem for processing it has to be copied back to str;
	  randomize();
	for(int i=0;i<99;i++)
		{
		for(int k=0;k<=10000;k++)
		j=random(95);
		j=j+32;
		key[i]=j;
		}//key is created


		body=new char[x+100];//body strats to write the encrypted data
		for(i=0;i<50;i++)
		body[i]=key[i];

		for(n=0,m=0;m<x;m++,n++)
		{
			 if(n==100)
					n=0;
			for(i=0;i<95;i++)
			{
				  if(square[0][i]==key[n])
			  {	posx=i;
					break;
			  }
			}
			for(i=0;i<95;i++)
			{
				if(square[i][0]==tem[m])
				{
				  posy=i;
				  break;
				}
			}

			body[50+m]=square[posy][posx];

		}

	for(i=50;i<100;i++)
		body[x+i]=key[i];//body is written
	 strcpy(str,body);
	 delete body;delete key;delete tem;
  };
  void menu()
  {
	char a;int i;
	char username[8],password[32];
	design();
	cout<<"*                                                            *"<<endl;
	cout<<"*                    My secret Diary                         *"<<endl;
	cout<<"*                                                            *"<<endl;
	design();
	cout<<"\n\n1:EXISTING USER\n\n2:NEW USER\n\n3:EXIT\n\n";
 a=getch();
 switch (a)
 {
  case '1':{
				exist e;
				start:
				cout<<"Enter username\n";
				gets(username);
				cout<<"Enter password\n";
				for(i=0;i<32;i++)
				 {
					password[i]=getch();

					if(password[i]==13)
					  {
						password[i]='\0';
						break;
					  }

					cout<<"*";

				}
				ifstream o;
				o.open(username,ios::binary);
				if(!o)
				  {
				  cout<<endl<<"Username does not exist";
				  goto start;
				  }
				 o.read((char*)&e,sizeof e);
				 e.initiate();
				 i=e.comp(password);
				 if(i!=0)
					{
					  cout<<"Wrong password\Username Entered"<<endl;
					  goto start;
					}
				diary(username);
				o.close();
				break;
				}
  case '2':{
				neu n;
				ofstream o;
				o.open(n.username,ios::binary);
				o.write((char*)&n,sizeof(n));
				cout<<"Username Created successfully"<<endl;
				cout<<"Press any key to exit"<<endl;
				getch();
				o.close();
				exit(1);
				break;
			  }
  case  '3':{
				exit(1);
				break;
				}
  default : {
				clrscr();
				cout<<"enter correct choice"<<endl;

				menu();
				}
  }
  }
  void design()
  {
  cout<<"**************************************************************"<<endl;
  }
 void main()
 { initiate();
  menu();
 }
 void diary(char u[32])
 {
	int j;
	char a,date[8];
	diry:
  design();
	cout<<"*                                                            *"<<endl;
	cout<<"*                    My secret Diary                         *"<<endl;
	cout<<"*                                                            *"<<endl;
	design();
	cout<<"\n\n1:Make an Entry \n\n2:View an Entry\n\n3:Sign Out\n\n";
	a=getch();
	switch(a)
	{
		case '1':{
					 newentry n(u);
					 ofstream a;
					 a.open(n.date,ios::app|ios::binary);
					 a.write((char*)&n,sizeof n);
					 a.close();
					 cout<<"Diary entry registered successfully"<<endl;
					 cout<<"Press any key to continue"<<endl;
					 getch();
					 goto diry;

					}
		case '2':{
					 oldentry o;
					 cout<<"Enter date in MMDDYYYY format..(For example to write 20 jan 2012 write as ja202012)\n";
						gets(date);
					 ifstream a;
					 a.open(date,ios::binary);
					 while(!a.eof())
					 {
					 a.read((char*)&o,sizeof o);
					 j=o.comp(u);
						 if(j==0)
						 {
							o.initiate();
							break;
						 }
					 }
					 a.close();
					 break;
					}
		case '3':{
					 cout<<endl<<"\n\t\t\t\t\t\t\tBYE";
					 exit(1);
					}
		default : {
				clrscr();
				cout<<"enter correct choice"<<endl;
				goto diry;
				}

	}
 }