#include "OutputPort.hpp"
#include "Element.hpp"


OutputPort::OutputPort(const std::string & _name, Element * _elem) : Port(_name)
{
	if (_elem)
		m_element = _elem;

}



void OutputPort::connect(const Element * _elem)
{
	m_element = _elem;

}


void OutputPort::disconnect() {

	m_element = nullptr;
}


bool OutputPort::getValue() const
{
	return(m_element) ? m_element->evaluate() : false;
}
