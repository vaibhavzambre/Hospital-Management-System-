#include<iostream>
using namespace std;
struct node
{
	char fname[20];
	char sname[20];
	char address[200];
    char contact[10];
    char phist[100];
    int age;
    char gender[8];
    char blood_gp[5];
    char disease_past[50];
    int id;
    char symptom[500];
    char diagnosis[500];
    char medicine[500];
    char addmission[30];
	struct node *next;
	bool diagnose;
};
struct node *head;
struct node *lastptr;
bool check=true;
int arr[20],i=0;
bool check_id(int ch)
{
  	    for(int a=0;a<i;a++)
  	    {
  	    	if(ch==arr[a])
  	    	{
  	    		return true;
			}
		}
		return false;
};
class doctor
{
    public:
	  void add()
	  {
	  	node *p;
	  	p=new node;
	  	p->diagnose=false;
	  	cout<<"enter Patient ID"<<endl;
	  	cin>>p->id;
	  	cout<<"enter Patient First name"<<endl;
	  	cin>>p->fname;
	  	cout<<"enter Patient Last name"<<endl;
	  	cin>>p->sname;
	  	cout<<"enter Patient Age"<<endl;
	  	cin>>p->age;
	  	cout<<"enter Patient Gender"<<endl;
	  	cin>>p->gender;
	  	cout<<"enter Patient Blood Group"<<endl;
	  	cin>>p->blood_gp;
	  	cout<<"enter Patient Contact "<<endl;
	  	cin>>p->contact;
	  	cout<<"enter Patient Past History"<<endl;
	  	cin>>p->phist;
	  	cout<<"enter Patient Address"<<endl;
	  	cin>>p->address;

	  	p->next=NULL;
	  	arr[i]=p->id;

	  	i++;
	  	if(check)
	{
	    head=p;
	    lastptr=p;
	    check=false;
	}
	else
	{
		lastptr->next=p;
		lastptr=p;
	}

  }
  void show()
  {
  	    int n;
  	    node *current=NULL;
  	    node *prev=NULL;
  	    prev=head;
  	    current=head;
  	    int ch;
 	    cout<<"enter Patient ID"<<endl;
  	    cin>>ch;
		if(check_id(ch))
		{
  	    while(current->id!=ch)
  	    {
  	    	prev=current;
  	    	current=current->next;
  	   	  }

  	 	cout<<"Patient First name:"<<endl;
	  	cout<<current->fname<<endl;
	  	cout<<"Patient Last name:"<<endl;
	  	cout<<current->sname<<endl;
	  	cout<<"Patient ID:"<<endl;
	  	cout<<current->id<<endl;
	  	cout<<"Patient Age:"<<endl;
	  	cout<<current->age<<endl;
	  	cout<<"Patient Gender:"<<endl;
	  	cout<<current->gender<<endl;
	  	cout<<"Patient Blood Group:"<<endl;
	  	cout<<current->blood_gp<<endl;
	  	cout<<"Patient Contact:"<<endl;
	  	cout<<current->contact<<endl;
	  	cout<<"Patient Past History:"<<endl;
	  	cout<<current->phist<<endl;
	  	cout<<"Patient Address:"<<endl;
	    cout<<current->address<<endl;
	    if(current->diagnose){
	    cout<<"Symptoms:"<<endl;
	    cout<<current->symptom<<endl;
	    cout<<"Diagnosis:"<<endl;
	    cout<<current->diagnosis<<endl;
	    cout<<"Medicines:"<<endl;
	    cout<<current->medicine<<endl;
	    cout<<"Admit Required to Hospital?-"<<endl;
	    cout<<current->addmission<<endl;
	   }}
	   else
	   {
	   	cout<<"ID not present"<<endl;
	   }
}
  void diagnosis()
  {
  	int n;
    node *p=NULL,*prev=NULL;
    p=new node;
  	prev=head;
    p=head;
  	int ch;
  	cout<<"enter Patient ID"<<endl;
  	cin>>ch;
	if(check_id(ch)){
		while(p->id!=ch )
	  	{
	  		prev=p;
	  		p=p->next;
		}
		p->diagnose=true;
		cout<<"Enter Symptoms"<<endl;
		cin>>p->symptom;
		cout<<"Enter Diagnosis"<<endl;
		cin>>p->diagnosis;
		cout<<"Enter Medicines"<<endl;
		cin>>p->medicine;
		cout<<"Admit Required to Hospital?"<<endl;
		cin>>p->addmission;

	}

	else
		cout<<"ID is not Registered\n";

	}
void deleteList()
{
	int counter=0;
    node *current=NULL,*prev=NULL;
  	prev=head;
  	current=head;
  	int ch;
	cout<<"Enter the ID: ";
	cin>>ch;
	if(check_id(ch)){
		while(current->id!=ch)
  	    {
  	    	prev=current;
  	    	current=current->next;
  		}
  		prev->next=current->next;
  		free(current);
  		
      for(int a=0;a<i;a++)
      {
      	if(arr[a]==ch){
      		for (int j=a;j<i;j++){
      			arr[j]=arr[j+1];
			  }
			  i--;
		  }
	  }
    cout<<"SUCCESSFULLY DELETED ALL NODES OF LINKED LIST\n";
    }
    else
       cout<<"ID not present"<<endl;
}
void update_menu()
{
	    cout<<"enter 1 Patient First name"<<endl;
	  	cout<<"enter 2 Patient Last name"<<endl;
	  	cout<<"enter 3 Patient ID"<<endl;
	  	cout<<"enter 4 Patient Age"<<endl;
	  	cout<<"enter 5 Patient Gender"<<endl;
	  	cout<<"enter 6 Patient Blood Group"<<endl;
	  	cout<<"enter 7 Patient Contact "<<endl;
	  	cout<<"enter 8 patient Past History"<<endl;
      	cout<<"enter 9 Patient Address"<<endl;
	    cout<<"Enter 10 Symptoms"<<endl;
	    cout<<"Enter 11 Diagnosis"<<endl;
	    cout<<"Enter 12 Medicines"<<endl;
	    cout<<"Admit 13 Required to Hospital?"<<endl;
}
void update_data(){
    node *current=NULL,*prev=NULL;
	current=head;
	prev=head;
	int id,ch;
	cout<<"enter ID"<<endl;
	cin>>id;
	if(check_id(id)){
		while(current->id!=id)
  	    {
  	    	prev=current;
  	    	current=current->next;
  		}
  		update_menu();
  		cout<<"chose number"<<endl;
  		cin>>ch;
  		if(ch==1){
  			cout<<"enter first name"<<endl;
  			cin>>current->fname;
		  }
		else if(ch==2){
			cout<<"enter second name"<<endl;
			cin>>current->sname;
		}
		else if(ch==3){
			cout<<"enter ID"<<endl;
			cin>>current->id;
		}
  		else if(ch==4){
  			cout<<"enter age"<<endl;
  			cin>>current->age;
		  }
		else if(ch==5){
			cout<<"enter gender"<<endl;
			cin>>current->gender;
		}
		else if(ch==6){
			cout<<"enter blood group"<<endl;
			cin>>current->blood_gp;
		}
		else if(ch==7){
			cout<<"enter contact"<<endl;
			cin>>current->contact;
		}
		else if(ch==8){
			cout<<"enter Patient Past History"<<endl;
			cin>>current->phist;
		}
		else if(ch==9){
			cout<<"enter address"<<endl;
			cin>>current->address;
		}
		else if(ch==10){
			cout<<"Enter 10 Symptoms"<<endl;
			cin>>current->symptom;
		}
		else if(ch==11){
	    cout<<"Enter 11 Diagnosis"<<endl;
	    cin>>current->diagnosis;
	    }
	    else if(ch==12){
	    cout<<"Enter 12 Medicines"<<endl;
	    cin>>current->medicine;
		}
	    else if(ch==13){
	    cout<<"Admit 13 Required to Hospital?"<<endl;
	    cin>>current->addmission;
	}
   }
   else
     cout<<"ID not present"<<endl;
}
};

void dis()
{
    cout<<"Hospital Management System - CITY HOSPITAL"<<endl;
	cout<<"1 Add New Patient Record "<<endl;
	cout<<"2 Add Patient prescription "<<endl;
	cout<<"3 Full History of the Patient"<<endl;
	cout<<"4 delete Patient Record"<<endl;
	cout<<"5 update Patient Record"<<endl;
}

int main()
{
	struct node* head=NULL;
	doctor d;
	int i=0;
	do{
	dis();
	cin>>i;
	if(i==1)
	d.add();
	else if(i==2)
	d.diagnosis();
	else if(i==3)
	d.show();
	else if(i==4)
	d.deleteList();
	else if(i==5)
	d.update_data();
	}while(1);
	return 0;
}

