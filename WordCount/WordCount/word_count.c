#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Count(char* filename, char a[]) {//���������ڼ�¼�ַ����͵������ĸ���
	FILE* f;//ָ������ļ�
	int charCount = 0;//�ַ���
	int wordCount = 0;//������
	int i;
	char buffer[500];//����
	char c;
	int bufferLen;//�ļ������е�Ԫ�ܳ���
	int isLastBlank = 0;
	while (fgets(buffer, 500, f) != NULL) {
		int a = 0;
		bufferLen = strlen(buffer);
		for (i = 0; i < bufferLen; i++) {
			c = buffer[i];
			if (a == 0) {
				if (c == ' ' || c == '\t' || c == ',') {
					if (c != ',') {
						charCount++;
					}
					continue;
				}
				else {
					charCount++;
					wordCount++;
					a = 1;
				}
			}
			else {
				if (c == ' ' || c == '\t' || c == ',') {
					if (c != ',') {
						charCount++;
					}
					if (isLastBlank == 0) {
						wordCount++;
					}
					isLastBlank = 1;
				}
				else if (c != ',') {
					charCount++;
					isLastBlank = 0;
				}
			}
		}
	}
	fclose(f);
	if (strcmp(a, "-c") == 0) {
		printf("�ַ�����%d\n", charCount);
	}
	if (strcmp(a, "-w") == 0) {
		printf("��������%d\n", wordCount);
	}
}
int main(int argc, char* argv[]) {//argv[] ��ȡ����������������ַ���
	char* filename = argv[2];
	Count(filename, argv[1]);
}
