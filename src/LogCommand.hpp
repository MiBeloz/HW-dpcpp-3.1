#pragma once

#include <string>
#include <iostream>
#include <fstream>


class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) const noexcept = 0;
};

class LogCommandConsole final : public LogCommand {
public:
    void print(const std::string& message) const noexcept override {
        std::cout << "LogCommandConsole: " << message << std::endl;
    }
};

class LogCommandFile final : public LogCommand {
public:
    explicit LogCommandFile(const std::string& filename) : m_filename(filename) {}
    void print(const std::string& message) const noexcept override {
	    std::ofstream ofile;
	    ofile.open(m_filename, std::fstream::app);

	    if (ofile.is_open()) {
		    ofile << message << std::endl;
            std::cout << "LogCommandFile: Сообщение в файл '" + m_filename + "' записано." << std::endl;
	    }
	    ofile.close();
    }

private:
    std::string m_filename;
};
