#include "Controller.hpp"
#include "parser.hpp"
#include "messages.hpp"
#include <cassert>
#include <iostream>


Parser::Parser(Controller & _cont, const char * _path):m_controller(_cont) 
{
	m_stream.open(_path);

}


void Parser::analyse() 
{
	std::cout << std::endl;
	char buf[100];
	while (!m_stream.eof())
	{
		m_stream.getline(buf, 100);
		if (!strcmp(buf, " "))
			break;
		parceString(buf);

	}

	sendCommands();
	

}

void Parser::sendCommands()
{
	for (Command c : m_commands) 
		sendCommand(c);
	

}

void Parser::parceString(char * command)
{
	
	char * token = strtok(command, " ");
	Command newCommand;


	if (!strcmp(token, show)) 
		newCommand.m_type = CommandType::Show;		
	else if (!strcmp(token, set))
		newCommand.m_type = CommandType::Set;
	else 
		throw std::logic_error(Messages::unknownCommand);
	

	token = strtok(nullptr, " ");
	strcpy(newCommand.port,token);
	
	if (newCommand.m_type == CommandType::Set) 
	{
		token = strtok(nullptr, " ");
		if (!token)
			throw std::logic_error(Messages::missingValue);
		if (!strcmp(token, "true"))
			newCommand.value = true;
		else if (!strcmp(token, "false"))
			newCommand.value = false;
		else 
			throw std::logic_error(Messages::wrongValue);

	}

	m_commands.push_back(newCommand);
}

void Parser::sendCommand(Command & _c)
{
	switch(_c.m_type) 
	{
	case CommandType::Set:
		m_controller.setValueOnPort(_c.port, _c.value);
		break;

	case CommandType::Show:
		m_controller.showPortValue(_c.port,std::cout);
	}

}



