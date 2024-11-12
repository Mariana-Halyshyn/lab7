#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Employee {
    int hoursWorked;       // ³���������� ������
    double hourlyRate;     // ��������� ������

public:
    Employee(int hours, double rate) : hoursWorked(hours), hourlyRate(rate) {}

    // ����� ��� ���������� ��������
    double calculateSalary() const {
        return hoursWorked * hourlyRate;
    }

    // �������������� ��������� 

    double operator+(const Employee& other) const {
        return this->calculateSalary() + other.calculateSalary();
    }

    friend ostream& operator<<(ostream& out, const Employee& emp) {
        out << "³����������� �����: " << emp.hoursWorked
            << ", ��������� ������: " << emp.hourlyRate
            << " ���, ��������: " << emp.calculateSalary() << " ���";
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
    cout << "���������� ��� ����������:\n";
    for (const auto& emp : employees) {
        cout << *emp << endl;  // ������������� �������������� �������� <<
        totalCost += emp->calculateSalary();
    }

    cout << "\n������ ������� ������ �� ������ �����: " << totalCost << " ���\n";

    if (employees.size() >= 2) {
        cout << "\n������� �������� ������� � ������� ����������: "
            << *employees[0] + *employees[1] << " ���\n";
    }
    for (auto& emp : employees) {
        delete emp;
    }

    return 0;
}
