#ifndef _UNARY_ELEMENT_HPP
#define _UNARY_ELEMENT_HPP
#include "Element.hpp"




class UnaryElement : public Element 
{
	const Element * m_element;

	const Operation m_operationCode;

public:

	UnaryElement(const Element * _element, Operation _operation) : m_element(_element), m_operationCode(_operation) {}

	UnaryElement(const UnaryElement & _element) = delete;

	UnaryElement & operator = (const UnaryElement & _element) = delete;

	bool evaluate() const override;

	Operation getOperationCode() const;

};

inline Operation UnaryElement::getOperationCode() const 
{
	return 	m_operationCode;

}

inline bool UnaryElement::evaluate() const
{
	bool signal = m_element->evaluate();
	
	if (m_operationCode == Operation::Inverter)
		return (signal) ? false : true;
	
	return signal;
}









#endif