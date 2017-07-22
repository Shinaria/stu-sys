#ifndef CHOOSE_H_INCLUDED
#define CHOOSE_H_INCLUDED

extern int class_num;
extern struct HEAD sum[10];

int choose_group(int fu)
{
    print_head_sum(sum);
    if(fu==2)
    {
        gotoxy(4,18);
        printf("注:支持模糊查找,若要使用请输入11并回车");
        gotoxy(44,15);
    }
    char order[10];
    int no;
    cg_m1:
    scanf("%s",order);
    if(strlen(order)==1&&order[0]>='1'&&order[0]<='9')
        no=order[0]-'0'-1;
    else if(strlen(order)==2&&order[0]=='1'&&order[1]=='0')
        no=9;
    else if(strlen(order)==2&&order[0]=='1'&&order[1]=='1')
        return 10;
    else if(strlen(order)==1&&order[0]=='0')
        return -1;
    else
    {
        print_head_sum(sum);
        printf("\n    输入错误,请重新输入!");
        gotoxy(44,15);
        goto cg_m1;
    }
    if(fu==1)
    {
        if(sum[no].phead==NULL)
        {
            print_head_sum(sum);
            printf("\n    此组数据为空,无法操作!");
            gotoxy(44,15);
            goto cg_m1;
        }
    }
    else if(fu==0)
    {
        if(sum[no].phead!=NULL)
        {
            print_head_sum(sum);
            printf("\n    此组数据不为空,无法操作!");
            gotoxy(44,15);
            goto cg_m1;
        }
    }
    else if(fu==2)
    {
        if(sum[no].phead==NULL)
        {
            print_head_sum(sum);
            printf("\n    该组数据为空,无法操作!");
            gotoxy(4,18);
            printf("注:支持模糊查找,若要使用请输入11并回车");
            gotoxy(44,15);
            goto cg_m1;
        }

    }
    return no;
}

void getname(int no)
{
    char name[30];
    print_getname();
    scanf("%s",name);
    strcpy(sum[no].name,name);
}

struct STUDENT *get_target(int o,int n)
{
    int k;
    struct STUDENT *target,*answer;
    char data[30],order[10];
    ddi_m2:
    k=0;
    if(o==0||o==1)
    {
        print_get_search_data();
        scanf("%s",data);
        print_find_answer();
        if(sum[n].phead!=NULL)
        {
            answer=find_p(&sum[n],data,o,NULL,0);
            if(answer!=NULL)
            {
                k++;
                printf("%d).  ",k);
                print_single_struct(9,answer,&sum[n]);
            }
            while(answer!=NULL)
            {
                answer=find_p(&sum[n],data,o,answer,1);
                if(answer==NULL)
                    break;
                k++;
                printf("\b\b\b\b\b%d).  ",k);
                print_single_struct(9,answer,&sum[n]);
            }
        }
    }
    else
    {
        print_find_answer();
        k=sum[n].stu_num;
        printf("     ");
        print_chained_list(9,&sum[n]);
    }
    if(k!=0)
        printf("\n        查找到数据%d组,结果如上\n        ",k);
    else
    {
        printf("\n        查找到数据0组,无结果,将返回主界面\n         ");
        system("PAUSE");
        return NULL;
    }
    printf("请输入要修改的数据序号:     (停止操作可输入end)");
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    int d;
    scanf("%s",order);
    if(strcmp(order,"end")==0)
        return NULL;
    d=char_to_int(order);
    if(d<=0||d>k)
    {
        printf("\n         输入错误,请回车然后重新输入");
        goto ddi_m2;
    }
    target=NULL;
    answer=find_p(&sum[n],data,o,NULL,0);
    k=0;
    if(o==1||o==0)
    {
        if(answer!=NULL)
        {
            k++;
            if(k==d)
                target=answer;
        }
        while(target==NULL)
        {
            answer=find_p(&sum[n],data,o,answer,1);
            if(answer==NULL)
                break;
            k++;
            if(k==d)
                target=answer;
        }
    }
    else
        target=array_p(n,d-1);
    return target;
}

#endif // CHOOSE_H_INCLUDED
