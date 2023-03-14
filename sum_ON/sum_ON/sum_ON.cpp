#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

using namespace std;

const int COUNT_REP = 100;

// функция перебора O(N)
void sum_of_two(int* A, int N, int value) {
	int i = 0, j = N - 1;
	while (i != j) {
		if (A[i] + A[j] == value) {
			cout << i << " " << j << "\n";
			return;
		}
		if (A[i] + A[j] > value)
			j--;
		else
			i++;
	}
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
				sum_of_two(A, N, 20);
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