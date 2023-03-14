#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

using namespace std;

const int COUNT_REP = 1;

// функция полного перебора
int exhaustive_search(int* A, int N, int value) {
	for (int i = 0; i < N; i++) {
		if (A[i] == value)
			return i;
	}
	return -1;
}



int main() {
	setlocale(LC_ALL, "RUS");

	// открываем файл для записи данных на txt файл
	string path;
	path = "..\\python";

	ofstream out;
	out.open(path + "\\data.txt");
	if (out.is_open()) {
		for (int N = 100; N < 1000000; N += 10000) {
			// создаём массив из N случайных чисел от 0 до 9
			int* A = new int[N];

			int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
			unsigned int seed = 1001;
			default_random_engine rng(seed);
			uniform_int_distribution<unsigned> dstr(0, 9);
			for (int i = 0; i < N; i++) {
				A[i] = arr[dstr(rng)];
			}

			

			// включаем таймер
			auto begin = chrono::steady_clock::now();

			// ищем значение COUNT_REP раз
			for (int i = 0; i < COUNT_REP; i++) {
				exhaustive_search(A, N, -1);
			}

			// находим среднее время
			auto end = chrono::steady_clock::now();
			auto time_span = chrono::duration_cast<chrono::microseconds>(end - begin);

			out << N << "\t" << time_span.count() / ((float) COUNT_REP) << "\n";


			delete[] A;

		}
	}
	else
		cout << "Ошибка создания файла\n";
}