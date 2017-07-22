#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
extern int class_num;
extern struct HEAD sum[10];
void gotoxy(int x, int y)
{
    COORD pos = {x,y};                 //设置光标位置
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);    // 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos);      //两个参数分别是指定哪个窗体，什么位置？
}//此处代码使用的网上的代码
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
    printf("1.向该组数据中添加新的学生数据");
    gotoxy(6,6);
    printf("2.删除该组数据中的某些数据");
    gotoxy(6,8);
    printf("请输入指令:");
    gotoxy(6,9);
    printf("注:输入错误指令或0将直接返回");
    gotoxy(19,8);
}

void print_after_change_struct(struct STUDENT *data,struct HEAD *head)
{
    void print_single_struct();
    print_screen_two();
    gotoxy(4,2);
    printf("修改后数据如下:");
    gotoxy(4,4);
    print_single_struct(4,data,head);
    gotoxy(4,7);
    printf("是否继续修改? (Y/N后回车) ");
}

void print_after_sort(int n)
{
    void print_chained_list();
    print_screen_one();
    gotoxy(4,2);
    printf("排序后数据如下:");
    gotoxy(4,5);
    print_chained_list(4,&sum[n]);
    gotoxy(4,3);

}

void print_build_new_list()
{
    print_screen_two();
    gotoxy(22,7);
    printf("已有%d组学生记录\n",class_num);
    gotoxy(22,9);
    system("PAUSE");

}

void print_chained_list(int x,struct HEAD *head)
{
    struct STUDENT *p;
    p=head->phead;
    p=p->pnext;
    int i,ii;
    printf("学号");
    print_blank(head->id_len-2);
    printf("姓名");
    print_blank(head->name_len-2);
    printf("性别");
    print_blank(1);
    printf("成绩");
    print_blank(9*head->cum_num-4);
    printf("总成绩   平均成绩\n");
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
            printf("男");
        else
            printf("女");
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
    printf("1).学号 2).姓名 3).性别 ");
    for(i=4;i<4+head->cum_num;i++)
        printf("%d).成绩%d ",i,i-3);
    gotoxy(4,5);
    printf("请输入要更改的数据类型: ");
    scanf("%s",order);
    o=char_to_int(order);
    if(o<=0||o>3+head->cum_num)
    {
        printf("\n    输入错误,请回车后重新输入!");
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
    printf("1).学号 2).姓名 ");
    for(i=3;i<3+head->cum_num;i++)
        printf("%d).成绩%d ",i,i-2);
    printf("%d).总成绩",3+head->cum_num);
    gotoxy(4,5);
    printf("请输入要排序的数据类型: ");
    scanf("%s",order);
    kind=char_to_int(order);
    if(kind<=0||kind>3+head->cum_num)
    {
        printf("\n    输入错误,请回车后重新输入!");
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
    printf("此为第%d组数据,名称%s\n    有%d门课程,有学生%d人",n+1,head->name,head->cum_num,head->stu_num);
    gotoxy(4,6);
    print_chained_list(4,head);
    gotoxy(4,8+head->stu_num);
    system("PAUSE");
}

void print_file_to_list(struct HEAD *head)
{
    print_screen_one();
    gotoxy(4,2);
    printf("已将这些数据存入系统:");
    gotoxy(4,4);
    print_chained_list(4,head);
    printf("\n\n    ");
}

void print_final_save()
{
    int i;
    print_screen_two();
    gotoxy(4,2);
    printf("系统中还有下列信息未保存!\n");
    for(i=0;i<10;i++)
    {
        if(sum[i].phead!=NULL&&sum[i].savetag==0)
            printf("\n    %d).%s",i+1,sum[i].name);
    }
    gotoxy(4,15);
    printf("是否返回?     (Y/N)");
    gotoxy(15,15);
}

void print_find_answer()
{
    print_screen_one();
    gotoxy(4,3);
    printf("查找数据如下:");
    gotoxy(4,5);
}

void print_forget_which()
{
    print_screen_two();
    gotoxy(6,4);
    printf("1.以学号查找");
    gotoxy(6,6);
    printf("2.以姓名查找");
    gotoxy(6,8);
    printf("请输入指令:");
    gotoxy(6,9);
    printf("注:输入错误指令或0将直接返回");
    gotoxy(19,8);
}

int print_forget_which_plus()
{
    print_screen_two();
    gotoxy(6,4);
    printf("1.以学号查找");
    gotoxy(6,6);
    printf("2.以姓名查找");
    gotoxy(6,8);
    printf("3.不查找,列出该组所有数据");
    gotoxy(6,10);
    printf("请输入指令:");
    gotoxy(6,11);
    printf("注:输入错误指令或0将直接返回");
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
    printf("请输入新的数据,以回车结束");
    gotoxy(10,8);
}

void print_getname()
{
    print_screen_two();
    gotoxy(10,6);
    printf("请输入新建组的名称(长度在20个英文字符内):");
    gotoxy(10,7);
}

int print_getnumcum()
{
    char temp[10];
    int res;
    print_screen_two();
    gotoxy(10,6);
    printf("请输入新建组储存成绩的课程数量(最大为10):");
    gotoxy(10,10);
    printf("注:若输入错误,则默认课程数量为5");
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
    printf("请输入文件所在路径或文件名:");
    gotoxy(2,7);
    printf("例: text.txt (文件与本程序在同一文件夹下)\n");
    printf("      D:%c%colder%c%cext.txt (文件在此路径中的folder文件夹下)",c,'f',c,'t');
    gotoxy(4,4);
}

void print_getstudata(struct HEAD *head)
{
    void print_chained_list();
    print_screen_one();
    gotoxy(4,2);
    printf("正在录入数据至%s",head->name);
    gotoxy(4,3);
    printf("请按如下格式输入:");
    gotoxy(4,5);
    printf("学号 姓名 性别(m:男性 f:女性) 成绩(空格分隔)");
    gotoxy(4,6);
    printf("注:本组数据需要记录%d门课的成绩",head->cum_num);
    gotoxy(4,8);
    printf("如果要停止输入,请直接输入end然后回车");
    if(head->stu_num!=0)
    {
        gotoxy(4,12);
        printf("已经录入%d个学生,数据如下:",head->stu_num);
        gotoxy(4,14);
        print_chained_list(4,head);
    }
    gotoxy(4,10);
}

void print_get_search_data()
{
    print_screen_two();
    gotoxy(10,6);
    printf("请输入要查找的数据,以回车结束");
    gotoxy(10,8);
}

void print_goodbye()
{
    print_screen_two();
    gotoxy(29,7);
    printf("再见!");
    gotoxy(0,20);
}

void print_group_or_single()
{
    print_screen_two();
    gotoxy(6,4);
    printf("1.删除整组数据");
    gotoxy(6,6);
    printf("2.增加或删除单组学生的数据");
    gotoxy(6,8);
    printf("请输入指令:");
    gotoxy(6,9);
    printf("注:输入错误指令或0将直接返回");
    gotoxy(19,8);
}

void print_head_sum(struct HEAD sum[10])
{
    print_screen_two();
    gotoxy(4,2);
    printf("请输入要操作的学生数据组的编号");
    int i;
    for(i=0;i<10;i++)
    {
        gotoxy(4,4+i);
        printf("%d",i+1);
        if(sum[i].phead==NULL)
            printf("(无数据).");
        else
            printf(".%s",sum[i].name);
    }
    gotoxy(4,15);
    printf("输入编号(输入0或输入错误则返回上一级):  ");
}

void print_list_to_file(struct HEAD *head)
{
    print_screen_one();
    gotoxy(4,2);
    printf("将以下数据输入文件:");
    gotoxy(4,4);
    print_chained_list(4,head);
    printf("\n\n    ");
}

void print_main(int wor)
{
    print_screen_two();
    gotoxy(0,3);
    printf("                           主菜单\n\n");
    printf("             1.新增学生序列      5.增删学生信息\n\n");
    printf("             2.修改学生信息      6.学生序列排序\n\n");
    printf("             3.显示学生信息      7.保存数据文件\n\n");
    printf("             4.查询学生信息      8.读取数据文件\n\n");
    printf("                        9.退出系统\n\n");
    printf("             请输入指令,按回车结束:     ");
    gotoxy(4,17);
    if(wor==1)
        printf("指令错误,请重新输入");
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
    printf("请选择升序还是降序(升序:1 降序:2):");
    gotoxy(12,6);
    scanf("%s",order);
    if(order[0]=='1'&&strlen(order)==1)
        o=0;
    else if(order[0]=='2'&&strlen(order)==1)
        o=1;
    else
    {
        printf("\n            输入错误,请回车后重新输入!");
        getchar();
        getchar();
        goto sa_m3;
    }
    return o;
}

void print_single_struct(int x,struct STUDENT *p,struct HEAD *head)
{
    int i;
    printf("学号");
    print_blank(head->id_len-2);
    printf("姓名");
    print_blank(head->name_len-2);
    printf("性别");
    print_blank(1);
    printf("成绩");
    print_blank(9*head->cum_num-4);
    printf("总成绩   平均成绩\n");
    print_blank(x);
    printf("%s",p->ni[0]);
    print_blank(head->id_len-strlen(p->ni[0])+2);
    printf("%s",p->ni[1]);
    print_blank(head->name_len-strlen(p->ni[1])+2);
    if(p->gen=='m')
        printf("男");
    else
        printf("女");
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
    printf("                欢迎使用学生信息管理系统");
    gotoxy(16,7);
    system("PAUSE");
}


#endif // SCREEN_H_INCLUDED
