#include <iostream>

#include "LogCommand.hpp"


void print(LogCommand& log_command, const std::string& message);


int main() {
#if WIN32
	setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
	std::cout << "\tПаттерн \"Команда\"\n\n" << std::endl;

	std::string message = "Hello World!";
	std::string filename = "out.txt";

	LogCommandConsole logCommandConsole;
	LogCommandFile logCommandFile(filename);

	print(logCommandConsole, message);
	print(logCommandFile, message);

	std::cin.get();
	return 0;
}

void print(LogCommand& log_command, const std::string& message) {
	log_command.print(message);
}
