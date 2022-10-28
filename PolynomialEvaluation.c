#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
int coef;
int expon;
struct poly *link;
};
typedef struct poly polyNode;
polyNode *a,*last_a,*b,*last_b,*c,*last_c,*node;
polyNode* getNode()
{
/*provide a node for use */
polyNode *node;
node=(polyNode*)malloc(sizeof(polyNode));
if(!node)
{
printf("INSUFFICIENT MEMEORY\n");
exit(0);
}
return node;
}
void attach(float coefficient,int exponent, polyNode **ptr)
{
/*create a new node with coeff=coefficient and expon=exponent, attach it to the node pointed to by ptr.ptr is updated to point to this new node. */
polyNode *temp;
temp=getNode();
temp->coef=coefficient;
temp->expon=exponent;
(*ptr)->link=temp;
*ptr=temp;
}
int COMPARE(int a, int b)
{
if(a==b)
return 0;
else if(a>b)
return 1;
else
return -1;
}
void cpadd(polyNode *a, polyNode *b)
{
//polynomials a and b are singly linked circular lists with a header node. Return a polynomial which is a sum of a and b
int sum;
while(a!=last_a->link && b!= last_b->link)
{
switch(COMPARE(a->expon,b->expon))
{
case -1:
//a->expon < b->expon
attach(b->coef,b->expon,&last_c);
b=b->link;
break;
case 0:
//a->expon = b->expon
sum=a->coef+b->coef;
if(sum) attach(sum,a->expon,&last_c);
a=a->link;
b=b->link;
break;
case 1:
//a->expon > b-expon
attach(a->coef,a->expon,&last_c);
a=a->link;
}
}
for(;a!=last_a->link;a=a->link)//remaining terms in a
attach(a->coef,a->expon,&last_c);
for(;b!=last_b->link;b=b->link)//remaining terms in b
attach(a->coef,a->expon,&last_c);
last_c->link=c;//link the last node of c to first node
}
void display_poly(polyNode *temp,polyNode *last)
{
while(temp!=last->link)
{
printf("%dX^%d + ",temp->coef,temp->expon);
temp=temp->link;
}
}
void peval(polyNode *temp,polyNode *last)
{
int eval=0,x;
printf("Enter the value of x\n");
scanf("%d",&x);
while(temp!=last->link)
{
eval=eval+temp->coef*pow(x,temp->expon);
temp=temp->link;
}
printf("The result of polynomial evaluation is: %d\n",eval);
}
void main()
{
int co,ex,n,m,i;
printf("******POLYNOMIAL ADDITION *******\n");
printf("Enter the number of terms in 1st polynomial\n");
scanf("%d",&m);
printf("Enter the number of terms in 2nd polynomial \n");
scanf("%d",&n);
a=(polyNode*)malloc(sizeof(polyNode));//headernode of a
last_a=a;
last_a->link=last_a;
b=(polyNode*)malloc(sizeof(polyNode));//headernode of b
last_b=b;
last_b->link=last_b;
//read 1st polynomial-a
for(i=1;i<=m;i++)
{
printf("Enter the %d term (coef and expon) of 1st polynomial\n",i);
scanf("%d%d",&co,&ex);
attach(co,ex,&last_a);
last_a->link=a;//circular list
}
//read 2nd polynomial -b
for(i=1;i<=n;i++)
{
printf("Enter the %d term (coef and expon) of 2nd polynomial\n",i);
scanf("%d%d",&co,&ex);
attach(co,ex,&last_b);
last_b->link=b;//circular list
}
//display a and b alon with result c
printf("*** 1st Polynomial a(x):");
display_poly(a->link,last_a);
printf("\n");
printf("*** 2nd Polynomial b(x):");
display_poly(b->link,last_b);
printf("\n");
c=(polyNode*)malloc(sizeof(polyNode));//headernode of a
last_c=c;
cpadd(a->link,b->link);
printf("*** Result c(x) :");
display_poly(c->link,last_c);
printf("\n");
printf("\n----------------------------------\n");
//evaluation of th result c
printf("******POLYNOMIAL EVALUATION*******\n");
peval(c->link,last_c);
}
