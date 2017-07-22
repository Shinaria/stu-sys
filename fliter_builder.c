extern int class_num;
extern struct HEAD sum[10];


void build_nl(struct HEAD *head)
{
    struct STUDENT *p1,*p2;
    head->stu_num=0;
    head->id_len=0;
    head->name_len=0;
    print_getstudata(head);
    head->phead=malloc(sizeof(struct STUDENT));
    p1=head->phead;
    int i;
    while(1)
    {
        p2=malloc(sizeof(struct STUDENT));
        p2->pnext=NULL;
        p2->ave=0;
        p2->sum=0;
        scanf("%s",p2->ni[0]);
        head->id_len=maxx(head->id_len,strlen(p2->ni[0]));
        if(strcmp(p2->ni[0],"end")==0)
        {
            free(p2);
            p1->pnext=NULL;
            break;
        }
        scanf("%s",p2->ni[1]);
        head->name_len=maxx(head->name_len,strlen(p2->ni[1]));
        do
        {
            scanf("%c",&p2->gen);
        }while(p2->gen!='f'&&p2->gen!='m');
        for(i=0;i<head->cum_num;i++)
        {
            scanf("%lf",&p2->score[i]);
            p2->sum+=p2->score[i];
        }
        p2->ave=p2->sum/head->cum_num;
        p1->pnext=p2;
        p1=p2;
        p2=p2->pnext;
        head->stu_num+=1;
        print_getstudata(head);
    }
    head->savetag=0;
}

void delete_cl(int n)
{
    struct STUDENT *p1,*p2;
    p1=sum[n].phead;
    p2=p1->pnext;
    while(p2!=NULL)
    {
        free(p1);
        p1=p2;
        p2=p2->pnext;
    }
    free(p2);
    sum[n].phead=NULL;
}

void add_data_tl(int n)
{
    int i;
    struct STUDENT *p1,*p2;
    p1=sum[n].phead;
    p2=p1->pnext;
    while(p1->pnext!=NULL)
        p1=p1->pnext;
    print_getstudata(&sum[n]);
    while(1)
    {
        p2=malloc(sizeof(struct STUDENT));
        p2->pnext=NULL;
        p2->ave=0;
        p2->sum=0;
        scanf("%s",p2->ni[0]);
        sum[n].id_len=maxx(sum[n].id_len,strlen(p2->ni[0]));
        if(strcmp(p2->ni[0],"end")==0)
        {
            free(p2);
            p1->pnext=NULL;
            break;
        }
        scanf("%s",p2->ni[1]);
        sum[n].name_len=maxx(sum[n].name_len,strlen(p2->ni[1]));
        do
        {
            scanf("%c",&p2->gen);
        }while(p2->gen!='f'&&p2->gen!='m');
        for(i=0;i<sum[n].cum_num;i++)
        {
            scanf("%lf",&p2->score[i]);
            p2->sum+=p2->score[i];
        }
        p2->ave=p2->sum/sum[n].cum_num;
        p1->pnext=p2;
        p1=p2;
        p2=p2->pnext;
        sum[n].stu_num+=1;
        print_getstudata(&sum[n]);
    }
    sum[n].savetag=0;
}

void delete_data_il(int n)
{
    struct STUDENT *target;
    int o;
    o=print_forget_which_plus();
    if(o==-1)
        return;
    ddi_m2:
    target=get_target(o,n);
    if(target==NULL)
        return;
    delete_single_struct(&sum[n],target);
    free(target);
    printf("\n    É¾³ý³É¹¦!");
    sum[n].savetag=0;
    getchar();
    getchar();
    goto ddi_m2;
}

void change_single_struct(int n,struct STUDENT *data)
{
    char order[10],datac[30];
    int o;
    double datai;
    css_m1:
    o=print_choose_kind(&sum[n],data);
    print_get_change_data();
    if(o>=1&&o<=3)
    {
        scanf("%s",datac);
        change_struct_char(o-1,datac,data);
    }
    else
    {
        scanf("%lf",&datai);
        change_struct_score(o-4,datai,data,&sum[n]);
    }
    print_after_change_struct(data,&sum[n]);
    scanf("%s",order);
    sum[n].savetag=0;
    if(order[0]=='Y'||order[0]=='y')
        goto css_m1;
    else
        return;
}

void change_single_stu(int n)
{
    struct STUDENT *target;
    int o;
    o=print_forget_which_plus();
    if(o==-1)
        return;
    target=get_target(o,n);
    if(target==NULL)
        return;
    change_single_struct(n,target);
}

void build_new_list()
{
    int no;
    print_build_new_list();
    no=choose_group(0);
    if(no==-1)
        return;
    getname(no);
    sum[no].cum_num=print_getnumcum();
    sum[no].phead=malloc(sizeof(struct STUDENT));
    build_nl(&sum[no]);
    class_num++;
}

void delete_chained_list()
{
    int no;
    no=choose_group(1);
    if(no==-1)
        return;
    delete_cl(no);
    class_num--;
}

void change_chained_list()
{
    int no;
    char order[20];
    no=choose_group(1);
    if(no==-1)
        return;
    print_add_or_delete();
    scanf("%s",order);
    if(strlen(order)==1&&order[0]=='1')
        add_data_tl(no);
    else if(strlen(order)==1&&order[0]=='2')
        delete_data_il(no);
    else
        return;
}

void change_stu_data()
{
    int no;
    no=choose_group(1);
    if(no==-1)
        return;
    change_single_stu(no);
}

