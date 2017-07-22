extern int class_num;
extern struct HEAD sum[10];


void find_in_group(int n)
{
    print_forget_which();
    char order[10],data[30];
    struct STUDENT *answer;
    int o,k;
    scanf("%s",order);
    if(order[0]=='1'&&strlen(order)==1)
        o=0;
    else if(order[0]=='2'&&strlen(order)==1)
        o=1;
    else
        return;
    print_get_search_data();
    scanf("%s",data);
    k=0;
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
    if(k!=0)
        printf("���ҵ�����%d��,�������\n         ",k);
    else
        printf("���ҵ�����0��,�޽��\n         ");
    getchar();
    getchar();
}

void forget_which()
{
    print_forget_which();
    char order[10],data[30];
    struct STUDENT *answer;
    int o,i,k;
    scanf("%s",order);
    if(order[0]=='1'&&strlen(order)==1)
        o=0;
    else if(order[0]=='2'&&strlen(order)==1)
        o=1;
    else
        return;
    print_get_search_data();
    scanf("%s",data);
    k=0;
    print_find_answer();
    for(i=0;i<10;i++)
        if(sum[i].phead!=NULL)
        {
            answer=find_p(&sum[i],data,o,NULL,0);
            if(answer!=NULL)
            {
                printf("��%d��,��������Ϊ%s,������ѧ��:\n    ",i+1,sum[i].name);
                k++;
                print_single_struct(4,answer,&sum[i]);
            }
            while(1)
            {
                answer=find_p(&sum[i],data,o,answer,1);
                if(answer==NULL)
                    break;
                k++;
                print_single_struct(4,answer,&sum[i]);

            }
        }
    if(k!=0)
        printf("���ҵ�����%d��,�������\n    ",k);
    else
        printf("���ҵ�����0��,�޽��\n    ");
    system("PAUSE");

}

void display_stu_data()
{
    int n;
    n=choose_group(1);
    if(n==-1)
        return;
    print_display_chained_list(n,&sum[n]);
}

void search_for_single_stu()
{
    int n;
    n=choose_group(2);
    if(n==-1)
        return;
    if(n<10)
        find_in_group(n);
    else
        forget_which();
}

