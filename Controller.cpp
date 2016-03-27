#include "Controller.hpp"
#include "CombinationalCircuit.hpp"
#include "Port.hpp"
#include "BinaryElement.hpp"
#include "InputPortElement.hpp"
#include "UnaryElement.hpp"
#include "messages.hpp"
#include "OutputPort.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>


Controller::Controller(const std::string & _name) 
{
	
	m_circuit = std::make_unique<CombinationalCircuit>(_name);

	m_factory = std::make_unique<ElementFactory>();
}


void Controller :: createUnaryElement(Operation _type, const std::string & ID, const std::string & _toConnect) 
{
	if (m_circuit->hasElement(ID))
		throw std::logic_error(Messages::duplicateID);

	if (_type != Operation::Buffer && _type != Operation::Inverter)
		throw std::logic_error(Messages::wrongCode);

	if (!m_circuit->hasElement(_toConnect))
		throw std::logic_error(Messages::unknownID);
			

	const Element * _elem = m_circuit->getElement(_toConnect);

	Element * newElement = (_type == Operation::Buffer) ? m_factory->createBuffer(_elem) : m_factory->createInverter(_elem);
	
	m_circuit->addElement(ID,std::unique_ptr<const Element>(newElement));


}

void Controller::createBinaryElement(Operation _type, const std::string & ID,const std::string & _toConnect_1, const std::string & _toConnect_2)
{
	if (!m_circuit->hasElement(_toConnect_1) || !m_circuit->hasElement(_toConnect_2))
		throw std::logic_error(Messages::unknownID);

	if (m_circuit->hasElement(ID))
		throw std::logic_error(Messages::duplicateID);


	const Element * first = m_circuit->getElement(_toConnect_1);
	const Element * second = m_circuit->getElement(_toConnect_2);

	std::unique_ptr<const Element> newElement;

	switch (_type) {
	case Operation::AND:
		newElement = std::unique_ptr<const Element>(m_factory->createAND(first, second));
		break;

	case Operation::OR:
		newElement = std::unique_ptr<const Element>(m_factory->createOR(first, second));
		break;
	
	case Operation::XOR:
		newElement = std::unique_ptr<const Element>(m_factory->createXOR(first, second));
		break;
	}

	m_circuit->addElement(ID,std::move(newElement));
}

void Controller::createInputPortElement(const std::string & _portName)
{
	if (!m_circuit->hasPort(_portName))
		throw std::logic_error(Messages::unknownPort);

	const InputPort * p = dynamic_cast<const InputPort *> ( m_circuit->getPort(_portName)); // -----------------------------------------
	
	if (!p)
		throw std::logic_error(Messages::wrongPortType);
	
	std::unique_ptr<Element> port (m_factory->createInputElement(p));
	
	m_circuit->addElement(_portName,std::move(port));

}

void Controller::createInputPort(const std::string & _portName)
{
	if (m_circuit->hasPort(_portName))
		throw std::logic_error(Messages::duplicatePort);

	std::unique_ptr<InputPort> port = std::make_unique<InputPort>(_portName);

	m_circuit->addPort(std::move (port));
}

void Controller::createOutputPort(const std::string & _portName,const std::string & ID)
{
	if (m_circuit->hasPort(_portName))
		throw std::logic_error(Messages::duplicatePort);

	if (!m_circuit->hasElement(ID))
		throw std::logic_error(Messages::unknownID);
	
	const Element * pElement = m_circuit->getElement(ID);
	assert(pElement);
	std::unique_ptr<OutputPort> port = std::make_unique<OutputPort>(_portName);
	port->connect(pElement);

	m_circuit->addPort(std::move(port));


}

bool Controller::getPortValue(const std::string & _portName) const
{
	if (!m_circuit->hasPort(_portName))
		throw std::logic_error(Messages::unknownPort);

	const Port * port = m_circuit->getPort(_portName);
	
	return port->getValue();

}

void Controller::setValueOnPort(const std::string & _portName, bool value) 
{
	if (!m_circuit->hasPort(_portName))
		throw std::logic_error(Messages::unknownPort);

	if (value != 0 && value != 1)
		throw std::logic_error(Messages::wrongValue);

	Port * port = m_circuit->getPort(_portName);

	InputPort * input = dynamic_cast<InputPort *>(port);

	if (!input)
		throw std::logic_error(Messages::wrongPortType);

	input->setValue(value);
	
}


void Controller::showPortValue(const std::string & _portName, std::ostream & _o) const
{
	
	if (!m_circuit->hasPort(_portName))
		throw std::logic_error(Messages::unknownPort);

	Port * port = m_circuit->getPort(_portName);
	
	std::cout << "Value on port " << _portName << " is " <<port->getValue() << std::endl;

}
