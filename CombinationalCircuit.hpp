#ifndef _COMBINATIONAL_CIRCUIT_HPP
#define _COMBINATIONAL_CIRCUIT_HPP

#include <unordered_map>
#include <memory>
#include <vector>

#include "Element.hpp"
#include "Port.hpp"


class CombinationalCircuit {

	const std::string m_name;

	std::unordered_map<std::string,std::unique_ptr<Port>> m_ports;

	std::unordered_map<std::string,std::unique_ptr<const Element>> m_elements;

public:

	CombinationalCircuit(const std::string & _name);
	
	CombinationalCircuit(const CombinationalCircuit &) = delete;

	CombinationalCircuit & operator = (const CombinationalCircuit &) = delete;

	int getPortsAmount() const;

	int getElementsAmount() const;

	void addPort(std::unique_ptr<Port> _newPort);

	void addElement(const std::string & _name,std::unique_ptr<const Element> _newElement);

	bool getPortValue(const std::string & _name) const;

	bool hasPort(const std::string & _name) const;

	bool hasElement(const std::string & _ID) const;

	const Element * getElement(const std::string & _name) const;

	Port * getPort(const std::string & _portName)const;
};

inline bool CombinationalCircuit::hasElement(const std::string & _ID) const 
{
	return (m_elements.count(_ID) != 0);

}

inline int CombinationalCircuit::getPortsAmount() const 
{
	return m_ports.size();

}

inline int CombinationalCircuit::getElementsAmount() const
{
	return m_elements.size();

}

inline bool CombinationalCircuit::hasPort(const std::string & _name) const
{
	return (m_ports.count(_name) != 0);
}







#endif