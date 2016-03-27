#ifndef _ELEMENT_HPP
#define _ELEMENT_HPP

enum class Operation {

	Buffer,
	Inverter,
	AND,
	OR,
	XOR

};


class Element {

protected:

	Element() = default;

	Element(const Element &) = delete;

	Element & operator = (const Element &) = delete;

public:
	virtual ~Element() {}

	virtual bool evaluate() const = 0;


};



#endif 