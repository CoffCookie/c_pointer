#include <stdio.h>
#include <string.h>
void test(char *p);

int main(void)
{
    char a[9]="";
    printf("before= %s %p \n",a,&a);
    test(&a[0]);
    printf("after= %s %p\n", a,&a); //コピー完了!
    return 0;
}

void test(char *p){
	char str[9]="hogehoge";
	//ポインタアドレス。
	printf("test before *p=%s %p \n",p ,&p);
	//ポインタの中身のアドレス
	printf("test before a[0]=%s %p \n",p ,p);

	printf("strのサイズ=%lu\n",sizeof(str));
	strncpy(p, str, sizeof(str)); 
	//strncpy()によって返される文字列は、NULL終端されていないのでnull入れる。
	p[sizeof(str)-1] = '\0';
	//ポインタのアドレス
	printf("test after *p=%s %p \n",p ,&p);
	//ポインタの中身アドレス
	printf("test after a[0]=%s %p \n",p ,p);
}



