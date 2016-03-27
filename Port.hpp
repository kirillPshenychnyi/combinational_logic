#ifndef _PORT_HPP
#define _PORT_HPP
#include <string>

class Port {

	const std::string m_name;

protected:

	Port(const std::string & _name) : m_name(_name) {}

public:
	Port(const Port & _port) = delete;

	Port & operator = (const Port &) = delete;

	~Port() {}

	virtual bool getValue() const = 0;

	const std::string & getName() const;

};


inline const std::string & Port::getName() const 
{
	return m_name;

}
#endif


