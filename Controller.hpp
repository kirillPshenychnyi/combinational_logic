#ifndef _CONTROLLER_HPP
#define _CONTROLLER_HPP

#include "CombinationalCircuit.hpp"
#include "ElementFactory.hpp"
#include <memory>


class Controller 
{

	std::unique_ptr <CombinationalCircuit> m_circuit;

	std::unique_ptr <ElementFactory> m_factory;

public:
	
	Controller(const std::string &_circuitName);
	
	Controller(const Controller &) = delete;

	Controller & operator = (const Controller &) = delete;

	void createUnaryElement(Operation _type, const std::string & ID, const std::string & _toConnect);

	void createBinaryElement(Operation _type, const std::string & ID,const std::string & _toConnect_1, const std::string & _toConnect_2);

	void createInputPortElement(const std::string & _portName);

	void createInputPort(const std::string & _portName);

	void createOutputPort(const std::string & _portName, const std::string & source);

	bool getPortValue(const std::string & _portName) const;

	void showPortValue(const std::string & _portName , std::ostream & _o) const;
	
	void setValueOnPort(const std::string & _Portname, bool value) ;


};









#endif
