#ifndef _PARSER_HPP
#define _PARCER_HPP

#include <fstream>
#include <vector>
class Controller;

enum class CommandType
{
	Show,
	Set
};

static const char * show = "SHOW_PORT";
static const char * set = "SET_INPUT";

struct Command
{
	CommandType m_type;

	char port[10];

	bool value;
};


class Parser 
{
	Controller & m_controller;

	std::ifstream m_stream;

	std::vector<Command > m_commands;

public:

	Parser(Controller & _cont, const char * m_path);

	Parser(const Parser &) = delete;

	Parser & operator = (const Parser &) = delete;

	void analyse();

private:

	void sendCommand(Command & _c);

	void sendCommands();

	void parceString(char * command);
};













#endif