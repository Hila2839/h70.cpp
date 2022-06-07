#include "message.hpp"

Message::Message(TextInput& a_input, TextTransformer& a_trans, TextOutput& a_output)
: m_input(a_input)
, m_trans(a_trans)
, m_output( a_output)
, m_string("")
{
}


void Message::run()
{
    while(true)
    {

    }
}


void Message::input()
{
    m_string = m_input.input();
}

void Message::manipulate()
{
    m_string = m_trans.incoding(m_string);
}

void Message::output()
{
    m_output.output(m_string);
}

