#include "employee.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
std::vector<Employee> EmployeeManager::employees;

CommandManager::CommandManager() {
	commands["exit"] = std::make_shared<ExitCommand>(); 
	commands["add"] = std::make_shared<AddCommand>();
	commands["list"] = std::make_shared<ListCommand>();
}

void CommandManager::loop() {
	std::string current_command;
	while (std::getline(std::cin, current_command)) {
		if (commands.find(current_command) == commands.end())
			std::cout << "Command " << current_command << " is not supported\n";
		else
			commands[current_command]->execute(); //tu powinna byc -> bo shared_ptr, ja gdzies zgubilem ze to ma byc wskaznik
	}
}
void ExitCommand::execute() {
	std::cout << "Exiting application... \n";
	std::exit(0);
}

void AddCommand::execute() {
	std::string name;
	std::string surname;
	std::string age_str;
	size_t age;

	std::cout << "Pass employee name:\n+";
	std::getline(std::cin, name);
	std::cout << "Pass employee surname:\n+";
	std::getline(std::cin, surname);
	std::cout << "Pass employee age:\n+";
	std::getline(std::cin, age_str);

	std::stringstream ss(age_str);
	ss >> age;

	EmployeeManager::employees.push_back({ name, surname, age });
}

void ListCommand::execute() {
	for (int i = 0; i < EmployeeManager::employees.size(); i++) {
		std::cout << (i + 1) << ". " << EmployeeManager::employees[i].surname << ", " << EmployeeManager::employees[i].name[0] << ".\n";
	}

}

std::vector<Salary> SalaryManager::salaries;

void PinCommand::execute() {
	std::cout << "Pass employee id\n";
	int employeeId, baseSalary, experienceExtra;
	std::string id_str, baseSalary_str, experienceExtra_str;

	std::getline(std::cin, id_str);
	std::stringstream id_stream(id_str);
	id_stream >> employeeId;
	std::cout << "Pass base salary\n?";
	std::getline(std::cin, baseSalary_str);
	std::stringstream baseSalary_stream(baseSalary_str);
	baseSalary_stream >> baseSalary;

	std::cout << "Pass experience extra\n?";
	std::getline(std::cin, experienceExtra_str);
	std::stringstream experienceExtra_stream(experienceExtra_str);
	experienceExtra_stream >> experienceExtra;
	SalaryManager::salaries.push_back({ employeeId, baseSalary, experienceExtra });

}

void TaxCommand::execute() {
	for (auto&& salary : SalaryManager::salaries) {
		std::cout << salary.countTax() << std::endl;

	}
}

void BonusCommand::execute() { //TODO
	std::string employee_name, bonus_str;
	int bonus;

	//TODO WYBIERZ PRACOWNIKA

	std::cout << "Pass bonus\n?";
	std::getline(std::cin, bonus_str);
	std::stringstream bonus_stream(bonus_str);
	bonus_stream >> bonus;

	//TODO OBLICZ PODATEK
	struct Bonus {};

}