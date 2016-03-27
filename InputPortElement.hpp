#ifndef _INPUT_PORT_ELEMENT_HPP
#define _INPUT_PORT_ELEMENT_HPP
#include "Element.hpp"
#include "InputPort.hpp"



class InputPortElement : public Element 
{

	const InputPort & m_inputPort;
	
public:

	InputPortElement(const InputPort & _input) :m_inputPort(_input) {}

	InputPortElement(const InputPortElement &) = delete;

	InputPortElement & operator = (const InputPortElement & ) = delete;

	bool evaluate() const ;
};

inline bool InputPortElement::evaluate() const
{
	return m_inputPort.getValue();


}













#endif

