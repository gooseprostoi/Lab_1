#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

using namespace std;

const int COUNT_REP = 1;
const int MAX_RAND = 99; // максимальное значение для чисел в массиве

// функция нахождеия самого распространенного числа
int most_common_number(int* A, int N) {
	int carr[MAX_RAND + 1] = {0}; // счётчик
	int max = -1;
	int value = 0;
	for (int i = 0; i < N; i++) {
		if (carr[A[i]] > max) {
			max = carr[A[i]];
			value = i;
		}
	}
	return value;
}

// функция полного перебора
int exhaustive_search(int* A, int N, int value) {
	for (int i = 0; i < N; i++) {
		if (A[i] == value)
			return i;
	}
	return -1;
}


void strategy_C(int* A, int N) {
	// массив счётчик
	int carr[MAX_RAND + 1] = {0};
	for (int i = 0; i < N; i++) {
		carr[A[i]]++;
	}
	// меняем местами по стратегии C
	for (int i = 1; i < N; i++) {
		if (carr[A[i]] > carr[A[i - 1]]) {
			int temp = A[i - 1];
			A[i - 1] = A[i];
			A[i] = temp;
		}
	}
}



int main() {
	setlocale(LC_ALL, "RUS");


	
	// открываем файл для записи данных на txt файл
	string path;
	path = "..\\python";
	ofstream out;
	out.open(path + "\\dataC.txt");
	if (out.is_open()) {
		for (int N = 100; N < 1000000; N += 10000) {
			// создаём массив из N случайных чисел от 0 до MAX_RAND
			int* A = new int[N];

			int arr[MAX_RAND + 1];
			for (int i = 0; i < MAX_RAND + 1; i++) {
				arr[i] = i;
			}
			unsigned int seed = rand();
			default_random_engine rng(seed);
			uniform_int_distribution<unsigned> dstr(0, MAX_RAND);
			for (int i = 0; i < N; i++) {
				A[i] = arr[dstr(rng)];
			}

			strategy_C(A, N); // применяем стратегию C
			auto value = most_common_number(A, N); // находим самое распространенное число

			// включаем таймер
			auto begin = chrono::steady_clock::now();
			// ищем значение COUNT_REP раз
			for (int i = 0; i < COUNT_REP; i++) {
				exhaustive_search(A, N, value);
			}

			// находим среднее время
			auto end = chrono::steady_clock::now();
			auto time_span = chrono::duration_cast<chrono::microseconds>(end - begin);

			out << N << "\t" << time_span.count() / ((float)COUNT_REP) << "\n";


			delete[] A;
		}
	}
	else
		cout << "Ошибка создания файла\n";
}