#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>


// Na zajeciach wszystkie klasy(struktury) mialy swoje wlasne pliki naglowkowe i zrodlowe, tutaj w jednym
// dla ulatwienia

struct Address {
	std::string city, street;
	int streetnum;
	int localenum;
	size_t zip;

};

struct Employee {
	std::string name, surname;
	size_t age;
	Address addr;
};

class EmployeeManager {
public:
	static std::vector<Employee> employees; //do static trzeba przydzielic pamiec w plkku zrodlowym

};

class Command {
public:
	virtual void execute() = 0; // =0 pozwala nam nie okreslac implementacji metody; metoda abstrakcyjna
								// nie mozna tworzyc obiektu tej klasy
};

using pCommand = std::shared_ptr<Command>;

class CommandManager {
	std::map<std::string, pCommand> commands; 

public: 
	CommandManager();
	
	void loop();
};

class ExitCommand : public Command {
public:
	void execute();

};

class AddCommand : public Command {
public:
	void execute();
};

class ListCommand : public Command {
public:
	void execute();
};

struct Salary :public TaxCountable<Salary>{
	int employeeId, baseSalary, experienceExtra;

	Salary(int employeeId, int baseSalary, int experienceExtra): employeeId(employeeId), baseSalary(baseSalary), experienceExtra(experienceExtra)){}

	int total()	{
		return baseSalary + experienceExtra;
	}
};

class SalaryManager {
public:
	static std::vector<Salary> salaries;
};

class PinCommand : public Command {
public:
	void execute();
};

template <class Derived>
class TaxCountable {
public:
	int countTax() {
		return 22* static_cast<Derived*>(this)->total() /100;
	}
};

class TaxCommand : public Command {
public:
	void execute();
};

struct Bonus : TaxCountable<Bonus> {
	std::string label;
	int value;
	int total() {
		return value;
	}
};

class BonusCommand : public Command {
public:
	void execute();
};