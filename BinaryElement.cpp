#include "BinaryElement.hpp"


BinaryElement::BinaryElement(Operation _operation, const Element * _element1, const Element * _element2):
	m_FirstElement(_element1),
	m_SecondElement(_element2),
	m_operationCode(_operation) {}


bool BinaryElement::evaluate() const
{
	bool firstSignal  =  m_FirstElement->evaluate();
	bool secondSignal =  m_SecondElement->evaluate();

	switch (m_operationCode) 
	{
	case Operation::AND:
		return secondSignal && firstSignal;
	case Operation::OR:
		return secondSignal || firstSignal;
	case Operation::XOR:
		return secondSignal ^ firstSignal;

	}

}