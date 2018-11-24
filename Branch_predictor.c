#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
 char b1[10],b2[10],b3[10],d[10],m1[2],m2[2],m3[2];
  int i1,i2,i3;
struct mainnode
{
	char institute[10];
	struct mainnode *nxt;
	struct mainnode *down;
} *head1=NULL,*root,*temp;

struct node
{
	int data;
	char branch[10];
	struct node *next;	
}*head=NULL,*tempo,*horroot;

void addmain(char x[])
{
	
	if (head1==NULL)
	{
		head1=(struct mainnode *)malloc(sizeof(struct mainnode));
		root=head1;
		strcpy(head1->institute,x);
		addhor(i1,b1);
		addhor(i2,b2);
		addhor(i3,b3);
		head1->nxt=horroot;
		head1->down=NULL;
   	}
	
	else
	{
		while(head1->down!=NULL)
		{
			head1=head1->down;
		}
		head1->down=(struct mainnode *)malloc(sizeof(struct mainnode));
		head1=head1->down;
		strcpy(head1->institute,x);
		addhor(i1,b1);
		addhor(i2,b2);
		addhor(i3,b3);
	
		
		head1->nxt=horroot;
		head1->down=NULL;
	}
	head=NULL;
}

void addhor(int a,char  x[]){
	
	if (head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node*));
		horroot=head;
		head->data=a;
		strcpy(head->branch,x);
		head->next=NULL;
	}
	else
	{
		head=horroot;
		while(head->next!=NULL)
		{
			head=head->next;
		}
		head->next=(struct node *)malloc(sizeof(struct node*));
		head=head->next;
		head->data=a;
		strcpy(head->branch,x);
		head->next=NULL;	
	}
	
}

display( int score)
{
	temp=root;
	while(temp!=NULL)
    {
		printf("%s ||",temp->institute);
		tempo=temp->nxt;
		head=tempo;
		struct node *newnode;
		while(tempo!=NULL)
    	{
	         while(tempo!=NULL && tempo->data<score)
	  		{   
	    	  	newnode=tempo;
	    		tempo=tempo->next;
	   		}
	         if(tempo==head)
	        {
	   			head=tempo->next;
	   			free(tempo);
	   			tempo=head;
	   		}
	   		 else if (tempo==NULL)
	   		{
	   			head=head;
	   		}
	   		 else
	   		{
	   			newnode->next=tempo->next;
	   			free(tempo);
	   			tempo=newnode->next;
	   		}
	    }
		tempo=head;
		while(tempo!=NULL)
		{
	    	printf("   ");
			printf(" %s",tempo->branch);
			printf(" -->");
			printf(" %d",tempo->data);
			tempo=tempo->next;
		}
		printf("\n");
		temp=temp->down;
   }	
}
void main()
{   int score;
    char a[10],b[10],ins[10];
    int i;
    printf("ENTER YOUR JEE SCORE \n");
    scanf("%d",&score);
    printf("the branches you are eligible for are \n");
    FILE *fptr;
	fptr = fopen("TRY.txt", "r");
	fscanf(fptr,"%s %s  %s  /n",b1,b2,b3);
    for(i=0;i<5;i++)
    { 
      fscanf(fptr,"%s %s %s %s  /n",ins,m1,m2,m3);
	  i1=atoi(m1) ;
	  i2=atoi(m2) ;
	  i3=atoi(m3) ;
	  addmain(ins);
    }	
	display(score);
}

