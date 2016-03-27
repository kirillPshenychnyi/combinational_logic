#include "CombinationalCircuit.hpp"
#include "Controller.hpp"
#include "testslib.hpp"
#include "parser.hpp"

DECLARE_OOP_TEST(unaryElementTest_inventer) 
{
	Controller c("Inverter");
	c.createInputPort("a");
	c.createInputPortElement("a");
	c.createUnaryElement(Operation::Inverter,"Inverter_1", "a");
	
	c.createOutputPort("b", "Inverter_1");
	
	c.setValueOnPort("a", 0);
	assert(c.getPortValue("b") == 1);
	
	c.setValueOnPort("a", 1);
	assert(c.getPortValue("b") == 0);

}

DECLARE_OOP_TEST(binary_element_AND) 
{
	Controller c("AND");

	c.createInputPort("a");
	c.createInputPort("b");
	

	c.createInputPortElement("a");
	c.createInputPortElement("b");

	c.createBinaryElement(Operation::AND, "AND_1", "a", "b");

	c.createOutputPort("c","AND_1");

	assert(c.getPortValue("c") == 0);

	c.setValueOnPort("a", 0);
	c.setValueOnPort("b", 1);

	assert(c.getPortValue("c") == 0);

	c.setValueOnPort("a", 1);
	c.setValueOnPort("b", 1);

	assert(c.getPortValue("c") == 1);

}


DECLARE_OOP_TEST(OR_element_test) 
{
	Controller c("OR");

	c.createInputPort("a");
	c.createInputPort("b");


	c.createInputPortElement("a");
	c.createInputPortElement("b");

	c.createBinaryElement(Operation::OR, "OR_1", "a", "b");
	c.createOutputPort("c", "OR_1");

	assert (c.getPortValue("c") == 0);

	c.setValueOnPort("a", 1);
	
	assert(c.getPortValue("c") == 1);

	c.setValueOnPort("a", 0);
	c.setValueOnPort("b", 1);

	assert(c.getPortValue("c") == 1);

}

DECLARE_OOP_TEST(XOR_element_test) 
{
	Controller c("XOR");

	c.createInputPort("a");
	c.createInputPort("b");


	c.createInputPortElement("a");
	c.createInputPortElement("b");

	c.createBinaryElement(Operation::XOR, "XOR_1", "a", "b");
	c.createOutputPort("c", "XOR_1");

	assert(c.getPortValue("c") == 0);

	c.setValueOnPort("a", 1);

	assert(c.getPortValue("c") == 1);

	c.setValueOnPort("a", 0);
	c.setValueOnPort("b", 1);

	assert(c.getPortValue("c") == 1);

	c.setValueOnPort("a", 1);
	c.setValueOnPort("b", 1);

	assert(c.getPortValue("c") == 0);
}

DECLARE_OOP_TEST(NOR_binary_unary_element_test) 
{
	Controller c("NOR");
	
	c.createInputPort("a");
	c.createInputPort("b");

	c.createInputPortElement("a");
	c.createInputPortElement("b");
	
	c.createBinaryElement(Operation::OR, "NOR", "a", "b");
	c.createUnaryElement(Operation::Inverter, "Inverter_1", "NOR");
	c.createOutputPort("c", "Inverter_1");

	(c.getPortValue("c") == 1);

	c.setValueOnPort("a", 1);
	(c.getPortValue("c") == 0);


	c.setValueOnPort("a", 1);
	c.setValueOnPort("b", 1);

	(c.getPortValue("c") == 0);

}


DECLARE_OOP_TEST(NAND_binary_unary_element_test)
{
	Controller c("NAND");

	c.createInputPort("a");
	c.createInputPort("b");

	c.createInputPortElement("a");
	c.createInputPortElement("b");

	c.createBinaryElement(Operation::AND, "NAND", "a", "b");
	c.createUnaryElement(Operation::Inverter, "Inverter_1", "NAND");
	c.createOutputPort("c", "Inverter_1");

	(c.getPortValue("c") == 1);

	c.setValueOnPort("a", 1);
	(c.getPortValue("c") == 1);


	c.setValueOnPort("a", 1);
	c.setValueOnPort("b", 1);

	(c.getPortValue("c") == 0);

}


DECLARE_OOP_TEST(NXOR_binary_unary_element_test)
{
	Controller c("NXNOR");

	c.createInputPort("a");
	c.createInputPort("b");

	c.createInputPortElement("a");
	c.createInputPortElement("b");

	c.createBinaryElement(Operation::XOR, "NXOR", "a", "b");
	c.createUnaryElement(Operation::Inverter, "Inverter_1", "NXOR");
	c.createOutputPort("c", "Inverter_1");

	(c.getPortValue("c") == 1);

	c.setValueOnPort("a", 1);
	(c.getPortValue("c") == 0);


	c.setValueOnPort("a", 1);
	c.setValueOnPort("b", 1);

	(c.getPortValue("c") == 1);

}



/*
	A D D1 F
	0 0 x  0
	0 1 x  1
	1 x 0  0
	1 x 1  1
*/


DECLARE_OOP_TEST (simple_mx_2_1) 
{
	Controller c ("MX_2_1");								
	c.createInputPort("D");
	c.createInputPort("D1");
	c.createInputPort("A");

	c.createInputPortElement("D");								
	c.createInputPortElement("D1");
	c.createInputPortElement("A");

	c.createUnaryElement(Operation::Inverter, "notA", "A");

	c.createBinaryElement(Operation::AND, "F", "notA", "D");
	c.createBinaryElement(Operation::AND, "S", "A", "D1");
	c.createBinaryElement(Operation::OR, "Res", "F", "S");

	c.createOutputPort("p", "Res");
	assert(c.getPortValue("p") == 0);

	c.setValueOnPort("D", 1);
	assert(c.getPortValue("p") == 1);

	c.setValueOnPort("A", 1);
	assert(c.getPortValue("p") == 0);

	c.setValueOnPort("D1", 1);
	assert(c.getPortValue("p") == 1);

}

void createMX_4_2 (Controller & c) 
{
	c.createInputPort("A"); // A, A0 - address 
	c.createInputPort("A1");

	c.createInputPort("D");
	c.createInputPort("D1"); // data inputs
	c.createInputPort("D2");
	c.createInputPort("D3");

	c.createInputPortElement("A");
	c.createInputPortElement("A1");
	c.createInputPortElement("D");
	c.createInputPortElement("D1");
	c.createInputPortElement("D2");
	c.createInputPortElement("D3");

	c.createUnaryElement(Operation::Inverter, "notA", "A");
	c.createUnaryElement(Operation::Inverter, "notA1", "A1");

	c.createBinaryElement(Operation::AND, "notAA1", "notA", "notA1");
	c.createBinaryElement(Operation::AND, "t1", "D", "notAA1");

	c.createBinaryElement(Operation::AND, "notA_A1", "notA", "A1");
	c.createBinaryElement(Operation::AND, "t2", "notA_A1", "D1");

	c.createBinaryElement(Operation::AND, "A_notA1", "A", "notA1");
	c.createBinaryElement(Operation::AND, "t3", "A_notA1", "D2");

	c.createBinaryElement(Operation::AND, "AA1", "A", "A1");
	c.createBinaryElement(Operation::AND, "t4", "AA1", "D3");

	c.createBinaryElement(Operation::OR, "t1_t2", "t1", "t2");
	c.createBinaryElement(Operation::OR, "t3_t4", "t3", "t4");

	c.createBinaryElement(Operation::OR, "t1_t2_t3_t4", "t1_t2", "t3_t4");
	c.createOutputPort("F", "t1_t2_t3_t4");

}

DECLARE_OOP_TEST(_mx_4_2) 
{
	Controller c("DMX_4_1");
	createMX_4_2(c);

	assert(c.getPortValue("F") == 0);
	c.setValueOnPort("D",1);
	assert(c.getPortValue("F") == 1);


	c.setValueOnPort("D1", 1);
	c.setValueOnPort("A1", 1);
	assert(c.getPortValue("F") == 1);

	
	c.setValueOnPort("A", 1);
	c.setValueOnPort("A1", 0);
	assert(c.getPortValue("F") == 0);
	c.setValueOnPort("D2", 1);
	assert(c.getPortValue("F") == 1);


	c.setValueOnPort("A", 1);
	c.setValueOnPort("A1", 1);

	assert(c.getPortValue("F") == 0);
	c.setValueOnPort("D3", 1);
	assert(c.getPortValue("F") == 1);


}

DECLARE_OOP_TEST (parcer) 
{

	Controller c("MX_2_1");
	c.createInputPort("D");
	c.createInputPort("D1");
	c.createInputPort("A");

	c.createInputPortElement("D");
	c.createInputPortElement("D1");
	c.createInputPortElement("A");

	c.createUnaryElement(Operation::Inverter, "notA", "A");

	c.createBinaryElement(Operation::AND, "F", "notA", "D");
	c.createBinaryElement(Operation::AND, "S", "A", "D1");
	c.createBinaryElement(Operation::OR, "Res", "F", "S");

	c.createOutputPort("p", "Res");


	Parser p(c, "simulations.txt");

	p.analyse();
	
}


DECLARE_OOP_TEST (test_MX_simulations) 
{
	Controller c("MX_4_1");
	createMX_4_2(c);

	Parser p(c, "simulations2.txt");
	p.analyse();


}