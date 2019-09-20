/*
	ポインタ見本帳
*/

#include <stdio.h>
int main(void)
{
//スタック上にchar型のポインタを確保し、
//char型のポインタに定数領域上のhogeの場所を格納している。
	char *str_ptr,*str_kara;
//配列strをスタック領域に確保しhoge\0を格納
	char str[10]="hoge";

	char str_array[256];
	char *str_array_ptr[1];

	str_ptr = &str[0];
	printf("%lu\n",sizeof(str_ptr)); 		//4  ポインタのサイズ nullなし
	printf("%lu\n",sizeof(str));     		//5
	printf("%lu\n",sizeof(*str_ptr));		//1文字のみ
	printf("%lu\n",sizeof(str_array));		//256
	printf("%lu\n",sizeof(str_array_ptr));	//1024 (256*4)? 4(1*4?)
	printf("%lu\n",sizeof(char));			//1

	//型が一致しないといわれる。
	//ダブルクォーテーションは文字列
	//シングルクォーテーションは1文字

	//ポインタ1
	//OK
	//出力:aoge,aoge
	str_ptr[0] = 'a';
	printf("%s\n",str_ptr);

	//ポインタ2
	//OK
	//出力:boge,boge
	*str_ptr = 'b';
	printf("%s,%p,%p\n",str_ptr,&str_ptr,&str);


	while(*str_ptr != '\0')
	{
		putchar(*str_ptr);
		++str_ptr;
	}
	printf("\n");

	//禁止
	str_kara = str_ptr;
	printf("%s\n",str_kara);

	//配列
	//OK
	//出力:fgge,fgge
	str[0] = 'f';
	str[1] = 'g';
	printf("%s,%s,%p,%p\n",str_ptr,str,&str_ptr,&str);

	//ANSI規格では、文字列リテラルの変更は未定義（何が起こるかわからないということ）
	//禁止
	str_ptr = "ab";
	printf("%s,%s,%p,%p\n",str_ptr,str,&str_ptr,&str);

	//文字列後の結果
	//NG
	//出力:ab,dego
	str[0] = 'd';
	str[1] = 'e';
	printf("%s,%s,%p,%p\n",str_ptr,str,&str_ptr,&str);

	return 0;
}
