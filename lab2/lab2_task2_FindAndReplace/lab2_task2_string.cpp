#include <vector>
#include <fstream>
#include <optional>
#include <string>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <limits>
#include <numbers>
#include "FindAndReplase.h"
#include "ParseArg.h"
/*Разработайте функцию
```c++
std::string FindAndReplace(std::string const& subject, std::string const& search, std::string  const& replace)
``
возвращающую результат замены всех вхождений подстроки **search** в строке **subject** на строку **replace**.
Если искомая строка пустая, замены строк производиться не должно.
Вычислительная сложность алгоритма, лежащего в основе FindAndReplace, должна линейно зависеть от длины строки Subject
Разработайте на ее основе программу, заменяющую все вхождения искомой строки в стандартном потоке ввода на строку-заменитель и выводящую результат в стандартный поток вывода.
Чтение и замена вхождений подстроки должны проводиться строка за строкой. Ввод продолжается до появления символа конца файла в стандартном потоке ввода.
Синтаксис командной строки:
```sh
replace.exe <search-string> <replace-string>
``
<span style="color:red">Внимание, реализация данной функции должна иметь сложность близкую к O(N+M+k*L),
где N - длина текста, M - длина искомой строки, L - длина строки-заменителя, а k - количество вхождений искомой строки в тексте.</span>
*/
int main(int argc, char* argv[])
{
    std::string search;
    std::string replace;
    auto args = ParseArg(argc, argv, search, replace);
    if (!args)
    {
        return 1;
    }
    //выделить в функцию все что ниже
    std::string inString;
    while (getline(std::cin, inString) && inString != "\\0")
    {
        std::string outString;
        outString = FindAndReplace(inString, search, replace);
        std::cout << outString <<std::endl;
    }
}
