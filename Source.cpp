#include <iostream>;
#include <cmath>;
#include <fstream>;
#include <string>;
#include <sstream>;
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	string menu;
	while (true) {
		cout << "Меню:\n1 - Алгоритм Евклида\n2 - Решето Эратосфена\n3 - Обработка текстового файла\n4 - Задачи для подготовки к экзамену [Ряды]\n5 - Задачи для подготовки к экзамену [Файлы]\n6 - Быки и коровы\n1227 - выход\n>> ";
		cin >> menu;
		if (atoi(menu.c_str()) == 1227) {
			break;
		}
		switch (atoi(menu.c_str()))
		{
		case 1: {
			int a, b;
			cout << "Введите числа a и b для нахождения их НОД\na = "; cin >> a;
			cout << "b = "; cin >> b;
			while (a != 0 && b != 0) {
				if (a > b) { a %= b; }
				else { b %= a; }
			}
			cout << "НОД = " << a + b;
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		case 2: {
			int n, j;
			cout << "Введите число n, до которого будем искать просте числа\nn = "; cin >> n;
			int* arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = i;
			}
			arr[1] = 0;
			for (int i = 2; i <= n; i++) {
				if (arr[i] != 0) {
					j = i + i;
					while (j <= n) { arr[j] = 0; j += i; }
				}
			}
			for (int i = 0; i < n; i++) {
				if (arr[i] != 0) { cout << arr[i] << " "; }
			}
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		case 3: {
			cout << "Открывается файл task.txt из корневой папки проекта. Результат работы программы записвается в файл answer.txt, создающийся на рабочем столе\n";

			ifstream file; //чтение		while (file.get(ch))
			file.open("C:\\Программирование\Euclid and Eratosthenes");
			ofstream file2; //запись	file2 << s;
			file2.open("C:\\Users\\Admin\\Desktop\\answer.txt");

			string str;
			int znak;
			while (getline(file, str)) {
				str[0] == '+' ? znak = 1 : str[0] == '*' ? znak = 2 : str[0] == '/' ? znak = 3 : str[0] == '!' ? znak = 4 : str[0] == 'M' ? znak = 5 : str[0] == 'X' ? znak = 6 : znak = -1;
				switch (znak) {
				case 1: {
					//cout << "+\t";	//вывод
					int s = 0, i = 2; string chislo = "";
					while (str[i] != '0' || str[i - 1] != ' ') {
						if (str[i] != ' ') {
							chislo += str[i];
						}
						else {
							if (chislo[chislo.length()] == ' ') { chislo[chislo.length()] = char(""); }
							s += stoi(chislo);
							chislo = "";
						}
						i++;
					}
					//cout << "Сумма: " << s << endl;	//вывод
					file2 << "Сумма: " << s << endl;
					break;
				}
				case 2: {
					//cout << "*\t";	//вывод
					int prod = 1, j = 0; string chislo = "", arr[2];
					for (int i = 2; i <= str.length(); i++) {
						if (str[i] != ' ' && i < str.length()) { chislo += str[i]; }
						else {
							if (chislo[chislo.length()] == ' ') { chislo[chislo.length()] = char(""); }
							arr[j] = chislo;
							prod *= stoi(chislo);
							chislo = "";
							j++;
						}
					}
					//cout << arr[0] << " * " << arr[1] << " = " << prod << endl;	//вывод
					file2 << arr[0] << " * " << arr[1] << " = " << prod << endl;
					break;
				}
				case 3: {
					//cout << "/\t";	//вывод
					string chislo = "";
					for (int i = 2; i < str.length(); i++) { chislo += str[i];	}
					if (chislo[chislo.length()] == ' ') { chislo[chislo.length()] = char(""); }
					//cout << 1 << "/" << chislo << " = " << 1 / stod(chislo) << endl;	//вывод
					file2 << 1 << "/" << chislo << " = " << 1 / stod(chislo) << endl;
					break;
				}
				case 4: {
					//cout << "!\t";	//вывод
					string chislo = ""; int fct = 1;
					for (int i = 2; i < str.length(); i++) { chislo += str[i]; }
					if (chislo[chislo.length()] == ' ') { chislo[chislo.length()] = char(""); }
					for (int i = 2; i <= stoi(chislo); i++) { fct *= i; }
					//cout << chislo << "! = " << fct << endl;	//вывод
					file2 << chislo << "! = " << fct << endl;
					break;
				}
				case 5: {
					//cout << "M\t";	//вывод
					int max = -1; string chislo = "";
					for (int i = 2; i < str.length(); i++) {
						if (str[i] != ' ' && i < str.length()) { chislo += str[i]; }
						else {
							if (chislo[chislo.length()] == ' ') { chislo[chislo.length()] = char(""); }
							if (stoi(chislo) > max) { max = stoi(chislo); }
							chislo = "";
						}
					}
					//cout << "Наибольшее среди первых 5-и чисел: " << max << endl;	//вывод
					file2 << "Наибольшее среди первых 5-и чисел: " << max << endl;
					break;
				}
				case 6: {
					//cout << "X\t";	//вывод
					int pos = 0, min = 0, n = 0, j = 0; string chislo; str += " ";
					for (int i = 2; i < str.length() - 1; i++) { if (str[i] != ' ' && str[i + 1] == ' ') { n++; } }
					int* arr = new int[n];
					string* rr = new string[n];
					for (int i = 2; i < str.length(); i++) {
						if (str[i] != ' ' && i < str.length()) { chislo += str[i]; }
						else {
							//if (chislo[chislo.length()] == ' ') { chislo[chislo.length()] = char(""); }
							arr[j] = stoi(chislo);
							rr[j] = chislo;
							min = stoi(chislo);
							chislo = "";
							pos = j;
							j++;
						}
					}
					for (int i = 0; i < n - 1; i++) {
						if (arr[i] < min) { pos = i; min = arr[i]; }
						
					}
					//for (int i = 0; i < n; i++) { cout << "(" << arr[i] << ")"; }
					//cout << "Позиция наименьшего элемента: " << pos+1 << endl;	//вывод
					file2 << "Позиция наименьшего элемента: " << pos+1 << endl;
					break;
				}
				default: {
					//cout << "\n"; //вывод
					file2 << endl;
					break;
				}
				}
			}

			file.close();	file2.close();
			//remove("C:\\Users\\Admin\\Desktop\\answer.txt");
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		case 4: {
			cout << "Программа определяет количество учеников в классе, чей рост превышает средний\nВведите рост в см и нажмите Enter. Для завершения введите 0 и нажмите Enter\n";
			int arr[1000];
			int h = 1, n = 0; float s = 0;
			while (h != 0) { cin >> h; arr[n] = h; n++; }
			for (int i = 0; i < n - 1; i++) { s += arr[i]; } s = s / (n - 1);
			h = 0;
			cout << "Средний рост: " << s <<  " см\n";
			for (int i = 0; i <= n - 1; i++) { if (arr[i] > s) { h++; } }
			cout << "Количество людей, чей рост превышает средний: " << h;
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		case 5: {
			cout << "Программа выводит на экран и сохряныет в файл Olympiad.txt отсортированный по кол-ву золотых медалей список стран-участниц\n";
			cout << "Введите количество золотых, серебряных и бронзовых медалей для соответствующей страны в указаном пордке, разделяя числа пробелом\n";
			string arr[10][6] = {
				{ "Австрия", "", "", "", "", "" },
				{ "Германия", "", "", "", "", "" },
				{ "Канада", "", "", "", "", "" },
				{ "Китай", "", "", "", "", "" },
				{ "Корея", "", "", "", "", "" },
				{ "Норвегия", "", "", "", "", "" },
				{ "Россия", "", "", "", "", "" },
				{ "США", "", "", "", "", "" },
				{ "Финляндия", "", "", "", "", "" },
				{ "Япония", "", "", "", "", "" },
			};
			for (int i = 0; i < 10; i++) {
				cout << arr[i][0] << " --> ";
				cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
				arr[i][4] = to_string( stoi(arr[i][1]) + stoi(arr[i][2]) + stoi(arr[i][3]) );
				arr[i][5] = to_string(stoi(arr[i][1]) * 7 + stoi(arr[i][2]) * 6 + stoi(arr[i][3]) * 5);
			}
			
			ofstream file; //запись	file << s;
			file.open("C:\\Users\\Admin\\Desktop\\Olympiad.txt");
			int mest[2][10]; for (int i = 0; i < 10; i++) { mest[0][i] = i; mest[1][i] = stoi(arr[i][1]); };

			//cout << endl << endl;
			//for (int i = 0; i < 2; i++) { for (int j = 0; j < 10; j++) { cout << mest[i][j] << "\t"; }; cout << endl; }

			for (int i = 0; i < 10; i++) {
				for (int j = 9; j > i; j--) {
					if (mest[1][j] > mest[1][j - 1]) {
						int temp1 = mest[1][j];
						mest[1][j] = mest[1][j - 1];
						mest[1][j - 1] = temp1;

						int temp0 = mest[0][j];
						mest[0][j] = mest[0][j - 1];
						mest[0][j - 1] = temp0;
					}
				}
			}

			//cout << endl << endl;
			//for (int i = 0; i < 2; i++) {for (int j = 0; j < 10; j++) { cout << mest[i][j] << "\t"; }; cout << endl; }

			cout << endl;
			cout << "№\tСтрана\t\tЗолото\tСеребро\tБронза\tВсего\tОчков\n";
			for (int i = 0; i < 10; i++) {
				cout << endl << i+1 << "\t";
				for (int j = 0; j < 6; j++) {
					cout << arr[mest[0][i]][j] << "\t"; if (arr[mest[0][i]][0].length() < 8 && j == 0) { cout << "\t"; }
				}
			}
			
			//for (int i = 0; i < 10; i++) { cout << i + 1 << "\t"; for (int j = 0; j < 6; j++) { cout << arr[i][j] << "\t"; }; cout << endl; }

			file << "№\tСтрана\t\tЗолото\tСеребро\tБронза\tВсего\tОчков\n";
			for (int i = 0; i < 10; i++) {
				file << endl << i + 1 << "\t";
				for (int j = 0; j < 6; j++) {
					file << arr[mest[0][i]][j] << "\t"; if (arr[mest[0][i]][0].length() < 9 && j == 0) { file << "\t"; }
				}
			}

			file.close();
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		case 6: {
			cout << "Программа про быков и коров\n";
			string p;
			bool err = true;
			while (err) {
				srand(time(NULL));
				p = to_string(rand() % 9999 + 1000);
				int count, allcount = 0;
				for (int i = 0; i < 4; i++) {
					count = 0;
					for (int j = 0; j < 4; j++) {
						if (p[i] != p[j]) { count++; }
					}
					if (count == 3) { allcount++; }
				}
				if (allcount == 4) { err = false; }
			}
			cout << ">>" << p << "<<\n";
			string a;
			int plus = -1, minus;
			while (plus < 4) {
				plus = 0; minus = 0;
				cout << "Введите число и нажмите enter: ";
				cin >> a;
				for (int i = 0; i < 4; i++) {
					if (a[i] == p[i]) { plus++; }
					for (int j = 0; j < 4; j++) {
						if (a[i] == p[j] && i != j) { minus++; }
					}
				}
				cout << "+ " << plus << "\n- " << minus << "\n";
			}
			cout << "Конец\t";
			cout << "Загаданное число " << p;
			cout << "\n----------------------Работа программы-задания завершена----------------------\n\n";
			break;
		}
		default: {
			cout << "Команда не распознана\n";
			break;
		}
		}
		cin.get(); cout << ">> Enter <<"; cin.get();
		system("cls");
	}
	cout << "\n\n\n----------------------Работа корневой программы завершена----------------------";
	return 0;
}
