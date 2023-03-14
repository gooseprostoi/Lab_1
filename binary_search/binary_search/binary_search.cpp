#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

using namespace std;

const int COUNT_REP = 10000000;


// функция бинарного поиска
int binary_search(int* A, int N, int value) {
	int a = 0, b = N - 1, mid;
	bool flag = false;
	while ((a <= b) && (flag == false)) {
		mid = (a + b) / 2;
		if (A[mid] == value) return mid;
		if (A[mid] > value) b = mid - 1;
		else a = mid + 1;
	}
	return -1;
}



int main() {
	// открываем файл для записи данных на txt файл
	string path;
	path = "..\\python";
	ofstream out;
	out.open(path + "\\data.txt");
	if (out.is_open()) {
		for (int N = 100; N < 1000000; N += 10000) {
			// создаём упорядоченный массив из N чисел
			int* A = new int[N];

			unsigned int seed = 1001;
			default_random_engine rng(seed);

			int temp = 0;
			for (int i = 0; i < N; i++) {
				uniform_int_distribution<unsigned> dstr(temp, temp + 10);
				A[i] = dstr(rng);
				temp = A[i];
			}

			// включаем таймер
			auto begin = chrono::steady_clock::now();

			// ищем значение COUNT_REP раз
			for (int i = 0; i < COUNT_REP; i++) {
				binary_search(A, N, -1);
			}

			// находим среднее время
			auto end = chrono::steady_clock::now();
			auto time_span = chrono::duration_cast<chrono::nanoseconds>(end - begin);

			out << N << "\t" << time_span.count() / ((float)COUNT_REP) << "\n";

			delete[] A;
		}
	}
	else
		cout << "Ошибка создания файла\n";
}