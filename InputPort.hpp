#pragma once
#include "Port.hpp"


class InputPort : public Port {

	bool m_currentValue;

public:

	InputPort(const std::string & _name) : Port(_name) ,m_currentValue(false) {}

	void setValue(bool _signal);

	bool getValue() const override;


};


inline void InputPort::setValue (bool _signal) 
{
	m_currentValue = _signal;

}


inline bool InputPort::getValue() const 
{
	return m_currentValue;

}

