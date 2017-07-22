#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
extern int class_num;
extern struct HEAD sum[10];
void gotoxy(int x, int y)
{
    COORD pos = {x,y};                 //���ù��λ��
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);    // ��ȡ��׼����豸���
    SetConsoleCursorPosition(hOut, pos);      //���������ֱ���ָ���ĸ����壬ʲôλ�ã�
}//�˴�����ʹ�õ����ϵĴ���
void print_screen_two()
{
    system("CLS");
    int i;
    for(i=0;i<62;i++)
        printf("=");
    gotoxy(0,19);
    for(i=0;i<62;i++)
        printf("=");
}
void print_screen_one()
{
    system("CLS");
    int i;
    for(i=0;i<62;i++)
        printf("=");
}
void print_blank(int n)
{
    int i;
    for(i=0;i<n;i++)
        printf(" ");
}

void print_add_or_delete()
{
    print_screen_two();
    gotoxy(6,4);
    printf("1.���������������µ�ѧ������");
    gotoxy(6,6);
    printf("2.ɾ�����������е�ĳЩ����");
    gotoxy(6,8);
    printf("������ָ��:");
    gotoxy(6,9);
    printf("ע:�������ָ���0��ֱ�ӷ���");
    gotoxy(19,8);
}

void print_after_change_struct(struct STUDENT *data,struct HEAD *head)
{
    void print_single_struct();
    print_screen_two();
    gotoxy(4,2);
    printf("�޸ĺ���������:");
    gotoxy(4,4);
    print_single_struct(4,data,head);
    gotoxy(4,7);
    printf("�Ƿ�����޸�? (Y/N��س�) ");
}

void print_after_sort(int n)
{
    void print_chained_list();
    print_screen_one();
    gotoxy(4,2);
    printf("�������������:");
    gotoxy(4,5);
    print_chained_list(4,&sum[n]);
    gotoxy(4,3);

}

void print_build_new_list()
{
    print_screen_two();
    gotoxy(22,7);
    printf("����%d��ѧ����¼\n",class_num);
    gotoxy(22,9);
    system("PAUSE");

}

void print_chained_list(int x,struct HEAD *head)
{
    struct STUDENT *p;
    p=head->phead;
    p=p->pnext;
    int i,ii;
    printf("ѧ��");
    print_blank(head->id_len-2);
    printf("����");
    print_blank(head->name_len-2);
    printf("�Ա�");
    print_blank(1);
    printf("�ɼ�");
    print_blank(9*head->cum_num-4);
    printf("�ܳɼ�   ƽ���ɼ�\n");
    print_blank(x-3);
    ii=0;
    while(p!=NULL)
    {
        ii++;
        printf("%d).%s",ii,p->ni[0]);
        print_blank(head->id_len-strlen(p->ni[0])+2);
        printf("%s",p->ni[1]);
        print_blank(head->name_len-strlen(p->ni[1])+2);
        if(p->gen=='m')
            printf("��");
        else
            printf("Ů");
        printf("   ");
        for(i=0;i<head->cum_num;i++)
            printf("%-7.2lf  ",p->score[i]);
        printf("%-7.2lf  %-7.2lf",p->sum,p->ave);
        printf("\n");
        for(i=0;i<x-3;i++)
            printf(" ");
        p=p->pnext;
    }
}

int print_choose_kind(struct HEAD *head,struct STUDENT *data)
{
    void print_single_struct();
    int o;
    char order[10];
    css_m1:
    print_screen_two();
    gotoxy(4,2);
    print_single_struct(4,data,head);
    gotoxy(4,7);
    int i;
    printf("1).ѧ�� 2).���� 3).�Ա� ");
    for(i=4;i<4+head->cum_num;i++)
        printf("%d).�ɼ�%d ",i,i-3);
    gotoxy(4,5);
    printf("������Ҫ���ĵ���������: ");
    scanf("%s",order);
    o=char_to_int(order);
    if(o<=0||o>3+head->cum_num)
    {
        printf("\n    �������,��س�����������!");
        getchar();
        getchar();
        goto css_m1;
    }
    return o;
}

int print_choose_kind_to_sort(struct HEAD *head)
{
    sa_m2:
    print_screen_two();
    gotoxy(4,7);
    int i,kind;
    char order[30];
    printf("1).ѧ�� 2).���� ");
    for(i=3;i<3+head->cum_num;i++)
        printf("%d).�ɼ�%d ",i,i-2);
    printf("%d).�ܳɼ�",3+head->cum_num);
    gotoxy(4,5);
    printf("������Ҫ�������������: ");
    scanf("%s",order);
    kind=char_to_int(order);
    if(kind<=0||kind>3+head->cum_num)
    {
        printf("\n    �������,��س�����������!");
        getchar();
        getchar();
        goto sa_m2;
    }
    return kind;
}

void print_display_chained_list(int n,struct HEAD *head)
{
    print_screen_one();
    gotoxy(4,3);
    printf("��Ϊ��%d������,����%s\n    ��%d�ſγ�,��ѧ��%d��",n+1,head->name,head->cum_num,head->stu_num);
    gotoxy(4,6);
    print_chained_list(4,head);
    gotoxy(4,8+head->stu_num);
    system("PAUSE");
}

void print_file_to_list(struct HEAD *head)
{
    print_screen_one();
    gotoxy(4,2);
    printf("�ѽ���Щ���ݴ���ϵͳ:");
    gotoxy(4,4);
    print_chained_list(4,head);
    printf("\n\n    ");
}

void print_final_save()
{
    int i;
    print_screen_two();
    gotoxy(4,2);
    printf("ϵͳ�л���������Ϣδ����!\n");
    for(i=0;i<10;i++)
    {
        if(sum[i].phead!=NULL&&sum[i].savetag==0)
            printf("\n    %d).%s",i+1,sum[i].name);
    }
    gotoxy(4,15);
    printf("�Ƿ񷵻�?     (Y/N)");
    gotoxy(15,15);
}

void print_find_answer()
{
    print_screen_one();
    gotoxy(4,3);
    printf("������������:");
    gotoxy(4,5);
}

void print_forget_which()
{
    print_screen_two();
    gotoxy(6,4);
    printf("1.��ѧ�Ų���");
    gotoxy(6,6);
    printf("2.����������");
    gotoxy(6,8);
    printf("������ָ��:");
    gotoxy(6,9);
    printf("ע:�������ָ���0��ֱ�ӷ���");
    gotoxy(19,8);
}

int print_forget_which_plus()
{
    print_screen_two();
    gotoxy(6,4);
    printf("1.��ѧ�Ų���");
    gotoxy(6,6);
    printf("2.����������");
    gotoxy(6,8);
    printf("3.������,�г�������������");
    gotoxy(6,10);
    printf("������ָ��:");
    gotoxy(6,11);
    printf("ע:�������ָ���0��ֱ�ӷ���");
    gotoxy(19,10);
    char order[10];
    int o;
    scanf("%s",order);
    if(order[0]=='1'&&strlen(order)==1)
        o=0;
    else if(order[0]=='2'&&strlen(order)==1)
        o=1;
    else if(order[0]=='3'&&strlen(order)==1)
        o=2;
    else
        o=-1;
    return o;
}

void print_get_change_data()
{

    print_screen_two();
    gotoxy(10,6);
    printf("�������µ�����,�Իس�����");
    gotoxy(10,8);
}

void print_getname()
{
    print_screen_two();
    gotoxy(10,6);
    printf("�������½��������(������20��Ӣ���ַ���):");
    gotoxy(10,7);
}

int print_getnumcum()
{
    char temp[10];
    int res;
    print_screen_two();
    gotoxy(10,6);
    printf("�������½��鴢��ɼ��Ŀγ�����(���Ϊ10):");
    gotoxy(10,10);
    printf("ע:���������,��Ĭ�Ͽγ�����Ϊ5");
    gotoxy(10,7);
    scanf("%s",temp);
    if(temp[1]=='\0'&&temp[0]>='1'&&temp[0]<='9')
        res=temp[0]-'0';
    else if(temp[2]=='\0'&&temp[0]=='1'&&temp[1]=='0')
        res=10;
    else
        res=5;
    return res;
}

void print_get_road()
{
    print_screen_two();
    char c;
    c='\\';
    gotoxy(4,2);
    printf("�������ļ�����·�����ļ���:");
    gotoxy(2,7);
    printf("��: text.txt (�ļ��뱾������ͬһ�ļ�����)\n");
    printf("      D:%c%colder%c%cext.txt (�ļ��ڴ�·���е�folder�ļ�����)",c,'f',c,'t');
    gotoxy(4,4);
}

void print_getstudata(struct HEAD *head)
{
    void print_chained_list();
    print_screen_one();
    gotoxy(4,2);
    printf("����¼��������%s",head->name);
    gotoxy(4,3);
    printf("�밴���¸�ʽ����:");
    gotoxy(4,5);
    printf("ѧ�� ���� �Ա�(m:���� f:Ů��) �ɼ�(�ո�ָ�)");
    gotoxy(4,6);
    printf("ע:����������Ҫ��¼%d�ſεĳɼ�",head->cum_num);
    gotoxy(4,8);
    printf("���Ҫֹͣ����,��ֱ������endȻ��س�");
    if(head->stu_num!=0)
    {
        gotoxy(4,12);
        printf("�Ѿ�¼��%d��ѧ��,��������:",head->stu_num);
        gotoxy(4,14);
        print_chained_list(4,head);
    }
    gotoxy(4,10);
}

void print_get_search_data()
{
    print_screen_two();
    gotoxy(10,6);
    printf("������Ҫ���ҵ�����,�Իس�����");
    gotoxy(10,8);
}

void print_goodbye()
{
    print_screen_two();
    gotoxy(29,7);
    printf("�ټ�!");
    gotoxy(0,20);
}

void print_group_or_single()
{
    print_screen_two();
    gotoxy(6,4);
    printf("1.ɾ����������");
    gotoxy(6,6);
    printf("2.���ӻ�ɾ������ѧ��������");
    gotoxy(6,8);
    printf("������ָ��:");
    gotoxy(6,9);
    printf("ע:�������ָ���0��ֱ�ӷ���");
    gotoxy(19,8);
}

void print_head_sum(struct HEAD sum[10])
{
    print_screen_two();
    gotoxy(4,2);
    printf("������Ҫ������ѧ��������ı��");
    int i;
    for(i=0;i<10;i++)
    {
        gotoxy(4,4+i);
        printf("%d",i+1);
        if(sum[i].phead==NULL)
            printf("(������).");
        else
            printf(".%s",sum[i].name);
    }
    gotoxy(4,15);
    printf("������(����0����������򷵻���һ��):  ");
}

void print_list_to_file(struct HEAD *head)
{
    print_screen_one();
    gotoxy(4,2);
    printf("���������������ļ�:");
    gotoxy(4,4);
    print_chained_list(4,head);
    printf("\n\n    ");
}

void print_main(int wor)
{
    print_screen_two();
    gotoxy(0,3);
    printf("                           ���˵�\n\n");
    printf("             1.����ѧ������      5.��ɾѧ����Ϣ\n\n");
    printf("             2.�޸�ѧ����Ϣ      6.ѧ����������\n\n");
    printf("             3.��ʾѧ����Ϣ      7.���������ļ�\n\n");
    printf("             4.��ѯѧ����Ϣ      8.��ȡ�����ļ�\n\n");
    printf("                        9.�˳�ϵͳ\n\n");
    printf("             ������ָ��,���س�����:     ");
    gotoxy(4,17);
    if(wor==1)
        printf("ָ�����,����������");
    else if(wor==0)
        ;
    gotoxy(37,15);
}

int print_rise_or_down()
{
    char order[30];
    int o;
    sa_m3:
    print_screen_two();
    gotoxy(12,4);
    printf("��ѡ�������ǽ���(����:1 ����:2):");
    gotoxy(12,6);
    scanf("%s",order);
    if(order[0]=='1'&&strlen(order)==1)
        o=0;
    else if(order[0]=='2'&&strlen(order)==1)
        o=1;
    else
    {
        printf("\n            �������,��س�����������!");
        getchar();
        getchar();
        goto sa_m3;
    }
    return o;
}

void print_single_struct(int x,struct STUDENT *p,struct HEAD *head)
{
    int i;
    printf("ѧ��");
    print_blank(head->id_len-2);
    printf("����");
    print_blank(head->name_len-2);
    printf("�Ա�");
    print_blank(1);
    printf("�ɼ�");
    print_blank(9*head->cum_num-4);
    printf("�ܳɼ�   ƽ���ɼ�\n");
    print_blank(x);
    printf("%s",p->ni[0]);
    print_blank(head->id_len-strlen(p->ni[0])+2);
    printf("%s",p->ni[1]);
    print_blank(head->name_len-strlen(p->ni[1])+2);
    if(p->gen=='m')
        printf("��");
    else
        printf("Ů");
    printf("   ");
    for(i=0;i<head->cum_num;i++)
        printf("%-7.2lf  ",p->score[i]);
    printf("%-7.2lf  %-7.2lf",p->sum,p->ave);
    printf("\n\n");
    for(i=0;i<x;i++)
        printf(" ");
}

void print_welcome()
{
    print_screen_two();
    gotoxy(0,6);
    printf("                ��ӭʹ��ѧ����Ϣ����ϵͳ");
    gotoxy(16,7);
    system("PAUSE");
}


#endif // SCREEN_H_INCLUDED
