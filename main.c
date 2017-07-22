#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include "chained_list.h"
#include "screen.h"
#include "choose.h"
#include "output.c"
#include "fliter_builder.c"
#include "file.c"
#include "sort.c"

struct HEAD sum[10];
int class_num;

int main()
{
	char order[10];
	int i,hns_m;
	for(i=0;i<10;i++)
    {
        sum[i].phead=NULL;
        sum[i].savetag=0;
    }
	print_welcome();
	class_num = 0;
	main_m1:
	print_main(0);
	while (scanf("%s", order) != EOF)
	{
		while (order[0]>'9' || order[0]<'1'||strlen(order)>1)
		{
			print_main(1);
			scanf("%s", order);
		}
		if (order[0] == '9')
			break;
		else if (order[0] == '1')//����ѧ������
			build_new_list();
		else if (order[0] == '2')//�޸�ѧ����Ϣ
			change_stu_data();
		else if (order[0] == '3')//��ʾѧ����Ϣ
			display_stu_data();
		else if (order[0] == '4')//��ѯѧ����Ϣ
			search_for_single_stu();
		else if (order[0] == '5')//��ɾ��������
		{
			print_group_or_single();
			char temp[10];
			scanf("%s",temp);
			if(strlen(temp)==1&&temp[0]=='1')
                delete_chained_list();
            else if(strlen(temp)==1&&temp[0]=='2')
                change_chained_list();
			else
                goto main_m1;
		}
		else if (order[0] == '6')//ѧ����������
			sort_all();
		else if (order[0] == '7')//���������ļ�
			save_to_file();
		else if (order[0] == '8')//��ȡ�����ļ�
			read_from_file();
		print_main(0);
	}
	hns_m=1;
	for(i=0;i<10;i++)
        if(sum[i].phead!=NULL&&sum[i].savetag==0)
        {
            hns_m=0;
            break;
        }
    if(hns_m==0)
    {
        print_final_save();
        scanf("%s",order);
        if(order[0]=='y'||order[0]=='Y')
            goto main_m1;
    }
    print_goodbye();
    getchar();
    getchar();
	return 0;
}

