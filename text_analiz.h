/* Модуль обработки строки!
Преобразует строку к удобному для подсчета виду

A	acos 	арккосинус	+ +
B	asin 	арксинус	+ +
D	atan 	арктангенс	+ +
F	ceil 	округление до ближайшего большего целого числа	+ +
C	cos 	косинус	+ +
J	ch 	гиперболический косинус	+ +
H	exp 	вычисление экспоненты	+ +
I	abs 	абсолютная величина (числа с плавающей точкой)	+ +
K	floor 	округление до ближайшего меньшего целого числа	+ +
L	fmod 	вычисление остатка от деления нацело для чисел с плавающей точкой
M	ctg  котангенс + +
N	actg аркккотангенс + +
G	ln 	натуральный логарифм	+ +
O	log 	логарифм по основанию 10	+ +
P	cth гиперболический котангенс ++
S	sin 	синус	+ +
T	sh 	гиперболический синус	+  +
Y	sqrt 	квадратный корень	+ +
V	tan 	тангенс	+ +
W	th 	гиперболический тангенс	+ +
* 
* Авраменко Е. АК5-31
*/

#ifndef TEXT_ANALIZ_H
#define TEXT_ANALIZ_H

//Фича
  char* ficha(char* st2);

///Процедура бреобразует строку к нижнему регистру

char* registr(char* st1);
///Преобразует строку ,чтобы считать синус
void *ssin(int i,char *input);

///Преобразует строку ,чтобы считать косинус
void *ccos(int i,char *input) ;

///Преобразует строку ,чтобы считать арккосинус
void *aacos(int i,char *input);

///Преобразует строку ,чтобы считать арксинус
void *aasin(int i,char *input);

///Преобразует строку ,чтобы считать арктангенс
void *aatan(int i,char *input);

///Преобразует строку ,для подсчета округления до ближайшего целого числа
void *cceil(int i,char *input);

///Преобразует строку ,чтобы гиперболический косинус
void *cch(int i,char *input);

///Преобразует строку ,чтобы считать экспоненту
void *eexp(int i,char *input);

///Преобразует строку ,чтобы считать модуль числа
void *aabs(int i,char *input);

///Преобразует строку ,чтобы считать округление до ближайшего меньшего целогои числа
void *ffloor(int i,char *input);

///Преобразует строку ,чтобы считать натуральный логарифм
void *lln(int i,char *input);

///Преобразует строку ,чтобы считать десятичный логарифм
void *llog(int i,char *input);

///Преобразует строку ,чтобы считать гиперболический синус
void *ssh(int i,char *input);

///Преобразует строку ,чтобы считать корень
void *ssqrt(int i,char *input);

///Преобразует строку ,чтобы считать тангенс
void *ttan(int i,char *input);

///Преобразует строку ,чтобы считать гиперболический тангенс
void *tth(int i,char *input);

///Преобразует строку ,чтобы считать котангенс
void *cctg(int i,char *input);

///Преобразует строку ,чтобы считать арккотангенс
void *aactg(int i,char *input);

///Преобразует строку ,чтобы считать гиперболический котангенс
void *ccth(int i,char *input);

char *len(char* input1,char* value);

///Функция преобразует строку к нужному виду
char *proobraz(char* input);



#endif
