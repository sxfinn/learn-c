//����ͷ�ļ�
#include"contact.h"

int main()
{
	int input = 0;
	CONTACT con;
	int ret=init_Contact(&con);
	if (ret == 1)
	{
		return 1;
	}
	do
	{
		meum();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:Contact_Add(&con);
			break;
		case DEL:del_contact(&con);
			break;
		case SEARCH:search(&con);
			break;
		case MODIFY:mod_contact(&con);
			break;
		case SORT:sortby_name(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		case PRINT:print(&con);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}