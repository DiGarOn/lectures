/*

экз*0,3 + кр*0,1 + пр * 0,2 + зд * 0,1 + лаб * 0,3

qt - Шлее
Паттерны - GoF

Иструментальные средства и POSIX
Иструментальные средства: 
    компиляторы(Ассемблер, транслятор , редактор связей), 
    ИСР - интергрированная среда разработки, 
    Отладчик,
    системы автоматизации и управления сборкой, 
    система контроля и учета версий, 
    Профилировщики, 
    система тестирования, 
    анализаторы кода
    средства инструментирования 

make - система сбоки, управления сборкой, автоматизацией сборки 
automake 

Portable Operation System Interface standart 

XPG4 -> IEEE 1003 -> ISO/IEC 4599
потоки OSPIX -> POSIX 1003.1.c-1996

Система автоматизации и управления сборкой make

gmake -> GNUMakefile  \   | Правила      |
make  -> Makefile     - > | разрешения   |
     \-> -f build.make/   | зависимостей |

pmake - BSD
nmake - by microsoft in visual studia

ex:
lol:
-> echo "LOL"
kek: lol nya
-> echo "KEK"
nya: lol
-> echo "\"\\w\/\""
___________________
lol.o: lol.c
-> gcc -c lol.c
kek: lol nya
-> gcc lol.o nya.o -o kek
nya.o: lol.o nya.c
-> gcc -c nya.c
________________________
lol.o: lol.c
-> gcc -c lol.c
kek: lol nya
-> gcc $^ -o $@
nya.o: lol.o nya.c
-> gcc -c nya.c
_____________________
kek: lol nya
-> $(cc) $^ $LDFLAGS -o $@



*/

