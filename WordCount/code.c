#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
	int i,cnt = 0, countword = 0;
	char ch, filename[80];
	FILE *fp;
	fp = fopen(argv[2],"r");
	if(strcmp(argv[1],"-c") == 0 || strcmp(argv[1],"-C") == 0){
		while(!feof(fp)){
			ch = getc(fp);
			printf("%c",ch);
			cnt ++;
		}
		printf("�ַ�����%d\n",--cnt);
	}
	else if(strcmp(argv[1],"-w") == 0 || strcmp(argv[1],"-W") == 0){
		cnt = 0;
		while(!feof(fp)){
			ch = getc(fp);
			//�����س��ͽ���ѭ������� 
			if(ch == '\n'){    
				break;
			}else if(ch != ' '){ //��Ϊ�ո����������������ľ�Ϊһ������
				if(ch >= 'a' && ch <= 'z' || ch>='A' && ch <= 'Z' || ch >= '0' && ch <= '9'){
					printf("%c",ch);
					countword++;   //������ĸͳ�Ƶ��ʸ���
					cnt++;   //cnt��Ϊ��ͳ����ĸ����
				}
				while(!feof(fp)){
					ch = getc(fp);
					printf("%c",ch);
					if(ch == ' ' || ch == '\n'){ //�����ո���߻س�˵�������ĸ������
						break;
					}
					cnt++;
				}
				//ѭ����������ĸ���ȴ���1��countword��1,����1���Ѿ�ͳ�ƹ���
				//֮����ͳ��cnt��Ϊ�˷�ֹ��һ����ĸ�Ժ����̶����˿ո���߻س�����ظ����
				if(cnt > 1){
					if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
						countword++;
				}
				if(ch == '\n'){
					break;//���break������ĵڶ���break��ϵ��һ����������ѭ���� 
				}
			} 
		}
		printf("��������%d\n",countword);
	}
	return 0;
}