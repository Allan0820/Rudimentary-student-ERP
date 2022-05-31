/*    author @Allan Pais
    
	This is a rudimentary version of a student ERP system that is written using c++
    for operating the ERP user name is admin 
    password is password@1234
    it consists of 2 basic interfaces i.e the admin and the student.
    
    In the admin interface the admin can enter the student performance attendance and general feedback
	which then gets written onto a file in the local directory named username+password.txt
	The biggest advantage of this file handling approach is that the files entered
	by the admin are always stored in the system till they are explictly deleted
	by the database handler(in this case the user) thus the student data remains saved even
	after repeated executions of the program.
	
	In the student interface the student can retrieve his result from the previously
	entered file and can see it in a formatted way that is easy to read
    
   ** Since this code was written for a college project
	(to demonstrate the learnings from the c++ course taught(duration 2.5 months))
	there has been explicit introduction of concepts which could have otherwise been omitted. **
	
	The broad concepts covered in this code are
	
	1. General structure of a c++ program
	2. Function and Method calls
	3. Constructors and Destructors
	4. Iterative and Program control-flow constructs
	5. Exception handling 
	6. Instruction execution time ( Shown in the delay function)
	7. File handling in c++
	   (total length 770 lines)
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>   // header files included

using namespace std;     

int adminview();
int studentview();
int registerstudent();
int studentlogin();
int checkcreds(string username, string password);
int adminlogin();
int checkListOfStudentRegistered();
int delay();    // Function prototype declarations


class Collegedatabase    
{
private:
    string collegename;
    string registration_number;

public:
    Collegedatabase()        
    {

        collegename = "^%$#";  // Default garbage values
        registration_number = " "; //Default garbage values
    }
    Collegedatabase(string name, string id)
    {
        collegename = name;
        registration_number = id;
    }
     void accept()
    {

        cout << "\n Enter name of the college recognised by the UGC  ";
        cin >> collegename;
        cout << "\n Enter the college registration number  ";
        cin >> registration_number;
    }
     void display()
    {
        cout << "\n College Name:"<<collegename;
          cout   << "\n College registration number:" << "   " <<registration_number<<endl;;
        
    }
   
  ~Collegedatabase()
    {
        cout<<"Destructor of the Collegedatabase is called"<<endl;
    }
};

class College : public Collegedatabase
{  public:
	 void accept()
    {
        Collegedatabase ::accept();
    }
    void display()
    {    
         cout<<"The information to be displayed is "<<endl;
        Collegedatabase ::display();
           
    }
};
int checkListOfStudentRegistered()   /////////////////////////////////
{
    
    cout<<"\n - Check List of Student Registered by Username-- ";	

//check if record already exists in the database
ifstream read;
read.open("student.txt");

if(read)
{   int recordFound =0; 
    string line;
    while(getline(read, line)) {
    	char name[100];   
    	strcpy(name, line.c_str());                //Filename extraction mechanism 
    	char onlyname[100];
    	strncpy(onlyname, name, (strlen(name) - 4));// Required to read the particular file and thus open it
    	cout<<" \n " << onlyname;
    }
     read.close();        
}
else
{
cout<<"\n No Record found :(";
}
		
cout<<"\n Please any key to continue..";
getchar(); getchar();
cout<<"\n List of All registered registered !!";
cout<<"\n Please any key to continue..";

return 0;
}
int studentlogin ()    ////////////////////////////////
{
  
cout<<"\n-----------------------------------------------------------------------------------------";  
cout<<"\n|                              Student Login                                            |";  
cout<<"\n-----------------------------------------------------------------------------------------";  
studentview ();
  
delay ();
return 0;
}

int delay()    /////////////////////////////////    manual delay function done with a brute force method to give a better
{	cout<<"\n Saving Records ";               //    estimate of the processor speed and instruction execution rate
for(int i = 0; i<2; i ++)
{ cout<<".";
    for(int j = 0; j<20000; j++)
    {
    	for( int k = 0; k<20000; k++)
       	{ }
    }
}         // This code segment can be replaced by the delay()(library) function
   
cout<<"\n Exiting Now";
for(int i = 0; i<2; i ++){
    cout<<".";
   for(int j = 0; j<20000; j ++) { 
     for(int k = 0; k<20000; k ++){
	 }
    } 
}
system("cls"); 
return 0;
}


int adminview()    /////////////////////////////////
{	
int goBack = 0;
while(1)
{
system("cls");
cout<<"\n 1 Register a Student";
cout<<"\n 2 Display all the registered students";
cout<<"\n 0. Go Back <- \n";
int choice;

cout<<"\n Enter you choice: ";
  try
  	        {
			cin>>choice;
		      if (std::cin.fail())
                {
				throw 1;
				 }}
			catch(int error) 
			 {   
			cout<<"Sorry error encountered (Expected int entered String)"<<endl;
			exit(0);
			}

 
switch(choice)
{
	case 1: registerstudent();
	break;  
	
	case 2:  checkListOfStudentRegistered(); break;


	case 0: goBack = 1;
		break;
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();  
	system("cls");         	
}   

if(goBack == 1)
{
break; 
}     
}
}

 int checkcreds(string username, string password)   /////////////////////////////////////
{


ifstream read;
read.open("student.txt");

if (read) {
                               // The file exists, and is open for input
int recordFound = 0;
string line;
string temp = username + password + ".txt";
cout<<"\n file name is : "<<temp;
while(getline(read, line)) {
	if(line == temp)
	{
		recordFound = 1;
		break;
	}
}

if(recordFound == 0)
    return 0;
else
   return 1;
}    		
}

int registerstudent()
{
    cout<<"\n-----------------------------------------------------------------------------------------";  
cout<<"\n|                              Form to register student                                 |";  
cout<<"\n-----------------------------------------------------------------------------------------";   

    string name, username, password, rollno, Attendanceds,Attendancedeld,Attendanceoop,Attendanceppl,Attendancees,Attendancecoa;
    string marksds,marksdeld,marksoop,marksppl,markses,markscoa,gradeds,gradedeld,gradeoop,gradeppl,gradees,gradecoa;
    cout<<"\n Enter the name : ";     cin>>name;
    cout<<"\n Enter the PRN number : ";     cin>>username;
        //check if record already exists..
    ifstream read;
    read.open("student.txt");
    
    if(read)
    {   int recordFound =0; 
	   string line;
	    while(getline(read, line)) {
    	if(line == username+password+".txt" )
    	{
    		recordFound = 1 ;
    	    break;
		}
        }
        if(recordFound == 1)
        {
    	cout<<"\n This PRN number has already registered !!!";
    	getchar(); getchar();
    	delay();
    	read.close();
    	return 0;
		}
	}
    read.close();

    cout<<"\n Enter the  password : ";     cin>>password;
    cout<<"\n Enter the rollno : ";     cin>>rollno;
    
    
    cout<<"          DISCRETE STRUCTURES"<<endl;
    cout<<"\n Enter Attendance  : ";     cin>>Attendanceds;
    cout<<"\n Enter Total marks in percentage : ";     cin>>marksds;
    cout<<"\n Enter letter grade :";cin>>gradeds;
     char remarkds[100];
     getchar();
    cout<<"\n Enter your general feedback [max 100 words]";
    cin.getline(remarkds, 100);
  cout<<endl;
     cout<<"          DIGITAL ELECTRONICS AND LOGIC DESIGN"<<endl;
    cout<<"\n Enter Attendance  : ";     cin>>Attendancedeld;
    cout<<"\n Enter Total marks in percentage : ";     cin>>marksdeld;
    cout<<"\n Enter letter grade :";cin>>gradedeld;
     char remarkdeld[100];
     getchar();
    cout<<"\n Enter your general feedback [max 100 words]";
    cin.getline(remarkdeld, 100);
   cout<<endl;
   cout<<"          OBJECT ORIENTED PROGRAMMING"<<endl;
    cout<<"\n Enter Attendance  : ";     cin>>Attendanceoop;
    cout<<"\n Enter Total marks in percentage : ";     cin>>marksoop;
    cout<<"\n Enter letter grade :";cin>>gradeoop;
     char remarkoop[100];
     getchar();
    cout<<"\n Enter your general feedback [max 100 words]";
    cin.getline(remarkoop, 100);
  cout<<endl;
   cout<<"          PRICIPLES OF PROGRAMMING LANGUAGES"<<endl;
    cout<<"\n Enter Attendance  : ";     cin>>Attendanceppl;
    cout<<"\n Enter Total marks in percentage : ";     cin>>marksppl;
    cout<<"\n Enter letter grade :";cin>>gradeppl;
     char remarkppl[100];
     getchar();
    cout<<"\n Enter your general feedback [max 100 words]";
    cin.getline(remarkppl, 100);
   cout<<endl;
   cout<<"          ENVIRONMENTAL SCIENCE"<<endl;
    cout<<"\n Enter Attendance  : ";     cin>>Attendancees;
    cout<<"\n Enter Total marks in percentage : ";     cin>>markses;
    cout<<"\n Enter letter grade :";cin>>gradees;
     char remarkes[100];
     getchar();
    cout<<"\n Enter your general feedback [max 100 words]";
    cin.getline(remarkes, 100);
    cout<<endl;
     cout<<"          COMPUTER ORGANIZATION AND ARCHIETECTURE"<<endl;
    cout<<"\n Enter Attendance  : ";     cin>>Attendancecoa;
    cout<<"\n Enter Total marks in percentage : ";     cin>>markscoa;
    cout<<"\n Enter letter grade :";cin>>gradecoa;
     char remarkcoa[100];
     getchar();
    cout<<"\n Enter your general feedback [max 100 words]";
    cin.getline(remarkcoa, 100);
    cout<<endl;
  
  

    ofstream out;
	out.open("student.txt", ios::app);
	out<<username+password+".txt"<<"\n";
	out.close();

	ofstream out1;
	string temp = username+password+".txt";
	out1.open(temp.c_str());
	out1<<name<<"\n"; 	out1<<username<<"\n"; 	out1<<password<<"\n";
	out1<<rollno<<"\n"; 	 
	out1<<Attendanceds<<"\n";
	out1<<marksds<<"\n";
	out1<<gradeds<<"\n";
	out1<<remarkds<<"\n";
		out1<<Attendancedeld<<"\n";
	out1<<marksdeld<<"\n";
	out1<<gradedeld<<"\n";

	out1<<remarkdeld<<"\n";
		out1<<Attendanceoop<<"\n";
	out1<<marksoop<<"\n";
	out1<<gradeoop<<"\n";

	out1<<remarkoop<<"\n";
		out1<<Attendanceppl<<"\n";
	out1<<marksppl<<"\n";
	out1<<gradeppl<<"\n";
	
	out1<<remarkppl<<"\n";
		out1<<Attendancees<<"\n";
	out1<<markses<<"\n";
	out1<<gradees<<"\n";
	out1<<remarkes<<"\n";
		out1<<Attendancecoa<<"\n";
	out1<<markscoa<<"\n";
	out1<<gradecoa<<"\n";
	out1<<remarkcoa<<"\n";
	out1.close();

	cout<<"\n Student Registered Successfully !!";
    
    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;		
}

int adminlogin()
{
system("cls");
cout<<"\n-----------------------------------------------------------------------------------------";  
cout<<"\n|                           Administration login                                        |";  
cout<<"\n-----------------------------------------------------------------------------------------";  

string username;
string password;

cout<<"\n Enter username : ";
cin>>username;
cout<<"\n Enter password : ";
cin>>password;

if(username=="admin" && password=="password@1234")   // Important information used during run time of the program
{
    adminview();
    getchar();	
    delay();
}   
else
{
cout<<"\n Error ! Invalid Credentials..";	
cout<<"\n Press any key for main menu ";
getchar();getchar();
system("cls");
}

return 0;
}
int studentview()                 ////////////////////
{
cout<<"\n ------- Student Login-------- \n";		

string username, password;

cout<<"\n Enter your PRN number : ";
cin>>username;

cout<<"\n Enter your account password  : ";
cin>>password;

int res = checkcreds(username, password);

if(res  == 0)
{
   cout<<"\n Invalid Credentials !!";
   cout<<"\n Press any key for Main Menu..";
   getchar(); getchar();	
   return 0;
} 
else
{
	cout<<"Enter your choice"<<endl;
	cout<<"\n  1.Check your attendance for DS ";
	cout<<"\n  2.Check your attendance for DELD";
	cout<<"\n  3.Check your attendance for OOP ";
	cout<<"\n  4.Check your attendance for PPL ";
	cout<<"\n  5.Check your attendance for ES ";
	cout<<"\n  6.Check your attendance for COA ";
    cout<<"\n  7.Display your final Result";
    int chs;
    cin>>chs;
    string line;
   
    string temp=" ";
   temp=username+password+".txt";
    ifstream f_att(temp.c_str(),ios::in);
   
    switch(chs)
    {       
	    case 1: cout<<"Your attendance for DS is"<<endl;
              
                for(int lineincrement=0; getline(f_att,line)&&lineincrement<6;lineincrement++)
                {
                	if(lineincrement==4)
                	{
                		cout<<line<<" Percent"<<endl;
					}
				}
    
	  break;
      
          case 2: cout<<"Your attendance for DELD is"<<endl;
 
                for(int lineincrement=0; getline(f_att,line)&&lineincrement<10;lineincrement++)
                {
                	if(lineincrement==8)
                	{
                		cout<<line<<" Percent"<<endl;
					}
				}
     
	   break;
      
          case 3: cout<<"Your attendance for OOP is"<<endl;
   
                for(int lineincrement=0; getline(f_att,line)&&lineincrement<14;lineincrement++)
                {
                	if(lineincrement==12)
                	{
                		cout<<line<<" Percent"<<endl;
					}
				}
     
	  break;
      
          case 4: cout<<"Your attendance for PPL is"<<endl;
 
                for(int lineincrement=0; getline(f_att,line)&&lineincrement<18;lineincrement++)
                {
                	if(lineincrement==16)
                	{
                		cout<<line<<" Percent"<<endl;
					}
				}
    
      break;
          case 5: cout<<"Your attendance for ES is"<<endl;
      
                for(int lineincrement=0; getline(f_att,line)&&lineincrement<22;lineincrement++)
                {
                	if(lineincrement==20)
                	{
                		cout<<line<<" Percent"<<endl;
					}
				}
   
      break;
          case 6: cout<<"Your attendance for COA is"<<endl;
  
                for(int lineincrement=0; getline(f_att,line)&&lineincrement<26;lineincrement++)
                {
                	if(lineincrement==24)
                	{
                		cout<<line<<" Percent"<<endl;
					}
				}
    
      break;
          case 7: cout<<"                                       FINAL RESULT "<<endl;
                  cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                  cout<<"| Candidate name -   ";
                  getline(f_att,line);  
                  cout<<line<<endl;
                  cout<<"| PRN Number -   |";
                    getline(f_att,line);   
                  cout<<line<<endl;
                   getline(f_att,line);
                    getline(f_att,line);
                  cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                  cout<<"|                  |";
                  cout<<"                                       |";
                  cout<<"                   |";
                  cout<<"          |";
                  cout<<"         |"<<endl;
                  cout<<"|         Sr No    |";
                  cout<<"                    Subject            |";
                  cout<<"     Attendance    |";
                  cout<<"Percentage|";
                  cout<<"  Grade  |"<<endl;
                   cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                   cout<<"|         1.       |";
                   cout<<"   DISCRETE STRUCTURE                  |";
                    getline(f_att,line);  
                   cout<<"     "<<line<<" %          |";
                    getline(f_att,line);  
                   cout<<"    "<<line<<" %  |";
                   getline(f_att,line); 
                   
                   cout<<"     "<<line<<"  |"<<endl;
                   getline(f_att,line); 
                   
                   cout<<"|         2.       |";
                   cout<<"  DIGITAL ELECTRONICS AND LOGIC DESIGN |";
                    getline(f_att,line);  
                   cout<<"     "<<line<<" %          |";
                    getline(f_att,line);  
                   cout<<"    "<<line<<" %  |";
                   getline(f_att,line); 
                   
                   cout<<"     "<<line<<"  |"<<endl;
                   getline(f_att,line); 
                   
                   
                   cout<<"|         3.       |";
                   cout<<"  OBJECT ORIENTED PROGRAMMING          |";
                    getline(f_att,line);  
                   cout<<"     "<<line<<" %          |";
                    getline(f_att,line);  
                   cout<<"    "<<line<<" %  |";
                   getline(f_att,line); 
                   
                   cout<<"     "<<line<<"  |"<<endl;
                   getline(f_att,line); 
                   
                   
                   cout<<"|         4.       |";
                      cout<<"  PRINCIPLES OF PROGRAMMING LANGUAGES  |";
                    getline(f_att,line);  
                   cout<<"     "<<line<<" %          |";
                    getline(f_att,line);  
                   cout<<"    "<<line<<" %  |";
                   getline(f_att,line); 
                   
                   cout<<"     "<<line<<"  |"<<endl;
                   getline(f_att,line); 
                   
                   
                   cout<<"|         5.       |";
                   cout<<"  ENVIRONMENTAL SCIENCE                |";
                   getline(f_att,line);  
                   cout<<"     "<<line<<" %          |";
                    getline(f_att,line);  
                   cout<<"    "<<line<<" %  |";
                   getline(f_att,line); 
                   
                   cout<<"     "<<line<<"  |"<<endl;
                   getline(f_att,line); 
                   
                   
                   cout<<"|         6.       |";
                   cout<<"COMPUTER ORGANIZATION AND ARCHIETECTURE|";
                    getline(f_att,line);  
                   cout<<"     "<<line<<" %          |";
                    getline(f_att,line);  
                   cout<<"    "<<line<<" %  |";
                   getline(f_att,line); 
                   
                   cout<<"     "<<line<<"  |"<<endl;
                   getline(f_att,line); 
                   
                   f_att.close();   
                    cout<<"|___________________________________________________________________________________________________|"<<endl;
            //to print the remarks
            string temp=" ";
           temp=username+password+".txt";
         ifstream f_att(temp.c_str(),ios::in);
          for(int lineincrement=0; getline(f_att,line)&&lineincrement<8;lineincrement++)
                {
                	if(lineincrement==7)
                	{    cout<<"|DS Remarks"<<endl;
                		 cout<<"|"<<line<<endl;
					}
				}  
                f_att.seekg(0);
                  for(int lineincrement=0; getline(f_att,line)&&lineincrement<12;lineincrement++)
                {
                	if(lineincrement==11)
                	{    cout<<"|DELD Remarks"<<endl;
                		 cout<<"|"<<line<<endl;
					}
				}
				 f_att.seekg(0);
				for(int lineincrement=0; getline(f_att,line)&&lineincrement<16;lineincrement++)
                {
                	if(lineincrement==15)
                	{    cout<<"|OOP Remarks"<<endl;
                		 cout<<"|"<<line<<endl;
					}
				}
				 f_att.seekg(0);
				for(int lineincrement=0; getline(f_att,line)&&lineincrement<20;lineincrement++)
                {
                	if(lineincrement==19)
                	{    cout<<"|PPL Remarks"<<endl;
                		 cout<<"|"<<line<<endl;
					}
				}
				 f_att.seekg(0);
				for(int lineincrement=0; getline(f_att,line)&&lineincrement<24;lineincrement++)
                {
                	if(lineincrement==23)
                	{    cout<<"|ES Remarks"<<endl;
                		 cout<<"|"<<line<<endl;
					}
				}
				 f_att.seekg(0);
				for(int lineincrement=0; getline(f_att,line)&&lineincrement<28;lineincrement++)
                {
                	if(lineincrement==27)
                	{    cout<<"|COA Remarks"<<endl;
                		 cout<<"|"<<line<<endl;
					}
				}
		 f_att.close();   		               
   
}
    cout<<"\n Press any key for Main Menu..";
   getchar();getchar();	
  
   return 0;
}
}


int main()        ////////////////////////////////////////////////
{     
cout<<"Do you want to login to the college database system?"<<endl;
cout<<"Enter 1 for yes and 2 for no"<<endl;
College col;
int t;
cin>>t;
if(t==1)
{

col.accept();
system("cls");
}
else
{ exit(0);
}
  
   while(1)
   {
   
  cout<<"---------------------Welcome to the student database management system--------------------------"<<endl;
  cout<<"Please enter your choice"<<endl;
  cout<<"1. Admin login"<<endl;
  cout<<"2. Student login"<<endl;
  cout<<"Enter 0 to logout"<<endl;
  int choice;
   try
  	        {
			  cin>>choice;
		      if (std::cin.fail())
                {
				throw 1;
				 }}
			catch(int error) 
			 {   
			cout<<"Sorry error encountered (Expected int entered String)"<<endl;
			exit(0);
			}

  switch(choice)
  {
  	case 0: cout<<"Are you sure you want to logout?"<<endl;
  	        cout<<"1. YES"<<endl;
  	        cout<<"2. NO"<<endl;
  	        int op;
  	        int temp;
  	        try
  	        {
			cin>>op;  
		      if (cin.fail())
                {
				throw 1;
				 }}
			catch(int error) 
			 {   
			cout<<"Sorry error encountered (Expected int entered String)"<<endl;
			exit(0);
			}
  	        if(op==1)
  	        {
			  col.display();
			  cout<<"Log out successful"<<endl;
  	        	exit(0);
			  }
  	        break;
  	        if(op==2)
  	        {
  	        	break;
			  }
			  if(op>2&&op<1)
			  {
			  	cout<<"invalid choice ";
			  }
			  break;
			      
  	case 1: adminlogin();
  	break;
  	case 2: studentlogin();
  	break;
  	default:cout<<"Invalid choice please enter the correct value again"<<endl;
  	
  }   
}
}







