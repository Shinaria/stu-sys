extern int class_num;
extern struct HEAD sum[10];

int list_to_file(int n,char road[256])
{
    FILE *fp;
    int i;
    struct STUDENT *p;
    fp=fopen(road,"w");
    p=sum[n].phead;
    while(p!=NULL&&p->pnext!=NULL)
    {
        p=p->pnext;
        fprintf(fp,"%s\t%s\t",p->ni[0],p->ni[1]);
        if(p->gen=='m')
            fprintf(fp,"m\t");
        else
            fprintf(fp,"f\t");
        for(i=0;i<sum[n].cum_num;i++)
            fprintf(fp,"%-6.2lf\t",p->score[i]);
        fprintf(fp,"\n");
    }
    sum[n].savetag=1;
    return fclose(fp);
}

int file_to_list(int n,char road[256])
{
    FILE *fp;
    fp=fopen(road,"r");
    struct STUDENT *p1,*p2;
    sum[n].stu_num=0;
    sum[n].id_len=0;
    sum[n].name_len=0;
    sum[n].phead=malloc(sizeof(struct STUDENT));
    p1=sum[n].phead;
    int i;
    while(1)
    {
        p2=malloc(sizeof(struct STUDENT));
        p2->pnext=NULL;
        p2->ave=0;
        p2->sum=0;
        if(fscanf(fp,"%s",p2->ni[0])==EOF)
        {
            free(p2);
            p1->pnext=NULL;
            break;
        }
        sum[n].id_len=maxx(sum[n].id_len,strlen(p2->ni[0]));
        fscanf(fp,"%s",p2->ni[1]);
        sum[n].name_len=maxx(sum[n].name_len,strlen(p2->ni[1]));
        do
        {
            fscanf(fp,"%c",&p2->gen);
        }while(p2->gen!='f'&&p2->gen!='m');
        for(i=0;i<sum[n].cum_num;i++)
        {
            fscanf(fp,"%lf",&p2->score[i]);
            p2->sum+=p2->score[i];
        }
        p2->ave=p2->sum/sum[n].cum_num;
        p1->pnext=p2;
        p1=p2;
        p2=p2->pnext;
        sum[n].stu_num+=1;
    }
    sum[n].savetag=1;
    return fclose(fp);
}


void save_to_file()
{
    char road[256];
    int no;
    no=choose_group(1);
    if(no==-1)
        return;
    print_get_road();
    scanf("%s",road);
    int result;
    result=list_to_file(no,road);
    if(result!=-1)
    {
        print_list_to_file(&sum[no]);
        printf("保存文件成功!");
    }
    getchar();
    getchar();
}

void read_from_file()
{
    char road[256];
    int no,result;
    print_build_new_list();
    print_get_road();
    scanf("%s",road);
    no=choose_group(0);
    if(no==-1)
        return;
    getname(no);
    sum[no].cum_num=print_getnumcum();
    sum[no].phead=malloc(sizeof(struct STUDENT));
    result=file_to_list(no,road);
    if(result!=-1)
    {
        print_file_to_list(&sum[no]);
        printf("读取数据成功!");
        class_num++;
    }
    getchar();
    getchar();
    return;
}
