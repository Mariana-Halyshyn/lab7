#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Employee {
    int hoursWorked;       // Відпрацьовані години
    double hourlyRate;     // Погодинна оплата

public:
    Employee(int hours, double rate) : hoursWorked(hours), hourlyRate(rate) {}

    // Метод для обчислення зарплати
    double calculateSalary() const {
        return hoursWorked * hourlyRate;
    }

    // Перевантаження операторів 

    double operator+(const Employee& other) const {
        return this->calculateSalary() + other.calculateSalary();
    }

    friend ostream& operator<<(ostream& out, const Employee& emp) {
        out << "Відпрацьовано годин: " << emp.hoursWorked
            << ", Погодинна оплата: " << emp.hourlyRate
            << " грн, Зарплата: " << emp.calculateSalary() << " грн";
        return out;
    }
};

int main() {
    setlocale(LC_ALL, "Ukr"); 
    srand(static_cast<unsigned int>(time(0)));

    vector<Employee*> employees;

    for (int i = 0; i < 10; ++i) {
        int hours = rand() % 51 + 50; 
        double rate = rand() % 6 + 5; 
        employees.push_back(new Employee(hours, rate));
    }


    double totalCost = 0;
    cout << "Інформація про працівників:\n";
    for (const auto& emp : employees) {
        cout << *emp << endl;  // Використовуємо перевантажений оператор <<
        totalCost += emp->calculateSalary();
    }

    cout << "\nСумарні витрати компанії на оплату праці: " << totalCost << " грн\n";

    if (employees.size() >= 2) {
        cout << "\nСумарна зарплата першого і другого працівника: "
            << *employees[0] + *employees[1] << " грн\n";
    }
    for (auto& emp : employees) {
        delete emp;
    }

    return 0;
}
