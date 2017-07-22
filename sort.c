extern int class_num;
extern struct HEAD sum[10];

void sort_by_char(int n,int ni,int order)
{
    int i;
    struct STUDENT *p,*pnew;
    for(i=1;i<sum[n].stu_num;i++)
    {
        p=array_p(n,i);
        delete_single_struct(&sum[n],p);
        pnew=find_new_place_char(n,i,ni,order,p);
        p->pnext=pnew->pnext;
        pnew->pnext=p;
    }
}

void sort_by_score(int n,int s_no,int order)
{
    int i;
    struct STUDENT *p,*pnew;
    for(i=1;i<sum[n].stu_num;i++)
    {
        p=array_p(n,i);
        delete_single_struct(&sum[n],p);
        pnew=find_new_place_score(n,i,s_no,order,p);
        p->pnext=pnew->pnext;
        pnew->pnext=p;
    }
}

void sort_all()
{
    int n,kind,o;
    n=choose_group(1);
    if(n==-1)
        return;
    kind=print_choose_kind_to_sort(&sum[n]);
    o=print_rise_or_down();
    if(kind>=1&&kind<=2)
    {
        sort_by_char(n,kind-1,o);
        sum[n].savetag=0;
    }
    else
    {
        sort_by_score(n,kind-3,o);
        sum[n].savetag=0;
    }
    print_after_sort(n);
    getchar();
    getchar();
}
