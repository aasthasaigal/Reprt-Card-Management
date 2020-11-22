#include<iostream>
#include<fstream>
using namespace std;


//FUNCTIONS DECLARATION
void intro();                                 //displays introduction
void result();                                //displays the result menu
void entry_edit();                            //displays the entry and edit menu
void class_result();                          //displays the result of the whole class
void display_sr(int);                         //displays the result of the mentioned student
void create_record();                         //creates the record of the student
void display_all();                           //displays the record of all the students
void modify_student(int);                     //modifies the record of the mentioned student
void delete_student(int);                     //deletes the record of the mentioned student


//CLASS used in the program
class report
{
   //private members
   int rollno;                                 //roll no of the student
   int phy,chem,math,eng,cs;                   //marks of the subjects
   char name[100];                             //name of the student
   char grade;                                 //grade of the student
   double per;                                 //percentage of the student
   void calculate_grade();                     //function to calculate the grade of a student
   //public members
public:
    void getdata();                            //function to get the data from the user
    void showdata();                           //function to show the data on the terminal output screen
    void show_tabular();                       //function to display the data in a tabular method
    int retrollno();                           //function to return the roll number
};


//function to INPUT THE DATA
void report::getdata()
{
    cout<<"Enter the roll number of student "<<endl;
	cin>>rollno;
	cout<<"Enter the Name of student "<<endl;
	cin.ignore();
	cin.getline(name,50);
	cout<<"Enter the marks in Physics out of 100 : "<<endl;
	cin>>phy;
	cout<<"Enter the marks in Chemistry out of 100 : "<<endl;
	cin>>chem;
	cout<<"Enter the marks in Maths out of 100 : "<<endl;
	cin>>math;
	cout<<"Enter the marks in English out of 100 : "<<endl;
	cin>>eng;
	cout<<"Enter the marks in Computer Science out of 100 : "<<endl;
	cin>>cs;
	calculate_grade();
}


//function to CALCULATE THE GRADE
void report::calculate_grade()
{
    per=(phy+chem+math+eng+cs)/5.0;
	if(per>=80)
        grade='A';
	else if(per>=70)
		grade='B';
	else if(per>=60)
		grade='C';
    else if(per>=50)
        grade='D';
    else if(per>=33)
        grade='E';
	else
		grade='F';
}


//function to SHOW THE DATA
void report::showdata()
{
	cout<<"Roll number of student : "<<rollno<<endl;
	cout<<"Name of student : "<<name<<endl;
	cout<<"Marks in Physics : "<<phy<<endl;
	cout<<"Marks in Chemistry : "<<chem<<endl;
	cout<<"Marks in Maths : "<<math<<endl;
	cout<<"Marks in English : "<<eng<<endl;
	cout<<"Marks in Computer Science :"<<cs<<endl;
	cout<<"Percentage of student is  :"<<per<<endl;
	cout<<"Grade of student is :"<<grade<<endl;
}


//function to SHOW DATA IN TABULAR MANNER
void report::show_tabular()
{
	cout<<rollno<<"\t"<<name<<"\t"<<phy<<"\t"<<chem<<"\t"<<math<<"\t"<<eng<<"\t"<<cs<<"\t"<<per<<"\t"<<grade<<endl;
}


//function to RETURN THE ROLL NUMBER
int report::retrollno()
{
	return rollno;
}


//MAIN FUNCTION
int main()
{
    char ch;                                   //enter choice
    intro();                                   //function to display the introduction of the program
    do
    {
        cout<<"\t MAIN MENU"<<endl;
        cout<<"\t 1. RESULT MENU"<<endl;
        cout<<"\t 2. ENTRY/EDIT MENU"<<endl;
        cout<<"\t 3. EXIT"<<endl;
        cout<<"\t Please enter the option(1-3)"<<endl;
        cin>>ch;

        switch(ch)
        {
            case '1': result();
                       break;
            case '2': entry_edit();
                       break;
            case '3':
                       break;
            default: cout<<"\a";               //generates an alarm for wrong choice entered

        }
    }while(ch!='3');
    return 0;
}


//function to display the INTRODUCTION
void intro()
{
    cout<<"\t MINI PROJECT"<<endl;
    cout<<"\t ------------"<<endl;
    cout<<"\t TOPIC - STUDENT REPORT CARD SYSTEM"<<endl;
	cout<<"\t AASTHA SAIGAL"<<endl;
	cout<<"\t BTECH CSE(CORE)"<<endl;
	cout<<"\t SECTION - D"<<endl;
    cout<<"\t UNIVERSITY ROLL NO - 2014355"<<endl;
    cout<<"\t SEMESTER - 3 "<<endl;
	cin.get();                                 //accepts the input
}


//function to display the RESULT MENU
void result()
{
    char ch;
	int rno;
	cout<<"\t RESULT MENU"<<endl;
	cout<<"\t 1. Class Result"<<endl;
	cout<<"\t 2. Student Report Card"<<endl;
	cout<<"\t 3. Back to Main Menu"<<endl;
	cout<<"\t Enter Choice (1/2/3) "<<endl;
	cin>>ch;

	switch(ch)
	{
	case '1' : class_result();
	           break;
	case '2' : cout<<"\tEnter Roll Number Of Student: "<<endl;
	           cin>>rno;
               display_sr(rno);
               break;
	case '3' :
	           break;
	default : cout<<"\a";
	}
}


//function to display the ENTRY/EDIT MENU
void entry_edit()
{
    char ch;
	int num;
	cout<<"\t ENTRY/EDIT MENU"<<endl;
	cout<<"\t 1. Create Student Record"<<endl;
	cout<<"\t 2. Display all student record"<<endl;
	cout<<"\t 3. Search student record"<<endl;
	cout<<"\t 4. Modify student record"<<endl;
	cout<<"\t 5. Delete student record"<<endl;
	cout<<"\t 6. Back to Main Menu"<<endl;
	cout<<"\t Enter choice (1/2/3/4/5/6)"<<endl;
	cin>>ch;

	switch(ch)
	{
	case '1': create_record();
              break;
	case '2': display_all();
	          break;
	case '3': cout<<"\tEnter the roll no of the student: "<<endl;
	          cin>>num;
			  display_sr(num);
              break;
	case '4': cout<<"\tEnter the roll no of the student: "<<endl;
	          cin>>num;
			  modify_student(num);
			  break;
	case '5': cout<<"\tEnter the roll no of the student: "<<endl;
	          cin>>num;
			  delete_student(num);
			  break;
	case '6':
	          break;
	default: cout<<"\a";
	}
}


//function to display the CLASS RESULT (result menu)
void class_result()
{
    report st;
	ifstream inFile;                                              //creating read file object
	inFile.open("report.dat",ios::binary);                        //opening binary file using file modes
	if(!inFile)
	{
		cout<<"File can't be open. Press any key to continue."<<endl;
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\tCLASS RESULT"<<endl<<endl;
	cout<<"========================================================================================\n";
	cout<<"R.No  Name   Physics  Chemistry  Maths  English  Computer  %age  Grade"<<endl;
	cout<<"========================================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(report)))
	{
		st.show_tabular();                                       //displaying class result using show_tabular function
	}
	cin.ignore();
	cin.get();
	inFile.close();                                              //closing the file
	cout<<"Press any key to continue"<<endl;
}


//function to display the RESULT OF A STUDENT (result menu)
void display_sr(int rno)
{
    report st;
	ifstream inFile;                                            //creating read file object
	inFile.open("report.dat",ios::binary);                      //opening binary file using file modes
	if(!inFile)
	{
		cout<<"File can't be open. Press any key to continue";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(report)))
	{
		if(st.retrollno()==rno)
		{
	  		 st.showdata();                                     //displaying data using showdata function
			 flag=true;
		}
	}
	inFile.close();                                             //closing the file
	if(flag==false)
    cout<<"\tRecord not exist"<<endl;
    cout<<"Press any key to continue"<<endl;
	cin.ignore();
	cin.get();
}


//function to CREATE RECORD OF A STUDENT (entry/edit menu)
void create_record()
{
    report st;
	ofstream outFile;                                                 //creating write file object
	outFile.open("report.dat",ios::binary|ios::app);                  //opening binary file using file modes
	st.getdata();                                                     //extracting data from user using getdata function
	outFile.write(reinterpret_cast<char *> (&st), sizeof(report));
	outFile.close();                                                  //closing the file
    cout<<"Student record has been created. Press any key to continue."<<endl;
	cin.ignore();
	cin.get();
}


//function to display the RESULT OF ALL STUDENTS (entry/edit menu)
void display_all()
{
    report st;
	ifstream inFile;                                                  //creating read file object
	inFile.open("report.dat",ios::binary);                            //opening binary file using file modes
	if(!inFile)
	{
		cout<<"File can't be open. Press any key to continue."<<endl;
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\tDISPLAY ALL RECORD OF THE STUDENTS"<<endl;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(report)))
	{
		st.showdata();
		cout<<endl;                                               //displaying data using showdata function
	}
	inFile.close();                                                   //closing the file
	cout<<"Press any key to continue.";
	cin.ignore();
	cin.get();

}


//function to MODIFY THE RESULT OF A STUDENT (entry/edit menu)
void modify_student(int num)
{
    bool found=false;
	report st;
	fstream File;                                                     //creating read and write file object
	File.open("report.dat",ios::binary|ios::in|ios::out);             //opening binary file using file modes
	if(!File)
	{
		cout<<"File can't be open. Press any key to continue."<<endl;
		cin.ignore();
		cin.get();
		return;
	}
    while(!File.eof() && found==false)
	{
        File.read(reinterpret_cast<char *> (&st), sizeof(report));
		if(st.retrollno()==num)
		{
			st.showdata();                                             //displaying the details of the student
			cout<<"Please Enter The New Details of student"<<endl;
			st.getdata();                                              //extracting the details of the student
		    	int pos=(-1)*static_cast<int>(sizeof(st));
		    	File.seekp(pos,ios::cur);
		    	File.write(reinterpret_cast<char *> (&st), sizeof(report));
		    	cout<<"\t Record Updated"<<endl;
		    	cout<<"Press any key to continue"<<endl;
		    	found=true;
		}
	}
	File.close();                                                       //closing the file
	if(found==false)
    cout<<"\t Record Not Found"<<endl;
    cout<<"Press any key to continue"<<endl;
	cin.ignore();
	cin.get();

}


//function to DELETE THE RESULT OF A STUDENT (entry/edit menu)
void delete_student(int num)
{
    report st;
	ifstream inFile;                                                   //creating a read file object
	inFile.open("report.dat",ios::binary);                             //opening binary file using file modes
	if(!inFile)
	{
		cout<<"File can't be open. Press any key to continue."<<endl;
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;                                                  //creating a write file object
	outFile.open("temp.dat",ios::out);                                 //opening a binary file using file modes
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(report)))
	{
		if(st.retrollno()!=num)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(report));
		}
	}
	outFile.close();                                                   //closing write file
	inFile.close();                                                    //closing read file
	remove("report.dat");
	rename("temp.dat","report.dat");
	cout<<"\t Record Deleted."<<endl;
	cout<<"Press any key to continue"<<endl;
	cin.ignore();
	cin.get();
}
