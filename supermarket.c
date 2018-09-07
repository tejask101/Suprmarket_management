#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

char ch;
typedef struct store
{
	int id;
	char name[30],catagory[30];
	int price,qty;
	struct store *link,*link1;
	
}node;


void swap(node *p1, node*p2);
int prod_count=0,key=0;
node *header=NULL;
node *get_node()
{
	return((node *)malloc(sizeof(node)));
}

node *header1=NULL;   // cart node and header pointer


node* search_node(int id)
{
	
}
void delay(int k)
{	
	int i=0,j;
	for(i=0;i<k;++i)
	{
	for(j=0;j<k;++j)
	{
	}
}}

void loading()
{int i;
	for(i=0; i<=10;++i)
	{
		delay(7000);
		printf(".");
	}
}

void sort_id(node *header)
{
	node *start = header;
	node *traverse;
	node *min;
	
	while(start->link)
	{
		min = start;
		traverse = start->link;
		
		while(traverse)
		{
										// Find minimum element from array 
			if( min->id > traverse->id )
			{
				min = traverse;
			}
			
			traverse = traverse->link;
		}
		swap(start,min);				// Put minimum element on starting location
		start = start->link;
	}
} 

void sort_price(node *header)
{
	node *start = header;
	node *traverse;
	node *min;
	
	while(start->link)
	{
		min = start;
		traverse = start->link;
		
		while(traverse)
		{
										// Find minimum element from array 
			if( min->price > traverse->price )
			{
				min = traverse;
			}
			
			traverse = traverse->link;
		}
		swap(start,min);				// Put minimum element on starting location
		start = start->link;
	}
} 

void sort_qty(node* header)
{
	node *start = header;
	node *traverse;
	node *min;
	
	while(start->link)
	{
		min = start;
		traverse = start->link;
		
		while(traverse)
		{
										// Find minimum element from array 
			if( min->qty > traverse->qty )
			{
				min = traverse;
			}
			
			traverse = traverse->link;
		}
		swap(start,min);				// Put minimum element on starting location
		start = start->link;
	}
} 
 
 
 
/* swap data field of linked list */
void swap(node *p1, node*p2)
{
	int temp_id,temp_price,temp_qty;
	char temp_cat[30],temp_name[30];
	temp_id = p1->id;
	p1->id = p2->id;
	p2->id = temp_id;
	
	temp_price = p1->price;
	p1->price = p2->price;
	p2->price = temp_price;
	
	temp_qty = p1->qty;
	p1->qty = p2->qty;
	p2->qty = temp_qty;
	
	strcpy(temp_name,p1->name);
	strcpy(p1->name,p2->name);
	strcpy(p2->name,temp_name);

	strcpy(temp_cat,p1->catagory);
	strcpy(p1->catagory,p2->catagory);
	strcpy(p2->catagory,temp_cat);
}

void insert()
{   
	prod_count++; 
    int id;
	char name[30],catagory[30];
	int price,qty;

	node *p,*temp;
	printf("\t\t\t\t:Add Products:");
	printf("\n\n\nEnter ID:");
	scanf("%d",&id);
	for(temp=header;temp!=NULL;temp=temp->link)
	{
		while(temp->id==id)
		{
			printf("\n\n ID Exists Try Again (press any key)");
			getch();
			system("cls");
			printf("\n\nEnter ID:");
			scanf("%d",&id);
			temp=header;
		}
	}
	printf("\nEnter product name:");
	scanf("%s",name);
	printf("\nEnter catagory:");
	scanf("%s",catagory);
	printf("\nEnter price:");
	scanf("%d",&price);
	printf("\nEnter quantity:");
	scanf("%d",&qty);
    p=get_node();
	p->id=id;
	p->price=price;
	p->qty=qty;
	strcpy(p->name,name);
	strcpy(p->catagory,catagory);
	p->link=NULL;
	if(header==NULL)
		header=p;
	else
	{
		p->link=header;
		header=p;
	}
	printf("\n\n Press enter to continue");
	getch();
}

void add_cart(int id,int qty)
{   int k=0;
	node *temp;
	for(temp=header;temp!=NULL;temp=temp->link)
	{	k=0;
		if(id==temp->id)
		{
		k=1;
		break;	
		}
		else
		{
		k=0;
		printf("\n\n ID not Found.\n\n check Again");
	
		}
	}
	if(k==1)
	{
	k=0;
	node *p;
	if(temp->qty==0)
	printf("\n\n\tProduct Not In stock");
	else
	{
	temp->qty=temp->qty-qty;
	if(temp->qty<0)
	{	
		temp->qty=(temp->qty)+qty;
		printf("\n\n\tChoose fewer items (limited stock)");
		while(((temp->qty)-qty)<0)
		{
		printf("\n\n\tenter quantity:");
		scanf("%d",&qty);
		temp->qty=temp->qty-qty;
		}
	}
    p=get_node();
	p->id=temp->id;
	p->price=temp->price;
	p->qty=qty;
	strcpy(p->name,temp->name);
	strcpy(p->catagory,temp->catagory);
	p->link=NULL;
	if(header1==NULL)
		header1=p;
	else
	{
		p->link1=header1;
		header1=p;
	}
	printf("\n\n product added");
	loading();
	}
	
	
getch();
}
}

void display_cart()
{   
	node *temp;
	int total=0;
	for(temp=header1;temp!=NULL;temp=temp->link1)
		{
		printf("\n\n\tID:%d",temp->id);
		printf("\n\tproduct name:%s",temp->name);
		printf("\n\tcatagory:%s",temp->catagory);
		printf("\n\tprice:%d",temp->price);
		printf("\n\tQuantity:%d\n\n",temp->qty);
		total+= (temp->price)*(temp->qty);
		}
		printf("\n\n\t TOTAL = %d",total);
		printf("\n\n\t Press enter to continue");
		getch();
		
}


void del()
{	
	node *temp;
	if(header==NULL)
	{
		printf("Empty List\n");
		return;
	}
	else
	{
		
	printf("Enter id of product\n");
	int id;
	scanf("%d",&id);
	node* curr = header;
	while(curr != NULL){
		if(curr->id == id){
			break;
		}
		curr = curr->link;
	}
	if(curr == NULL){
		printf("There is no such product. Please enter valid choice\n");
	}
	else{
		if(curr == header){
			node *temp = header->link;
				printf("deleted product is\n");
				printf("ID:%d",curr->id);
				printf("\nproduct name:%s",curr->name);
				printf("\ncatagory:%s",curr->catagory);
				printf("\nprice:%d",curr->price);
				printf("\nQuantity:%d",curr->qty);
			free(curr);
			header=temp;
		}
		else{
			node *temp = header;
			while(temp->link != curr){
				temp = temp->link;
			}
			temp->link = curr->link;
				printf("deleted product is\n");
				printf("ID:%d",curr->id);
				printf("\nproduct name:%s",curr->name);
				printf("\ncatagory:%s",curr->catagory);
				printf("\nprice:%d",curr->price);
				printf("\nQuantity:%d",curr->qty);
			free(curr);
		}
	}
}
printf("\n\n Press enter to continue");
getch();
}

struct products
{
	char catagory[30];
}products[100];

void displaycat()
{
	printf("\n........... Catagories..........\n");
	int k=0,i,j,cat,key1=0,id,qty;
	char ch;
	node *temp1,*temp2;

		for(i=0,temp1=header;i<prod_count&&temp1!=NULL;++i,temp1=temp1->link)
		{
		temp2=header;
		for(j=0;j<=i&&temp2!=NULL;++j,temp2=temp2->link)
		{ 
		 	
			 if(strcmp(temp1->catagory,temp2->catagory)==0)
			 break;
		}
		if(i==j)
		{
		printf("\n\n\n\n%d.   %s.\n",++k,temp1->catagory);
		delay(11000);
		strcpy(products[k-1].catagory,temp1->catagory);
		}
	
}
//printf("\n\n Press enter to continue");
		//getch();
		node *temp,*t;
		printf(" \n\n Enter catagory No. ");
		scanf("%d",&cat);
		
		for(temp=header;temp!=NULL;temp=temp->link)
	{
		if(strcmp(products[cat-1].catagory,temp->catagory)==0)
		{
			key1=1;
		printf("\n\nID:%d",temp->id);
		printf("\nproduct name:%s",temp->name);
		printf("\ncatagory:%s",temp->catagory);
		printf("\nprice:%d",temp->price);
		printf("\nQuantity:%d\n\n",temp->qty);
		delay(22000);
		}
		if(key1==0)
		{
			printf("\n\n No products Found....\n");
		}
		

	
	
	}
	printf("\n\n Do you want to add items to cart (press y or n )?");
	scanf(" %c",&ch);
	if(ch=='y'||ch=='Y')
	{
		printf("\n\n\nEnter product Id: ");
		scanf("%d",&id);
		printf("\n\n\nEnter product qty: ");
		scanf("%d",&qty);
		add_cart(id,qty);
		
	}
printf("\n\n Press enter to continue");
getch();
}
void search()
{	
	int id,key=0;
	node *temp;
	printf("Enter the ID of product to be searched : ");
	scanf("%d",&id);
	for(temp=header;temp!=NULL;temp=temp->link)
	{
		if(id==temp->id)
		{
		key=1;
		printf("\nItem found");
		printf("\n\nID:%d",temp->id);
		printf("\nproduct name:%s",temp->name);
		printf("\ncatagory:%s",temp->catagory);
		printf("\nprice:%d",temp->price);
		printf("\nQuantity:%d",temp->qty);
		delay(22000);
	
		}
		
	}
	
	if(key==0)
	printf("product Not Found !!!\n");
	printf("\n\n Press enter to continue");
	getch();
}




void admin()
{	
	
	char username[30],password[30];
	system("cls");
	printf("\n\t\t:.:.:.:.:.:.:.:.:Login:.:.:.:.:.:.:.:.:");
	printf("\n\n\n\n\tEnter Details\n");
	printf("\n\tUsername: ");
	scanf("%s",&username);
	printf("\n\n\tPassword: ");
	scanf("%s",&password);
	
	if(strcmp(password,"p")==0)
	{
		printf("\n\n\n\tauthentication successful");
		delay(5000);
		key=1;
	}
	else
	{
		printf("\n\t\t authentication failed (incorrect password)");
		delay(5000);
		admin();
	}
	printf("\n\n\n\n\n\n\tlogging in as: %s\n\n\n\n\n\t(press enter)",username);
	loading();
	getch();
}


void menu()
{  		
	int choice,choice1;
	char ch;


				
				{
				system("cls");
				printf("\n\t\t\t\t:...............Main Menu..................:\n\n\n1 - Add a new product\n\n2 - Delete existing product\n\n3 - Search for a product\n\n4 - Display all products catagories\n\n5 - Display cart \n\n6 - sort items \n	1. By Id \n	2.By price \n	3.By quantity\n\n7 - sort cart \n	1. By Id \n	2.By price \n	3.By quantity\n\n8 - Press any other number to EXIT !\n");
				printf("\nchoice:");
				scanf("%d",&choice);
			
				switch(choice)
				{
				case 1 :system("cls");
						insert();
						break;
				case 2 :system("cls");
						del();
						break;
				case 3 :system("cls");
						search();						
						break;
				case 4 :system("cls");
					 	displaycat();					 
						break;
				case 5 :system("cls");
					 	display_cart();					 
						break;
				case 6 :system("cls");
					 	printf("\n\n\n 1. By Id \n	2.By price \n	3.By quantity\n\n enter choice:");
						 scanf("%d",&choice1);
						 if(choice1==1)
						 sort_id(header);	
						 else if(choice1==2)
						 sort_price(header);
						 else if(choice1==3)
						 sort_qty(header);	 
						break;	
				case 7	:system("cls");
					 	printf("\n\n\n 1. By Id \n	2.By price \n	3.By quantity\n\nenter choice:");
						 scanf("%d",&choice1);
						 if(choice1==1)
						 sort_id(header1);	
						 else if(choice1==2)
						 sort_price(header1);
						 else if(choice1==3)
						 sort_qty(header1);	 
						break;			
				default : 	exit(0);
							break;
				}
				}
}

int main()
{
	
	HANDLE  hConsole;
    int k=15;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     
  	SetConsoleTextAttribute(hConsole, k);
	if(k==255)
  	k=1;
	
	int choice,id,c1,c2;
	printf("\n\t\t:.:.:.:.:.:.:.:.:Welcome:.:.:.:.:.:.:.:.:\n\n\n\n\n\n\n\n\n\n\n\n\t\t:.:.:.:.:.:.:.:login to account.:.:.:.:.:.:.:.: \n");
				delay(19000);
				admin();
	while(1)
	{	
	
	
	menu();
	}
	
	return 0;
}


