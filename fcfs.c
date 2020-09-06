#include<stdio.h>
#include<stdlib.h>
#define max 5
struct fcfs
{
char process_name[10];
int cpu_time;
int arr_time;
}s[10];
int c_time[10],w_time[10],t_time[10],l,k;
float average(int a[10],int n)
{
    int i;
    float sum=0.0,temp;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    temp=sum/n;
    return temp;
    
}
void cal(int n)
{ 
int i;
c_time[0]=0;
    for(i=0;i<n;i++)
    {
        if(i==0)
         c_time[i]=c_time[i]+s[i].cpu_time;
         else
         c_time[i]=c_time[i-1]+s[i].cpu_time;
        t_time[i]=c_time[i]-s[i].arr_time;
        w_time[i]=t_time[i]-s[i].cpu_time;
    }
    printf("calculation completed\n");
}
void read(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
    
        printf("enter P_name,cpu_time,arr_time");
        scanf("%s",s[i].process_name);
        scanf("%d",&s[i].cpu_time);
        scanf("%d",&s[i].arr_time);
    }
    
}

void display(int n)
{
int i;
float m,t,o;
m=average(c_time,n);
t=average(t_time,n);
o=average(w_time,n);
printf("process_name     cpu_time      arrival_time    completion_time   turnaround_time    waiting_time\n");
    for(i=0;i<n;i++)
        {
            printf("%10s %10d %14d %14d %16d %16d\n",s[i].process_name,s[i].cpu_time,s[i].arr_time,c_time[i],t_time[i],w_time[i]);
        }
        printf("\t\t  \t\t  \t\t %8f %15f %15f",m,t,o);

}
void sor_t(int n)
{
    struct fcfs temp;
    int i,j,k;
    printf("hello");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[j].arr_time<s[i].arr_time)
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    printf("sorting completed\n");
}
int main()
{
int n;
printf("enter no of process");
scanf("%d",&n);
read(n);
sor_t(n);
cal(n);
display(n);
}

