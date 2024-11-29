#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void Create()
{
    struct Node *t, *last = NULL;
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    printf("Enter the terms in the form of coefficient and exponent :");
    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if (poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

long Eval(struct Node *p,int x){
   long val=0;
    while(p){
        val+=(p->coeff)*pow(x,p->exp);
        p=p->next;
    }
    return val;
}

void Display(struct Node *p)
{
    while (p)
    {
        if (p->exp == 0)
        {
            printf("%d", p->coeff);
            
        }
        else
        {
            printf("%dx^%d + ", p->coeff, p->exp);
        }
            p = p->next;
    }
    printf("\n");
}

int main()
{
    int x;
    Create();
    Display(poly);
    printf("Enter value of x : ");
    scanf("%d",&x);
    printf("Result of polynomial is : %ld",Eval(poly,x));
    

    return 0;
}