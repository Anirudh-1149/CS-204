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
		cout<<"-1";
	}
	else{
		coordinate* temp = *headptr;
    	*headptr = temp->next;
    	free(temp);
    	cout<<"0";
	}
} 

void Del(int a,int b,struct coordinate** headptr){
	coordinate* temp = *headptr;
	coordinate* temp_ = NULL;
	int flag = 0; 
	while(temp!=NULL){
		if(temp->x==a&&temp->y==b&&temp_!=NULL){
			temp_->next = temp->next;
			free(temp);
			cout<<"0";
			flag =1;
			break;
		}
		else if(temp_ == NULL&&temp->x==a&&temp->y==b){
			DelFirst(headptr);
			flag = 1;
			break;
		}
		else{
			temp_ = temp;
			temp = temp->next;

		}
	}
	if(flag == 0)
		cout<<"-1";
}
void search(double d, struct coordinate** headptr){
	coordinate* temp = *headptr;
	while(temp!= NULL){
		double len = sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y));
		if(len<=d){
			cout<<temp->x<<" "<<temp->y<<"\n";
			temp = temp->next;
		}
		else{
			temp = temp->next;	
		}
	}
}
void search(int a ,int b ,struct coordinate** headptr){
	coordinate* temp = *headptr;
	int flag = 0;
	while(temp!= NULL){
		if(temp->x==a&&temp->y==b){
			flag++;
			temp = temp->next;
		}
		else{
			temp = temp->next;
		}
	}
	if(flag>=1){
		cout<<flag;
	}
	else{
		cout<<false;
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
	int T;
	cin>>T;
	while(T--){
	int condition;
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

