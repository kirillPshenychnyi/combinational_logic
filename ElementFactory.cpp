#include "BinaryElement.hpp"
#include "UnaryElement.hpp"
#include "InputPortElement.hpp"
#include "ElementFactory.hpp"
#include "Port.hpp"

Element * ElementFactory::createXOR(const Element * p1, const Element * p2) const
{
	return new BinaryElement(Operation::XOR,p1, p2);
}

Element * ElementFactory::createAND(const Element *p1, const Element * p2) const
{
	return new BinaryElement(Operation::AND, p1, p2);

}


Element * ElementFactory::createOR(const Element *p1, const Element * p2) const
{
	return new BinaryElement(Operation::OR, p1, p2);

}

Element * ElementFactory::createBuffer(const Element * p) const
{
	return new UnaryElement(p, Operation::Buffer);
}

Element * ElementFactory::createInverter(const Element * p)
{
	return new UnaryElement (p,Operation::Inverter);
}

Element * ElementFactory::createInputElement(const InputPort * p)
{
	return new InputPortElement(*p);
}

