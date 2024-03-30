#pragma once
#include "OSForms.hpp"


class ControlFactory 
{
public:
    virtual Form* createForm(std::pair<int, int> Position) 
    { 
        return new Form(Position);
    }
    virtual Label* createLabel(std::string Text, std::pair <int, int> Position)
    { 
        return new Label(Text, Position);
    }
    virtual TextBox* createTextBox(std::string Text, std::pair<int, int> Position) 
    {
        return new TextBox(Text, Position);
    }
    virtual Button* createButton(std::string Text, std::pair<int, int> Position)
    {
        return new Button(Text, Position);
    }
    virtual ~ControlFactory() = default;
};

class WindowsControlFactory : public ControlFactory
{
public:
    Form* createForm(std::pair<int, int> Position) override 
    {
        return new WindowsForm(Position);
    }
    Label* createLabel(std::string Text, std::pair <int, int> Position) override
    {
        return new WindowsLabel(Text, Position);
    }
    TextBox* createTextBox(std::string Text, std::pair<int, int> Position) override 
    {
        return new WindowsTextBox(Text, Position);
    }
    Button* createButton(std::string Text, std::pair<int, int> Position) override 
    {
        return new WindowsButton(Text, Position);
    }
};

class LinuxControlFactory : public ControlFactory
{
public:
    Form* createForm(std::pair<int, int> Position) override
    {
        return new LinuxForm(Position);
    }
    Label* createLabel(std::string Text, std::pair <int, int> Position) override
    {
        return new LinuxLabel(Text, Position);
    }
    TextBox* createTextBox(std::string Text, std::pair<int, int> Position) override 
    {
        return new LinuxTextBox(Text, Position);
    }
    Button* createButton(std::string Text, std::pair<int, int> Position) override 
    {
        return new LinuxButton(Text, Position);
    }
};


class MacOSControlFactory : public ControlFactory
{
public:
    Form* createForm(std::pair<int, int> Position) override
    {
        return new MacOSForm(Position);
    }
    Label* createLabel(std::string Text, std::pair <int, int> Position) override
    {
        return new MacOSLabel(Text, Position);
    }
    TextBox* createTextBox(std::string Text, std::pair<int, int> Position) override 
    {
        return new MacOSTextBox(Text, Position);
    }
    Button* createButton(std::string Text, std::pair<int, int> Position) override 
    {
        return new MacOSButton(Text, Position);
    }
};