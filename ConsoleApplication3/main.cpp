#include "file.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, ".UTF-8");

    try {
        Complex number1;
        Complex number2(5, 3);
        Complex number3(2, 4);
        Complex number4(number2);
        cout << "СОЗДАНИЕ КОМПЛЕКСНЫХ ЧИСЕЛ" << endl;
        cout << "Число 1: ";
        number1.Show();
        cout << "Число 2: ";
        number2.Show();
        cout << "Число 3: ";
        number3.Show();
        cout << "Копия числа 2: ";
        number4.Show();
        cout << "\nВВОД КОМПЛЕКСНОГО ЧИСЛА" << endl;
        cin >> number1;

        cout << "Введенное число: ";
        number1.Show();

        
        cout << "\nАРИФМЕТИЧЕСКИЕ ОПЕРАЦИИ" << endl;

        cout << "Сложение: ";
        cout << number2 + number3 << endl;

        cout << "Вычитание: ";
        cout << number2 - number3 << endl;

        cout << "Умножение: ";
        cout << number2 * number3 << endl;

        cout << "Деление: ";
        cout << number2 / number3 << endl;

        
        cout << "\nОПЕРАТОР ПРИСВАИВАНИЯ" << endl;

        number1 = number2;
        cout << "После присваивания: ";
        number1.Show();

       
        number1 += number3;
        cout << "После += : ";
        number1.Show();

        cout << "\nИНКРЕМЕНТ" << endl;

        cout << "Префиксный ++: ";
        cout << ++number2 << endl;

        cout << "Постфиксный ++: ";
        cout << number2++ << endl;

        cout << "После постфиксного ++: ";
        cout << number2 << endl;

        cout << "\nДЕКРЕМЕНТ" << endl;

        cout << "Префиксный --: ";
        cout << --number2 << endl;

        cout << "Постфиксный --: ";
        cout << number2-- << endl;

        cout << "После постфиксного --: ";
        cout << number2 << endl;

        cout << "\nСРАВНЕНИЕ КОМПЛЕКСНЫХ ЧИСЕЛ" << endl;
        cout << "Число 2: " << number2 << endl;
        cout << "Число 3: " << number3 << endl;
        cout << "Число 2 > Число 3: "
            << (number2 > number3) << endl;
        cout << "Число 2 < Число 3: "
            << (number2 < number3) << endl;
        cout << "Число 2 == Число 3: "
            << (number2 == number3) << endl;
        cout << "Число 2 != Число 3: "
            << (number2 != number3) << endl;
    }
    catch (const exception& error) {
        cout << "Ошибка: " << error.what() << endl;
    }
    return 0;
}