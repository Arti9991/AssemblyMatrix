# AssemblyMatrix
Проект по ускорению вычисления умножения матриц размерами MxNxK, при помощи написания ассемблерного микроядра на языке ассемблера x86. Система Linux ubuntu. 
.Cpp файлы содержат основной код c++ для генерации и подготовки исходных матриц. Далее в коде с++ происходит подключение ассемблерного микроядра Matrix2.s, для вычисления
блока 8х8 и записи в итоговую матрицу. Время выполнения ассемблерной функции фиксируется и вычислияется производительность относительно идеального случая (все 
такты являются вычислительными и идеальная производительность составит M*N*K / P, где P - количество АЛУ. В данном случае используется процессор Intel® Core™ i5-10505
в котором имеется 8 АЛУ. Однако особенность архитектуры х86 состоит в том, что вычисления в двух АЛУ могут идти паралельно, соответственно считаем, что теоретическое 
количество арифметико логических устройств равно 16). Далее, при помощи bash скрипта, происхожит запуск и вычисление производительности при условии изменения 
одного из размеров MxNxK, изменение происхожит с шагом 8 для кратности микроядру. Резльтаты сохраняются в csv файлы с названиями соответсвенно, изменияемой величине. 
В jupyter notebook строятся графики с результатами тестов для их анализа
