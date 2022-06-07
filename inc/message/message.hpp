#include "TextInput.hpp"
#include "TextOutput.hpp"
#include "TextTransformer.hpp"


class Message
{
public:
   
    Message(TextInput& a_input, TextTransformer& a_trans, TextOutput& a_output);

    void run();

    void input();
    void manipulate();
    void output();

private:
    TextInput& m_input;
    TextTransformer& m_trans;
    TextOutput& m_output;
    std::string m_string;
};