#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

using namespace std;

const int COUNT_REP = 1;
const int MAX_RAND = 99; // максимальное значение для чисел в массиве


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
	int* carr = new int[N];
	for (int i = 0; i < N; i++) {
		carr[A[i]] = 1;
	}
	// меняем местами по стратегии C
	for (int i = 1; i < N; i++) {
		int j = i;
		while (j != 0 && carr[A[j]] > carr[A[j - 1]]) {
			int temp;
			temp = A[j - 1];
			A[j - 1] = A[j];
			A[j] = temp;
			j--;
		}
	}
	delete[] carr;
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
			// создаём равномерный массив
			int* A = new int[N];

			for (int i = 0; i < N; i++) {
				A[i] = i;
			}

			strategy_C(A, N); // применяем стратегию А
			// рандомное число, которое надо найти
			unsigned int seed = 1001;
			default_random_engine rng(seed);
			uniform_int_distribution<unsigned> dstr(0, N - 1);

			// включаем таймер
			auto begin = chrono::steady_clock::now();

			// ищем значение COUNT_REP раз
			for (int i = 0; i < COUNT_REP; i++) {
				exhaustive_search(A, N, dstr(rng));
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