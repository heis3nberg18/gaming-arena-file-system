#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<process.h>
using namespace std;

class admin
{
	public:
		   string pid,pname,pname1,price,pname_list[100],buffer1,name1;
		   int addr_list[100],count;
		   void create_gdata();
		   void packs();
		   void write_to_files();
		   void unpacks();
		   string extract_name();
		   int create_in();
		   void sort_in();
		   void read_from_file(int);
		   void delete_from_file(int);
		   void remove(string);
		   int search_index(string);
		   void search(string);
		   string compression(string);
		   string decompression(string);
		   void disp();
};
void admin::create_gdata()
{
	cout<<"product id:";
	cin>>pid;
	cout<<"product name:";
	cin>>pname;
	pname1=compression(pname);
	cout<<"price:";
	cin>>price;
}
void admin::packs()
{
 buffer1.erase();
 buffer1+=pid+"|"+pname1+"|"+price+"$"+"\n";
}
void admin::write_to_files()
{
  int pos;
  fstream file;
  file.open("pdata2.txt",ios::out|ios::app);
  pos=file.tellp();
  file<<buffer1;
  file.close();
  pname_list[++count]=pname;
  addr_list[count]=pos;
}
string admin::extract_name()
{
	string pid;
	int i=0;
	pid.erase();
	while(buffer1[i]!='|')
	 pid+=buffer1[i++];
	i++;
	pname.erase();
	while(buffer1[i++]!='|')
	 pname+=buffer1[i++];
	return pname;
}
int admin::create_in()
{
	fstream file;
	int pos,i;
	count=-1;
	string pid;
	file.open("pdata2.txt",ios::in);
	while(!file.eof())
	{
		pos=file.tellg();
		buffer1.erase();
		getline(file,buffer1);
		if(buffer1[0]!='*')
		{
			if(buffer1.empty());
			continue;
		/*	pname=extract_name();
			pname_list[++count]=pname;
			price_list[count]=price;
			addr_list[count]=pos;
		}
	}
	file.close();
	sort_in();
	return count;
} */
            int i=0;
			pid.erase();
			while(buffer1[i]!='|')
			pname+=buffer1[i++];
			pname_list[++count]=pname;
			addr_list[count]=pos;
		}
	}
	file.close();
for(i=0;i<=count;i++)
	{
		file<<pname_list[i]<<"\t"<<addr_list[i]<<"\t""\n";
	}	
	buffer1.erase();    



}
void admin::disp()
{
 /*   int i;
	cout << endl << "\t INDEX FILE" << endl;
	cout<<" \t \t PRODUCT DETAILS  \n";
	cout<<" \t \t .....................";
	for(i=0;i<=count;i++)
	    cout<<endl<<"\n\t \t \tproduct name: "<<pname_list[i]<<"\tprice:"<<price_list[i];
	cout<<"\n";
	cout<<" \t \t ..................... \n"; */
	int pos=0;
	fstream file;
	cout<<"\nPID\t\t PNAME\t\t\t  PRICE\tDIMENSION\n";
    cout<<"----------------------------------------------------\n";
	file.open("pdata2.txt",ios::in);
	while(!file.eof())
	{
		buffer1.erase();
		pos=file.tellg();
		getline(file,buffer1);
		if(buffer1.empty())continue;
		unpacks();
		string pname=decompression(pname1);
		cout<<pid<<"\t""\t"<<pname<<"\t\t"<<price<<"\n";
   } 
}
void admin::sort_in()
{
	int i,j,tempa;
	string tempn;
	for(i=0;i<=count;i++)
	  for(j=i+1;j<=count;j++)
	    if(pname_list[i]>pname_list[j])
	    {
	    	 tempn=pname_list[i];
	    	 pname_list[i]=pname_list[j];
	    	 pname_list[j]=tempn;
	    	 tempa=addr_list[i];
	    	 addr_list[i]=addr_list[j];
	    	 addr_list[j]=tempa;
		}
}
void admin::unpacks()
{
	int ch=1,i=0;
	pid.erase();
	while(buffer1[i]!='|')
	pid+=buffer1[i++];
	pname1.erase();
	i++;
	while(buffer1[i]!='|')
	pname1+=buffer1[i++];
	price.erase();
	i++;
	while(buffer1[i]!='|')
	price+=buffer1[i++];
}
int admin::search_index(string key)
{
  int low=0,high=count,mid=0,flag=0,pos;
  while(low<=high)
  {
   mid=(low+high)/2;
   if(pname_list[mid]==key)
   {
   flag=1;break;
   }
   if(pname_list[mid]>key)
   high=mid-1;
   if(pname_list[mid]<key)
   low=mid+1;
  }
 if(flag)
 return mid;
 else
 return-1;
}
string admin::compression(string pname)
{
  if(pname=="counterstrike")
   return "csgo";
  else if(pname=="callofduty")
   return "cod";
  else if(pname=="leagueoflegends")
   return "lol";
  else if(pname=="assassincreed")
   return "as";
  else if(pname=="playerunknownsbattleground")
   return "pubg";
  else if(pname=="rainbowsixseige")
return "rs6";
else if(pname=="grandtheftauto5")
return "gta";
else if(pname=="dota2")
return "d2";
else if(pname=="overwatch2016")
return "ov";
else if(pname=="minecraft")
return "mc";
else if(pname=="mortalkombat11")
return "mk";
else if(pname=="residentevil8")
return "re";
else
return pname;

}
string admin::decompression(string pname1)
{
if(pname1=="csgo")
return "counterstrike";
else if(pname1=="cod")
return "callofduty";
else if(pname1=="lol")
return "leagueoflegends";
else if(pname1=="as")
return "assassincreed";
else if(pname1=="pubg")
return "playerunknownsbattleground";
else if(pname1=="rs6")
return "rainbowsixseige";
else if(pname1=="gta")
return "grandtheftauto5";
else if(pname1=="d2")
return "dota2";
else if(pname1=="ov")
return "overwatch";
else if(pname1=="mc")
return "minecraft";
else if(pname1=="mk")
return "mortalkomat11";
else if(pname1=="re")
return "residentevil8";
else 
return pname1;

}

void admin::search(string key)
{
 int pos=0,t;
 string buffer1;
 buffer1.erase();
 pos=search_index(key);
 if(pos==-1)
 cout<<endl<<"data not found"<<endl;
 else if(pos>=0)
 {
  read_from_file(pos);
  t=pos;
  while(pname_list[++t]==key&&t<=count)
  read_from_file(t);
  t=pos;
  while(pname_list[--t]==key&&t>=0)
  read_from_file(t);
 }
}
void admin::read_from_file(int pos)
{
 int address,i;
 fstream file;
 file.open("pdata2.txt",ios::in|ios::app);
 address=addr_list[pos];
 file.seekp(address,ios::beg);
 buffer1.erase();
 getline(file,buffer1);
 cout<<"found record!!!!";
 file.close();
}
void admin::remove(string key)
{
 int pos=0,t,choice;
 string buffer1;
 buffer1.erase();
 pos=search_index(key);
 if(pos==-1)
 cout<<endl<<"not possible to remove";
 else if(pos>=0)
 {
  read_from_file(pos);
  cout<<"\nDelete?(1/0):";
  cin>>choice;
  if(choice)
  delete_from_file(pos);
  t=pos;
  while(pname_list[++t]==key)
  {
   read_from_file(t);
   cout<<"\nDelete?";
    cin>>choice;
   if(choice)
   delete_from_file(t);
  }
 t=pos;
  while(pname_list[--t]==key)
 {
  read_from_file(t);
  cout<<"\nDelete?";
  cin>>choice;
  if(choice)
delete_from_file(t);
 }
}
}
void admin::delete_from_file(int pos)
{
 int i,address;
 fstream file;
 file.open("pdata2.txt");
 address=addr_list[pos];
 file.seekp(address,ios::beg);
 file.put('*');
 cout<<"\ndata Deleted:";
 for(i=pos;i<count;i++)
 {
  pname_list[i]=pname_list[i+1];
  addr_list[i]=addr_list[i+1];
 }
count--;
}
class user
{
	 public:
	 	    string cid,cname,address,state,buffer2, phnno, dob;
	 	    string gender,cid_list[100];
	 	    int add_list[100];
	 	    int count;
	 	    void read_data();
	 	    void pack();
	 	    void write_file();
            void unpack();
            void sort_index();
            int create_index();
            int search_index(string);
            string extract_cid();
            int search(string);
            int valid(string);
            int delete_file(string);
            void modify(string);
            void remove(string);
            int password();
};

void user::read_data()
{
	cout<<"enter customer-Id:";
	cin>>cid;
	cout<<"enter your name:";
	cin>>cname;
	cout<<"enter your dob ddmmyyyy:";
	cin>>dob;
	cout<<"enter address:";
	cin>>address;
	cout<<"enter the state:";
	cin>>state;
/*xyz: */	cout<<"gender M/F:";
	cin>>gender;
/*	if(gender=='m'||gender=='M')
	  gender='M';
	 if(gender=="f"||gender=="F")
	    gender="F";
	    else
	    {
	    cout<<"incorrect keyword entered\n please enter the deatils again!! ";
	    goto xyz;
     	}*/
	cout<<"mobile no:";
	cin>>phnno;
}


void user::pack()
{
 buffer2.erase();
 buffer2+=cid+"|"+cname+"|" +dob+ "|"+ address+"|"+state+"|"+gender+"|" +phnno+"$"+"\n";
}
void user::write_file()
{
  int pos;
  fstream file;
  file.open("cdata.txt",ios::out|ios::app);
  pos=file.tellp();
  file<<buffer2;
  file.close();
  cid_list[++count]=cid;
  add_list[count]=pos;
  sort_index();
}
void user::sort_index()
{
 int i,j,temp_Address;
 string temp_cid;
 for(int i=0;i<=count;i++)
  {
    for(int j=i+1;j<=count;j++)
    { 
      if(cid_list[i]>cid_list[j])
      {
       temp_cid=cid_list[i];
       cid_list[i]=cid_list[j];
       cid_list[j]=temp_cid;
       temp_Address=add_list[i];
       add_list[i]=add_list[j];
       add_list[j]=temp_Address;
      }
    }
  } 
 for(i=0;i<=count;i++)
 {
   cout<<cid_list[i]<<"\t"<<add_list[i]<<"\n";
 }
 system("pause");
}
void user::unpack()
{
	int ch=1,i=0;
	 cid.erase();
	 while(buffer2[i]!='|')
	 cid+=buffer2[i++];
	 cname.erase();
	 i++;
	 while(buffer2[i]!='|')
	 cname+=buffer2[i++];
	 dob.erase();
	 i++;
	 while(buffer2[i]!='|')
	 dob+=buffer2[i++];
	 address.erase();
	 i++;
	 while(buffer2[i]!='|')
	 address+=buffer2[i++];
	 state.erase();
	 i++;
	 while(buffer2[i]!='|')
	 state+=buffer2[i++];
	 gender.erase();
	 i++;
	 while(buffer2[i]!='|')
	 gender+=buffer2[i++];
	 phnno.erase();
	 i++;
	 while(buffer2[i++]!='|')
	 phnno+=buffer2[i++];
}
int user::create_index()
{
  fstream file;
  int pos;
  string cid;
  count=-1;
  file.open("cdata.txt",ios::in);
    while(!file.eof())
  {
   pos=file.tellg();
   buffer2.erase();
   getline(file,buffer2);
   if(buffer2[0]!='*')
   {
    if(buffer2.empty())break;
     cid=extract_cid();
     cid_list[++count]=cid;
     add_list[count]=pos;
   }   
  }
  return count;
 file.close();
 sort_index();
 buffer2.erase();
}
string user::extract_cid()
{
  string cid;
  int i=0;
  cid.erase();
  while(buffer2[i]!='|')
   cid+=buffer2[i++];
 return cid;
}
int user::search(string key)
{
 int pos=0,address;
 fstream file;
 buffer2.erase();
 count=create_index();
 pos=search_index(key);
 if(pos==-1)
 cout<<endl<<"id not found"<<endl;
 else if(pos>=0)
 {
  file.open("cdata.txt");
  address=add_list[pos];
  file.seekp(address,ios::beg);
  getline(file,buffer2);
  cout<<"id found....\n";
  file.close();
 }
 return pos;
}
int user::valid(string key)
{
 int pos=0,address,flag=0;
 fstream file;
 buffer2.erase();
 count=create_index();
 pos=search_index(key);
 if(pos>=0)
 {
  file.open("cdata.txt");
  address=add_list[pos];
  file.seekp(address,ios::beg);
  getline(file,buffer2);
  cout<<"login successfull!!!....";
  flag=1;
 }
 return flag;
}
int user::search_index(string key)
{
 int low=0,high=count,mid=0,flag=0,pos;
 while(low<=high)
 {
  mid=(low+high)/2;
  if(cid_list[mid]==key)
  {
  flag=1;
  break;
  }
 if(cid_list[mid]>key)
 high=mid-1;
 if(cid_list[mid]<key)
 low=mid+1;
 }
 if(flag)
 return mid;
else
 return-1;
}
int user::delete_file(string key)
{
	fstream file;
	int flag=0,p;
	p=search(key);
	if(p>=0)
    {
      file.open("cdata.txt");
      file.seekp(p,ios::beg);
      file.put('*');
      flag=1;
   }
if(flag==1)
 return 1;
else
return 0;
}
void user::modify(string key)
{
	int c;
	if(delete_file(key))
	{ 
 		 cout<<"\nwhat to modify\n1.cname\n2.mobile no\n3.address\n4.state\n enter your choice:";
		 cin>>c;
		 switch(c)
		 {
		 	 case 1:
		 	 	    cout<<"customer name:";
		 	 	    cin>>cname;
		 	 	    break;
		 	case 2:
		 		    cout<<"mobile no:";
		 		    cin>>phnno;
		 		    break;
		 	case 3:
		 		    cout<<"address:";
		 		    cin>>address;
		 		    break;
		 	case 4:
		 		    cout<<"state";
		 		    cin>>state;
		 		    break;
		 	default:"wrong choice!!";
		 }
		 pack();
		 write_file();
	}
}
int user::password()
{

	char p1,p2,p3,p4,p5;

	cout<<"\n\n\t\t\tENTER THE PASSWORD: ";

	cin>>p1;
	cout<<"*";
	cin>>p2;
	cout<<"*";
	cin>>p3;
	cout<<"*";
	cin>>p4;
	cout<<"*";
	cin>>p5;
	cout<<"*";

	if ((p1=='a'||p1=='A')&&(p2=='r'||p2=='R')&&(p3=='j'||p3=='J')&&(p4=='u'||p4=='U')&&(p5=='n'||p5=='N'))

		return 1;

	else
		return 0;
}
void user::remove(string key)
{
   int pos=0,i,address;
   fstream file;
   pos=search_index(key);
   if(pos>=0)
   {
    file.open("cdata.txt",ios::out|ios::in);
    address=add_list[pos];
    file.seekp(address,ios::beg);
    file.put('*');
    file.close();
    cout<<"\nRecord Deleted:";
    for(i=pos;i<count;i++)
   {
     cid_list[i]=cid_list[i+1];
     add_list[i]=add_list[i+1];
   }
count--;
}
else
cout<<"record not found\n";
}
class head
{
	char Iname[50][50];

public:
	int totalitems;
	float Qty[3];
	float price[3];
	int vatprice[3];
	int tprice[3];
	void input();
	void output();
};
class vat:public head
{
	float vats;
public:
	void vatcal();
	void outputs();
	void sum();
};
void head::input()
{
	cout<<"\nEnter number of items= ";
	cin>>totalitems;

	for(int i=0; i<totalitems; i++)
	{
		cout<<"\nEnter name of item "<<i+1<<": ";
		cin>>Iname[i];
		cout<<"Enter quantity: ";
		cin>>Qty[i];
		cout<<"Enter price of item "<<i+1<<": ";
		cin>>price[i];
		tprice[i]=Qty[i]*price[i];
	}
}
void head::output()
{
	int a;

	ifstream infile("COUNT.TXT");
	infile>>a;

	ofstream outfile("COUNT.TXT");
	a+=1;
	outfile<<a;
	outfile.close();

	{ofstream outfile("HIS.TXT", ios::app);
	outfile<<endl<<"Bill No.: "<<a<<endl;
	outfile<<"------------------------------------------------------------------------"<<endl;
cout<<"\n";
	cout<<"Name of Item\tQuantity   Price  Total Price\n";
	for(int i=0;i<totalitems;i++)
	{
		outfile<<"Name: "<<Iname[i]<<" Qty: "<<Qty[i]<<" Price: "<<tprice[i]<<endl;
		cout<<Iname[i]<<"\t\t"<<Qty[i]<<"\t   "<<price[i]<<"\t   "<<tprice[i]<<'\n';
	}

	outfile<<"------------------------------------------------------------------------"<<endl;
	outfile.close();
	}
}

void vat::vatcal()
{
	input();
	for(int i=0;i<totalitems;i++)
	{
		if(price[i]<=100.00)
		{
			vatprice[i]=tprice[i]+(0.03*tprice[i]);
		}
		else
		{
			vatprice[i]=tprice[i]+(0.1*tprice[i]);
		}
	}
}
void vat::outputs()
{
	output();

	float cash=0,sum=0,qty=0,sumt=0;

	for(int i=0;i<totalitems;i++)
	{
	       sumt+=tprice[i];
		   sum+=vatprice[i];
		   qty+=Qty[i];
	}
	cout<<"\nTotal:";
	cout<<"\n------------------------------------------------------------------------------";
	cout<<"\n\tQuantity= "<<qty<<"\t\t Sum= "<<sumt<<"\tWith Vat:"<<sum;
	cout<<"\n------------------------------------------------------------------------------";

pay:

	cout<<"\n\n\t\t\t****PAYMENT SUMMARY****\n";
	cout<<"\n\t\t\tTotal cash given: ";
	cin>>cash;

	if(cash>=sum)
		cout<<"\n\t\t\tTotal cash repaid: "<<cash-sum<<'\n';
		
	else
	{	cout<<"\n\t\t\tCash given is less than total amount!!!";

	goto pay;
	}
}
int main()
{
	int choice,i,f;
	vat obj;
	char ch;
	int a=1;
	fstream fin;
	user s1;
	admin a1;
	s1.create_index();
	a1.create_in();
	string key;
	system("cls");
	
	while(1) 
	{
	abc:	system("cls");
	    cout<<"-------------------------------------------------------------";	
	    cout<<"\n\t\tFSOCIETY GAMING ARENA\n1.customer login\n2.register account\n3.admin login\n4.exit\n";
		cout<<"-------------------------------------------------------------\n\t enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 2: system("cls");
			        cout<<"\n  data\n----------";
			        s1.read_data();
					s1.pack();
					s1.write_file();
					break;

	        case 1:system("cls");
	        	 int q;
		    	cout<<"\n\n    enter custmer id:";
		    	cin>>key;
		    	system("cls");
		    	 f=s1.valid(key);
		    	 if(f==1)
		    	 {    system("pause");
		    	  user:  system("cls");
		            cout<<"-----------------------------------------------------";	 
				  	cout<<"\n\t\tUSER MENU\n";
					cout<<"-----------------------------------------------------\n 1.buy game\n2.modify account details\n3.delete account\n4.exit to main menu\nenter your choice:";
		    	 	cin>>q;
		    	 	switch(q)
		    	 	{
		    	 		case 1: 
						 {      int k;
						        system("cls");
						        a1.disp();
		    	 		        cout<<"\n\n\nTO BUY PRESS 1 OR 0 TO EXIT TO PREVIOUS MENU......";
		    	 		        cin>>k;
		    	 		        if(k==1)
		    	 		        {
		    	 		        	cout<<"\n\t\t\t------------------------------";
                                	cout<<"\n\t\t\tFSOCIETY GAMING ARENA\n\n\t\t\t Billing Management System";
	                                cout<<"\n\t\t\t------------------------------";
	                                obj.vatcal();

		                            obj.outputs();
								 }
								 system("pause");
		    	 		         
		    	 		}
		    	 			   goto user;
		    	 		case 2: 
						        system("cls");
								s1.modify(key);
		    	 		        system("pause");
		    	 		        goto user;
		    	 	    case 3: 
						        system("cls");
								s1.remove(key);
		    	 	            system("pause");
		    	 	            goto abc;
		    	 	    case 4: goto abc;
		    	 	    default:cout<<"invalid input....!!";
					}
				 }
				 break;
		    case 3:
		    	    int n,p;
			        system("cls");
					p=s1.password();
					if(p==1)
					{
					admin:	system("cls");
					    cout<<"\t\tADMIN MENU\n1.add product\n2. remove product\n3.view orders\n4.exit\nenter your choice:";
						cin>>n;
						switch(n)
						{
							case 1:cout<<"enter product details.....\n";
							        a1.create_gdata();
							        a1.packs();
							        a1.write_to_files();
							        cout<<"details updated";
							        system("pause");
							        goto admin;
							case 2:cout<<"enter the product name to delete:";
							        cin>>key;
							        a1.remove(key);
							        system("pause");
							        goto admin;
							case 3:fin.open("HIS.TXT", ios::in);
		                           while(fin.get(ch))
		                           {
		                         	 cout<<ch;
		                            }
		                            system("pause");
		                            fin.close();
		                            goto admin;
		                            
							case 4: goto abc;
							default:cout<<"invalid choice!!!"; 	    
						}
				    }
					break;	 
		    case 4: return 0; 
		    default:cout<"wrong choice";
		}
	}
	return 0;
}
