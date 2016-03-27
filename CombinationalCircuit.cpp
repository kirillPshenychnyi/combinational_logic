#include "CombinationalCircuit.hpp"

CombinationalCircuit::CombinationalCircuit(const std::string & _name): m_name(_name)
{
}

bool CombinationalCircuit::getPortValue(const std::string & _portName) const
{
	return m_ports.find(_portName)->second->getValue();

}


void CombinationalCircuit::addPort(std::unique_ptr<Port> _newPort) 
{
	m_ports.insert(std::make_pair(_newPort->getName(), std::move(_newPort)));

}

void CombinationalCircuit::addElement(const std::string & _name,std::unique_ptr<const Element> _newElement)
{
	m_elements.insert(std::make_pair(_name,std::move(_newElement)));

}

const Element * CombinationalCircuit:: getElement(const std::string & _name) const 
{
	return m_elements.at(_name).get();
}

Port * CombinationalCircuit :: getPort(const std::string & _portName)const 
{
	return m_ports.at(_portName).get();

}


