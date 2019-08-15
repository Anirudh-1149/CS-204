#include <bits/stdc++.h>
using namespace std;

struct coordinate{
	int x,y;
	struct coordinate* next;
};

void AddFirst(int a,int b,struct coordinate** headptr){
	if(*headptr == NULL){
		*headptr = new coordinate();
		(*headptr)->x = a;
		(*headptr)->y = b;
		(*headptr)->next = NULL;
	}
	else{
		coordinate* temp = new coordinate();
		temp->x =a;
		temp->y =b;
		temp->next = *headptr;
		*headptr = temp;
	}

}

void DelFirst(struct coordinate** headptr){
	if(*headptr == NULL){
		cout<<"-1"<<"\n";
	}
	else{
		coordinate* temp = *headptr;
    	*headptr = temp->next;
    	free(temp);
	}
} 

void Del(int a,int b,struct coordinate** headptr){
	coordinate* temp = *headptr;
	coordinate* temp_ = NULL; 
	int flag =0;
	while(temp!=NULL){
		if(temp->x==a&&temp->y==b&&temp_!=NULL){
			temp_->next = temp->next;
			free(temp);
			flag =1;
		}
		else if(temp_ == NULL&&temp->x==a&&temp->y==b){
			DelFirst(headptr);
			flag =1;
		}
		else{
			temp_ = temp;
			temp = temp->next;
	}
	}
		if(flag ==0){
			cout<<"-1"<<"\n";
		}
}
void search(double d, struct coordinate** headptr){
	coordinate* temp = *headptr;
	int flag =0;
	while(temp!= NULL){
		double len = sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y));
		if(len<=d){
			temp = temp->next;
			flag++;
		}
		else{
			temp = temp->next;	
		}
	}
	if(flag ==0){
			cout<<"-1"<<"\n";
		}
	else{
		cout<<flag<<"\n";
		}
}
void search(int a ,int b ,struct coordinate** headptr){
	coordinate* temp = *headptr;
	int flag = 0;
	while(temp!= NULL){
		if(temp->x==a&&temp->y==b){
			flag =1;
			break; 
		}
		else{
			temp = temp->next;
		}
	}
	if(flag==1){
		cout<<"True"<<"\n";
	}
	else{
		cout<<"False"<<"\n";
	}
}
void length(struct coordinate** headptr){
	coordinate* temp = *headptr;
	int i=0;
	while(temp!=NULL){
		temp= temp->next;
		i++;
	}
	cout<<i; 
}

int main(){
	coordinate* head = NULL;
	int condition;
	int T;
	cin>>T;
	while(T--){
		cin>>condition;
		if(condition==1){
			int a,b;
			cin>>a>>b;
			AddFirst(a,b,&head);
		}
		else if(condition ==2){
			DelFirst(&head);
		}
		else if(condition == 3){
			int a,b;
			cin>>a>>b;
			Del(a,b,&head);
		}
		else if(condition==4){
			double a;
			cin>>a;
			search(a,&head);
		}
		else if(condition==5){
			int a,b;
			cin>>a>>b;
			search(a,b,&head);
		}
		else if(condition ==6){
			length(&head);
		}

	}
	return 0;
}
