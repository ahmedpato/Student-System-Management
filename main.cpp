#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
/////////////////Class : STUDENT//////////////////////
class student
{
    ////////////Attribute//////////////////
    private:
    string Id , StudentName , FatherName , PlaceOfBirth , DataOfBirth , Nationality , FatherPhoneNumber, HomeEmail , NumberOfFamilyMemebers , Cuontry , City , Address , Note ; 
    char type; 
    ////////////Methods//////////////////
    public:
    void add_student(); //Function to Add Student to Database .
    void delete_student(); //Function to Delete Student From File (Data).
    void delete_id(); // Function to Delete Student By ID Number .
    void delete_name(); // Function to Delete Student BY Student Name .
    void delete_nationality(); // Function to Delete Student By Nationality .
    void search_student(); //Function to Search For Student From File (Database).
    void search_id(); // Function to Search Student By ID Number .
    void search_name(); // Function to Search Student By Student Name .
    void search_dataofbirth(); // Function to Search Student By Data OF Birth .
    void search_nationality(); // Function to Search Student By Nationality .
    void display_students(); //Function to Show All Students .
    void modify_student(); //Function to Update Information .
    void display_deleted(); // Function to Show All Delete Student .
    void option_student(); //Function Add All Functions . (MENU).
    void waitforenter()
    {
        cout<<"Press Enter to go Back ..."<<endl;
        cin.get();
        cin.get();
        option_student();
    }
    void woe();
};
    /////////////End Class Student/////////////////
    ////////////Class : Teacher///////////////////
class teacher 
{
    private:
    string idteacher , teachername , teacherage , subject;
    public:
    void add_teacher(); //Function to Add Teacher to database .
    void delete_teacher(); //Function to Delete Teacher From File (Teacher).
    void delete_idteacher(); //Function to Delete Teacher By ID Number .
    void delete_teachername(); //Function to Delete Teacher By Name .
    void delete_teachersubject(); //Function to Delete Teacher By Subject .
    void search_teacher(); // Function to Search For Teacher .
    void search_idteacher(); //Function to Search For Teacher By ID Number .
    void search_teachername(); //Function to Search For Teacher By Name .
    void search_teachersubject(); //Function to Search For Teacher By Subject .
    void display_teachers(); //Function to Display All Teacher From File .
    void modify_teacher(); // Function to Edit Teacher Information .
    void display_deleted(); // Function to Show All Delete Teacher .
    void option_teacher(); // Function Take All Function . (MENU) .
    void waitfenter() // Function to go back (Menu).
    {
        cout<<"Press Enter to go Back ..."<<endl;
        cin.get();
        cin.get();
        option_teacher();
    }
    void woe2();
};

    /////////////End Class Teacher//////////////////
void student::add_student()
    {
        system("cls");
        cout<<"\t\t\nEnter ID Number :"; cin>>Id;
        cout<<"\t\t\nEnter Student Name :"; cin>>StudentName;
        cout<<"\t\t\nEnter Father Name :"; cin>>FatherName;
        cout<<"\t\t\nEnter Place Of Birth :"; cin>>PlaceOfBirth;
        cout<<"\t\t\nEnter Data Of Birth :"; cin>>DataOfBirth;
        cout<<"\t\t\nEnter Nationality :"; cin>>Nationality;
        cout<<"\t\t\nEnter Type[F/M] :"; cin>>type;
        cout<<"\t\t\nEnter Father Phone Number :"; cin>>FatherPhoneNumber;
        cout<<"\t\t\nEnter Home Email :"; cin>>HomeEmail;
        cout<<"\t\t\nEnter Number Of Family Memebers :"; cin>>NumberOfFamilyMemebers;
        cout<<"\t\t\nEnter Cuontry :"; cin>>Cuontry;
        cout<<"\t\t\nEnter City :"; cin>>City;
        cout<<"\t\t\nEnter Address :"; cin>>Address;
        cout<<"\t\t\nEnter Any Note :"; cin>>Note;
        char confirm; cout<<"\t\t\nEnter 'y' to Save Student Information to database :";
        cin>>confirm;
        if(confirm=='y'||confirm=='Y')
        {
            fstream file;
            file.open("data.txt" , ios::binary | ios::app | ios::out);
            file<< Id << " " << StudentName << " " << FatherName << " " << PlaceOfBirth << " " << DataOfBirth << " " << Nationality << " " << type << " " << FatherPhoneNumber << " "
            << HomeEmail << " " << NumberOfFamilyMemebers << " " << Cuontry << " " << City << " " << Address << " " << Note << endl;
            file.close();
            cout<<"\t\t\nStudent has been Add to Database ."<<endl;
            waitforenter();
        }
        
    }
///////////////////////////////////////////////////////
void student::delete_id()
{
    system("cls");
    string checkid;
    fstream file , temp , deleted ;
    file.open("data.txt" , ios::in);
	temp.open("temp.txt" , ios::out);
    deleted.open("delete.txt" , ios::out | ios::app);
	if (file.good())
	{
		cout << "\nEnter ID Student to Delete : "; cin >> checkid;
		while (file>> Id >> StudentName >>  FatherName >> PlaceOfBirth >> DataOfBirth >> Nationality >> type >> FatherPhoneNumber >> HomeEmail >> NumberOfFamilyMemebers >> Cuontry >> City >> Address >> Note)
		{
			if (checkid != Id)
			{
				temp << Id << " " << StudentName << " " << FatherName << " " << PlaceOfBirth << " " << DataOfBirth << " " << Nationality << " " << type << " " << FatherPhoneNumber << " "
            << HomeEmail << " " << NumberOfFamilyMemebers << " " << Cuontry << " " << City << " " << Address << " " << Note << endl;
			}else
            {
                deleted << Id << " " << StudentName << " " << FatherName << " " << PlaceOfBirth << " " << DataOfBirth << " " << Nationality << " " << type << " " << FatherPhoneNumber << " "
            << HomeEmail << " " << NumberOfFamilyMemebers << " " << Cuontry << " " << City << " " << Address << " " << Note << endl;
            }
            
		}cout<<"The Student are Deleted ."<<endl;
	}
	else
	{
		cout<< "\nFile Not Found\n";
	}

	file.close();
	temp.close();
    deleted.close();
	remove("data.txt");
	rename("temp.txt", "data.txt");
    waitforenter();
}
////////////////////////////////////////////////////////////////
void student::delete_name()
{
    system("cls");
    string checkname;
    fstream file , temp , deleted ;
    file.open("data.txt" , ios::in);
	temp.open("temp.txt" , ios::out);
    deleted.open("delete.txt" , ios::out | ios::app);
	if (file.good())
	{
		cout << "\nEnter Student Name to Delete : "; cin >> checkname;
		while (file>> Id >> StudentName >>  FatherName >> PlaceOfBirth >> DataOfBirth >> Nationality >> type >> FatherPhoneNumber >> HomeEmail >> NumberOfFamilyMemebers >> Cuontry >> City >> Address >> Note)
		{
			if (checkname != StudentName)
			{
				temp << Id << " " << StudentName << " " << FatherName << " " << PlaceOfBirth << " " << DataOfBirth << " " << Nationality << " " << type << " " << FatherPhoneNumber << " "
            << HomeEmail << " " << NumberOfFamilyMemebers << " " << Cuontry << " " << City << " " << Address << " " << Note << endl;
			}else
            {
                deleted << Id << " " << StudentName << " " << FatherName << " " << PlaceOfBirth << " " << DataOfBirth << " " << Nationality << " " << type << " " << FatherPhoneNumber << " "
            << HomeEmail << " " << NumberOfFamilyMemebers << " " << Cuontry << " " << City << " " << Address << " " << Note << endl;
            }
		}cout<<"The Student are Deleted ."<<endl;
	}
	else
	{
		cout<< "\nFile Not Found\n";
	}

	file.close();
	temp.close();
    deleted.close();
	remove("data.txt");
	rename("temp.txt", "data.txt");
    waitforenter();
}   
///////////////////////////////////////////////////////////////////
void student::delete_nationality()
{
    system("cls");
    string checknatio;
    fstream file , temp , deleted ;
    file.open("data.txt" , ios::in);
	temp.open("temp.txt" , ios::out);
    deleted.open("delete.txt" , ios::out | ios::app);
	if (file.good())
	{
		cout << "\t\tEnter Student Nationality to Delete : "; cin >> checknatio;
		while (file>> Id >> StudentName >>  FatherName >> PlaceOfBirth >> DataOfBirth >> Nationality >> type >> FatherPhoneNumber >> HomeEmail >> NumberOfFamilyMemebers >> Cuontry >> City >> Address >> Note)
		{
			if (checknatio != Nationality)
			{
				temp << Id << " " << StudentName << " " << FatherName << " " << PlaceOfBirth << " " << DataOfBirth << " " << Nationality << " " << type << " " << FatherPhoneNumber << " "
            << HomeEmail << " " << NumberOfFamilyMemebers << " " << Cuontry << " " << City << " " << Address << " " << Note << endl;
			}else
            {
                deleted << Id << " " << StudentName << " " << FatherName << " " << PlaceOfBirth << " " << DataOfBirth << " " << Nationality << " " << type << " " << FatherPhoneNumber << " "
            << HomeEmail << " " << NumberOfFamilyMemebers << " " << Cuontry << " " << City << " " << Address << " " << Note << endl;
            }
		}cout<<"\t\tThe Student are Deleted ."<<endl;
	}
    
	else
	{
		cout<< "\t\tFile Not Found\n";
	}

	file.close();
	temp.close();
    deleted.close();
	remove("data.txt");
	rename("temp.txt", "data.txt");
    waitforenter();

}
///////////////////////////////////////////////////////////////
void student::delete_student()
    {
        int choice;
        system("cls");
        cout<<"\t\t***(Student Delete List By)***"<<endl;
        cout<<"\t\t1_Delete Student By ID Number ."<<endl;
        cout<<"\t\t2_Delete Student By Student Name ."<<endl;
        cout<<"\t\t3_Delete Student By Nationality ."<<endl;
        cout<<"\t\t0_Go to Back ."<<endl;
        cout<<"\t\tEnter Your Choice :"; cin>>choice;
        switch(choice)
        {
            case 1 : delete_id(); break;
            case 2 : delete_name(); break;
            case 3 : delete_nationality(); break;
            case 0 : waitforenter(); break;
            default : cout<<"Sorry I Dont Understand That !!!"<<endl; break;
        }
    
    }
//////////////////////////////////////////////////////////////
void student::search_id()
{
    system("cls");
     string checkid;
            cout<<"Enter ID Student You Want to Search :"; cin>>checkid;
            fstream file;
             file.open("data.txt" , ios::in);
             if(file.is_open())
                {
            while(file>> Id >> StudentName >>  FatherName >> PlaceOfBirth >> DataOfBirth >> Nationality >> type >> FatherPhoneNumber >> HomeEmail >> NumberOfFamilyMemebers >> Cuontry >> City >> Address >> Note)
            {
                if(checkid==Id)
                {
                    cout<<"\t"<<Id<<" IS Found !"<<endl;
                    cout<<"-----------The Student Details---------------"<<endl;
                    cout<<"\tID Number :"<<Id<<endl;
                    cout<<"\tStudent Name :"<<StudentName<<endl;
                    cout<<"\tFther Name :"<<FatherName<<endl;
                    cout<<"\tPlace Of Birth :"<<PlaceOfBirth<<endl;
                    cout<<"\tData Of Birht :"<<DataOfBirth<<endl;
                    cout<<"\tNationality :"<<Nationality<<endl;
                    cout<<"\tType [F/M] :"<<type<<endl;
                    cout<<"\tFather Phone Number :"<<FatherPhoneNumber<<endl;
                    cout<<"\tHome Email :"<<HomeEmail<<endl;
                    cout<<"\tNumber Of Family Members :"<<NumberOfFamilyMemebers<<endl;
                    cout<<"\tCountry :"<<Cuontry<<endl;
                    cout<<"\tCity :"<<City<<endl;
                    cout<<"\tAddress :"<<Address<<endl;
                    cout<<"\tNote :"<<Note<<endl;
                    cout<<"\t--------------------------------"<<endl;
                }
            }
            file.close();
            waitforenter();
                }else cout<<"\tError !!"<<endl;


}
///////////////////////////////////////////////////////////////
void student::search_name()
{
    system("cls");
    string checkname;
    cout<<"\tEnter Student Name You Want to Search :"; cin>>checkname;
    fstream file; file.open("data.txt" , ios::in);
             if(file.is_open())
                {
            while(file>> Id >> StudentName >>  FatherName >> PlaceOfBirth >> DataOfBirth >> Nationality >> type >> FatherPhoneNumber >> HomeEmail >> NumberOfFamilyMemebers >> Cuontry >> City >> Address >> Note)
            {
                if(checkname==StudentName)
                {
                    cout<<"\t"<<StudentName<<" IS Found !"<<endl;
                    cout<<"\t-----------The Student Details---------------"<<endl;
                    cout<<"\tID Number :"<<Id<<endl;
                    cout<<"\tStudent Name :"<<StudentName<<endl;
                    cout<<"\tFther Name :"<<FatherName<<endl;
                    cout<<"\tPlace Of Birth :"<<PlaceOfBirth<<endl;
                    cout<<"\tData Of Birht :"<<DataOfBirth<<endl;
                    cout<<"\tNationality :"<<Nationality<<endl;
                    cout<<"\tType [F/M] :"<<type<<endl;
                    cout<<"\tFather Phone Number :"<<FatherPhoneNumber<<endl;
                    cout<<"\tHome Email :"<<HomeEmail<<endl;
                    cout<<"\tNumber Of Family Members :"<<NumberOfFamilyMemebers<<endl;
                    cout<<"\tCountry :"<<Cuontry<<endl;
                    cout<<"\tCity :"<<City<<endl;
                    cout<<"\tAddress :"<<Address<<endl;
                    cout<<"\tNote :"<<Note<<endl;
                    cout<<"\t--------------------------------"<<endl;
                }
            }
            file.close();
            waitforenter();
                }else cout<<"\tError !!"<<endl;
    
}
///////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
void student::search_nationality()
{
    system("cls");
    string checknatio;
    cout<<"\tEnter Student Nationality to Search :"; cin>>checknatio;
     fstream file; file.open("data.txt" , ios::in);
             if(file.is_open())
                {
            while(file>> Id >> StudentName >>  FatherName >> PlaceOfBirth >> DataOfBirth >> Nationality >> type >> FatherPhoneNumber >> HomeEmail >> NumberOfFamilyMemebers >> Cuontry >> City >> Address >> Note)
            {
                if(checknatio==Nationality)
                {
                    cout<<"\t"<<Nationality<<" IS Found !"<<endl;
                    cout<<"\t-----------The Student Details---------------"<<endl;
                    cout<<"\tID Number :"<<Id<<endl;
                    cout<<"\tStudent Name :"<<StudentName<<endl;
                    cout<<"\tFther Name :"<<FatherName<<endl;
                    cout<<"\tPlace Of Birth :"<<PlaceOfBirth<<endl;
                    cout<<"\tData Of Birht :"<<DataOfBirth<<endl;
                    cout<<"\tNationality :"<<Nationality<<endl;
                    cout<<"\tType [F/M] :"<<type<<endl;
                    cout<<"\tFather Phone Number :"<<FatherPhoneNumber<<endl;
                    cout<<"\tHome Email :"<<HomeEmail<<endl;
                    cout<<"\tNumber Of Family Members :"<<NumberOfFamilyMemebers<<endl;
                    cout<<"\tCountry :"<<Cuontry<<endl;
                    cout<<"\tCity :"<<City<<endl;
                    cout<<"\tAddress :"<<Address<<endl;
                    cout<<"\tNote :"<<Note<<endl;
                    cout<<"\t--------------------------------"<<endl;
                }
            }
            file.close();
            waitforenter();
                }else cout<<"\tError !!"<<endl;
}
////////////////////////////////////////////////////////////
void student::search_student()
    {
        system("cls");
      int choice;
      cout<<"\t\t***(Student Search List By)***"<<endl;
      cout<<"\t\t1_Search Student By ID Number ."<<endl;
      cout<<"\t\t2_Search Student By Student Name ."<<endl;
      cout<<"\t\t3_Search Student By Nationality ."<<endl;
      cout<<"\t\t0_Go to back ."<<endl;
      cout<<"\t\tEnter Your Choice :"; cin>>choice;
      switch(choice)
      {
          case 1 : search_id(); break;
          case 2 : search_name(); break;
          case 3 : search_nationality(); break;
          case 0 : waitforenter(); break;
          default : cout<<"\t\tSorry I dont Understand That !!!"; break;
      }   
    }
////////////////////////////////////////////////////////////    
void student::display_students()
{
    system("cls");
    fstream file;
    file.open("data.txt" , ios::in);
    cout<<"\tThe All Student In Database ."<<endl;
    while(file>> Id >> StudentName >>  FatherName >> PlaceOfBirth >> DataOfBirth >> Nationality >> type >> FatherPhoneNumber >> HomeEmail >> NumberOfFamilyMemebers >> Cuontry >> City >> Address >> Note)
    {
    cout<<"\tID Number :"<<Id<<endl;
    cout<<"\tStudent Name :"<<StudentName<<endl;
    cout<<"\tFather Name :"<<FatherName<<endl;
    cout<<"\tPlace Of Birth :"<<PlaceOfBirth<<endl;
    cout<<"\tData Of Birht :"<<DataOfBirth<<endl;
    cout<<"\tNationality :"<<Nationality<<endl;
    cout<<"\tType [F/M] :"<<type<<endl;
    cout<<"\tFather Phone Number :"<<FatherPhoneNumber<<endl;
    cout<<"\tHome Email :"<<HomeEmail<<endl;
    cout<<"\tNumber Of Family Members :"<<NumberOfFamilyMemebers<<endl;
    cout<<"\tCountry :"<<Cuontry<<endl;
    cout<<"\tCity :"<<City<<endl;
    cout<<"\tAddress :"<<Address<<endl;
    cout<<"\tNote :"<<Note<<endl;
    cout<<"\t--------------------------------"<<endl;
    }
    file.close();
    waitforenter();
}
////////////////////////////////////////////////////////////
void student::modify_student()
{
    system("cls");
    string checkid;
    fstream file , temp;
    file.open("data.txt" , ios::in);
    temp.open("temp.txt" , ios::out);
    bool check = false;
    cout<<"\tEnter ID Student to Edit :"; cin>>checkid;
    while(file >> Id >> StudentName >> FatherName >> PlaceOfBirth >> DataOfBirth >> Nationality >> type >> FatherPhoneNumber >> HomeEmail >> NumberOfFamilyMemebers >> Cuontry >> City >> Address >> Note)
    {
        if(checkid == Id)
        {
            cout<<"\tEnter New Details For Student ."<<endl;
            cout<<"\tEnter ID Number :"; cin>>Id;
            cout<<"\tEnter Student Name :"; cin>>StudentName;
            cout<<"\tEnter Father Name :"; cin>>FatherName;
            cout<<"\tEnter Place Of Birth :"; cin>>PlaceOfBirth;
            cout<<"\tEnter Data Of Birth :"; cin>>DataOfBirth;
            cout<<"\tEnter Nationality :"; cin>>Nationality;
            cout<<"\tEnter Type[F/M] :"; cin>>type;
            cout<<"\tEnter Father Phone Number :"; cin>>FatherPhoneNumber;
            cout<<"\tEnter Home Email :"; cin>>HomeEmail;
            cout<<"\tEnter Number Of Family Memebers :"; cin>>NumberOfFamilyMemebers;
            cout<<"\tEnter Cuontry :"; cin>>Cuontry;
            cout<<"\tEnter City :"; cin>>City;
            cout<<"\tEnter Address :"; cin>>Address;
            cout<<"\tEnter Any Note :"; cin>>Note;
            temp << Id << " " << StudentName <<" " << FatherName << " " << PlaceOfBirth << " " << DataOfBirth << " " << Nationality << " " << type << " " << FatherPhoneNumber << " " << HomeEmail << " " << NumberOfFamilyMemebers << " " << Cuontry << " " << City << " " << Address << " " << Note << endl;
            cout<<"\tThe New Details Has Been Add ."<<endl;
            check = true;
        }else
        {
            temp << Id << " " << StudentName <<" " << FatherName << " " << PlaceOfBirth << " " << DataOfBirth << " " << Nationality << " " << type << " " << FatherPhoneNumber << " " << HomeEmail << " " << NumberOfFamilyMemebers << " " << Cuontry << " " << City << " " << Address << " " << Note << endl;
        }
        
    }
    if(check==false)
    cout<<"\tStudent ID Not Found !!"<<endl;
    file.close();
    temp.close();
    remove("data.txt");
	rename("temp.txt", "data.txt");
    waitforenter();

}
//////////////////////////////////////////////////////////////////
void student::display_deleted()
{
    system("cls");
    string checkid;
    fstream deleted;
    deleted.open("delete.txt" , ios::app);
    while(deleted >> Id >> StudentName >> FatherName >> PlaceOfBirth >> DataOfBirth >> Nationality >> type >> FatherPhoneNumber >> HomeEmail >> NumberOfFamilyMemebers >> Cuontry >> City >> Address >> Note)
    {
        cout<<"\tEnter ID Number :"; cin>>Id;
            cout<<"\tEnter Student Name :"; cin>>StudentName;
            cout<<"\tEnter Father Name :"; cin>>FatherName;
            cout<<"\tEnter Place Of Birth :"; cin>>PlaceOfBirth;
            cout<<"\tEnter Data Of Birth :"; cin>>DataOfBirth;
            cout<<"\tEnter Nationality :"; cin>>Nationality;
            cout<<"\tEnter Type[F/M] :"; cin>>type;
            cout<<"\tEnter Father Phone Number :"; cin>>FatherPhoneNumber;
            cout<<"\tEnter Home Email :"; cin>>HomeEmail;
            cout<<"\tEnter Number Of Family Memebers :"; cin>>NumberOfFamilyMemebers;
            cout<<"\tEnter Cuontry :"; cin>>Cuontry;
            cout<<"\tEnter City :"; cin>>City;
            cout<<"\tEnter Address :"; cin>>Address;
            cout<<"\tEnter Any Note :"; cin>>Note;
    }
    deleted.close();
    waitforenter();
}
//////////////////////////////////////////////////////////////////////
void teacher::add_teacher()
{
    system("cls");
    cout<<"\tEnter ID Teacher :"; cin>>idteacher;
    cout<<"\tEnter Teacher Name :"; cin>>teachername;
    cout<<"\tEnter Teacher Age :"; cin>>teacherage;
    cout<<"\tEnter Teacher Subject :"; cin>>subject;
    char ch; cout<<"\tEnter 'y' to Save Teacher Information to Database :"; 
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        fstream file2;
        file2.open("teacher.txt" , ios::app | ios::binary | ios::out);
        file2 << idteacher << " " << teachername << " " << teacherage << " " << subject <<endl;
        file2.close();
        cout<<"\tThe Teacher has Been Saved to Database ."<<endl;
        waitfenter();
    }

}
///////////////////////////////////////////////////////////////////////////
void teacher::delete_idteacher()
{
    system("cls");
    string checkid;
    fstream file2 , temp2 , deleted;
    file2.open("teacher.txt" , ios::in);
    temp2.open("temp2.txt" , ios::out);
    deleted.open("delete.txt" , ios::out);
    if(file2.good())
    {
        cout<<"\tEnter ID Teacher to Delete :"; cin>>checkid;
        while(file2 >> idteacher >> teachername >> teacherage >> subject)
        {
            if(checkid!=idteacher)
            {
                temp2<<idteacher <<" "<< teachername <<" "<< teacherage <<" "<< subject <<endl;
            }else
            {
                deleted<<idteacher <<" "<< teachername <<" "<< teacherage <<" "<< subject <<endl;
            }
            
        }cout<<"\tThe Teacher are Deleted ."<<endl;
    }else
    {
        cout<<"\tFile Not Found !!"<<endl;
    }
    file2.close();
    temp2.close();
    deleted.close();
    remove("teacher.txt");
    rename("temp2.txt" , "teacher.txt");
    waitfenter();
}
/////////////////////////////////////////////////////////
void teacher::delete_teachername()
{
    system("cls");
    string checkname;
    fstream file2 , temp2 , deleted;
    file2.open("teacher.txt" , ios::in);
    temp2.open("temp2.txt" , ios::out);
    deleted.open("delete.txt" , ios::out);
    if(file2.good())
    {
        cout<<"\tEnter Teacher Name to Delete :"; cin>>checkname;
        while(file2 >> idteacher >> teachername >> teacherage >> subject)
        {
            if(checkname!=teachername)
            {
                temp2<<idteacher <<" "<< teachername <<" "<< teacherage <<" "<< subject <<endl;
            }else
            {
                deleted<<idteacher <<" "<< teachername <<" "<< teacherage <<" "<< subject <<endl;
            }
            
        }cout<<"\tThe Teacher are Deleted ."<<endl;
    }else
    {
        cout<<"\tFile Not Found !!"<<endl;
    }
    file2.close();
    temp2.close();
    deleted.close();
    remove("teacher.txt");
    rename("temp2.txt" , "teacher.txt");
    waitfenter();
}
//////////////////////////////////////////////////////////////////////////////
void teacher::delete_teachersubject()
{
    system("cls");
    string checksubject;
    fstream file2 , temp2 , deleted;
    file2.open("teacher.txt" , ios::in);
    temp2.open("temp2.txt" , ios::out);
    deleted.open("delete.txt" , ios::out);
    if(file2.good())
    {
        cout<<"\tEnter Teacher Subject to Delete :"; cin>>checksubject;
        while(file2 >> idteacher >> teachername >> teacherage >> subject)
        {
            if(checksubject!=subject)
            {
                temp2<<idteacher <<" "<< teachername <<" "<< teacherage <<" "<< subject <<endl;
            }else
            {
                deleted<<idteacher <<" "<< teachername <<" "<< teacherage <<" "<< subject <<endl;
            }
            
        }cout<<"\tThe Teacher are Deleted ."<<endl;
    }else
    {
        cout<<"\tFile Not Found !!"<<endl;
    }
    file2.close();
    temp2.close();
    deleted.close();
    remove("teacher.txt");
    rename("temp2.txt" , "teacher.txt");
    waitfenter();
}
/////////////////////////////////////////////////////////////////
void teacher::delete_teacher()
{
    system("cls");
    int choice;
    cout<<"\t\t1_Delete Teacher By ID Number ."<<endl;
    cout<<"\t\t2_Delete Teacher By Teacher Name ."<<endl;
    cout<<"\t\t3_Delete Teacher By Subject ."<<endl;
    cout<<"\t\t0_Go To Back ."<<endl;
    cout<<"\t\tEnter Your Choice :"; cin>>choice;
    switch(choice)
    {
        case 1 : delete_idteacher(); break;
        case 2 : delete_teachername(); break;
        case 3 : delete_teachersubject(); break;
        case 0 : waitfenter(); break;
        default : break;
    }
    
}
////////////////////////////////////////////////////////////////////////
void teacher::search_idteacher()
{
    system("cls");
    string checkid;
    cout<<"\tEnter ID Teacher to Search :"; cin>>checkid;
    fstream file2;
    file2.open("teacher.txt" , ios::in);
    if(file2.is_open())
    {
        while(file2 >> idteacher >> teachername >> teacherage >> subject)
        {
            if(checkid==idteacher)
            {
                cout<<"\tID Teacher :"<<idteacher<<" Is Found ."<<endl;
                cout<<"\tThe Details Teacher ."<<endl;
                cout<<"\tID Number :"<<idteacher<<endl;
                cout<<"\tTeacher Name :"<<teachername<<endl;
                cout<<"\tTeacher Age :"<<teacherage<<endl;
                cout<<"\tTeacher Subject :"<<subject<<endl;
                cout<<"\t----------------------------------"<<endl;
            }
        }
        file2.close();
        waitfenter();
    }else cout<<"\tError !!"<<endl;
}
///////////////////////////////////////////////////////////////////////////
void teacher::search_teachername()
{
    system("cls");
    string checkname;
    cout<<"\tEnter Teacher Name to Search :"; cin>>checkname;
    fstream file2;
    file2.open("teacher.txt" , ios::in);
    if(file2.is_open())
    {
        while(file2 >> idteacher >> teachername >> teacherage >> subject)
        {
            if(checkname==teachername)
            {
                cout<<"\tTeacher Name :"<<teachername<<" Is Found ."<<endl;
                cout<<"\tThe Details Teacher ."<<endl;
                cout<<"\tID Number :"<<idteacher<<endl;
                cout<<"\tTeacher Name :"<<teachername<<endl;
                cout<<"\tTeacher Age :"<<teacherage<<endl;
                cout<<"\tTeacher Subject :"<<subject<<endl;
                cout<<"\t----------------------------------"<<endl;
            }
        }
        file2.close();
        waitfenter();
    }else cout<<"\tError !!"<<endl;
}
///////////////////////////////////////////////////////////////////
void teacher::search_teachersubject()
{
    system("cls");
    string checksubject;
    cout<<"\tEnter Teacher subject to Search :"; cin>>checksubject;
    fstream file2;
    file2.open("teacher.txt" , ios::in);
    if(file2.is_open())
    {
        while(file2 >> idteacher >> teachername >> teacherage >> subject)
        {
            if(checksubject==subject)
            {
                cout<<"\tTeacher Subject :"<<subject<<" Is Found ."<<endl;
                cout<<"\tThe Details Teacher ."<<endl;
                cout<<"\tID Number :"<<idteacher<<endl;
                cout<<"\tTeacher Name :"<<teachername<<endl;
                cout<<"\tTeacher Age :"<<teacherage<<endl;
                cout<<"\tTeacher Subject :"<<subject<<endl;
                cout<<"\t----------------------------------"<<endl;
            }
        }
        file2.close();
        waitfenter();
    }else cout<<"\tError !!"<<endl;
}
////////////////////////////////////////////////////////////////////
void teacher::search_teacher()
{
    system("cls");
   int choice;
   cout<<"\t\t1_Search Teacher By ID Number ."<<endl;
   cout<<"\t\t2_Search Teacher By Teacher Name ."<<endl;
   cout<<"\t\t3_Search Teacher By Subject ."<<endl;
   cout<<"\t\t0_Go to Back ."<<endl;
   cout<<"\t\tEnter Your Choice :"; cin>>choice;
   switch(choice)
   {
       case 1 : search_idteacher(); break;
       case 2 : search_teachername(); break;
       case 3 : search_teachersubject(); break;
       case 0 : waitfenter(); break;
       default: break;
   }

}
/////////////////////////////////////////////////
void teacher::display_teachers()
{
    system("cls");
    fstream file2;
    file2.open("teacher.txt" , ios::in);
    cout<<"\tThe List Of All Teachers ."<<endl;
    while(file2 >> idteacher >> teachername >> teacherage >> subject)
    {
        cout<<"\tTeacher ID Number :"<<idteacher<<endl;
        cout<<"\tTeacher Name :"<<teachername<<endl;
        cout<<"\tTeacher Age :"<<teacherage<<endl;
        cout<<"\tTeacher Subject :"<<subject<<endl;
        cout<<"\t---------------------------------"<<endl;
    }
    file2.close();
    waitfenter();
}
/////////////////////////////////////////////////
void teacher::modify_teacher()
{
    system("cls");
    string checkid;
    fstream file2 , temp2;
    file2.open("teacher.txt" , ios::in);
    temp2.open("temp2.txt" , ios::out);
    bool check = false;
    cout<<"\tEnter Teacher ID Number to Edit :"; cin>>checkid;
    while(file2 >> idteacher >> teachername >> teacherage >> subject)
    {
        if(checkid==idteacher)
        {
            cout<<"\tEnter Teacher ID Number :"; cin>>idteacher;
            cout<<"\tEnter Teacher Name :"; cin>>teachername;
            cout<<"\tEnter Teacher Age :"; cin>>teacherage;
            cout<<"\tEnter Teacher Subject :"; cin>>subject;
            temp2 << idteacher << " " << teachername << " " << teacherage << " " << subject << endl;
            cout<<"\tEdit Teacher Success ."<<endl;
            check = true ;
        }
        else
        {
             temp2 << idteacher << " " << teachername << " " << teacherage << " " << subject << endl;
        }
        
    }
    if(check==false)
    cout<<"\tTeacher ID Number Was Not Found !!! "<<endl;
    file2.close();
    temp2.close();
    remove("teacher.txt");
    rename("temp2.txt" , "teacher.txt");
    waitfenter();
}
//////////////////////////////////////////////
void teacher::display_deleted()
{
    system("cls");
    fstream deleted;
    deleted.open("delete.txt" , ios::app | ios::out);
    cout<<"\tThe List Of Deleted Teacher ."<<endl;
    while(deleted>>idteacher>>teachername>>teacherage>>subject)
    {
        cout<<"\tTeacher ID Number :"<<idteacher<<endl;
        cout<<"\tTeacher Name :"<<teachername<<endl;
        cout<<"\tTeacher Age :"<<teacherage<<endl;
        cout<<"\tTeacher Subject :"<<subject<<endl;
        cout<<"\t--------------------------------"<<endl;
    }
    deleted.close();
    waitfenter();

}
//////////////////////////////////////
void student::option_student()
    {
        int choice;
        system("cls");
        cout<<"\t\t\n\t---------Student Menu--------------\n"<<endl;
        cout<<"\t\t1_ADD SCHOOL STUDENT ."<<endl;
        cout<<"\t\t2_DELETE SCHOOL STUDENT ."<<endl;
        cout<<"\t\t3_DISPLAY ALL STUDENT ."<<endl;
        cout<<"\t\t4_SEARCH STUDENT ."<<endl;
        cout<<"\t\t5_MODIFY STUDENT ."<<endl;
        cout<<"\t\t6_DISPLAY DELETED STUDENTS ."<<endl;
        cout<<"\t\t0_to go back ..."<<endl;
        cout<<"\t\tEnter Your Choice :"; cin>>choice;
        cout<<"\t\t-----------------------------"<<endl;
        switch(choice)
        {
            case 1 : add_student(); break;
            case 2 : delete_student(); break;
            case 3 : display_students(); break;
            case 4 : search_student(); break;
            case 5 : modify_student(); break;
            case 6 : display_deleted(); break;
            case 0 : woe(); break;
            default: break;
        }
    }
//////////////////////////////////////
void teacher::option_teacher()
{
    system("cls");
    int choice;
    cout<<"\t\t\n\t---------Teacher Menu---------------\n"<<endl;
    cout<<"\t\t1_ADD TEACHER ."<<endl;
    cout<<"\t\t2_DELETE TEACHER ."<<endl;
    cout<<"\t\t3_DISPLAY TEACHER ."<<endl;
    cout<<"\t\t4_SEARCH TEACHER ."<<endl;
    cout<<"\t\t5_MODIFY TEACHER ."<<endl;
    cout<<"\t\t6_DISPLAY DELETED TEACHERS ."<<endl;
    cout<<"\t\t0_to go back ."<<endl;
    cout<<"\t\tEnter Your Choice :"; cin>>choice;
    switch(choice)
    {
        case 1 : add_teacher(); break;
        case 2 : delete_teacher(); break;
        case 3 : display_teachers(); break;
        case 4 : search_teacher(); break;
        case 5 : modify_teacher(); break;
        case 6 : display_deleted(); break;
        case 0 : woe2(); break;
        default : break;
    }
}    
///////////////////////////////////////
void menu()
{
    int login();
    login();
    student s;
    teacher t;
    system("cls");
    int choice;
    cout<<"\t\t\n\n\n\t***(School Managment System)***\n\n"<<endl;
    cout<<"\t\t1_MENU STUDENT .\n"<<endl;
    cout<<"\t\t2_MENU TEACHER .\n"<<endl;
    cout<<"\t\t3_Exit .\n"<<endl;
    cout<<"\t\t\nEnter Your Choice :"; cin>>choice;
    switch(choice)
    {
        case 1 : s.option_student(); break;
        case 2 : t.option_teacher(); break;
        case 3 : cout<<"\t\tThank You For Using This Program ; \n\n\t\tBy : Ahmed Mohammed Ali\n\n\n\n"<<endl;
        default: break;
    }
    
}
///////////////////////////////////////
void student::woe()
{
    cout<<"\t\t\tPress Enter to go back ..."<<endl;
    cin.get();
    cin.get();
    menu();
}
//////////////////////////////////////
void teacher::woe2()
{
    cout<<"\t\t\tPress Enter to go back ..."<<endl;
    cin.get();
    cin.get();
    menu();
}
////////////MAIN FUNCTION/////////////////////
int main()
{
    menu(); 
    return 0;
}
//////////////////////////////////////////////
//////////FUNCTION TO ENTER TO PROGRAM BY PASSWORD////////////////////////
int login()
{
    system("cls");
    string pass="";
    cout<<"\n\n\t\tSCHOOL MANAGEMENT SYSTEM"<<endl;
    cout<<"\n\n\t\tEnter Your Password :"; cin>>pass;
    if(pass=="pass")
    {
        cout<<"\n\t\t\tLoding"<<endl;
        for(int i=0 ; i<20 ; i++)
        {
            cout<<"...";
        }
        cout<<"\n\n\t\tAccess Granted !"<<endl;
        cout<<"\t\t"; system("pause");
        system("cls");

    }else{
        cout<<"\n\n\t\tAccess Aborted !"<<endl;
        login();
    }
}
////////END///////////////




