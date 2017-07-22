#ifndef CHAINED_LIST_H_INCLUDED
#define CHAINED_LIST_H_INCLUDED
extern int class_num;

int maxx(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int minn(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}

struct STUDENT
{
    char ni[2][30],gen;
    double score[10],ave,sum;
    int ranking;
    struct STUDENT *pnext;
};

struct HEAD
{
    char name[21];
    int cum_num,stu_num,id_len,name_len,savetag;
    struct STUDENT *phead;
};

extern struct HEAD sum[10];

int cmp_char(struct STUDENT *a,struct STUDENT *b,int ni,int order)//a在前,b在后
{
    if(order==1)
    {
        if(strcmp(a->ni[ni],b->ni[ni])>0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(strcmp(a->ni[ni],b->ni[ni])<0)
            return 1;
        else
            return 0;
    }
}

int cmp_score(struct STUDENT *a,struct STUDENT *b,int ni,int order,int n)//order:1降序,0升序
{
    if(order==1)
    {
        if(ni==sum[n].cum_num)
        {
            if(a->sum>b->sum)
                return 1;
            else
                return 0;
        }
        else
        {
            if(a->score[ni]>b->score[ni])
                return 1;
            else
                return 0;
        }
    }
    else
    {
        if(ni==sum[n].cum_num)
        {
            if(a->sum<b->sum)
                return 1;
            else
                return 0;
        }
        else
        {
            if(a->score[ni]<b->score[ni])
                return 1;
            else
                return 0;
        }
    }
}

struct STUDENT *find_p(struct HEAD *head,char ni[30],int o,struct STUDENT *phead,int swi)
{
    struct STUDENT *p;
    if(swi==0)
        p=head->phead;
    else
        p=phead;
    p=p->pnext;
    while(p!=NULL)
    {
        if(strcmp(p->ni[o],ni)==0)
            break;
        p=p->pnext;
    }
    return p;
}

struct STUDENT *find_p_before(struct HEAD *head,struct STUDENT *p2)
{
    struct STUDENT *p1;
    p1=head->phead;
    while(p1->pnext!=p2)
    {
        p1=p1->pnext;
        if(p1==NULL)
            break;
    }
    return p1;
}

struct STUDENT *array_p(int n,int j)
{
    int i=-1;
    struct STUDENT *p;
    p=sum[n].phead;
    while(p!=NULL)
    {
        i++;
        p=p->pnext;
        if(i==j)
            break;
    }
    return p;
}

struct STUDENT *find_new_place_char(int n,int ii,int ni,int order,struct STUDENT *p)
{
    struct STUDENT *p1,*p2;
    int i;
    p1=sum[n].phead;
    p2=p1->pnext;
    for(i=0;i<ii;i++)
    {
        if(cmp_char(p2,p,ni,order)==0)
            break;
        p1=p1->pnext;
        p2=p2->pnext;
        if(p2==NULL)
            break;
    }
    return p1;
}

struct STUDENT *find_new_place_score(int n,int ii,int ni,int order,struct STUDENT *p)
{
    struct STUDENT *p1,*p2;
    int i;
    p1=sum[n].phead;
    p2=p1->pnext;
    for(i=0;i<ii;i++)
    {
        if(cmp_score(p2,p,ni,order,n)==0)
            break;
        p1=p1->pnext;
        p2=p2->pnext;
        if(p2==NULL)
            break;
    }
    return p1;
}

int char_to_int(char data[])
{
    int res,i,len;
    len=strlen(data);
    res=0;
    for(i=0;i<len;i++)
    {
        res=res*10+data[i]-'0';
    }
    return res;
}

void delete_single_struct(struct HEAD *head,struct STUDENT *target)
{
    struct STUDENT *p1,*p2;
    p2=target;
    p1=find_p_before(head,p2);
    p1->pnext=p2->pnext;
}

void change_struct_char(int order,char datac[],struct STUDENT *data)
{
    if(order==2)
    {
        data->gen=datac[0];
        return ;
    }
    strcpy(data->ni[order],datac);
}

void change_struct_score(int order,double datai,struct STUDENT *data,struct HEAD *head)
{
    data->sum=data->sum-data->score[order];
    data->score[order]=datai;
    data->sum=data->sum+data->score[order];
    data->ave=data->sum/head->cum_num;
}



#endif // CHAINED_LIST_H_INCLUDED
