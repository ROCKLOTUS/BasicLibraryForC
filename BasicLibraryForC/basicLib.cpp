#include "basicLib.h"
#include "stdafx.h"
#include <stdlib.h>
//putc(char ch,FILE *stream):��ӡ�ַ�ch���ļ���stream
void B_putc(void) {
	printf("In B_putc\n");
	FILE* stream;
	char *p, ch = '\0', str[] = "Welcome to NorthWest University!";
	stream = stdout;
	for (p = str; (ch!= 'EOF') && (*p != 0); p++)
		ch = putc(*p, stream);
	putchar('\n');
}

//B_putchar is an example to illustrate the usage of putchar
//putchar(ch):���ַ�ch��ӡ����Ļ
void B_putchar(void) {
	printf("In B_putchar\n");
	char str[] = "Welcome to NorthWest University!";
	int i = 0;
	printf("�ַ���:\n");
	while (str[i]) {
		putchar(str[i]);
		i++;
	}
	putchar('\n');
}

void B_fputc(void) {
	printf("In B_fputc");
	FILE *fp;
	errno_t err;
	char *ch,c,str[] = "This is a test!";
	//д���ַ������ļ�file.txt
	err = fopen_s(&fp,"file.txt", "w+");
	if (err) {
		printf("can not open write file!\n");
			exit(-1);
	}
	ch = str;
	while (*ch) {
		fputc(*ch, fp);
		ch++;
	}
	fclose(fp);				//�ر��ļ���

	//�����ļ�����Ļ
	err = fopen_s(&fp,"file.txt", "r");
	if (err) {
		printf("can not open read file!");
		exit(-1);
	}
	do {
		c = fgetc(fp);
		putchar(c);
	} while (c != EOF);
	putchar('\n');
	fclose(fp);
}