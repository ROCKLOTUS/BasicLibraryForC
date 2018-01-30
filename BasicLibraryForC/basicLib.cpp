#include "basicLib.h"
#include "stdafx.h"
#include <stdlib.h>
//putc(char ch,FILE *stream):打印字符ch到文件流stream
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
//putchar(ch):把字符ch打印到屏幕
void B_putchar(void) {
	printf("In B_putchar\n");
	char str[] = "Welcome to NorthWest University!";
	int i = 0;
	printf("字符串:\n");
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
	//写入字符串到文件file.txt
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
	fclose(fp);				//关闭文件、

	//读入文件到屏幕
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