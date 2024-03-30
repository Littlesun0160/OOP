#pragma once

class Control
{
private:
    std::pair<int, int> m_Position;
public:
    explicit Control(std::pair<int, int> Position)
    {
        m_Position = Position;
    }
    virtual void setPosition(std::pair<int, int> Position)
    {
        m_Position = Position;
    };
    virtual std::pair<int, int> getPosition()
    {
        return m_Position;
    };
    virtual std::string toString()
    {
        return {};
    }
    virtual ~Control() {}
};

class Form : public Control 
{
public:
    std::vector<Control*> Controls;
    Form(std::pair <int, int> Position) : Control(Position) {}

    virtual void addControl(Control* control) 
    {
        std::cout << "Добавлен элемент " << control->toString() << " в " << this->toString() << "\n";
        Controls.push_back(control);
    }
    std::string toString() override 
    {
        return "Form";
    }
};

class Label : public Control 
{
private:
    std::string m_Text;
public:
    Label(std::string Text, std::pair <int, int> Position) : Control(Position)
    {
        m_Text = Text;
    }
    void setText(const std::string& newText) 
    {
        m_Text = newText;
        std::cout << "Текст метки изменен на '" << newText << "'\n";
    }
    std::string getText() 
    {
        std::cout << "Текст метки = '" << m_Text << "'\n";
        return m_Text;
    }
};

class TextBox : public Control 
{
private:
    std::string m_Text;
    void OnValueChanged()
    {
        if (m_Text.length() > 15)
        {
            std::cout << "Длина текста в поле ввода превышает 15 символов\n";
        }
    }
public:
    TextBox(std::string& Text, std::pair<int, int> Position) :Control(Position) 
    {
        m_Text = Text;
    }
    void setText(const std::string& newText) 
    {
        m_Text = newText;
        std::cout << "Текст в поле ввода изменен на '" << newText << "'\n";
        OnValueChanged();
    }
    std::string getText() 
    {
        std::cout << "Текст из поля ввода = '" << m_Text << "'\n";
        return m_Text;
    }
};

class Button : public Control 
{
private:
    std::string m_Text;
public:
    Button(std::string& Text, std::pair<int, int> Position): Control(Position)
    {
        m_Text = Text;
    }
    void setText(const std::string& newText) 
    {
        m_Text = newText;
        std::cout << "Текст на кнопке изменен на '" << newText << "'\n";
    }
    std::string getText() 
    {
        std::cout << "Текст при нажатии кнопки = '" << m_Text << "'\n";
        return m_Text;
    }

    void Click() 
    {
        std::cout << "Кнопка нажата через " << this->toString() << "\n" << m_Text << "\n";
    }
};
