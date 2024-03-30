#pragma once

class WindowsForm : public Form 
{
public:
    explicit WindowsForm(std::pair<int, int> Position) : Form(Position) {};
    void addControl(Control* control) override 
    {
        Form::addControl(control);
    }
    std::string toString() override 
    {
        return "WindowsForm";
    }
};
class WindowsLabel : public Label
{
public:
    WindowsLabel(std::string& Text, std::pair<int, int> Position) : Label(Text, Position) {};
    std::string toString() override
    {
        return "WindowsLabel";
    }
};
class WindowsTextBox : public TextBox
{
public:
    WindowsTextBox(std::string& Text, std::pair<int, int> Position) : TextBox(Text, Position) {};
    std::string toString() override
    {
        return "WindowsTextBox";
    }
};
class WindowsButton : public Button 
{
public:
    WindowsButton(std::string& Text, std::pair<int, int> Position) : Button(Text, Position) {};
    std::string toString() override 
    {
        return "WindowsButton";
    }
};





class LinuxForm : public Form
{
public:
    explicit LinuxForm(std::pair<int, int> Position) : Form(Position) {};
    void addControl(Control* control) override
    {
        Form::addControl(control);
    }
    std::string toString() override
    {
        return "LinuxForm";
    }
};
class LinuxLabel : public Label
{
public:
    LinuxLabel(std::string& Text, std::pair<int, int> Position) : Label(Text, Position) {};
    std::string toString() override
    {
        return "LinuxLabel";
    }
};
class LinuxTextBox : public TextBox
{
public:
    LinuxTextBox(std::string& Text, std::pair<int, int> Position) : TextBox(Text, Position) {};
    std::string toString() override
    {
        return "LinuxTextBox";
    }
};
class LinuxButton : public Button
{
public:
    LinuxButton(std::string& Text, std::pair<int, int> Position) : Button(Text, Position) {};
    std::string toString() override
    {
        return "LinuxButton";
    }
};




class MacOSForm: public Form
{
public:
    explicit MacOSForm(std::pair<int, int> Position) : Form(Position) {};
    void addControl(Control* control) override
    {
        Form::addControl(control);
    }
    std::string toString() override
    {
        return "MacOSForm";
    }
};
class MacOSLabel : public Label
{
public:
    MacOSLabel(std::string& Text, std::pair<int, int> Position) : Label(Text, Position) {};
    std::string toString() override
    {
        return "MacOSLabel";
    }
};
class MacOSTextBox : public TextBox
{
public:
    MacOSTextBox(std::string& Text, std::pair<int, int> Position) : TextBox(Text, Position) {};
    std::string toString() override
    {
        return "MacOSTextBox";
    }
};
class MacOSButton : public Button
{
public:
    MacOSButton(std::string& Text, std::pair<int, int> Position) : Button(Text, Position) {};
    std::string toString() override
    {
        return "MacOSButton";
    }
};