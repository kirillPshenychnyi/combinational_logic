#ifndef _FACTORY_HPP
#define _FACTORY_HPP

class Element;
class InputPort;

class ElementFactory 
{

public:
	
	Element * createXOR(const Element * p1, const Element *p2) const;

	Element * createAND(const Element * p1, const Element * p2) const;

	Element * createOR(const Element * p1, const Element * p2) const;

	Element * createBuffer(const Element * p) const;

	Element * createInverter(const Element * p);

	Element * createInputElement(const InputPort * p);

};











#endif
