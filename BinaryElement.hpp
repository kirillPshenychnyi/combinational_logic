#ifndef _BINARY_ELEMENT_HPP
#define _BINARY_ELEMENT_HPP
#include "Element.hpp"


class BinaryElement: public Element 
{
	const Operation m_operationCode;

	const Element * m_FirstElement;

	const Element * m_SecondElement;

public:

	BinaryElement(Operation _operation, const Element * _element1, const Element * _element2);

	bool evaluate() const override;

	Operation getOperation() const;

};



inline Operation BinaryElement::getOperation() const 
{
	return m_operationCode;

}





#endif