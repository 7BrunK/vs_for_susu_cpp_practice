#include <iostream>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

void bubble_sort(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - 1 - (i - start); j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

int main_arrays() {
    int N, K;

    cout << "Введите размер массива N: ";
    cin >> N;
    if (N <= 0) {
        cerr << "Ошибка: N <= 0" << endl;
        return 1;
    }

    int* arr = new int[N];
    // Инициализация массива случайными числами
    srand(time(NULL));
    cout << "Исходный массив: ";
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    cout << "\nВведите количество блоков K: ";
    cin >> K;

    try {
        if (K <= 0 || K > N) {
            throw "Некорректное значение K!";
        }

        int block_size = N / K;
        int remainder = N % K; // Остаток распределяется по первым блокам

        cout << "\nРазмеры блоков: ";
        int cur_index = 0;

        for (int i = 0; i < K; i++) {
            int cur_block_size = block_size + (i < remainder ? 1 : 0);
            cout << cur_block_size << " ";

            // Сортируем текущий блок по убыванию
            bubble_sort(arr, cur_index, cur_index + cur_block_size);
            cur_index += cur_block_size;
        }

        cout << "\nМассив после сортировки блоков: ";
        print(arr, N);
    }
    catch (const char* err) {
        cerr << "Ошибка: " << err << endl;
        delete[] arr;
        return 1;
    }

    delete[] arr;
    return 0;
}

bool is_real_number(const string& str) {
    int i = 0;
    int n = str.length();
    bool has_digits = false;
    bool has_point = false;

    if (str[i] == '+' || str[i] == '-') i++;
    if (i >= n) return false;

    // Проверка символов строки
    for (; i < n; i++) {
        if (isdigit(str[i])) {
            has_digits = true;
        }
        else if (str[i] == '.') {
            // Точка может быть только одна
            if (has_point) return false;
            has_point = true;
        }
        // Если встретилась не цифра и не точка
        else return false;
    }
    return has_digits;
}

int main_strings() {
    string input;
    cout << "Введите строку для проверки: ";
    getline(cin, input);

    if (input.empty()) {
        cerr << "Ошибка: Введена пустая строка!";
        return 1;
    }

    if (is_real_number(input)) printf("Строка %s является вещественным числом.", input.c_str());
    else printf("Строка %s НЕ является вещественным числом.", input.c_str());

    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    cout << "Выберите задачу:\n";
    cout << "1. Задача на массивы\n";
    cout << "2. Задача на строки\n";
    cout << "Ваш выбор: ";
    cin >> choice;
    cin.ignore();
    cout << string(30, '=') << endl;

    switch (choice) {
    case 1:
        return main_arrays();
    case 2:
        return main_strings();
    default:
        cerr << "Ошибка!" << endl;
        return 1;
    }
}