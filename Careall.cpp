#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int number_of_young=0;
int appointment_id;
int number_of_old=0;
void display_handling_ppl(int);

class young
{
 private:
 int y_id;
 char y_name[10];
 int phno;
 int age;
 char reviews[10];

 public:
 int total_no_of_ppl;
 int old_id[4];

 void set_ydetails(int id)
 {
  y_id=id;
  cout<<"Enter the name and ph number age";
  cin>>y_name>>phno>>age;
  display_ydetails();
 // set_of_young[number_of_young++]=y;
 }
 void display_ydetails()
 {
  cout<<"ID "<<y_id<<endl<<"Name "<<y_name<<endl<<"Phone Number "<<phno<<endl<<"Age "<<age<<endl<<"Reviews "<<reviews<<endl;
 }
 void display_people_details()
 {
  int i;
  for(i=0;i<total_no_of_ppl;i++)
  {
   display_handling_ppl(old_id[i]);
  }
 }
 void update_total_no_of_ppl(int n)
 {
  total_no_of_ppl=n;
 }
 void update_yreviews(char r[10])
 {
  strcpy(reviews,r);
 }
}set_of_young[100];


class old
{
 private:
 char o_name[10];
 int phno;
 int age;
 char reviews[10];
 public:
 int o_id;
 young caretaker;
 void set_odetails(int id)
 {
  o_id=id;
  cout<<"Enter the name and ph number age";
  cin>>o_name>>phno>>age;
  display_odetails();
 }
 
 void display_odetails()
 {
  cout<<"ID "<<o_id<<endl<<"Name "<<o_name<<endl<<"Phone Number "<<phno<<endl<<"Age "<<age<<endl<<"Reviews "<<reviews<<endl;
 }
 void update_oreviews(char r[10])
 {
  strcpy(reviews,r);
 }
 void set_young(young y)
 {
  caretaker=y;
 }
}set_of_old[100];

void display_handling_ppl(int old_id)
{
  set_of_old[old_id].display_odetails();
}
 
class appointment
{
 old ol;
 public:
 int appointment_id;
 
 void young_details()
 {
  for(int i=0;i<number_of_young;i++)
   set_of_young[i].display_ydetails();
 }


 void appoint(old o,int id)
 {
  ol=o;
  int n;
  young_details();
  appointment_id=id;
  cout<<"Enter the young puple you want to select";
  cin>>n;
  if(set_of_young[n].total_no_of_ppl<4)
  {
   set_of_young[n].total_no_of_ppl++;
   set_of_young[n].old_id[set_of_young[n].total_no_of_ppl]=o.o_id;
   o.set_young(set_of_young[n]);
  }
  else  
   cout<<"Invalied input as he has reached maximum input";
 }

 void display_appointment_details()
 {
  cout<<"The appointment id is"<<appointment_id<<endl;
  ol.display_odetails();
  ol.caretaker.display_ydetails();
 }

 void display_appointment_details(old o)
 {
  o.display_odetails();
  o.caretaker.display_ydetails();
 }
 
}app_details[100];


void oldppl()
{
 int n;
 cout<<"Enter 1)Enrole 2)To Check Details 3)To get appointment 4)To Update review of Caretaker 5)Caretaker details 6)Appointment details";
 cin>>n;
 int old_id;
 switch(n)
 {
 case 1 :set_of_old[number_of_old].set_odetails(number_of_old);
	 number_of_old++;
	 break;
 case 2 :cout<<"Enter the old id";
         cin>>old_id;
	 if(old_id>number_of_old)
         {
 	  cout<<"Invalied old_id";
	  break;
 	 }
         set_of_old[old_id].display_odetails();
	 break;
 case 3 :cout<<"Enter the old id";
         cin>>old_id;
 	 if(old_id>number_of_old)
         {
 	  cout<<"Invalied old_id";
	 break;
	 }
         app_details[appointment_id].appoint(set_of_old[old_id],appointment_id++);
	 break;
 case 4 :cout<<"Enter the old id";
         cin>>old_id;
 	 if(old_id>number_of_old)
         {
 	  cout<<"Invalied old_id";
	 break;
	 }
	 char rev[10];
         cout<<"Enter the review";
	 cin>>rev;
         set_of_old[old_id].caretaker.update_yreviews(rev);
	 break;
 case 5 :cout<<"Enter the old id";
         cin>>old_id;
 	 if(old_id>number_of_old)
         {
  	  cout<<"Invalied old_id";
	  break;
 	 }
         set_of_old[old_id].caretaker.display_ydetails();
	 break;
 case 6 :cout<<"Enter the old id";
         cin>>old_id;
	 if(old_id>number_of_old)
         {
  	  cout<<"Invalied old_id";
	  break;
 	 }
	 appointment a;
	 a.display_appointment_details(set_of_old[old_id]);
	 break;
 default:cout<<"Invalied Input";
	 break;
 }
}

void youngppl()
{
 int n;
 int young_id;
 cout<<"Enter 1)Enrole 2)To Check Details 3)check appointment 4)To Update review of old 5)old people under the caretaker";
 cin>>n;
 switch(n)
 {
 case 1 :set_of_young[number_of_young].set_ydetails(number_of_young);
 	 number_of_young++;
	 break;
 case 2 :cout<<"Enter the young id";
         cin>>young_id;
	 if(young_id>number_of_young)
         {
 	  cout<<"Invalied young_id";
	  break;
  	 }
         set_of_young[young_id].display_ydetails();
	 break;
 case 3 :cout<<"Emter appointment id";
         int i;
	 cin>>i;
         /*cin>>young_id;
 	 if(young_id>number_of_young)
         {
   	  cout<<"Invalied old_id";
 	  break;
  	 }
         app_details[appointment_id].appoint(set_of_old[old_id],appointment_id++);*/
         app_details[i].display_appointment_details();
	 break;
 case 4 :cout<<"Enter the young id";
         cin>>young_id;
  	 if(young_id>number_of_young)
         {
   	  cout<<"Invalied young_id";
 	  break;
  	 }
	 char rev[10];
 	 int num;
         cout<<"Enter the old number";
         cin>>num;
         cout<<"Enter the review";
  	 cin>>rev;
         set_of_old[set_of_young[young_id].old_id[num]].update_oreviews(rev);
	 break;
 case 5 :cout<<"Enter the young id";
         cin>>young_id;
  	 if(young_id>number_of_young)
         {
   	  cout<<"Invalied young_id";
 	  break;
  	 }
         set_of_young[young_id].display_people_details();
	 break;
 default:cout<<"Invalied Input";
	 break;
 }
}
 
int main()
{
 int n;
 while(1)
 {
  cout<<"Enter 1)old 2)young 3)all appintment details"<<endl;
  cin>>n;
  switch(n)
  {
   case 1 :oldppl();
           break;
   case 2 :youngppl();
    	   break;
   case 3 :int i;
  	  for(i=0;i<appointment_id;i++)
            app_details[i].display_appointment_details();
 	  break;
   default:exit(0);
  }
 }
 return 0;
}
