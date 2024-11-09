#include<iostream>
#include<ctime>
#include<string>
#include<queue>
#include<stack>


using namespace std;

static int count;

class Ticket_Management{
	public :
		int id;
		string name;
		int priority;
		string service_description;
		time_t Creation_time;
		bool Status;
		time_t close_time;
		Ticket_Management* next_tick  = NULL;
		
		Ticket_Management(string nm, string desc, int p, int i){
			id = i;
			name = nm;
			service_description = desc;
			priority = p;
			Creation_time = time(0);
			close_time = 0;
			Status = true;
			Ticket_Management* next_tick = NULL;
		}
		
		
};

class Ticket_list{
	public :
		Ticket_Management* head;
		stack<Ticket_Management*> Ticket_Resolution_log;
		queue<Ticket_Management*> Pending_Ticket;
		
		Ticket_list(){
			head = NULL;
			count = 1;
		}		
		
		Ticket_Management* Add_Ticket(string nm, string des, int p, int i){
			Ticket_Management* ticket = new Ticket_Management(nm,des,p,i);
			Pending_Ticket.push(ticket);  //Push Pending ticket in Queue
			if(head == NULL){
				head = ticket;
				cout<<"Ticket with id : "<<ticket->id<<", Insert Successfully at Time : "<<ctime(&ticket->Creation_time)<<endl;
				return head;
			}else{
				Ticket_Management* Temp = head;
				
				while(Temp->next_tick != NULL){
					Temp = Temp->next_tick;
				}
				Temp->next_tick = ticket;
				ticket->next_tick = NULL;
				cout<<"Ticket with id : "<<ticket->id<<", Insert Successfully at Time : "<<ctime(&ticket->Creation_time)<<endl;
				return ticket;
			}
		}
		
		void Remove_Ticket(int search){
			if(head == NULL){
				cout<<"No Ticket to Remove....\a"<<endl;
				return;
			}
			Ticket_Management* Temp = head;
			while(Temp != NULL){
				Temp = Temp->next_tick;
				if(Temp->id == search){
					if(Temp->Status){
						Temp->Status = false;
						Pending_Ticket.pop();
						Ticket_Resolution_log.push(Temp);
						Temp->close_time = time(0);
						cout<<"Ticket with id : "<<search<<" is Remove Successfully at Time : "<<ctime(&Temp->close_time)<<endl;
						return;
					}
				}
			}
			cout<<"Ticket with id : "<<search<<", not found...\a"<<endl;
		}
		
		bool Search(string nm, int i){
			if(head == NULL){
				cout<<"Ticket List is Empty....\a"<<endl;
				return false;
			}else{
				Ticket_Management* Temp = head;
				while(Temp != NULL){
					if(Temp->id == i){
						if(Temp->name.compare(nm) == 0){
							cout<<"Ticket with id : "<<i<<", &  name : "<<nm<<", is Found in Ticket List, Status : "<<boolalpha<<Temp->Status<<"....\a"<<endl;
							return true;
						}
					}
					
					Temp = Temp->next_tick;
				}
			}
			
			cout<<"Ticket with id : "<<i<<", &  name : "<<nm<<", not Found in Ticket List....\a"<<endl;
			return false;
		}
		
		void Sort_Ticket(){
			if(head == NULL){
				cout<<"Ticket List is Empty..."<<endl;
				return;
			}else{
				int n = 0;
				Ticket_Management* Temp = head;
				while(Temp != NULL){
					n++;
					Temp = Temp->next_tick;
				}
				cout<<"Enter Option for Sorting :\n" 
				       "1-by creation time\n"
					   "2-by name \n"
					   "3-by Priority "<<endl;
					   int option;
					   cin >>option;
					   
					   
				if(option == 1){
					cout<<"-----SORT LIST BY CREATION TIME------"<<endl;
					Ticket_Management* Temp = head;
					Ticket_Management* Arr[n];
					
					//Copy Elements to Array
					for(int i=0; i<n; i++){
						Arr[i] = Temp;
						Temp = Temp->next_tick;
					}
					
					//Use Bubble Sort for Sorting
					for(int i=0; i<n; i++){
						for(int j=0; j<n-1; j++){
							if(Arr[j]->Creation_time > Arr[j+1]->Creation_time){
								Ticket_Management* swap = Arr[j];
								Arr[j] = Arr[j+1];
								Arr[j+1] = swap;
							}
						}
					}
					//Array is Sort by Creation time now put it in list again
					head = Arr[0];
					Ticket_Management* tempswap = head;
					
					for(int i=1; i<n; i++){
						tempswap->next_tick = Arr[i];
						tempswap = tempswap->next_tick;
					}
				}else if(option == 2){
					cout<<"-----SORT LIST BY NAME------"<<endl;
					Ticket_Management* Temp = head;
					Ticket_Management* Arr[n];
					
					//Copy Elements to Array
					for(int i=0; i<n; i++){
						Arr[i] = Temp;
						Temp = Temp->next_tick;
					}
					
					//Use Bubble Sort for Sorting
					for(int i=0; i<n; i++){
						for(int j=0; j<n-1; j++){
							if(Arr[j]->name > Arr[j+1]->name){
								Ticket_Management* swap = Arr[j];
								Arr[j] = Arr[j+1];
								Arr[j+1] = swap;
							}
						}
					}
					
					//Array is Sort by Creation time now put it in list again
					head = Arr[0];
					Ticket_Management* tempswap = head;
					
					for(int i=1; i<n; i++){
						tempswap->next_tick = Arr[i];
						tempswap = tempswap->next_tick;
					}
					tempswap->next_tick = NULL;
					
				}else if(option == 3){
					
					cout<<"-----SORT LIST BY PRIORITY------"<<endl;
					Ticket_Management* Temp = head;
					Ticket_Management* Arr[n];
					
					//Copy Elements to Array
					for(int i=0; i<n; i++){
						Arr[i] = Temp;
						Temp = Temp->next_tick;
					}
					
					//Use Bubble Sort for Sorting
					for(int i=0; i<n; i++){
						for(int j=0; j<n-1; j++){
							if(Arr[j]->priority > Arr[j+1]->priority){
								Ticket_Management* swap = Arr[j];
								Arr[j] = Arr[j+1];
								Arr[j+1] = swap;
							}
						}
					}
					
					//Array is Sort by Creation time now put it in list again
					head = Arr[0];
					Ticket_Management* tempswap = head;
					
					for(int i=1; i<n; i++){
						tempswap->next_tick = Arr[i];
						tempswap = tempswap->next_tick;
					}
					tempswap->next_tick = NULL;	
				}else{
					cout<<"Invalid Option!!!"<<endl;
					Sort_Ticket();
				}
			}
		}
		
		void Display_List(){
			if(head == NULL){
				cout<<"Ticket List is Empty"<<endl;
				return;
			}else{
				cout<<"\n------DISPLAY TICKET LIST----------\a"<<endl;
				Ticket_Management* Temp = head;
				
				while(Temp != NULL){
					cout<<"ID : "<<Temp->id
					<<", Name : "<<Temp->name
					<<", Status : "<<boolalpha<<Temp->Status
					<<", Priority : "<<Temp->priority
					<<", Description : "<<Temp->service_description
					<<", Creation Time : "<<ctime(&Temp->Creation_time)<<endl;
					
					Temp = Temp->next_tick;
				}
        		cout << "--------------------------------" << endl;
			}
		}
		
		void Display_Open_Tickets(){
			if(head != NULL){
				cout<<"Display Open Status Ticket---"<<endl;
				Ticket_Management* Temp = head;
				while(Temp != NULL){
					if(Temp->Status){
						cout<<"ID : "<<Temp->id
						<<", Name : "<<Temp->name
						<<", Status : "<<boolalpha<<Temp->Status
						<<", Priority : "<<Temp->priority
						<<", Description : "<<Temp->service_description
						<<", Creation Time : "<<ctime(&Temp->Creation_time)<<endl;
						
						Temp = Temp->next_tick;
					}
				}
			}else{
				cout<<"List is NULL"<<endl;
			}
		}
		
		void Display_Resolution_Tickets(){
			if(head != NULL){
				cout<<"Display Resolve Ticket---"<<endl;
				Ticket_Management* Temp = head;
				while(Temp != NULL){
					if(!(Temp->Status)){
						cout<<"ID : "<<Temp->id
						<<", Name : "<<Temp->name
						<<", Status : "<<boolalpha<<Temp->Status
						<<", Priority : "<<Temp->priority
						<<", Description : "<<Temp->service_description
						<<", Closed Time : "<<ctime(&Temp->close_time)<<endl;
						
						Temp = Temp->next_tick;
					}
				}
			}else{
				cout<<"List is NULL"<<endl;
			}
		}
};

class Agent_Management{
	public :
		int Agent_id;
		string Agent_name;
		Ticket_Management* Assigned_ticket[5];
		int counter;
		bool Availability;
		Agent_Management* next_Agent;
		
		Agent_Management(int i, string n){
			Agent_id = i;
			Agent_name = n;
			Availability = true;
			counter = 0;
		}
		
		void AssignTicket(Ticket_Management* ticket){
			if(counter < 5){
				Assigned_ticket[counter] = ticket;
				
				counter++;
			}
			Availability = false;
		}
		
		int Resolve() {
    // Check if any tickets are assigned
    if (counter == 0 || Assigned_ticket == NULL) {
        cout << "No tickets are assigned to this agent. Please assign tickets first.\n";
        return -1; // Indicating no tickets to resolve
    }

    // Sort tickets by priority in descending order
    for (int i = 0; i < counter - 1; i++) {
        for (int j = 0; j < counter - i - 1; j++) {
            if (Assigned_ticket[j]->priority < Assigned_ticket[j + 1]->priority) {
                // Swap if priority of current is less than next
                Ticket_Management* temp = Assigned_ticket[j];
                Assigned_ticket[j] = Assigned_ticket[j + 1];
                Assigned_ticket[j + 1] = temp;
            }
        }
    }

    // Resolve the highest-priority ticket
    int resolvedTicketId = Assigned_ticket[0]->id;
    cout << "\nResolution of Ticket ID: " << resolvedTicketId
         << " is done successfully by Agent: " << Agent_name << endl;

    // Shift tickets in the array to remove the resolved ticket
    for (int i = 1; i < counter; i++) {
        Assigned_ticket[i - 1] = Assigned_ticket[i];
    }
    counter--; // Decrease the counter after removing the resolved ticket

    return resolvedTicketId;
}

		
		void Display_Assigned_Tickets(){
			if(counter == 0){
				cout<<"No list Assigned yet";
				return;
			}else{
			
				for(int i=0; i<counter; i++){
					
					cout<<"ID : "<<Assigned_ticket[i]->id
					<<", Name : "<<Assigned_ticket[i]->name
					<<", Status : "<<boolalpha<<Assigned_ticket[i]->Status
					<<", Priority : "<<Assigned_ticket[i]->priority
					<<", Description : "<<Assigned_ticket[i]->service_description
					<<", Closed Time : "<<ctime(&Assigned_ticket[i]->close_time)<<endl;
				}
			}
		}
};

class Agents{
	public :
	Agent_Management* head;
	
	Agents(){
		head = NULL;
	}
	
	public :
		void add_Agent(int i, string n){
		Agent_Management* Agent = new Agent_Management(i,n);
		
			if(head == NULL){
				head = Agent;
			}else{
				Agent_Management* Temp = head;
				
				while(Temp->next_Agent != NULL){
					Temp = Temp->next_Agent;
				}
				Temp->next_Agent = Agent;
				Agent->next_Agent = NULL;
				cout<<"Agent Inserted"<<endl;
			}
		}
		
		void Display_Agents(){
			if(head == NULL){
				cout<<"No agent"<<endl;
				return;
			}else{
				cout<<"DISPLAY ALL Agents ...."<<endl;
				Agent_Management* temp = head;
				while(temp != NULL){
					cout<<"Id : "<<temp->Agent_id<<", Name : "<<temp->Agent_name<<endl;
					temp = temp->next_Agent;
				}
			}
		}
		void Display_Assign_Tickets(){
			if(head == NULL){
				cout<<"No Agent"<<endl;
				return;
			}else{
				Agent_Management* temp = head;
				while(temp != NULL){
					temp->Display_Assigned_Tickets();
					temp = temp->next_Agent;
				}
			}
		}
};

int main(){
	cout<<"-----23k-3001 | ABDULLAH------"<<endl;
	cout<<"______________________________________________________"<<endl;
	cout<<"--------------ONE STOP MANAGEMENT SYSTEM--------------"<<endl;
	cout<<"______________________________________________________"<<endl;
	
	Ticket_list* list = new Ticket_list();
	Agents* agent = new Agents();
	
	
	int flag1 = 1;
	int flag2 = 1;
	int opt1;
	int opt2;
	while(flag1){
		
		cout<<"------MENU-------"<<endl;
		cout<<"Choose Option : "<<endl;
		cout<<"1.Admin"<<endl;
		cout<<"2.Student"<<endl;
		cout<<"3.exit"<<endl;
		cin>>opt1;
		
		flag2 = 1;
		
		if(opt1 == 1){
			
			
			while(flag2){
				cout<<"Choose Option FOR ADMIN : "<<endl;
				cout<<"1.Add Agent"<<endl;
				cout<<"2.Display List of Agents"<<endl;
				cout<<"3.Display Assigned Ticket"<<endl;
				cout<<"4.Sort"<<endl;
				cout<<"5.Display all Tickets"<<endl;
				cout<<"6.Resolve a Ticket Problem"<<endl;
				cout<<"7.Search"<<endl;
				cout<<"8.Display List of all Open Tickets"<<endl;
				cout<<"9.Display Resolution Tickets"<<endl;
				cout<<"10.Menu"<<endl;
				cin>>opt2;
				
				if(opt2 == 1){
					cout<<"Enter Name : ";
					string name;
					cin >>name;
					cout<<"Enter Id : ";
					int id;
					cin >> id;
					agent->add_Agent(id,name);
					
				}else if(opt2 == 2){
					
					agent->Display_Agents();
					
				}else if(opt2 == 3){
					
					agent->Display_Assign_Tickets();
					
					
				}else if(opt2 == 4){
					
					list->Sort_Ticket();
					
				}else if(opt2 == 5){
					
					list->Display_List();
					
				}else if(opt2 == 6){
					
					int id = agent->head->Resolve();
					list->Remove_Ticket(id);  //change this ticket status
					
				}else if(opt2 == 7){
					
					cout<<"Enter Name & Id to Search : "<<endl;
					string nm;
					int id;
					list->Search(nm, id);
					
				}else if(opt2 == 8){
					
					list->Display_Open_Tickets();
					
				}else if(opt2 == 9){
					
					list->Display_Resolution_Tickets();
					
				}else if(opt2 == 10){

					flag2 = 0;
					
				}else{
					cout<<"! Invalid Input....Choose option Correctly.."<<endl;
				}
			
			}
			
			
		}else if(opt1 == 2){
			
			
			while(flag2){
				
				cout<<"Choose Option for STUDENT : "<<endl;
				cout<<"1.Add Ticket"<<endl;
				cout<<"2.Sort"<<endl;
				cout<<"3.Display"<<endl;
				cout<<"4.Menu"<<endl;
				cin>>opt2;
				
				if(opt2 == 1){
					
					cout<<"Enter Name : ";
					string name;
					cin >>name;
					cout<<"Enter Id : ";
					int id;
					cin >> id;
					cout<<"Enter Description : ";
					string des;
					cin >>des;
					cout<<"Enter Priority : ";
					int priority;
					cin >> priority;
					
					Ticket_Management* tick = list->Add_Ticket(name,des,priority,id);
					agent->head->AssignTicket(tick);
					
				}else if(opt2 == 2){
					list->Sort_Ticket();
				}else if(opt2 == 3){
					list->Display_List();
				}else if(opt2 == 4){
					
					flag2 = 0;
						
				}else{
					cout<<"! Invalid Input....Choose option Correctly.."<<endl;
				}
			
			}	
			
		}else if(opt1 == 3){
			
			flag1 = 0;
			
		}else{
			
			cout<<"Invalid Option !!"<<endl;
			
		}
	}
	
	return 0;
}

