#ifndef _OUTPUT_PORT_HPP
#define _OUTPUT_PORT_HPP
#include "Port.hpp"
#include <memory>

class Element;

class OutputPort : public Port
{
	const Element * m_element;

public:

	OutputPort(const std::string & _name, Element * _element = nullptr);

	OutputPort(const OutputPort &) = delete;

	OutputPort & operator = (const OutputPort &) = delete;

	void connect(const Element * _element);

	void disconnect();

	bool getValue() const override;

	bool hasConnection() const;

};


inline bool OutputPort::hasConnection() const
{

	return (m_element != nullptr);

}

#endif 